
#include <stdio.h>

const unsigned char xLength = 11;
const unsigned char zLength = 11;
const signed char terrain[11][11] = {
	{
	//  1   2   3   4   5   6   7   8   9   +
		+0, +1, +2, +1, -1, -1, -1, +0, +0, +0, +0
	},
	{
	//  1   2   3   4   5   6   7   8   9   +
		+0, +1, +2, +1, -1, -1, -1, +0, +0, +0, +0
	},
	{
	//  1   2   3   4   5   6   7   8   9   +
		+0, +1, +2, +1, -1, -1, -1, +0, +0, +0, +0
	},
	{
	//  1   2   3   4   5   6   7   8   9   +
		+0, +1, +2, +1, -1, -1, -1, +1, +0, +0, +0
	},
	{
	//  1   2   3   4   5   6   7   8   9   +
		+0, +1, +2, +1, -2, -1, -1, +0, +0, +0, +0
	},
	{
	//  1   2   3   4   5   6   7   8   9   +
		+0, +1, +2, +1, -1, -1, -1, +0, +0, +0, +0
	},
	{
	//  1   2   3   4   5   6   7   8   9   +
		+0, +1, +2, +1, -1, -1, -1, +0, +0, +0, +0
	},
	{
	//  1   2   3   4   5   6   7   8   9   +
		+0, +1, +2, +1, -1, -1, -1, +0, +0, +0, +0
	},
	{
	//  1   2   3   4   5   6   7   8   9   +
		+0, +1, +2, +1, -1, -1, -1, +0, +0, +1, +0
	},
};

int main(void)
{
	FILE *file = fopen("testfile.ter", "w");
	fwrite(&xLength, sizeof(unsigned char), 1, file);
	fwrite(&zLength, sizeof(unsigned char), 1, file);
	for (int i = 0; i < 11; i++)
	{
		fwrite(terrain[i], sizeof(signed char), 11, file);
	}
	fclose(file);
	return 0;
}

