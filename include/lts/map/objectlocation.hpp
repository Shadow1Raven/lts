#ifndef LTS_OBJECTLOCATION_HPP
#define LTS_OBJECTLOCATION_HPP

#include <irrlicht/IReadFile.h>

#include <lts/aliases.hpp>
#include "tilealignedboundingbox.hpp"

namespace lts
{
	namespace map
	{
		class ObjectLocation
		{
			friend class Storey;

			private:
			ObjectIdentifier objectIdentifier;
			TileAlignedBoundingBox tileAlignedBoundingBox;

			ObjectLocation(irr::io::IReadFile &dataStream);

			public:
			ObjectLocation(ObjectIdentifier objectIdentifier, TileAlignedBoundingBox tileAlignedBoundingBox);
			TileAlignedBoundingBox getTileAlignedBoundingBox() const;
			const ObjectIdentifier & getObjectIdentifier() const;

			bool intersect(ObjectLocation &other);
		};
	}
}

#endif
