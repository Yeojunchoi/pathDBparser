#include <stdio.h>
#include <math.h>
#include <iostream>


class Node{
    public:
        Node();
        void setNode(const char*,double,double,float);
        void printout();
        const char* getName();
        double getLatitude();
        double getLongitude();
        float getAltitude();
    private:
        const char* name;
        double latitude;
        double longitude;
        float altitude;
};

Node::Node(){
    name=" ";
    longitude=0;
    latitude=0;
    altitude=0;

}

void Node::setNode(const char* n,double lat, double lon, float alt){
    name=n;
    latitude=lat;
    longitude=lon;
    altitude=alt;
}

void Node::printout(){
    std::cout<<"node name: "<< name<<"  lla:  "<<latitude<<" "<<longitude<<"  "<<altitude<<std::endl;
    //std::cout<<"node name: "<<"  lla:  "<<latitude<<" "<<longitude<<"  "<<altitude<<std::endl;
}

const char* Node::getName(){
    return name;
}

double Node::getLatitude(){
    return latitude;
}

double Node::getLongitude(){
    return longitude;
}

float Node::getAltitude(){
    return altitude;
}