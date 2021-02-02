#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>

#include "node.h"


std::vector<std::string> tokenize_operator(const std::string& data) {
	std::vector<std::string> result;
	std::string token;
	std::stringstream ss(data);

	while (ss >> token) {
		result.push_back(token);
	}
	return result;
}

int main(){
    /*std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(30);
    vec.push_back(50);
     for (std::vector<int>::size_type i = 0; i < vec.size(); i++) {
    std::cout << "vec 의 " << i + 1 << " 번째 원소 :: " << vec[i] << std::endl;
  }
    std::reverse(std::begin(vec),std::end(vec));

     for (std::vector<int>::size_type i = 0; i < vdec.size(); i++) {
    std::cout << "vec 의 " << i + 1 << " 번째 원소 :: " << vec[i] << std::endl;
  }*/


    std::ifstream in("node.txt");

     char buf[100];

    if (!in.is_open()) {
      std::cout << "파일을 찾을 수 없습니다!" << std::endl;
      return 0;
    }

    std::cout.precision(12);
    std::vector<Node> nodelist;
    while (in) {
      int nodenum=0;
      in.getline(buf, 100);
      const char* name;
      float lat,lon,alt;
      std::cout << buf << std::endl;
      std::vector<std::string> result=tokenize_operator(buf);
      for (int i = 0; i < result.size(); i++)
      {
        if(result[i]=="#"){std::cout<<"worked"<<std::endl; break;}                                    //erase out first index row  # name    lat     lon     alt
        switch (i)
        {
        case 0:
          name =static_cast<std::string>(result[i]).c_str();
          //std::cout<<name<<std::endl;
          break;
        case 1:
          lat=stof(static_cast<std::string>(result[i]));
          //std::cout<<lat<<std::endl;
          break;

        case 2:
          lon=stof(static_cast<std::string>(result[i]));
          //std::cout<<lon<<std::endl;
          break;

        case 3:
          alt=stof(static_cast<std::string>(result[i]));
          //std::cout<<alt<<std::endl;
          break;
        
        default:
          std::cout<<"unexpected coulumn input"<<std::endl;
          break;
        }
      }

      std::cout<<lat<<" "<<lon<<" "<<alt<<" "<<std::endl;
      //nodelist[nodenum].setNode(name,lat,lon,alt);
    }

    return 0;
}