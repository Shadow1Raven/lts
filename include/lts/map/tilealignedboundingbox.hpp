#ifndef TLS_TILEALIGENDBOUNDINGBOX_HPP
#define TLS_TILEALIGENDBOUNDINGBOX_HPP

#include <lts/aliases.hpp>

namespace lts
{
	namespace map
	{
		class TileAlignedBoundingBox
		{
			private:
			TileAlignedBox tileAlignedBox;
			float lowY;
			float highY;

			public:
			TileAlignedBoundingBox();
			TileAlignedBoundingBox(TileAlignedBox tileAlignedBox, float lowY, float highY);
			TileAlignedBox getTileAlignedBox();
			float getLowY();
			float getHighY();

			bool collides(TileAlignedBoundingBox &other);
		};
	}
}

#endif
