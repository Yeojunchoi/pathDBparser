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
    float       param1;
    float       param2;
    float       param3;
    float       param4;
    double      Lat_x;
    double      Lon_y;
    double      Alt_z;
    uint16_t    command;
    bool        is_current;
    bool        autocontinue;
    uint8_t     frame;
};


class Route{
    public:
        Route();
        void setStartEnd(Node &,Node &);
        void pushbackWP(Waypoint);
        Node* startnode();
        Node* endnode();
        bool* checkUproute();
        void printOut();




    private:
        Node start;
        Node end;
        bool uproute;
        std::vector<Waypoint> waypoints;


};



















#endif
