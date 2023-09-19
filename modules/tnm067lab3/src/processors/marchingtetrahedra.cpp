#include <inviwo/tnm067lab3/processors/marchingtetrahedra.h>
#include <inviwo/core/datastructures/geometry/basicmesh.h>
#include <inviwo/core/datastructures/volume/volumeram.h>
#include <inviwo/core/util/indexmapper.h>
#include <inviwo/core/util/assertion.h>
#include <inviwo/core/network/networklock.h>
#include <modules/tnm067lab1/utils/interpolationmethods.h>
#include <iostream>
#include <fstream>

namespace inviwo {

size_t MarchingTetrahedra::HashFunc::max = 1;

const ProcessorInfo MarchingTetrahedra::processorInfo_{
    "org.inviwo.MarchingTetrahedra",  // Class identifier
    "Marching Tetrahedra",            // Display name
    "TNM067",                         // Category
    CodeState::Stable,                // Code state
    Tags::None,                       // Tags
};
const ProcessorInfo MarchingTetrahedra::getProcessorInfo() const { return processorInfo_; }

MarchingTetrahedra::MarchingTetrahedra()
    : Processor()
    , volume_("volume")
    , mesh_("mesh")
    , isoValue_("isoValue", "ISO value", 0.5f, 0.0f, 1.0f) {

    addPort(volume_);
    addPort(mesh_);

    addProperty(isoValue_);

    isoValue_.setSerializationMode(PropertySerializationMode::All);

    volume_.onChange([&]() {
        if (!volume_.hasData()) {
            return;
        }
        NetworkLock lock(getNetwork());
        float iso = (isoValue_.get() - isoValue_.getMinValue()) /
                    (isoValue_.getMaxValue() - isoValue_.getMinValue());
        const auto vr = volume_.getData()->dataMap_.valueRange;
        isoValue_.setMinValue(static_cast<float>(vr.x));
        isoValue_.setMaxValue(static_cast<float>(vr.y));
        isoValue_.setIncrement(static_cast<float>(glm::abs(vr.y - vr.x) / 50.0));
        isoValue_.set(static_cast<float>(iso * (vr.y - vr.x) + vr.x));
        isoValue_.setCurrentStateAsDefault();
    });
}

// Function to calculate the linear interpolation between two points depending on the iso value
vec3 MarchingTetrahedra::interpolatePosition(const DataPoint& point1, const DataPoint& point2,
                                             float iso) {
    // Calculate the interpolation factor
    float t = (iso - point1.value) / (point2.value - point1.value);

    // Interpolated vec3
    return point1.pos + t * (point2.pos - point1.pos);
}

void MarchingTetrahedra::createTriangle(const Edge& e1, const Edge& e2, const Edge& e3, float iso,
                                        bool inverted, MarchingTetrahedra::MeshHelper& mesh) {

    auto v0 = mesh.addVertex(interpolatePosition(e1.start, e1.end, iso), e1.start.indexInVolume,
                             e1.end.indexInVolume);
    auto v1 = mesh.addVertex(interpolatePosition(e2.start, e2.end, iso), e2.start.indexInVolume,
                             e2.end.indexInVolume);
    auto v2 = mesh.addVertex(interpolatePosition(e3.start, e3.end, iso), e3.start.indexInVolume,
                             e3.end.indexInVolume);
    // Add triangle to mesh
    // Invert depending on case (normal direction)
    if (!inverted) {
        mesh.addTriangle(v0, v2, v1);
    } else {
        mesh.addTriangle(v0, v1, v2);
    }
}

void MarchingTetrahedra::process() {
    auto volume = volume_.getData()->getRepresentation<VolumeRAM>();
    MeshHelper mesh(volume_.getData());

    const auto& dims = volume->getDimensions();
    MarchingTetrahedra::HashFunc::max = dims.x * dims.y * dims.z;

    const float iso = isoValue_.get();

    util::IndexMapper3D mapVolPosToIndex(dims);

    const static size_t tetrahedraIds[6][4] = {{0, 1, 2, 5}, {1, 3, 2, 5}, {3, 2, 5, 7},
                                               {0, 2, 4, 5}, {6, 4, 2, 5}, {6, 7, 5, 2}};

    size3_t pos{};
    // Which grid, (all cells in a volume)
    for (pos.z = 0; pos.z < dims.z - 1; ++pos.z) {
        for (pos.y = 0; pos.y < dims.y - 1; ++pos.y) {
            for (pos.x = 0; pos.x < dims.x - 1; ++pos.x) {
                // The DataPoint index should be the 1D-index for the DataPoint in the cell
                // Use volume->getAsDouble to query values from the volume
                // Spatial position should be between 0 and 1

                // TODO: TASK 2: create a nested for loop to construct the cell
                Cell c;
                size_t cellVertex = 0;  // to keep track of which vertex

                //[0,0,0]
                //[0,0,1]
                //[0,1,0]
                //[1,0,0]
                //[1,1,1]
                //[1,1,0]
                //[0,1,1]
                //[1,0,1]

                // Loop for grid
                for (size_t z = 0; z <= 1; z++) {
                    for (size_t y = 0; y <= 1; y++) {
                        for (size_t x = 0; x <= 1; x++) {
                            vec3 localPos(x, y, z);
                            vec3 globalPos(x + pos.x, y + pos.y, z + pos.z);

                            vec3 scaledCellPos =
                                calculateDataPointPos(pos, localPos, dims);  // get scaled position

                            size_t indexInVolume =
                                mapVolPosToIndex(globalPos);  // get index for position

                            double value =
                                volume->getAsDouble(globalPos);

                            cellVertex = calculateDataPointIndexInCell(localPos);

                            c.dataPoints[cellVertex].pos = scaledCellPos;
                            c.dataPoints[cellVertex].value = value;
                            c.dataPoints[cellVertex].indexInVolume = indexInVolume; 

                        }
                    }
                }

                // TODO: TASK 3: Subdivide cell into 6 tetrahedra (hint: use tetrahedraIds)
                std::vector<Tetrahedra> tetrahedras;

                // Loop through each vertex, in each direction (?)
                for (size_t i = 0; i < 6; i++) {
                    Tetrahedra newTetra{};
                    // Every corner in tetraheder
                    for (size_t j = 0; j < 4; j++) {

                        newTetra.dataPoints[j] = c.dataPoints[tetrahedraIds[i][j]];
                    }
                    tetrahedras.push_back(newTetra);
                } 

                for (const Tetrahedra& tetrahedra : tetrahedras) {
                    // TODO: TASK 4: Calculate case id for each tetrahedra, and add triangles for
                    // each case (use MeshHelper)

                    // Calculate for tetra case index
                    int caseId = 0;

                    for (size_t point = 0; point < 4; ++point) {
                        if (tetrahedra.dataPoints[point].value < iso) {
                            // 2 raised to 4 opportunities
                            caseId += (int)glm::pow(2.0, (double)point);
                        }
                    }

                    // Four vertices in tetrahedra
                    DataPoint d0 = tetrahedra.dataPoints[0];
                    DataPoint d1 = tetrahedra.dataPoints[1];
                    DataPoint d2 = tetrahedra.dataPoints[2];
                    DataPoint d3 = tetrahedra.dataPoints[3];

                    // Extract triangles
                    switch (caseId) {
                        case 0:
                        case 15:
                            break;

                        //OK
                         case 1:
                        case 14: {
                            createTriangle(Edge{d0, d1}, Edge{d0, d3}, Edge{d0, d2}, iso,
                                           caseId == 14, mesh);
                            break;
                        }
                        
                        // OK
                        case 2:
                        case 13: {
                            createTriangle(Edge{d1, d0}, Edge{d1, d2}, Edge{d1, d3}, iso,
                                           caseId == 13, mesh);
                            break;
                        }

                        // OK
                        case 3:
                        case 12: {
                            createTriangle(Edge{d1, d2}, Edge{d1, d3}, Edge{d0, d3}, iso,
                                           caseId == 12, mesh);
                            createTriangle(Edge{d1, d2}, Edge{d0, d3}, Edge{d0, d2}, iso,
                                           caseId == 12, mesh);
                            break;
                        }
                        
                        //OK
                        case 4:
                        case 11: {
                            createTriangle(Edge{d2, d0}, Edge{d2, d3}, Edge{d2, d1}, iso,
                                           caseId == 11, mesh);
                            break;
                        }


                        //OK
                        case 5:
                        case 10: {
                            createTriangle(Edge{d0, d1}, Edge{d0, d3}, Edge{d2, d1}, iso,
                                           caseId == 10, mesh);
                            createTriangle(Edge{d2, d3}, Edge{d2, d1}, Edge{d0, d3}, iso,
                                           caseId == 10, mesh);
                            break;
                        }

                        case 6:
                        case 9: {
                            createTriangle(Edge{d1, d0}, Edge{d2, d0}, Edge{d1, d3}, iso,
                                           caseId == 9, mesh);
                            createTriangle(Edge{d1, d3}, Edge{d2, d3}, Edge{d2, d0}, iso,
                                           caseId == 9, mesh);
                            break;
                        }

                        case 7:
                        case 8: {
                            createTriangle(Edge{d3, d1}, Edge{d3, d0}, Edge{d3, d2}, iso,
                                           caseId == 8, mesh);
                            break;
                        }
                    }
                }
            }
        }
    }

    mesh_.setData(mesh.toBasicMesh());
}

int MarchingTetrahedra::calculateDataPointIndexInCell(ivec3 index3D) {
    // TODO: TASK 1: map 3D index to 1D
    return 1 * index3D.x + 2 * index3D.y + 4 * index3D.z;  // Why 1,2,4 --> 2^0, 2^1, 2^2
}

vec3 MarchingTetrahedra::calculateDataPointPos(size3_t posVolume, ivec3 posCell, ivec3 dims) {
    // TODO: TASK 1: scale DataPoint position with dimensions to be between 0 and 1
    float x = (float(posVolume[0] + posCell[0])) / float(dims[0] - 1);
    float y = (float(posVolume[1] + posCell[1])) / float(dims[1] - 1);
    float z = (float(posVolume[2] + posCell[2])) / float(dims[2] - 1);

    // dims = number of vertices in each dimension, Why -1?
    // X o o o o o o o o o o o o o

    return vec3(x, y, z);
}

MarchingTetrahedra::MeshHelper::MeshHelper(std::shared_ptr<const Volume> vol)
    : edgeToVertex_()
    , vertices_()
    , mesh_(std::make_shared<BasicMesh>())
    , indexBuffer_(mesh_->addIndexBuffer(DrawType::Triangles, ConnectivityType::None)) {
    mesh_->setModelMatrix(vol->getModelMatrix());
    mesh_->setWorldMatrix(vol->getWorldMatrix());
}

void MarchingTetrahedra::MeshHelper::addTriangle(size_t i0, size_t i1, size_t i2) {
    IVW_ASSERT(i0 != i1, "i0 and i1 should not be the same value");
    IVW_ASSERT(i0 != i2, "i0 and i2 should not be the same value");
    IVW_ASSERT(i1 != i2, "i1 and i2 should not be the same value");

    indexBuffer_->add(static_cast<glm::uint32_t>(i0));
    indexBuffer_->add(static_cast<glm::uint32_t>(i1));
    indexBuffer_->add(static_cast<glm::uint32_t>(i2));

    const auto a = std::get<0>(vertices_[i0]);
    const auto b = std::get<0>(vertices_[i1]);
    const auto c = std::get<0>(vertices_[i2]);

    const vec3 n = glm::normalize(glm::cross(b - a, c - a));
    std::get<1>(vertices_[i0]) += n;
    std::get<1>(vertices_[i1]) += n;
    std::get<1>(vertices_[i2]) += n;
}

std::shared_ptr<BasicMesh> MarchingTetrahedra::MeshHelper::toBasicMesh() {
    for (auto& vertex : vertices_) {
        // Normalize the normal of the vertex
        std::get<1>(vertex) = glm::normalize(std::get<1>(vertex));
    }
    mesh_->addVertices(vertices_);
    return mesh_;
}

std::uint32_t MarchingTetrahedra::MeshHelper::addVertex(vec3 pos, size_t i, size_t j) {
    IVW_ASSERT(i != j, "i and j should not be the same value");
    if (j < i) std::swap(i, j);

    auto [edgeIt, inserted] = edgeToVertex_.try_emplace(std::make_pair(i, j), vertices_.size());
    if (inserted) {
        vertices_.push_back({pos, vec3(0, 0, 0), pos, vec4(0.7f, 0.7f, 0.7f, 1.0f)});
    }
    return static_cast<std::uint32_t>(edgeIt->second);
}

}  // namespace inviwo
