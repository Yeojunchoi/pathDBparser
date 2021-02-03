#ifndef GRAPH_H
#define GRAPH_H
#include "node.h"
#include <vector>
#include <boost/filesystem.hpp>


class ConnectionGraph{
    public:
        ConnectionGraph();
        void regNode(std::vector<Node>*);
        void setConnection(std::string);
        std::vector<std::vector<float>> getCostMat();
    private:
       std::vector<Node>* nodes;
       std::vector<std::vector<float>> costMat;
       std::vector<std::string> nodenameIndex1;
       std::vector<std::string> nodenameIndex2;

};


#endif




