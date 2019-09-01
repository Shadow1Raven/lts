
#include <lts/map/storey.hpp>

namespace lts
{
	namespace map
	{
		Storey::Storey(uint32_t xLength, uint32_t zLength)
		{
			this->extent = Dimension(0, 0, xLength, zLength);
			this->changeable = new ChangeabilityMap(xLength, zLength);
		}

		Storey::Storey(irr::io::IReadFile &dataStream)
		{
			uint8_t xLength;
			uint8_t zLength;
			uint32_t objectCount;

			dataStream.read(&xLength, sizeof(uint8_t));
			dataStream.read(&zLength, sizeof(uint8_t));
			this->extent = Dimension(0, 0, xLength, zLength);
			this->changeable = new ChangeabilityMap(xLength, zLength, dataStream);

			dataStream.read(&objectCount, sizeof(uint32_t));
			ObjectLocation *objectLocation;
			for (uint32_t i = 0; i < objectCount; i++)
			{
				objectLocation = new ObjectLocation(dataStream);
				this->objects.push_back(*objectLocation);
			}
		}

		ChangeabilityMap & Storey::getChangeabilityMap()
		{
			return *(this->changeable);
		}

		Dimension Storey::getExtent()
		{
			return this->extent;
		}

		bool Storey::canPlace(ObjectLocation &location)
		{
			if (!withinStoreyBounds(location))
				return false;

			if (!allTilesChangeable(location))
				return false;

			if (!noIntersectingObject(location))
				return false;

			return true;
		}

		bool Storey::place(ObjectLocation &location)
		{
			if (!canPlace(location))
				return false;

			this->objects.push_back(location);
		}

		std::vector<ObjectLocation>::const_iterator Storey::objectIterator()
		{
			return this->objects.cbegin();
		}

		std::vector<ObjectLocation>::const_iterator Storey::constEnd()
		{
			return this->objects.cend();
		}

		bool Storey::withinStoreyBounds(ObjectLocation &location)
		{
			TileAlignedBox storeyBox = this->extent;
			TileAlignedBox objectBox = location.getTileAlignedBoundingBox().getTileAlignedBox();
			return storeyBox.isPointInside(objectBox.LowerRightCorner) && storeyBox.isPointInside(objectBox.UpperLeftCorner);
		}

		bool Storey::allTilesChangeable(ObjectLocation &location)
		{
			TileAlignedBox objectBox = location.getTileAlignedBoundingBox().getTileAlignedBox();


			for (uint32_t x = objectBox.UpperLeftCorner.X; x <= objectBox.LowerRightCorner.X; x++)
			{
				for (uint32_t y = objectBox.UpperLeftCorner.Y; y <= objectBox.LowerRightCorner.Y; y++)
				{
					if (!changeable->isChangeable(x, y))
						return false;
				}
			}

			return true;
		}

		bool Storey::noIntersectingObject(ObjectLocation &location)
		{
			for (ObjectLocation &otherObject : this->objects)
			{
				if (otherObject.intersect(location))
					return false;
			}

			return true;
		}
	}
}
