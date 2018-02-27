
#include <iostream>
#include <string>
#include "GetInput.hpp"

using namespace std;

void GetInput::getData(){
    getline(cin,in);
}
string GetInput::retrieveData(){
    return in;
}
