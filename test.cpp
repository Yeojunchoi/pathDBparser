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

    std::cout.precision(10);
    std::vector<Node> nodelist;
    int nodenum=0;
    
    while (in) {
      const char* nodename;
      std::string nodename2;
      double lat,lon;
      float alt;
      int name;


      in.getline(buf, 100);
      
      if(in.eof()==true){break;}                                             //detect eof and break out, prevents tokenizer seg_fault

      std::vector<std::string> result=tokenize_operator(buf);
      
      if(result[0]=="#"){std::cout<<"pass index row"<<std::endl; continue;}  //erase out first index row  # nodename    lat     lon     alt
      
      for (int i = 0; i < result.size(); i++)
      {                                 
        switch (i)
        {
        case 0:
          nodename =static_cast<std::string>(result[i]).c_str();
          nodename2 =static_cast<std::string>(result[i]);                    //something wrong, set some string variable makes memory error correct
          std::cout<<nodename<<std::endl;
          break;
        case 1:
          lat=stod(static_cast<std::string>(result[i]));
          //std::cout<<lat<<std::endl; 
          break;

        case 2:
          lon=stod(static_cast<std::string>(result[i]));
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
      std::cout<<nodename<<std::endl;

      Node tmp;
      tmp.setNode(nodename,lat,lon,alt);
      nodelist.push_back(tmp);
      nodelist[nodenum].printout();
      std::cout<<nodelist[nodenum].getName()<<std::endl;
      nodenum++;
    }
    
   /* for (int i = 0; i < nodelist.size(); i++)
    {
      std::cout<<"nodelist["<<i<<"] :"<<std::endl;
      nodelist[i].printout();
    }*/
    

   /* std::vector<Node> nodearray;
     Node tmp;
     const char* nodename="gellp";
     tmp.setNode(nodename,123.123123,123.22222,334.21);
     nodearray.push_back(tmp);
     nodearray.push_back(tmp);
     std::cout<<tmp.getnodename()<<std::endl;
     nodearray[0].printout();
     nodearray[1].printout();*/
     
    


    return 0;
}