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
        void setConnection(std::vector<std::string>, std::vector<std::string>, std::vector<std::string>);
        void copyNode(const Node &);
        void printout();
        std::string getName();
        double getLatitude();
        double getLongitude();
        float getAltitude();
        std::vector<std::vector<std::string>>* getConnection();
    private:
        std::string name;
        double latitude;
        double longitude;
        float altitude;
        std::vector<std::vector<std::string>> con_mat;
};


#endif
