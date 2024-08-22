#include<iostream>
#include<fstream>
#include<list>
#include<string>
using namespace std;

int main(){
	list<string>l_buf,t_buf;
	ifstream ifs("/home/elsie/work/include/local.h");
	string buf,flag("#include <local.h>");
	while(getline(ifs,buf)) t_buf.emplace_back(move(buf));
	ifs.close();
	ifs.open("/dev/shm/a.cpp");
	while(getline(ifs,buf))
		if(buf==flag) l_buf.insert(l_buf.end(),t_buf.begin(),t_buf.end());
		else l_buf.emplace_back(move(buf));
	for(string&line:l_buf)
		cout<<line<<"\n";
}
