#include<iostream>
#include<fstream>
#include<cstdint>
#include<cstdlib>
#include<string>
using namespace std;

int32_t main(){
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	ofstream ofs("/dev/shm/c.cpp",ios::trunc);
	string buf;
	while(getline(cin,buf)) ofs<<buf<<endl;
	ofs.close();
	// /dev/shm/c.cpp -> /dev/shm/combined.cpp
	int _ = system("python3 /home/elsie/work/include/tools/src/expander.py /dev/shm/c.cpp --lib /home/elsie/work/include/ac-library");
	if(_) return -1;
	ifstream ifs("/dev/shm/combined.cpp");
	while(getline(ifs,buf)) cout<<buf<<endl;
	_ = system("rm /dev/shm/c.cpp");
	_ = system("rm /dev/shm/combined.cpp");
}