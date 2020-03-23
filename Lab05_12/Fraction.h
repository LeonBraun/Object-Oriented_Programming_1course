#include <iostream>
using namespace std;

class fraction
{
    const int znam;
    const int chisl;
public:
    int getchisl() const { return chisl; }
    int getznam() const { return znam; }
    fraction() : chisl(0), znam(1) {}
    fraction(int chisl, int znam) : chisl(chisl), znam(znam) {}
};