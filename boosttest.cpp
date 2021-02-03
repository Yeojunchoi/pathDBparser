#include <boost/filesystem.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>


namespace fs=boost::filesystem;


std::vector<std::string> tokenize_operator(const std::string& data) {
        std::vector<std::string> result;
        std::string token;
        std::stringstream ss(data);

        while (ss >> token) {
            result.push_back(token);
        }
        return result;
    }





int main()
{

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