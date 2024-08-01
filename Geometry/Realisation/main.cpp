#include "../vector.h"
#include "../ishape.h"
#include "../point.h"
#include "../segment.h"
#include "../ray.h"
#include "../line.h"
#include "../circle.h"
#include "../polygon.h"
#include <string>
#include <memory>
#include <iostream>
#include <vector>
using namespace geometry;

int main() {
    Circle s(Point(0, 0), 5);
    Segment q(4, 0, 0, 4);
    std::cout << (s.ContainsPoint(q.GetFirstPoint()) ? "yes" : "no") << '\n';
    std::cout << (s.CrossesSegment(q) ? "yes" : "no") << '\n';
}