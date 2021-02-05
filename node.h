#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
#include <boost/filesystem.hpp>

class Node{
    public:
        Node();
        Node(const Node &);
        void setNode(std::string,double,double,float);
        void setConnection(Node &);
        void setCost(float);
        void setRoute(std::string);
        void copyNode(const Node &);
        void printout();
        std::string getName();
        double getLatitude();
        double getLongitude();
        float getAltitude();
        std::vector<Node> getConnection();
    private:
        std::string name;
        double latitude;
        double longitude;
        float altitude;
        std::vector<Node> connect_list;
        std::vector<float> cost_list;
        std::vector<std::string> route_list;
};


#endif
