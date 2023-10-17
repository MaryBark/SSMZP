#ifndef MAPMARBLETRASSA_H
#define MAPMARBLETRASSA_H

#include <vector>
#include "coordinateVectors.h"
#include "xyz2blh.h"

using namespace std;

class MapMarbleTrassa
{
public:
    MapMarbleTrassa();

    static vector<coordVectorBLH<double>> buildingRouteKA();

    static vector<coordVectorXYZ<double>> buildingRouteKAXYZ();

    static vector<double> buildingRouteKAXYZ1();

    static vector<double> Runge_Kutta(vector<double> init_coord, vector<double> acc,int n,int h);

    vector<double> coords()const {return _coord;}


private:
    vector<double> _coord;
};

#endif // MAPMARBLETRASSA_H
