#pragma once

#include <modules/tnm067lab1/tnm067lab1moduledefine.h>
#include <inviwo/core/util/glm.h>


namespace inviwo {

template <typename T>
struct float_type {
    using type = double;
};

template <>
struct float_type<float> {
    using type = float;
};
template <>
struct float_type<vec3> {
    using type = float;
};
template <>
struct float_type<vec2> {
    using type = float;
};
template <>
struct float_type<vec4> {
    using type = float;
};

namespace TNM067 {
namespace Interpolation {

#define ENABLE_LINEAR_UNITTEST 1
template <typename T, typename F = double>
T linear(const T& a, const T& b, F x) {
    if (x <= 0) return a;
    if (x >= 1) return b;

    return  a*(1.0-x) + b*x;
}

// clang-format off
    /*
     2------3
     |      |
    y|  •   |
     |      |
     0------1
        x
    */
    // clang format on
#define ENABLE_BILINEAR_UNITTEST 1
template<typename T, typename F = double> 
T bilinear(const std::array<T, 4> &v, F x, F y) {

    T topRow = linear(v[2], v[3], x);
    T bottomRow = linear(v[0], v[1], x);

    T biInt = linear(bottomRow,topRow, y);
    return biInt;
}


    // clang-format off
    /* 
    a--•----b------c
    0  x    1      2
    */
// clang-format on
#define ENABLE_QUADRATIC_UNITTEST 1
template <typename T, typename F = double>
T quadratic(const T& a, const T& b, const T& c, F x) {
    // See lecture04_data_2 2023 slide 12 for equation
    T f = (1 - x) * (1 - 2 * x) * a + 4 * x * (1 - x) * b + x * (2 * x - 1) * c; 
    
    return f;
}

// clang-format off
    /* 
    6-------7-------8
    |       |       |
    |       |       |
    |       |       |
    3-------4-------5
    |       |       |
   y|  •    |       |
    |       |       |
    0-------1-------2
    0  x    1       2
    */
// clang-format on
#define ENABLE_BIQUADRATIC_UNITTEST 1
template <typename T, typename F = double>
T biQuadratic(const std::array<T, 9>& v, F x, F y) {
    T topRow = quadratic(v[6], v[7], v[8], x);
    T middleRow = quadratic(v[3], v[4], v[5], x);
    T bottomRow = quadratic(v[0], v[1], v[2], x);

    T biQuad = quadratic(bottomRow, middleRow, topRow, y);
    return biQuad;
}

// clang-format off
    /*
     2---------3
     |'-.      |
     |   -,    |
   y |  •  -,  |
     |       -,|
     0---------1
        x
    */
// clang-format on
#define ENABLE_BARYCENTRIC_UNITTEST 1
template <typename T, typename F = double>
T barycentric(const std::array<T, 4>& v, F x, F y) {

    // lecture 3 data 2, slide 20
    // alpha + beta + gamma = 1
    double alpha, beta, gamma;
    T f_a;
    T f_b = v[1];
    T f_c = v[2];

    if (x + y < 1.0) {
        alpha = 1 - (x + y);
        beta = x;
        gamma = y;
        f_a = v[0];
    } else {
        alpha = (x + y) - 1.0;
        beta = 1.0 - y;
        gamma = 1.0 - x;
        f_a = v[3];
    }

    T f = alpha * f_a + beta * f_b + gamma * f_c;

    return f;
}

}  // namespace Interpolation
}  // namespace TNM067
}  // namespace inviwo
