#include <iostream>
#include "GetInput.hpp"
#include <unistd.h>
#include  <stdio.h>
#include  <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include "Command.hpp"
#include "BaseFactory.h"
#include "CommandExecute.hpp"


using namespace std;


int main() {
 
cout<<"Type 'Exit' to end program"<<endl;   

  BaseFactory* commandType1=new CoShellFactory();
   BaseFactory* commandType2=new TestFactory();
    
   GetInput test;


 do{
    cout<<"$ ";
    test.getData();
   if(test.retrieveData() =="Exit"){
      return 0;
   }   
   else{ 
    CommandExecute *instance=new Command;
    instance->parse(test.retrieveData());
    cout<<endl;
    instance->execute();
    
    cout<<endl;
   }
  }while(test.retrieveData() != "Exit");

}
