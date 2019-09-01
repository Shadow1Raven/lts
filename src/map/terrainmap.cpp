
#include <lts/map/terrainmap.hpp>

namespace lts
{
	namespace map
	{
		TerrainMap::TerrainMap(irr::io::IReadFile &dataStream)
		{
			uint8_t xLength;
			uint8_t zLength;
			dataStream.read(&xLength, sizeof(uint8_t));
			dataStream.read(&zLength, sizeof(uint8_t));
			this->extent = Dimension(0, 0, xLength, zLength);

			this->terrainHeights = new int8_t*[xLength]();
			for (uint16_t x = 0; x < xLength; x++)
			{
				this->terrainHeights[x] = new int8_t[zLength]();
			}

			int8_t height;
			for (uint8_t x = 0; x < xLength; x++)
			{
				for (uint8_t z = 0; z < zLength; z++)
				{
					dataStream.read(&height, sizeof(int8_t));
					this->terrainHeights[x][z] = height;
				}
			}
		}

		Dimension TerrainMap::getExtent()
		{
			return this->extent;
		}

		int8_t TerrainMap::getTerrainHeight(uint8_t x, uint8_t z)
		{
			return this->terrainHeights[x][z];
		}
	}
}
