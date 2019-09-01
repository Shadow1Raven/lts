#ifndef LTS_ALIASES_HPP
#define LTS_ALIASES_HPP

#include <string>
#include <cstdint>
#include <irrlicht/vector2d.h>
#include <irrlicht/rect.h>

using ObjectIdentifier = std::string;
using TileAlignedBox = irr::core::rect<uint8_t>;
using TileAlignedLocation = irr::core::vector2d<uint8_t>;
using Dimension = irr::core::rect<uint8_t>;

#endif
