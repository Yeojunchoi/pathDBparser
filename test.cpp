#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>
#include <boost/filesystem.hpp>
#include <cmath>

#include "node.h"

#define pi 3.14159265358979323846
//#include "tools.h"
//#include "graph.h"

double deg2rad(double deg) {
return (deg * pi / 180);
}

//  This function converts radians to decimal degrees
double rad2deg(double rad) {
return (rad * 180 / pi);
}

double dist_btw_lla_points(double lat_origin,double lon_origin, double lat_far,double lon_far){
    float R=6371*pow(10,3);
    double delta_phi=deg2rad((lat_far-lat_origin));
    double delta_lambda=deg2rad((lon_far-lon_origin));

    double a=sin(delta_phi/2)*sin(delta_phi/2)+
             cos(deg2rad(lat_origin))*cos(deg2rad(lat_far))*
             sin(delta_lambda/2)*sin(delta_lambda);

    double c=2*atan2(sqrt(a),sqrt(1-a));
    double d=R*c;

    return d;
}


std::vector<std::string> tokenize_operator(const std::string& data) {
        std::vector<std::string> result;
        std::string token;
        std::stringstream ss(data);

        while (ss >> token) {
            result.push_back(token);
        }
        return result;
    }

std::vector<Node> parse_node_file(std::string nodefile,std::vector<Node> &nodelist){
        std::ifstream in(nodefile);

        char buf[100];

        if (!in.is_open()) {
        std::cout << "파일을 찾을 수 없습니다! check file name" << std::endl;

        }

        std::cout.precision(10);
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
            //std::cout<<nodename<<std::endl;
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

        Node tmp;
        tmp.setNode(nodename,lat,lon,alt);
        nodelist.push_back(tmp);
        //nodelist[nodenum].printout();
        // std::cout<<nodelist[nodenum].getName()<<std::endl;
        nodenum++;
        }

        return nodelist;
}//parse_node_file end

void parse_connection_file(std::vector<Node> &nodelist)                                         //send nodelist reference
{
  namespace fs=boost::filesystem;                                                               //using boost filesystem
  std::vector<fs::path> files;                                                                  //creating path object
  fs::path folder=fs::current_path();                                                           //find current path
  fs::path p=folder.generic_string()+"/connection";                                             //designate connection folder to current path
  fs::directory_iterator it{p};                                                                 //boost create folder iterater object

  // connection file example(A-1.txt) 
  
  // #	Connected to	cost	route
  //	Base		0.422	base-a1`	
  //  	A-4		    0.168	a1-a4

  while (it != fs::directory_iterator{})                                                        //while iteration end
  {
      if(it->status().type()==fs::regular_file){                                                //if find regular file, add to files vector
          files.push_back(it->path());
      }
      it++;                                                                                     //to next iteration
  }

  for (auto & node :nodelist)                                                                   //for each node in nodelist
  {
    
    for(auto& file: files)                                                                      //for each file in connection folder
    {
     
      if(file.stem()==node.getName())                                                           //if filename matches to nodename
      {     

            std::ifstream cnectfile(file.generic_string());                                     //ifstream, open exact file
            std::string tmp_connected,tmp_cost,tmp_route;                                                 //create temporary variable
            char buf[100];
            std::string bufconvert;
            
            if (!cnectfile.is_open())                                                           //  if cannot open file
            {
                std::cout << "파일을 찾을 수 없습니다! check file name" << std::endl;
            }

            while(cnectfile)                                                                    //while file is open , until eof()
            {
                cnectfile.getline(buf,100);                                                     //write one line to buffer
                bufconvert=static_cast<std::string>(buf);                                       //change char -> string for later use
               
                if(bufconvert.length()==0){break;}                                              //detects blank line, break
                
                if(cnectfile.eof()==true){break;}                                               //detects eof(), break

                std::vector<std::string> result=tokenize_operator(buf);                         //tokenize line

                if(result[0]=="#"){std::cout<<"pass index row"<<std::endl; continue;}           //pass first index line

                for (int i = 0; i < result.size(); i++)                                         // for each element in one line
                {                                 
                    switch (i)
                    {
                    case 0:                                                                     //first element, node name
                        tmp_connected =static_cast<std::string>(result[i]);                   
                        //std::cout<<"parsing elements "<< connected<<"  ";
                        break;
                    case 1:                                                                     //second element, cost
                        tmp_cost=static_cast<std::string>(result[i]);
                        //std::cout<<cost<<"  "; 
                        break;

                    case 2:                                                                     //third element, route
                        tmp_route =static_cast<std::string>(result[i]);
                        //std::cout<<route<<std::endl; 
                        break;

                    default:                                                                    //exception, wrong element
                        std::cout<<"unexpected coulumn input"<<std::endl;
                        break;
                    }
                }

                for(auto & current:nodelist)                                                    //searching for all node in nodelist
                {
                    if(tmp_connected==current.getName())                                        //if nodename matches with tmp_connected
                    {   
                        node.setConnection(current);                                            //insert current node to connection_list of mother node 
                        node.setCost(stof(tmp_cost));                                           //insert cost
                        node.setRoute(tmp_route);                                               //insert route
                    }
                }

            }
            //############ DEBUGCODE ###########################
            /*
            std::cout<<"connection nodes: ";
            for(auto & i :connected_nodes){
                    std::cout<<i<<"  ";
                }
            std::cout<<std::endl;
            
            std::cout<<"costs:  ";
            for(auto & i :costs){
                std::cout<<i<<"  ";   
            }
            std::cout<<std::endl;
            
            std::cout<<"routes:  ";
            for(auto & i :routes){
                std::cout<<i<<"  ";   
            }
            std::cout<<std::endl;
            */
            
            //node.setConnection(connected_nodes,costs,routes);
        }

      }
    }
}                                                                                               //parse_connection_file end



float cal_heuristic_cost(Node now, Node arrival){
    return dist_btw_lla_points(now.getLatitude(),now.getLongitude(),arrival.getLatitude(),arrival.getLongitude())/1000.0;
}

float cal_cost(std::vector<Node> &openlist, Node arrival){
    float f,g,h;
    std::vector<std::string> connectionName;
    std::vector<float> g_cost;
    std::vector<float> h_cost;
    std::vector<float> f_cost;
    for(auto &current:openlist)
    {
        for (int j = 0; j < 3; j++)
        {
            for(auto & k:i.getConnection()->at(j))
            {
                if(j==0)
                {
                    connectionName.push_back(k);
                }
                else if(j==1)
                {
                    g_cost.push_back(stof(k));
                }
            }
        }    


    }

   
}


int a_star_path(std::vector<Node> &nodelist,std::vector<Node> &path, std::string start, std::string target){
    bool flag1,flag2 =false;
    Node departure;
    Node arrival;
    std::vector<Node> openlist;                                                                 //a* start create open and closed list
    std::vector<Node> closedlist;
    
    for(auto &node:nodelist){                                                                   //search all node in nodelist
        if(node.getName()==start){                                                              //if find start node in nodelist
            flag1 =true;                                                                        //indicating found start node
            //departure.copyNode(node);                                                           //Deep Copy node
            departure=node;
            std::cout<<"found starting node"<<std::endl;
        }
        else if(node.getName()==target){                                                        //if found target node in nodelist
            flag2 =true;                                                                        //indicating found target node
            //arrival.copyNode(node);
            arrival=node;                                                             //Deep Copy
            std::cout<<"found target node"<<std::endl;
        }
    }
    
    
    closedlist.push_back(departure);                                                            //push back departure Node address
    
                                                          //Check node name input





}



int main(){

   std::vector<Node> parsedlist;                                                                    //main data pool, do not delete or free                  
   std::vector<Node> resultpath;
   parse_node_file("node.txt",parsedlist);
  
   parse_connection_file(parsedlist);
    

   // cal_cost(parsedlist);
    //std::cout<<dist_btw_points(37.222222,127.222222,37.222223,127.2222223);    
    
    
    /*
    for(auto & k:parsedlist[2].getConnection()->at(1)){
        std::cout<<k<<std::endl;
    }*/
    
    
    //std::cout<<a_star_path(parsedlist,resultpath,"Base","A-2")<<std::endl;

   
    
   /*for(auto &list : parsedlist){
       list.printout();

        //std::vector<std::vector<std::string>> *mat_ref=list.getConnection();
        //std::cout<<mat_ref->at(0).at(0)<<std::endl;
   }*/



     
    


    return 0;
}