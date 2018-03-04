
/* Comand Source File*/

#include "Command.hpp"

using namespace std;



Command::Command(){
    this->executeFunction= new CoShellFactory();/*by defaoult*/
}
Command::Command(BaseFactory*Factory){
    this->executeFunction = Factory;
}


void Command::parse(std::string a){
    string::iterator it;
    int i = 0;
    string tmp;
    for ( it = a.begin() ; it < a.end(); it++,i++)   /* loop iteration on input*/
    {tmp=tmp+a[i];
        
           if (a[i]==38||a[i]==59||a[i]==124)
               {
                   this->connector.push_back(a[i]);  /* Store conector in data member*/
                 tmp.erase((tmp.size()-1),1);
          
               for (int j=0; j<tmp.size();j++){      /* Parse trough array and separates comanss*/
                    if (tmp[0]==32)
                    {tmp.erase(0,1);}}
                this->commads.push_back(tmp);
                tmp.clear();
            if (a[i]!=59){ i++;}
           }
       else if (it==(a.end()-1))                     /* gets last command */
        { this->commads.push_back(tmp);}
    }}








