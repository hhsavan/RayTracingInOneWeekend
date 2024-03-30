#ifndef __COLOR_H__
#define __COLOR_H__

#include "vec3.h"

#include <iostream>

using color = Vector3f::Vec3f;

void write_color(std::ostream &out, color pixeelColor) {
    // Write the translated [0,255] value of each color component.
    out << static_cast<int>(255.999 * pixeelColor.x) << ' '
        << static_cast<int>(255.999 * pixeelColor.y) << ' '
        << static_cast<int>(255.999 * pixeelColor.z) << '\n';
}

#endif