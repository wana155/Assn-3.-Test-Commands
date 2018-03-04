/* ComandExecute header File*/

#ifndef CommandExecute_hpp
#define CommandExecute_hpp

#include "BaseFactory.h"
#include <iostream>
#include <vector>

class CommandExecute{

public:
    CommandExecute();
    CommandExecute(BaseFactory*Factory);
    
    /*setExecuteFunct()*/
    
    void execute();
    virtual void parse(std::string p);
protected:
     bool run(char **a);
    std::vector <std::string> commads;
    std::vector <char> connector;
    bool status=true;   
 BaseFactory* executeFunction;
    
};


#endif /* CommandExecute_hpp */
