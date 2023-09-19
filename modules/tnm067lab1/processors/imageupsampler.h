#pragma once

#include <modules/tnm067lab1/tnm067lab1moduledefine.h>
#include <inviwo/core/processors/processor.h>
#include <inviwo/core/properties/ordinalproperty.h>
#include <inviwo/core/ports/imageport.h>
#include <modules/tnm067lab1/utils/scalartocolormapping.h>
#include <inviwo/core/properties/optionproperty.h>

namespace inviwo {

class IVW_MODULE_TNM067LAB1_API ImageUpsampler : public Processor {
public:
    enum class IntepolationMethod { PiecewiseConstant, Bilinear, Biquadratic, Barycentric };

    ImageUpsampler();
    virtual ~ImageUpsampler() = default;

    virtual void process() override;

    virtual const ProcessorInfo getProcessorInfo() const override;
    static const ProcessorInfo processorInfo_;

    static dvec2 convertCoordinate(ivec2 inputCoordinates, size2_t inputSize, size2_t outputSize);

private:
    ImageInport inport_;
    ImageOutport outport_;

    // Interpolation method
    OptionProperty<IntepolationMethod> interpolationMethod_;
};

}  // namespace inviwo
