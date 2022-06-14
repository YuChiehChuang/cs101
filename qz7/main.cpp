#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class myString{
    
};

class ReadClass{
    private:
        ifstream cf;
        string temp,outp,fn="main.cpp";
        int count;
    public:
        ReadClass(){
            cf.open(fn);
            count = 0;
        }
        ~ReadClass(){
            cf.close();
        }
        void showClass(){
            while(getline(cf, temp)){
                string pt="";
                int cki = temp.find("class ",0);
                if(cki!=-1){
                    for(char t:temp){
                        if(t!='{')
                            pt+=t;
                        else{
                            outp+=pt+"\n";
                            count++;
                        }
                            
                    }
                }
            }
            cout<<count<<" class in "<<fn<<endl<<outp;
            
        }
};
int main()
{
    ReadClass rfile;
    rfile.showClass();

    return 0;
}
