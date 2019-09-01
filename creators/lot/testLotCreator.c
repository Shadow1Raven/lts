
#include <stdlib.h>
#include <inttypes.h>
#include <stdio.h>

uint32_t version = 1;
uint8_t xLength = 10;
uint8_t zLength = 10;

uint8_t storeys[256] = { 0 };

uint8_t s_xLength = 10;
uint8_t s_zLength = 10;
uint8_t s_changeable[10][10] = {};

uint32_t s_objectCount = 1;
uint16_t objectIdentifierLength = 23;
const char s_objectIdentifier[23] = "lts::core::shelf_cheap";
uint8_t s_tileBoundingBox[4] = { 2, 2, 2, 1 };
float s_yLocationAndHeight[2] = { 0.0f, 0.9f };

int main(void)
{
	storeys[128] = 1;

	for (int i = 0; i < 128; i++)
	{
		int x = rand() % s_xLength;
		int y = rand() % s_zLength;
		uint8_t val = (uint8_t) (rand() % 2);

		s_changeable[x][y] = val;
	}

	FILE *lotFile = fopen("test/core.lot", "w");
	fwrite(&version, sizeof(uint32_t), 1, lotFile);
	fwrite(&xLength, sizeof(uint8_t), 1, lotFile);
	fwrite(&zLength, sizeof(uint8_t), 1, lotFile);
	fwrite(storeys, sizeof(uint8_t), 256, lotFile);
	fclose(lotFile);

	char buf[16] = "test/";
	FILE *storeyFile;
	size_t writtenBytes = 0;
	for (int i = 0; i < 256; i++)
	{
		if (storeys[i] != 0)
		{
			snprintf(buf + 5, 8, "%d", i);
			storeyFile = fopen(buf, "w");

			writtenBytes += fwrite(&s_xLength, sizeof(uint8_t), 1, storeyFile);
			writtenBytes += fwrite(&s_zLength, sizeof(uint8_t), 1, storeyFile);
			for (uint8_t x = 0; x < s_xLength; x++)
			{
				writtenBytes += fwrite(&s_changeable[x], sizeof(uint8_t), s_zLength, storeyFile);
			}
			writtenBytes += fwrite(&s_objectCount, sizeof(uint32_t), 1, storeyFile);
			writtenBytes += fwrite(&objectIdentifierLength, sizeof(uint16_t), 1, storeyFile);
			writtenBytes += fwrite(s_objectIdentifier, sizeof(const char), 23, storeyFile);
			writtenBytes += fwrite(s_tileBoundingBox, sizeof(uint8_t), 4, storeyFile);
			writtenBytes += fwrite(s_yLocationAndHeight, sizeof(float), 2, storeyFile);
			fclose(storeyFile);
		}
	}

	return 0;
}

