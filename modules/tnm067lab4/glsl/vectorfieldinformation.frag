#include "utils/structs.glsl"

uniform sampler2D vfColor;
uniform ImageParameters vfParameters;
in vec3 texCoord_;

float passThrough(vec2 coord){
    return texture(vfColor,coord).x;
}

// equation 5
vec2 dvdx(vec2 coord, vec2 pixelSize){
    // v(x+pixelSize.x,y) = texture(vfColor, vec2(coord.x + pixelSize.x, coord.y)).xy
    return (texture(vfColor, vec2(coord.x + pixelSize.x, coord.y)).xy - texture(vfColor, vec2(coord.x - pixelSize.x, coord.y)).xy) / (2.0*pixelSize.x);
}

// equation 6
vec2 dvdy(vec2 coord, vec2 pixelSize){
    return (texture(vfColor, vec2(coord.x + pixelSize.y, coord.y)).xy - texture(vfColor, vec2(coord.x - pixelSize.y, coord.y)).xy) / (2.0*pixelSize.y);
}


float magnitude( vec2 coord ){
    //TASK 1: find the magnitude of the vectorfield at the position coords
    vec2 velo = texture(vfColor, coord.xy).xy; // vector field at position (x,y)
    float mag = sqrt(pow(velo.x, 2.0)+pow(velo.y, 2.0)); // equation 2
    return mag;
}
// How can vector magnitude be extended to 3D?
// Extend by one dimension and add z
// vec3 coord, vec3 velo .xyz, mag x^2 + y^2 + z^2

float divergence(vec2 coord){
    //TASK 2: find the divergence of the vectorfield at the position coords
    vec2 pixelSize = vfParameters.reciprocalDimensions;
    
    float div = dvdx(coord, pixelSize).x + dvdy(coord, pixelSize).y; // equation 3    
    return div;
}
// How can divergence be extended to 3D?
// vec3 pixelSize, Add dvdz in the same way as previous, add (+) dvdx to div

// Some parts of the image are black, why?
// We don't see any black parts

float rotation(vec2 coord){
    //TASK 3: find the curl of the vectorfield at the position coords
    vec2 pixelSize = vfParameters.reciprocalDimensions;
    float rot = dvdx(coord, pixelSize).y - dvdy(coord, pixelSize).x;   // equation 4 
    return rot;
}
// How can rotation be extended to 3D?
// Add z dimenson
// rot V(x,y,) = dvdx - dvdy - dvdz

// Some parts of the image are black, why?
// We don't see any black parts

void main(void) {
    float v = OUTPUT(texCoord_.xy);
    FragData0 = vec4(v);
}
