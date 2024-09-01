#include<iostream>
#include<filesystem>
#include<fstream>
#include<cstdlib>
using namespace std;

int main(){
	filesystem::path dir("/dev/shm");
	for(auto file:filesystem::directory_iterator(dir)){
		string fstr=file.path().string();
		if(fstr.ends_with(".in")){
			ifstream inputfile(fstr);
			cout<<fstr<<endl;
			string tmp;
			while(getline(inputfile,tmp))
				cout<<tmp<<endl;
			string command=string("/dev/shm/a.out < ")+fstr;
			int ret=system(command.c_str());
		}
	}
}