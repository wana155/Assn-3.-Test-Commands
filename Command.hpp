
/* Comand Header File*/

#ifndef COMMAND_H
#define COMMAND_H
#include <iostream>
#include <vector>
#include "CommandExecute.hpp"

class Command: public CommandExecute{
public:Command();
    Command(BaseFactory*Factory);
    void parse(std::string p);

};


#endif /* Command_hpp */
