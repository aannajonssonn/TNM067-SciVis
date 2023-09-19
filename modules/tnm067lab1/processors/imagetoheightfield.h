#pragma once

#include <modules/tnm067lab1/tnm067lab1moduledefine.h>
#include <inviwo/core/processors/processor.h>
#include <inviwo/core/properties/ordinalproperty.h>
#include <inviwo/core/ports/imageport.h>
#include <inviwo/core/ports/meshport.h>
#include <modules/base/properties/gaussianproperty.h>
#include <modules/tnm067lab1/utils/scalartocolormapping.h>
#include <inviwo/core/datastructures/geometry/basicmesh.h>

namespace inviwo {

class IVW_MODULE_TNM067LAB1_API ImageToHeightfield : public Processor {
public:
    ImageToHeightfield();
    virtual ~ImageToHeightfield() = default;

    virtual void process() override;

    virtual const ProcessorInfo getProcessorInfo() const override;
    static const ProcessorInfo processorInfo_;

private:
    ImageInport imageInport_;
    MeshOutport meshOutport_;
    FloatProperty heightScaleFactor_;

    IntSizeTProperty numColors_;
    std::array<FloatVec4Property, 10> colors_;

};

}  // namespace inviwo
