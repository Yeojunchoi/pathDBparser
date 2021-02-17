#include<vector>
#include<iostream>


using namespace std;

int main(){
    vector<vector<string>> mat;
    vector<string> v1={"hello", "world", "fuckyou"};
    vector<string> v2={"i", "wanna", "go home"};

    mat.push_back(v1);
    mat.push_back(v2);

    for(auto &i:mat){
        for (auto &j:i){
            cout<<j<<std::endl;
        }    
    }

    
    
}