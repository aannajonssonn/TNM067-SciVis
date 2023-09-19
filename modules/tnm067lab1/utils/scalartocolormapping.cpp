#include <modules/tnm067lab1/utils/scalartocolormapping.h>

namespace inviwo {

void ScalarToColorMapping::clearColors() { baseColors_.clear(); }
void ScalarToColorMapping::addBaseColors(vec4 color) { baseColors_.push_back(color); }

vec4 ScalarToColorMapping::sample(float t) const {
    if (baseColors_.size() == 0) return vec4(t);
    if (baseColors_.size() == 1) return vec4(baseColors_[0]);
    if (t <= 0) return vec4(baseColors_.front());
    if (t >= 1) return vec4(baseColors_.back());

    // Get t according to size of baseColors
    t = t * (baseColors_.size() - 1);

    int colorIndex = floor(t);  // Get index by flooring

    // Adjust scale factor to be in between the points colorIndex and colorIndex + 1
    t -= colorIndex;

    // Interpolate
    vec4 finalColor = (1 - t) * baseColors_[colorIndex] + t * baseColors_[colorIndex + 1];

    return finalColor;
}

}  // namespace inviwo
