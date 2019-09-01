
#include <lts/map/lot.hpp>

namespace lts
{
	namespace map
	{
		Lot::Lot(uint32_t xLength, uint32_t zLength)
		{
			this->extent = Dimension(0, 0, xLength, zLength);

			Storey *storey = new Storey(xLength, zLength);
			for (uint16_t i = 0; i < 256; i++)
			{
				this->storeys[i] = nullptr;
			}

			this->storeys[127] = storey;
		}

		Lot::Lot(irr::io::IFileArchive &archive)
		{
			irr::io::IReadFile *coreFile = archive.createAndOpenFile(u8"core.lot");
			irr::io::IReadFile *terrainFile = archive.createAndOpenFile(u8"testfile.ter");

			this->terrainMap = new TerrainMap(*terrainFile);

			uint32_t version;
			uint8_t xLength;
			uint8_t zLength;
			uint8_t storeys[256] { 0 };
			coreFile->read(&version, sizeof(uint32_t));
			coreFile->read(&xLength, sizeof(uint8_t));
			coreFile->read(&zLength, sizeof(uint8_t));
			this->extent = Dimension(0, 0, xLength, zLength);

			coreFile->read(storeys, sizeof(uint8_t) * 256);
			for (size_t i = 0; i < 256; i++)
			{
				if (storeys[i] == 1)
				{
					std::string nameString = std::to_string(i);
					irr::io::IReadFile *storeyReadFile = archive.createAndOpenFile(nameString.c_str());

					Storey *storey = new Storey(*storeyReadFile);
					this->storeys[i] = storey;

					storeyReadFile->drop();
				}
				else
				{
					this->storeys[i] = nullptr;
				}
			}

			coreFile->drop();
			terrainFile->drop();
		}

		Dimension Lot::getExtent()
		{
			return this->extent;
		}

		TerrainMap * Lot::getTerrainMap()
		{
			return this->terrainMap;
		}

		// The ground storey is level 128, so we need a bias to correct for that.
		Storey * Lot::getStorey(int8_t level)
		{
			return this->storeys[((size_t) level) + 128];
		}
	}
}
