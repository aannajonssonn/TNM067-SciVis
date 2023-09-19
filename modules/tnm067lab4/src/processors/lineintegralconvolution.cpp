#include <inviwo/tnm067lab4/processors/lineintegralconvolution.h>
#include <modules/opengl/texture/textureunit.h>
#include <modules/opengl/texture/textureutils.h>
#include <modules/opengl/image/imagegl.h>
#include <modules/opengl/shader/shaderutils.h>

namespace inviwo {

// The Class Identifier has to be globally unique. Use a reverse DNS naming scheme
const ProcessorInfo LineIntegralConvolution::processorInfo_{
    "org.inviwo.LineIntegralConvolution",  // Class identifier
    "Line Integral Convolution",           // Display name
    "Vector Field Visualization",          // Category
    CodeState::Stable,                     // Code state
    Tags::GL,                              // Tags
};
const ProcessorInfo LineIntegralConvolution::getProcessorInfo() const { return processorInfo_; }

LineIntegralConvolution::LineIntegralConvolution()
    : Processor()
    , vf_("vf")
    , noise_("noise")
    , outport_("outport")

    , steps_("nSteps", "Steps", 20, 3, 100)
    , stepSize_("stepSize", "stepSize", 0.003f, 0.0001f, 0.01f, 0.0001f)

    , shader_("lineintegralconvolution.vert", "lineintegralconvolution.frag") {

    addPort(vf_);
    addPort(noise_);
    addPort(outport_);
    addProperty(steps_);
    addProperty(stepSize_);

    shader_.onReload([this]() { invalidate(InvalidationLevel::InvalidOutput); });
}

void LineIntegralConvolution::process() {
    utilgl::activateAndClearTarget(outport_);

    shader_.activate();
    TextureUnitContainer units;
    utilgl::bindAndSetUniforms(shader_, units, vf_, ImageType::ColorOnly);
    utilgl::bindAndSetUniforms(shader_, units, noise_, ImageType::ColorOnly);

    utilgl::setUniforms(shader_, outport_, steps_, stepSize_);

    utilgl::singleDrawImagePlaneRect();
    shader_.deactivate();
    utilgl::deactivateCurrentTarget();
}

}  // namespace inviwo
