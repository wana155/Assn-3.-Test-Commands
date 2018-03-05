 
/* ComandExecute Source File*/
#include <iostream>
#include <sys/wait.h>
#include  <sys/types.h>
#include <unistd.h>
#include  <stdio.h>
#include <string>
#include "CommandExecute.hpp"

using namespace std;


CommandExecute::CommandExecute(){
    this->executeFunction= new CoShellFactory();/*by defaoult*/
}
CommandExecute::CommandExecute(BaseFactory*Factory){
    this->executeFunction = Factory;
}
void CommandExecute::execute(){
    
    BaseExecute * Exetype=executeFunction->generateExecute(this->commads,this->connector,this->status);
    Exetype->ExecuteC();
  
  }

void CommandExecute::parse(std::string p)
{}
