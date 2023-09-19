#pragma once

#include <modules/tnm067lab1/tnm067lab1moduledefine.h>

#include <vector>
#include <inviwo/core/util/glmvec.h>

// Change this to one to enable the Unit tests for ScalarToColorMapping
#define ENABLE_COLORMAPPING_UNITTEST 0

namespace inviwo {

/**
 * \class ScalarToColorMapping
 * \brief Scalar to color mapping
 * Colors are interpolated from the baseColors_.
 */
class IVW_MODULE_TNM067LAB1_API ScalarToColorMapping {
public:
    ScalarToColorMapping() = default;
    void addBaseColors(vec4 color);
    void clearColors();
    vec4 sample(float t) const;

private:
    std::vector<vec4> baseColors_;  // base colors to be interpolated
};

}  // namespace inviwo
