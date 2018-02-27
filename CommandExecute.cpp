

/* ComandExecute Source File*/
#include <iostream>
#include <sys/wait.h>
#include  <sys/types.h>
#include <unistd.h>
#include  <stdio.h>
#include <string>
#include "CommandExecute.hpp"
using namespace std;

CommandExecute::CommandExecute(){}


void CommandExecute::execute(){
    /* Setting up variables for execution*/
    string str;
    char *tmp[50];
    tmp[0]="sh";
    tmp[1]="-c";
    /* Executes comands in conatiner*/
    for (int i=0;i<this->commads.size();i++){
    char buffer[99];
    str=this->commads[i];
    size_t length=str.copy(buffer, str.size(),0);
    buffer[length]='\0';
    tmp[2]=buffer;
    tmp[3]=NULL;
    
        bool sta=true;
        if (status==true)
        {  sta=this->run(tmp);}
       if (this->connector.empty()==false)
       {/*Odered Execution based on Conectors */
            if (this->connector[i]==';'){
                this->status=true;}
            else if (this->connector[i]=='&'){
                if (sta==true){this->status=true;}
                else{
                    this->status=false;
                }}
            else if (this->connector[i]=='|'){
                if (sta==false){this->status=true;}
                else{
                    this->status=false;}}
        }}}

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

