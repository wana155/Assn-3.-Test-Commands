



#ifndef BaseExecute_h
#define BaseExecute_h
#include <iostream>
#include <vector>
#include <sys/wait.h>
#include  <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>



using namespace std;

class BaseExecute{
protected:
    vector <string> comma;
    bool stas=true;
    vector <char> connec;
    
    string str;
    char *tmp[50];
    
public: BaseExecute(){}
    virtual void ExecuteC()=0;
    bool runs(char **a);
    void ComadsEx(int i);
};

/* Encapsulates the execute algorithm for Commands */
class CoShellExecute: public BaseExecute{
  
public:
    CoShellExecute(){}
    CoShellExecute(vector<string> PA, vector<char> PB, bool PC){
            this->comma=PA;
            this->connec=PB;
            this->stas=PC;
        }
    void ExecuteC();
};


/* Encapsulates the execute algorithm for Tests */
class TestExecute:public BaseExecute{
 
public:
    TestExecute(){}
    TestExecute(vector<string> PA, vector<char> PB, bool PC){
        this->comma=PA;
        this->connec=PB;
        this->stas=PC;
    }
    void ExecuteC();
};
#endif /* BaseExecute_h */
