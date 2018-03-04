

#ifndef BaseFactory_h
#define BaseFactory_h

#include <iostream>
#include "BaseExecute.h"
using namespace std;


class BaseFactory {
public:
    /* Constructor */
    BaseFactory(){}
    
    /* Pure Virtual Generate Function */
    virtual BaseExecute* generateExecute(vector<string> PA, vector<char> PB, bool PC)=0;
    
};

class CoShellFactory: public BaseFactory {
public:
    /* Constructor */
    
    /* Pure Virtual Generate Function */
    BaseExecute* generateExecute(vector<string> PA, vector<char> PB, bool PC){
        return new CoShellExecute(PA,PB,PC);
    }
};
class TestFactory: public BaseFactory {
public:
    /* Constructor */
    
    /* Pure Virtual Generate Function */
     BaseExecute* generateExecute(vector<string> PA, vector<char> PB, bool PC){
         return new TestExecute(PA,PB,PC);
         
     }
};

#endif /* BaseFactory_h */
