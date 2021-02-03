#include "tools.h"


namespace UTIL{
    

    std::vector<std::string> tokenize_operator(const std::string& data) {
        std::vector<std::string> result;
        std::string token;
        std::stringstream ss(data);

        while (ss >> token) {
            result.push_back(token);
        }
        return result;
    }


}