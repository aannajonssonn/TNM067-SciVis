#pragma once

#include <inviwo/tnm067lab3/tnm067lab3moduledefine.h>
#include <inviwo/core/processors/processor.h>
#include <inviwo/core/properties/ordinalproperty.h>
#include <inviwo/core/ports/imageport.h>
#include <inviwo/core/ports/volumeport.h>
#include <inviwo/core/ports/meshport.h>
#include <inviwo/core/datastructures/geometry/basicmesh.h>

namespace inviwo {

class IVW_MODULE_TNM067LAB3_API MarchingTetrahedra : public Processor {
public:
    struct HashFunc {
        static size_t max;
        size_t operator()(std::pair<size_t, size_t> p) const {
            size_t asdf;
            asdf = p.first;
            asdf += p.second * max;
            return std::hash<size_t>{}(asdf);
        }
    };

    struct DataPoint {
        vec3 pos;
        float value;
        size_t indexInVolume;
    };

    struct Cell {
        DataPoint dataPoints[8];
    };

    struct Tetrahedra {
        DataPoint dataPoints[4];
    };

    // OUR: Edge in a tetrahedra
    struct Edge {
        DataPoint start;
        DataPoint end;

        Edge(DataPoint d0, DataPoint d1) {
            start = d0;
            end = d1;
        }
    };

    struct MeshHelper {

        MeshHelper(std::shared_ptr<const Volume> vol);

        /**
         * Adds a vertex to the mesh. The input parameters i and j are the DataPoint-indices of the
         * two DataPoints spanning the edge on which the vertex lies. The vertex will only be added
         * created if a vertex between the same indices has not been added before. Will return the
         * index of the created vertex or the vertex that was created for this edge before. The
         * DataPoint-index i and j can be given in any order.
         *
         * @param pos spatial position of the vertex
         * @param i DataPoint index of first DataPoint of the edge
         * @param j DataPoint index of second DataPoint of the edge
         */
        std::uint32_t addVertex(vec3 pos, size_t i, size_t j);
        void addTriangle(size_t i0, size_t i1, size_t i2);
        std::shared_ptr<BasicMesh> toBasicMesh();

    private:
        std::unordered_map<std::pair<size_t, size_t>, size_t, HashFunc> edgeToVertex_;
        std::vector<BasicMesh::Vertex> vertices_;
        std::shared_ptr<BasicMesh> mesh_;
        std::shared_ptr<IndexBufferRAM> indexBuffer_;
    };

    MarchingTetrahedra();
    virtual ~MarchingTetrahedra() = default;

// TODO: TASK 1: change 0 to 1 when functions are implemented
#define ENABLE_DATAPOINT_INDEX_TEST 1
    static int calculateDataPointIndexInCell(ivec3 index3D);

#define ENABLE_DATAPOINT_POS_TEST 1
    static vec3 calculateDataPointPos(size3_t posVolume, ivec3 posCell, ivec3 dims);

    virtual void process() override;

    virtual const ProcessorInfo getProcessorInfo() const override;
    static const ProcessorInfo processorInfo_;

private:
    VolumeInport volume_;
    MeshOutport mesh_;

    FloatProperty isoValue_;

    vec3 interpolatePosition(const DataPoint& from, const DataPoint& to, float iso);
    void createTriangle(const Edge& side0, const Edge& side1, const Edge& side2, float iso,
                        bool inverted, MeshHelper& mesh);

   // MeshHelper& mesh;
};

}  // namespace inviwo
