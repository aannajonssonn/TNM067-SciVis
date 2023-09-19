#pragma once

#include <modules/tnm067lab1/tnm067lab1moduledefine.h>
#include <inviwo/core/processors/processor.h>
#include <inviwo/core/properties/ordinalproperty.h>
#include <inviwo/core/ports/imageport.h>

namespace inviwo {

class IVW_MODULE_TNM067LAB1_API ImageMappingCPU : public Processor {
public:
    ImageMappingCPU();
    virtual ~ImageMappingCPU() = default;

    virtual void process() override;

    virtual const ProcessorInfo getProcessorInfo() const override;
    static const ProcessorInfo processorInfo_;

private:
    ImageInport inport_;
    ImageOutport outport_;

    IntSizeTProperty numColors_;
    std::array<FloatVec4Property, 10> colors_;
};

}  // namespace inviwo
