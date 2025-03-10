#include<fstream>
#include<iostream>
#include<sstream>
#include<set>
#include<filesystem>
#include<string>
#include<cctype>
using namespace std;
using sstream=stringstream;
int main(){
    filesystem::path dir("/dev/shm/");
    set<int>seen;
    seen.insert(0);
    for(auto file:filesystem::directory_iterator(dir)){
        if(file.path().string().ends_with(".in")){
            int num;
            string s=file.path().string();
            for(auto&x:s)if(!isdigit(x))x=' ';
            sstream str;
            str<<s;
            str>>num;
            seen.insert(num);
        }
    }
    string filename=dir.string()+string("/")+to_string(*seen.rbegin()+1)+string(".in");
    cout<<filename<<endl;
    ofstream ofs(filename);
    string tmp;
    while(getline(cin,tmp)){
        ofs<<tmp<<endl;
    }
}