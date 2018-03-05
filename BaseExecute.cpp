

#include <stdio.h>
#include "BaseExecute.h"


bool BaseExecute::runs(char **a){
    
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
void BaseExecute::ComadsEx(int i){
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
    }
    
    
}
void CoShellExecute::ExecuteC(){
    tmp[0]="sh";
    tmp[1]="-c";
    /* Executes comands in conatiner*/
    for (int l=0;l<this->comma.size();l++){
        this->ComadsEx(l);
        }
}


void TestExecute::ExecuteC(){

  
    tmp[0]="sh";
    tmp[1]="-c";
    /* Executes comands in conatiner*/
    for (int l=0;l<this->comma.size();l++){
        
        string tmo=this->comma[l];
        std::size_t found=tmo.find("test");
        std::size_t foundSy=tmo.find("[");
        std::size_t foundSy2=tmo.find("]");
        if (found!=std::string::npos||foundSy!=std::string::npos){
            
            if (found!=std::string::npos){
                tmo.erase(0, (found+5));}
            if (tmo[tmo.size()-1]==32){
                tmo.erase(tmo.size()-1,1);
            }
            if (foundSy!=std::string::npos){
                tmo.erase((foundSy2-1),2);
                tmo.erase(0,(foundSy+2));
                
            }
        bool staa=true;
            if (tmo[1]==101){
                tmo.erase(0,3);
                
                struct stat buffer;
                int status;
                
                
                status=stat(tmo.c_str(), &buffer);
                if (status==0){ cout <<"(True) "<<endl;
                }
                if (status!=0){
                    cout<<"(False)"<<endl;
                    stas=false;
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
                    else{cout<<"(False)"<<endl;
                        stas=false;
                    }
                }
                if (status!=0){
                    cout<<"(False)"<<endl;
                    stas=false;
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
                    else{cout<<"(False)"<<endl;
                        stas=false;
                    }
                }
                if (status!=0){
                    cout<<"(False)"<<endl;
                    stas=false;
                }
            }
            
            
            else{ struct stat buffer;
                int status;
                
                
                status=stat(tmo.c_str(), &buffer);
                if (status==0){
                    cout <<"(True) "<<endl;
                }
                
                if (status!=0){
                    cout<<"(False)"<<endl;
                    stas=false;
                }}
        }
        else{this->ComadsEx(l);}
        }}
