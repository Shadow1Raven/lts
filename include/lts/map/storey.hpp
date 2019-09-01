#ifndef LTS_STOREY_HPP
#define LTS_STOREY_HPP

#include <string>
#include <vector>
#include <irrlicht/IReadFile.h>

#include "changeabilitymap.hpp"
#include "objectlocation.hpp"

namespace lts
{
	namespace map
	{
		class Storey
		{
			friend class Lot;

			private:
			Dimension extent;
			ChangeabilityMap *changeable;
			std::vector<ObjectLocation> objects;

			bool withinStoreyBounds(ObjectLocation &location);
			bool allTilesChangeable(ObjectLocation &location);
			bool noIntersectingObject(ObjectLocation &location);

			Storey(irr::io::IReadFile &dataStream);

			public:
			Storey(uint32_t xLength, uint32_t zLength);
			ChangeabilityMap & getChangeabilityMap();
			Dimension getExtent();
			bool canPlace(ObjectLocation &location);
			bool place(ObjectLocation &location);
			std::vector<ObjectLocation>::const_iterator objectIterator();
			std::vector<ObjectLocation>::const_iterator constEnd();
		};
	}
}

#endif
