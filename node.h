#include <stdio.h>
#include <math.h>
#include <iostream>


class Node{
    public:
        Node();
        void setNode(const char*,float,float,float);
        const char* getName();
        float getLatitude();
        float getLongitude();
        float getAltitude();
    private:
        const char* name;
        float latitude;
        float longitude;
        float altitude;
};

Node::Node(){
    name=" ";
    longitude=0;
    latitude=0;
    altitude=0;

}

void Node::setNode(const char* n,float lat, float lon, float alt){
    name=n;
    latitude=lat;
    longitude=lon;
    altitude=alt;
}

const char* Node::getName(){
    return name;
}

float Node::getLatitude(){
    return latitude;
}

float Node::getLongitude(){
    return longitude;
}

float Node::getAltitude(){
    return altitude;
}