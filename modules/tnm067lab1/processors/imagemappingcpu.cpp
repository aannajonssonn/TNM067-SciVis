#include <modules/tnm067lab1/processors/imagemappingcpu.h>
#include <modules/tnm067lab1/utils/scalartocolormapping.h>
#include <inviwo/core/common/inviwoapplication.h>
#include <inviwo/core/datastructures/image/layerramprecision.h>
#include <inviwo/core/util/indexmapper.h>
#include <inviwo/core/util/imageramutils.h>


namespace inviwo {

// The Class Identifier has to be globally unique. Use a reverse DNS naming scheme
const ProcessorInfo ImageMappingCPU::processorInfo_{
    "org.inviwo.ImageMappingCPU",  // Class identifier
    "Image Mapping CPU",           // Display name
    "TNM067",                      // Category
    CodeState::Stable,             // Code state
    Tags::CPU,                     // Tags
};
const ProcessorInfo ImageMappingCPU::getProcessorInfo() const { return processorInfo_; }

ImageMappingCPU::ImageMappingCPU()
    : Processor()
    , inport_("inport", true)
    , outport_("outport", false)
    , numColors_("numColors", "Number of colors", 2, 1, 10)
    , colors_({FloatVec4Property{"color1", "Color 1", vec4(0, 0, 0, 1), vec4(0, 0, 0, 1), vec4(1)},
               FloatVec4Property{"color2", "Color 2", vec4(1), vec4(0, 0, 0, 1), vec4(1)},
               FloatVec4Property{"color3", "Color 3", vec4(1), vec4(0, 0, 0, 1), vec4(1)},
               FloatVec4Property{"color4", "Color 4", vec4(1), vec4(0, 0, 0, 1), vec4(1)},
               FloatVec4Property{"color5", "Color 5", vec4(1), vec4(0, 0, 0, 1), vec4(1)},
               FloatVec4Property{"color6", "Color 6", vec4(1), vec4(0, 0, 0, 1), vec4(1)},
               FloatVec4Property{"color7", "Color 7", vec4(1), vec4(0, 0, 0, 1), vec4(1)},
               FloatVec4Property{"color8", "Color 8", vec4(1), vec4(0, 0, 0, 1), vec4(1)},
               FloatVec4Property{"color9", "Color 9", vec4(1), vec4(0, 0, 0, 1), vec4(1)},
               FloatVec4Property{"color10", "Color 10", vec4(1), vec4(0, 0, 0, 1), vec4(1)}}) {

    addPort(inport_);
    addPort(outport_);

    addProperty(numColors_);
    for (auto& c : colors_) {
        c.setSemantics(PropertySemantics::Color);
        c.setCurrentStateAsDefault();
        addProperty(c);
    }

    auto colorVisibility = [&]() {
        for (size_t i = 0; i < 10; i++) {
            colors_[i].setVisible(i < numColors_);
        }
    };

    numColors_.onChange(colorVisibility);
    colorVisibility();
}

void ImageMappingCPU::process() {
    auto inImg = inport_.getData();
    auto img = std::make_shared<Image>(inImg->getDimensions(), DataVec4UInt8::get());
    auto outRep = static_cast<LayerRAMPrecision<glm::u8vec4>*>(
        img->getColorLayer()->getEditableRepresentation<LayerRAM>());
    glm::u8vec4* outPixels = outRep->getDataTyped();
    util::IndexMapper2D index(inImg->getDimensions());

    ScalarToColorMapping map;
    for (size_t i = 0; i < numColors_.get(); i++) {
        map.addBaseColors(colors_[i].get());
    }

    inImg->getColorLayer()->getRepresentation<LayerRAM>()->dispatch<void>([&](const auto inRep) {
        auto inPixels = inRep->getDataTyped();
        util::forEachPixelParallel(*inRep, [&](size2_t pos) {
            auto i = index(pos);
            float inPixelVal = util::glm_convert_normalized<float>(inPixels[i]);
            outPixels[i] = map.sample(inPixelVal) * 255.f;
        });
    });

    outport_.setData(img);
}

}  // namespace inviwo
