# Geometry
This repository contains header files and files with realization of functions from headers. Each class lays in geometry namespace.

## Vector
Directed segment. Supports some arithmetical operations, such as addition, subtraction, multiplication by integer number. 
Also you can get projection on the plane of cross product of two vectors.

## IShape
IShape is an abstract class and parent to each other class from repository. Each class has methods to move object in coordinate plane, 
check if object contains point or crosses segment, clone itself and get string representation.

## Point
Class which represents point in coordinate plane.  
*Subtraction of two points is vector.*

## Segment
A part of line, limited by two points. Can be created by two points or by their coordinates.

## Ray
A part of line, limited by only one point - peek of the ray. Each ray is defined by two parameters - Point object which will be peek of ray and Vector, which represents direction of ray.

## Line
Each line on coordinate plane is defined by the equation: *ax + by + c = 0*. You can create line object using three parameters which are *A, B, C* coefficients or by two Point object.

## Circle
Class which represents circle on coordinate plane.\
*In **ContainsPoint** function circle is a circle, but in **CrossesSegment** dots into circle don't play role*

## Polygon
Defined by std::vector of Point objects. Border of Polygon is defined by points order in std::vector.
