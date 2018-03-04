


#ifndef GetInput_hpp
#define GetInput_hpp

#include <stdio.h>


class GetInput{
  
private:
    std::string in;
    bool isTest=false;

public:
   void getData();
    std::string retrieveData(bool * a);
     std::string retrieveData();
    
};


#endif /* GetInput_h */

