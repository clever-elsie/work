#include<iostream>
#include<algorithm>
#include<vector>
#include<filesystem>
#include<fstream>
#include<cstdlib>
using namespace std;

int main(){
	filesystem::path dir("/dev/shm");
	vector<string>exe;
	for(auto file:filesystem::directory_iterator(dir)){
		string fstr=file.path().string();
		if(fstr.ends_with(".in"))
			exe.push_back(fstr);
	}
	sort(exe.begin(),exe.end());
	for(auto fstr:exe){
		cout<<endl;
		ifstream inputfile(fstr);
		cout<<fstr<<endl;
		string tmp;
		while(getline(inputfile,tmp))
			cout<<tmp<<endl;
		cout<<endl;
		string command=string("/dev/shm/a.out < ")+fstr;
		int ret=system(command.c_str());
	}
}