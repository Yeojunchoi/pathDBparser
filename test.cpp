#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>
//#include <boost/filesystem.hpp>

#include "node.h"
//#include "tools.h"
//#include "graph.h"

std::vector<std::string> tokenize_operator(const std::string& data) {
        std::vector<std::string> result;
        std::string token;
        std::stringstream ss(data);

        while (ss >> token) {
            result.push_back(token);
        }
        return result;
    }

std::vector<Node> parse_node_file(std::string nodefile){
        std::ifstream in(nodefile);

        char buf[100];

        if (!in.is_open()) {
        std::cout << "파일을 찾을 수 없습니다! check file name" << std::endl;

        }

        std::cout.precision(10);
        std::vector<Node> nodelist;
        int nodenum=0;
        
        while (in) {
        std::string nodename;
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
            nodename =static_cast<std::string>(result[i]);                    //something wrong, set some string variable makes memory error correct
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
        //nodelist[nodenum].printout();
        // std::cout<<nodelist[nodenum].getName()<<std::endl;
        nodenum++;
        }
        
        for (int i = 0; i < nodelist.size(); i++)
        {
        std::cout<<"nodelist["<<i<<"] :"<<std::endl;
        nodelist[i].printout();
        }

        return nodelist;
}
/*
void parse_connection_file(std::vector<Node> nodelist)
{
  namespace fs=boost::filesystem;
  std::vector<fs::path> files;
  fs::path p("/home/airon/pathDB/connection");
  fs::directory_iterator it{p};
  std::string connected;
  std::string route;
  std::string cost;
  std::vector<std::string> connected_nodes;
  std::vector<float> costs;
  std::vector<std::string> routes;
  


  while (it != fs::directory_iterator{})
  {
      if(it->status().type()==fs::regular_file){
          files.push_back(it->path());
      }
      it++;
  }

  for (auto & node :nodelist){
    node.printout();
    
    /*for(auto& file: files){
      std::cout<<node.getName()<<" "<<file.filename().generic_string()<<std::endl;
      //if(file.filename().native()==node)
    }
  }



  for (const auto& file: files)
  {
      std::cout<<file.generic_string()<<std::endl;
      std::ifstream cnectfile(file.generic_string());
      
      char buf[100];
      std::string bufconvert;
    if (!cnectfile.is_open()) {
        std::cout << "파일을 찾을 수 없습니다! check file name" << std::endl;
    }

    while(cnectfile)
    {
        cnectfile.getline(buf,100);
        bufconvert=static_cast<std::string>(buf);
        if(bufconvert.length()==0){break;}
        if(cnectfile.eof()==true){break;}

        std::vector<std::string> result=tokenize_operator(buf);

        if(result[0]=="#"){std::cout<<"pass index row"<<std::endl; continue;}

        for (int i = 0; i < result.size(); i++)
        {                                 
            switch (i)
            {
            case 0:
                connected =static_cast<std::string>(result[i]);                    //something wrong, set some string variable makes memory error correct
                std::cout<<"parsing elements "<< connected<<"  ";
                break;
            case 1:
                cost=static_cast<std::string>(result[i]);
                std::cout<<cost<<"  "; 
                break;

            case 2:
                route =static_cast<std::string>(result[i]);
                std::cout<<route<<std::endl; 
                break;

            default:
                std::cout<<"unexpected coulumn input"<<std::endl;
                break;
            }
        }
        connected_nodes.push_back(connected);
        costs.push_back(cost);
        routes.push_back(route);

    }
    
  }

  for (int i = 0; i < connected_nodes.size(); i++)
    {
        std::cout<<connected_nodes[i]<<" "<<costs[i]<<" "<<routes[i]<<std::endl;
    }
 
}
*/
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

  std::cout<<"wtffffffffffffffffff"<<std::endl;
   //std::vector<Node> parsedlist=parse_node_file("node.txt");
  
   //parse_connection_file(parsedlist);

   
   
   
   /*std::vector<std::vector<int>> mat={{1,3,5},{3,2,4},{7,8,1}};
   std::cout<<mat[2][2]<<std::endl;*/

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