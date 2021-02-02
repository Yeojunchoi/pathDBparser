#include "node.h"
#include <iostream>

Node::Node(){
    name=" ";
    longitude=0;
    latitude=0;
    altitude=0;

}

void Node::setNode(std::string n,double lat, double lon, float alt){
    name=n;
    latitude=lat;
    longitude=lon;
    altitude=alt;
}

void Node::printout(){
    std::cout<<"node name: "<< name<<"  lla:  "<<latitude<<" "<<longitude<<"  "<<altitude<<std::endl;
    //std::cout<<"node name: "<<"  lla:  "<<latitude<<" "<<longitude<<"  "<<altitude<<std::endl;
}

std::string Node::getName(){
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



