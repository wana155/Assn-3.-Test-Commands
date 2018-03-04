 
/* ComandExecute Source File*/
#include <iostream>
#include <sys/wait.h>
#include  <sys/types.h>
#include <unistd.h>
#include  <stdio.h>
#include <string>
/*#include "BaseFactory.h"*/
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
bool CommandExecute::run(char **a){
    /* Forks parent and child processes for execution */
    bool tmp=true;
    pid_t  pid;
    int    status;
    if ((pid = fork()) < 0) {     /* Start fork and child  */
        cout<<"* Unable to create fork child process"<<endl;
    }
    
    else if (pid == 0) {
        if (execvp("/bin/sh", a) < 0) {     /* execute the command  */
            cout<<"* unable to execute commnad"<<endl;
            tmp=false;
        }}
    else {
        while (wait(&status) != pid);}
    return tmp;
}

