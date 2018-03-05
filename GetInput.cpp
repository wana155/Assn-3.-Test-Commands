


#include <iostream>
#include <string>
#include "GetInput.hpp"

using namespace std;

void GetInput::getData(){
    getline(cin,in);
}
string GetInput::retrieveData(bool*a){
    string tmp=in;
        std::size_t found=tmp.find("test");
         std::size_t foundSy=tmp.find("[");
        if (found!=std::string::npos||foundSy!=std::string::npos)
        { *a= true;}
    return in;
    
}
string GetInput::retrieveData(){
    return in;
}
