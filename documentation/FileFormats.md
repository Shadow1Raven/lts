
# File Formats

## Lot file format

A lot is merely a width, a depth and all its storeys.
Thus, this file format looks as follows:

| Data offset | Data type                        | Comment                                      |
|-------------|----------------------------------|----------------------------------------------|
| 0x00000000  | 32 bit unsigned integer          | A version number.                            |
| 0x00000004  | 8 bit unsigned integer           | The xLength.                                 |
| 0x00000005  | 8 bit unsigned integer           | The zLength.                                 |
| 0x00000006  | Array of unsigned 8 bit integers | xLength * zLength, a map of existing storeys |

## Ter file format

The terrain is only characterised by its relief.
The ter file stores height values (in decimeters of divergence from "zero height level")
of the vertices that make up the tiles of the map.

Note that this must not be smaller than the lot.
Indeed, xLength and zLength must both be at least one higher than their lot file counterparts.
They may be bigger, however.

| Data offset | Data type                        | Comment                                                   |
|-------------|----------------------------------|-----------------------------------------------------------|
| 0x00000000  | Unsigned 8 bit integer           | The xLength of the terrain map.                           |
| 0x00000001  | Unsigned 8 bit integer           | The zLength of the terrain map.                           |
| 0x00000002  | Array of signed 8 bit integers   | The actual height map; xLength * zLength.                 |

## Storey file format

Notably, the name of these files is equal to the storey they have in the house
with a bias of +128 (i.e. ground floor is called "128",
the first floor would be called "129" et cetera).

A storey file looks as follows:

| Data offset | Data type                        | Comment                                                   |
|-------------|----------------------------------|-----------------------------------------------------------|
| 0x00000000  | Unsigned 8 bit integer           | The xLength of the storey.                                |
| 0x00000001  | Unsigned 8 bit integer           | The zLength of the storey.                                |
| 0x00000002  | Array of unsigned 8 bit integers | The changeability map of the storey; xLength * zLength.   |
| 0x0000EFGH  | Unsigned 32 bit integer          | The object count in the storey.                           |
| 0xEFGH + 4  | Array of ObjectLocations.        | ObjectLocations in this storey. Amount: the number above. |

