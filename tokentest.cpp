
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>
#include <boost/filesystem.hpp>
#include <cmath>
#include <limits.h>

#include "node.h"

std::vector<std::string> tokenize_operator(const std::string& data) {
        std::vector<std::string> result;
        std::string token;
        std::stringstream ss(data);
        std::getline(ss,token,'/');
        std::cout<<token<<std::endl;
        /*
        while (ss >> token) {
            result.push_back(token);
        }
        */
        return result;
    }


int main(){

    tokenize_operator("/home/yjcom/pathDBparser/route/B-4");


}