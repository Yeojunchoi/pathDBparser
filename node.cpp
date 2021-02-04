#include "node.h"


Node::Node(){
    name=" ";
    longitude=0;
    latitude=0;
    altitude=0;

}

Node::Node(const Node &copyfrom){

    name=copyfrom.name;
    latitude=copyfrom.latitude;
    longitude=copyfrom.longitude;
    altitude=copyfrom.altitude;
    connect_list=copyfrom.connect_list;
    
}

void Node::copyNode(const Node &copyfrom){
    name=copyfrom.name;
    latitude=copyfrom.latitude;
    longitude=copyfrom.longitude;
    altitude=copyfrom.altitude;
    connect_list=copyfrom.connect_list;
}

void Node::setNode(std::string n,double lat, double lon, float alt){
    name=n;
    latitude=lat;
    longitude=lon;
    altitude=alt;
}

void Node::setConnection(Node node){
    
    connect_list.push_back(node);

}
void Node::setCost(float cost){
    
    cost_list.push_back(cost);

}

void Node::setRoute(std::string route){
    
    route_list.push_back(route);

}

void Node::printout(){
    std::cout<<"node name: "<< name<<"  lla:  "<<latitude<<" "<<longitude<<"  "<<altitude<<std::endl;
    std::cout<<"connect_list"<<std::endl;
    for(auto &i:connect_list){
        for (auto &j:i){
            std::cout<<j<<"\t";
        }    
        std::cout<<std::endl;
    }
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

std::vector<std::vector<std::string>>* Node::getConnection(){

    return &connect_list;
}



