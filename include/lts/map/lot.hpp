#ifndef LTS_LOT_HPP
#define LTS_LOT_HPP

#include <array>
#include <irrlicht/IFileArchive.h>

#include "storey.hpp"
#include "terrainmap.hpp"

namespace lts
{
	namespace map
	{
		class Lot
		{
			private:
			Dimension extent;
			std::array<Storey *, 256> storeys;
			TerrainMap *terrainMap;

			public:
			Lot(uint32_t xLength, uint32_t zLength);
			Lot(irr::io::IFileArchive &archive);
			Dimension getExtent();
			TerrainMap * getTerrainMap();
			Storey * getStorey(int8_t level);
		};
	}
}

#endif
