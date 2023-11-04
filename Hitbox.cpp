#include "Hitbox.h"

Hitbox::Hitbox(float xl, float xr, float yb, float yt) : xLeft(xl), xRight(xr), yBottom(yb), yTop(yt){}

bool Hitbox::collisionDetection(Hitbox other)
{
    bool xCollision = ((xLeft <= other.xRight) && (xRight >= other.xLeft));
    bool yCollision = ((yTop >= other.yBottom) && (yBottom <= other.yTop));

    return xCollision&&yCollision;
}
