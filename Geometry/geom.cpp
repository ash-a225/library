#ifndef GEOM_H
#define GEOM_H

const double eps = 1e-9;
bool equal(double a, double b) { return abs(a-b) < eps;}

#endif