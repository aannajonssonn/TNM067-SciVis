#include <modules/tnm067lab2/processors/hydrogengenerator.h>
#include <inviwo/core/datastructures/volume/volume.h>
#include <inviwo/core/util/volumeramutils.h>
#include <modules/base/algorithm/dataminmax.h>
#include <inviwo/core/util/indexmapper.h>
#include <inviwo/core/datastructures/volume/volumeram.h>
#include <modules/base/algorithm/dataminmax.h>

namespace inviwo {

const ProcessorInfo HydrogenGenerator::processorInfo_{
    "org.inviwo.HydrogenGenerator",  // Class identifier
    "Hydrogen Generator",            // Display name
    "TNM067",                        // Category
    CodeState::Stable,               // Code state
    Tags::CPU,                       // Tags
};

const ProcessorInfo HydrogenGenerator::getProcessorInfo() const { return processorInfo_; }

HydrogenGenerator::HydrogenGenerator()
    : Processor(), volume_("volume"), size_("size_", "Volume Size", 16, 4, 256) {
    addPort(volume_);
    addProperty(size_);
}

void HydrogenGenerator::process() {
    auto vol = std::make_shared<Volume>(size3_t(size_), DataFloat32::get());

    auto ram = vol->getEditableRepresentation<VolumeRAM>();
    auto data = static_cast<float*>(ram->getData());
    util::IndexMapper3D index(ram->getDimensions());

    util::forEachVoxel(*ram, [&](const size3_t& pos) {
        vec3 cartesian = idTOCartesian(pos);
        data[index(pos)] = static_cast<float>(eval(cartesian));
    });

    auto minMax = util::volumeMinMax(ram);
    vol->dataMap_.dataRange = vol->dataMap_.valueRange = dvec2(minMax.first.x, minMax.second.x);

    volume_.setData(vol);
}

vec3 HydrogenGenerator::cartesianToSpherical(vec3 cartesian) {
    vec3 sph{cartesian};

    // TASK 1: implement conversion using the equations in the lab script
    double r = glm::sqrt(glm::pow(cartesian.x, 2.0) + glm::pow(cartesian.y, 2.0) + glm::pow(cartesian.z, 2.0));
    if (r < 0.00001) return vec3{0.0};  // avoid division by 0, if r = 0 return nollvektor
    double theta = glm::acos(cartesian.z / r);
    double psi = glm::atan(cartesian.y, cartesian.x);

    sph.x = r;
    sph.y = theta;
    sph.z = psi;

    return sph;
}

double HydrogenGenerator::eval(vec3 cartesian) {
    // TASK 2: Evaluate wave function
    const double PI = 2 * glm::acos(0.0);
    double z = 1.0;
    double a0 = 1.0;
    vec3 sph = cartesianToSpherical(cartesian);

    double eq1 = 1.0 / (81 * glm::sqrt(6 * PI)); // yellow
    double eq2 = glm::pow(z / a0, 3 / 2); // red
    double eq3 = (glm::pow(z, 2) * glm::pow(sph.x, 2)) / glm::pow(a0, 2); // blue
    double eq4 = glm::exp(-z*sph.x/3*a0); // green
    double eq5 = 3 * glm::pow(glm::cos(sph.y), 2) - 1; // pink

    double eq = eq1 * eq2 * eq3 * eq4 * eq5;
    double density = glm::abs(glm::pow(eq, 2));

    return density;
}

vec3 HydrogenGenerator::idTOCartesian(size3_t pos) {
    vec3 p(pos);
    p /= size_ - 1;
    return p * (36.0f) - 18.0f;
}

}  // namespace inviwo
