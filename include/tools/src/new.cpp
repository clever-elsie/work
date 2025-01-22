#include<iostream>
#include<fstream>
#include<list>
#include<string>
using namespace std;

int main(){
	list<string>t_buf;
	ifstream ifs("include/tools/resource/template.cpp");
	string buf;
	while(getline(ifs,buf)) t_buf.emplace_back(move(buf));
	ifs.close();
	ofstream ofs("/dev/shm/a.cpp");
	for(string&line:t_buf)
		ofs<<line<<"\n";
}
