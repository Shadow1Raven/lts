
#include <lts/map/changeabilitymap.hpp>

namespace lts
{
	namespace map
	{
		ChangeabilityMap::ChangeabilityMap(uint8_t xLength, uint8_t zLength)
		{
			this->extent = Dimension(0, 0, xLength, zLength);
			this->changeable = new bool*[xLength]();
			for (uint8_t i = 0; i < xLength; i++)
			{
				this->changeable[i] = new bool[zLength]();
			}
		}

		ChangeabilityMap::ChangeabilityMap(uint8_t xLength, uint8_t zLength, irr::io::IReadFile &dataStream) : ChangeabilityMap(xLength, zLength)
		{
			uint8_t changeable;
			for (uint8_t x = 0; x < xLength; x++)
			{
				for (uint8_t z = 0; z < zLength; z++)
				{
					dataStream.read(&changeable, sizeof(uint8_t));
					this->changeable[x][z] = changeable;
				}
			}
		}

		bool ChangeabilityMap::isChangeable(uint8_t x, uint8_t z)
		{
			return this->changeable[x][z];
		}

		void ChangeabilityMap::setChangeable(uint8_t x, uint8_t z, bool changeable)
		{
			this->changeable[x][z] = changeable;
		}
	}
}
