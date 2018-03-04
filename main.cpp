

#include <iostream>
#include "GetInput.hpp"
#include <unistd.h>
#include  <stdio.h>
#include  <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include "Command.hpp"
#include <sys/stat.h>
#include "BaseFactory.h"
#include "CommandExecute.hpp"

using namespace std;

bool fileExists(const std::string& file) {
    struct stat buf;
    return (stat(file.c_str(), &buf) == 0);
}

int main() {

    cout<<"Type 'Exit' to End Program"<<endl;
   
   BaseFactory* commandType1=new CoShellFactory();
   BaseFactory* commandType2=new TestFactory();

    GetInput test;

 do{
    cout<<"$ ";
    test.getData();
     bool T=false;
   if(test.retrieveData(&T) =="Exit"){
      return 0;
   }
   else if (T==true){
           CommandExecute *instance=new Command(commandType2);
            instance->parse(test.retrieveData());
           instance->execute();
       }
       else{
           CommandExecute *instance=new Command(commandType1);
           instance->parse(test.retrieveData());
           instance->execute();
       }
    
    cout<<endl;
   
  }while(test.retrieveData() != "Exit");

}
