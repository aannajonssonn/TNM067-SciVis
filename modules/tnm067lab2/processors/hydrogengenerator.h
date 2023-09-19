#pragma once

#include <modules/tnm067lab2/tnm067lab2moduledefine.h>
#include <inviwo/core/processors/processor.h>
#include <inviwo/core/properties/ordinalproperty.h>
#include <inviwo/core/ports/imageport.h>
#include <inviwo/core/ports/volumeport.h>

namespace inviwo {

class IVW_MODULE_TNM067LAB2_API HydrogenGenerator : public Processor {
public:
    HydrogenGenerator();
    virtual ~HydrogenGenerator() = default;

    virtual void process() override;

    virtual const ProcessorInfo getProcessorInfo() const override;
    static const ProcessorInfo processorInfo_;

    static vec3 cartesianToSpherical(vec3 cartesian);
    static double eval(vec3 cartesian);

    vec3 idTOCartesian(size3_t pos);

private:
    VolumeOutport volume_;

    IntSizeTProperty size_;
};

}  // namespace inviwo
