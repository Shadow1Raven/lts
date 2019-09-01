
#include <lts/map/objectlocation.hpp>

namespace lts
{
	namespace map
	{
		ObjectLocation::ObjectLocation(ObjectIdentifier objectIdentifier, TileAlignedBoundingBox tileAlignedBoundingBox)
		{
			this->objectIdentifier = objectIdentifier;
			this->tileAlignedBoundingBox = tileAlignedBoundingBox;
		}

		ObjectLocation::ObjectLocation(irr::io::IReadFile &dataStream)
		{
			uint16_t objectIdentifierLengthShort;
			char *objectIdentifierCstring;
			uint8_t tileBoundingBoxArray[4];
			float lowYhighY[2];

			dataStream.read(&objectIdentifierLengthShort, sizeof(uint16_t));

			uint32_t objectIdentifierLength = objectIdentifierLengthShort;
			objectIdentifierCstring = new char[objectIdentifierLength + 1]();
			dataStream.read(objectIdentifierCstring, objectIdentifierLength);

			dataStream.read(tileBoundingBoxArray, sizeof(uint8_t) * 4);
			dataStream.read(lowYhighY, sizeof(float) * 2);

			this->objectIdentifier = objectIdentifierCstring;
			TileAlignedBox tileAlignedBox(tileBoundingBoxArray[0], tileBoundingBoxArray[1], tileBoundingBoxArray[2], tileBoundingBoxArray[3]);
			this->tileAlignedBoundingBox = TileAlignedBoundingBox(tileAlignedBox, lowYhighY[0], lowYhighY[1]);
		}

		const ObjectIdentifier & ObjectLocation::getObjectIdentifier() const
		{
			return this->objectIdentifier;
		}

		TileAlignedBoundingBox ObjectLocation::getTileAlignedBoundingBox() const
		{
			return this->tileAlignedBoundingBox;
		}

		bool ObjectLocation::intersect(ObjectLocation &other)
		{
			return this->tileAlignedBoundingBox.collides(other.tileAlignedBoundingBox);
		}
	}
}
