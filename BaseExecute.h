

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
public: BaseExecute(){}
    virtual void ExecuteC()=0;
    
        
    
    bool runs(char **a){
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
};

class CoShellExecute: public BaseExecute{
private:
    vector <string> comma;
    bool stas=true;
   
    vector <char> connec;
    
public:
    CoShellExecute(){}
    CoShellExecute(vector<string> PA, vector<char> PB, bool PC){
            this->comma=PA;
            this->connec=PB;
            this->stas=PC;
        
    }
        
    void ExecuteC(){
        
        cout<<"Sell execute"<<endl;
        string str;
        char *tmp[50];
        tmp[0]="sh";
        tmp[1]="-c";
        /* Executes comands in conatiner*/
        for (int i=0;i<this->comma.size();i++){
            char buffer[99];
            str=this->comma[i];
            size_t length=str.copy(buffer, str.size(),0);
            buffer[length]='\0';
            tmp[2]=buffer;
            tmp[3]=NULL;
            
            bool sta=true;
            if (stas==true)
            {  sta=this->runs(tmp);}
            if (this->connec.empty()==false)
            {/*Odered Execution based on Conectors */
                if (this->connec[i]==';'){
                    this->stas=true;}
                else if (this->connec[i]=='&'){
                    if (sta==true){this->stas=true;}
                    else{
                        this->stas=false;
                    }}
                else if (this->connec[i]=='|'){
                    if (sta==false){this->stas=true;}
                    else{
                        this->stas=false;}}
            }}
    }
};



class TestExecute:public BaseExecute{
private:
    vector <string> comma;
    bool stas=true;
    vector <char> connec;
public:
    TestExecute(){}
    TestExecute(vector<string> PA, vector<char> PB, bool PC){
        this->comma=PA;
        this->connec=PB;
        this->stas=PC;
        
    }
   
    
    void ExecuteC(){
       cout<< "Test Execute"<<endl;
        string str;
        char *tmp[50];
        tmp[0]="sh";
        tmp[1]="-c";
        /* Executes comands in conatiner*/
        for (int i=0;i<this->comma.size();i++){
            
            string tmo=this->comma[i];
            std::size_t found=tmo.find("test");
            if (found!=std::string::npos){
            
        
                tmo.erase(found, (found+5));
    
                if (tmo[1]==101){
                    tmo.erase(0,3);
                
                    struct stat buffer;
                    int status;
                    
                    
                    status=stat(tmo.c_str(), &buffer);
                    if (status==0){ cout <<"(True) "<<endl;
                    }
                    if (status!=0){
                        cout<<"(False)"<<endl;
                    }
                }
                
                else if(tmo[1]==102){
                    tmo.erase(0,3);
                    
                    
                    struct stat buffer;
                    int status;
                    
                    
                    status=stat(tmo.c_str(), &buffer);
                    if (status==0){
                        
                        
                        if( S_ISREG( buffer.st_mode ) != 0 )
                        {   cout <<"(True) "<<endl;
                            cout<< "This is a File"<<endl;}
                        else{cout<<"(False)"<<endl;}
                    }
                    if (status!=0){
                        cout<<"(False)"<<endl;
                    }
                }
                
                
                else if(tmo[1]==100){
                    tmo.erase(0,3);
                    struct stat buffer;
                    int status;
                    
                    
                    status=stat(tmo.c_str(), &buffer);
                    if (status==0){
                        
                        
                        if( S_ISREG( buffer.st_mode ) == 0 )
                        {   cout <<"(True) "<<endl;
                            cout<< "This is a Directory"<<endl;}
                        else{cout<<"(False)"<<endl;}
                    }
                    if (status!=0){
                        cout<<"(False)"<<endl;
                    }
                }
               
                
                else{ struct stat buffer;
                int status;
                
                
                status=stat(tmo.c_str(), &buffer);
                if (status==0){
                    cout <<"(True) "<<endl;}
                
                if (status!=0){
                    cout<<"(False)"<<endl;
                }}
   
                
            }
        else{
            char buffer[99];
            str=this->comma[i];
            size_t length=str.copy(buffer, str.size(),0);
            buffer[length]='\0';
            tmp[2]=buffer;
            tmp[3]=NULL;
            
            bool sta=true;
            if (stas==true)
            {  sta=this->runs(tmp);}
            if (this->connec.empty()==false)
            {/*Odered Execution based on Conectors */
                if (this->connec[i]==';'){
                    this->stas=true;}
                else if (this->connec[i]=='&'){
                    if (sta==true){this->stas=true;}
                    else{
                        this->stas=false;
                    }}
                else if (this->connec[i]=='|'){
                    if (sta==false){this->stas=true;}
                    else{
                        this->stas=false;}}
            }}
        
        }}
    
};
#endif /* BaseExecute_h */
