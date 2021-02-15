#ifndef ROUTE_H
#define ROUTE_H
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
#include <boost/filesystem.hpp>
#include "node.h"

struct Waypoint{
    double  Lat;
    double  Lon;
    float   Alt;
    float   param1;
    float   param2;
    float   param3;
    float   param4;
    int     command;
    int     doJumpId;
    int     AltMode;
    bool    autocontinue;
    int     frame;
};


class Route{
    public:






    private:
        Node node1;
        Node node2;
        std::vector<Waypoint> route;


}



















#endif
