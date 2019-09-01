#ifndef TLS_TERRAINMAP_HPP
#define TLS_TERRAINMAP_HPP

#include <cstdint>
#include <irrlicht/IReadFile.h>

#include <lts/aliases.hpp>

namespace lts
{
	namespace map
	{
		class TerrainMap
		{
			friend class Lot;

			private:
			Dimension extent;
			int8_t **terrainHeights;
			TerrainMap(irr::io::IReadFile &dataStream);

			public:
			Dimension getExtent();
			int8_t getTerrainHeight(uint8_t x, uint8_t z);
		};
	}
}

#endif
