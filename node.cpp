#include "node.h"


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

void Node::setConnection(std::vector<std::string> connected_nodes,std::vector<std::string> costs,std::vector<std::string> routes){
    
    con_mat.push_back(connected_nodes);
    con_mat.push_back(costs);
    con_mat.push_back(routes);

}

void Node::printout(){
    std::cout<<"node name: "<< name<<"  lla:  "<<latitude<<" "<<longitude<<"  "<<altitude<<std::endl;
    std::cout<<"con_mat"<<std::endl;
    for(auto &i:con_mat){
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




