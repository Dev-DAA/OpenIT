#include <core/common.h>

bool
OpenIT::operator==(const Position current, const Position other)
{
  return current.x == other.x && current.y == other.y;
}