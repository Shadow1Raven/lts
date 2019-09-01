#ifndef LTS_CHANGEABILITYMAP_HPP
#define LTS_CHANGEABILITYMAP_HPP

#include <cstdint>
#include <irrlicht/IReadFile.h>

#include <lts/aliases.hpp>

namespace lts
{
	namespace map
	{
		class ChangeabilityMap
		{
			friend class Storey;

			private:
			Dimension extent;
			bool **changeable;
			ChangeabilityMap(uint8_t xLength, uint8_t zLength, irr::io::IReadFile &dataStream);

			public:
			ChangeabilityMap(uint8_t xLength, uint8_t zLength);
			bool isChangeable(uint8_t x, uint8_t z);
			void setChangeable(uint8_t x, uint8_t z, bool changeable = true);
		};
	}
}

#endif
