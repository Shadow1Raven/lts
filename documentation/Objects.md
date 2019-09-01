
# Objects

Generally, objects take up space.
Objects are measured in metric units,
with the unit length of one tile being 1 metre
(which means a tile creates 1 square metre of area to place objects on).

Because they use up space,
it has to be asserted that no object be within the space of another object.
Because of that,
an object has a bounding box approximating the boundaries of the object.
If looked at the object from above,
all geometry is contained within that bounding box.
Vertically, it begins at the bottom of an object (obviously).

# Storeys ("levels", "floors")

Storeys offer space that may be occupied by objects.
The storey contains information about which objects are situated within it.
A storey is informed about the bounding box of any item within it.
As objects may be placed upon other objects (where sensible),
the height of a storey is limited at 3 metres.

# Summary: about bounding boxes

There are four kinds of bounding boxes to be differentiated:

 * An object's width/length bounding box.
   It denotes the object's approximate width and length (if looked at from above).
   It encloses the object as close as possible in metres.
 * An object's height.
   It denotes the object's approximate height in fractions of one metre.
 * A placed object's tile bounding box.
   An object takes up space in tiles.
   This bounding box is the width/length bounding box
   translated to the correct place on the tile map.
   As an object also has a specific height,
   it is translated into the correct vertical place in the storey.

# Lots

A lot contains at least one storey at ground level.
A lot is informed about which tiles on the map may be changed.
Storeys generally have at most the tiles available to them as tiles are on the lot.

