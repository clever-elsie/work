#include<iostream>
#include<fstream>
#include<filesystem>
#include<list>
#include<string>
#include<unordered_set>
using namespace std;

const static string library_dir("lib_Clever_Elsie/"); // from pwd == ./work
unordered_set<string>included;
list<string>lines;

void rec_parser(ifstream&&);

int main(){
	rec_parser(ifstream("/dev/shm/a.cpp"));
	for(const auto&x:lines)
		cout<<x<<'\n';
	cout<<flush;
}

void rec_parser(ifstream&&ifs){
	auto pq=[](const string&s)->pair<size_t,size_t> {
		size_t p=s.find('<'),q=s.find('>');
		if(p==string::npos){
			p=s.find('\"');
			q=s.find('\"',p+1);
		}
		return {p+1,q};
	};
	string buf;
	while(getline(ifs,buf)){
		bool for_insert=true;
		if(buf.starts_with("#include")){
			auto[p,q]=pq(buf);
			string b=string(begin(buf)+p,begin(buf)+q);
			if(included.contains(b)) for_insert=false;
			else{
				included.insert(b);
				if(b=="local.h"){
					for_insert=false;
					rec_parser(ifstream("include/local.h"));
				}else{
					string file=library_dir+b;
					if(filesystem::exists(file)){
						for_insert=false;
						rec_parser(ifstream(file));
					}
				}
			}
		}
		if(for_insert)lines.push_back(move(buf)); // plane program
	}
}
