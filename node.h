#ifndef NODE_H
#define NODE_H
#include <iostream>

class Node{
    public:
        Node();
        void setNode(std::string,double,double,float);
        void printout();
        std::string getName();
        double getLatitude();
        double getLongitude();
        float getAltitude();
    private:
        std::string name;
        double latitude;
        double longitude;
        float altitude;
};

#endif
