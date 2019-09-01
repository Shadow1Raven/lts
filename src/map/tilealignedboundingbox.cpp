
#include <lts/map/tilealignedboundingbox.hpp>

namespace lts
{
	namespace map
	{
		TileAlignedBoundingBox::TileAlignedBoundingBox()
		{
			this->tileAlignedBox = TileAlignedBox(0, 0, 0, 0);
			this->lowY = 0;
			this->highY = 0;
		}

		TileAlignedBoundingBox::TileAlignedBoundingBox(TileAlignedBox tileAlignedBox, float lowY, float highY)
		{
			this->tileAlignedBox = tileAlignedBox;
			this->lowY = lowY;
			this->highY = highY;
		}

		TileAlignedBox TileAlignedBoundingBox::getTileAlignedBox()
		{
			return this->tileAlignedBox;
		}

		float TileAlignedBoundingBox::getLowY()
		{
			return this->lowY;
		}

		float TileAlignedBoundingBox::getHighY()
		{
			return this->highY;
		}

		bool TileAlignedBoundingBox::collides(TileAlignedBoundingBox &other)
		{
			if (this->tileAlignedBox.isRectCollided(other.tileAlignedBox))
				return true;

			if ((this->highY < other.lowY) || (this->lowY > other.highY))
				return true;

			return false;
		}
	}
}
