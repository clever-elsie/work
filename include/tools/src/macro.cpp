#include<iostream>
#include<fstream>
#include<filesystem>
#include<list>
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;

const static string library_dir("lib_Clever_Elsie/"); // from pwd == ./work
unordered_set<string>included;
list<string>lines;
vector<string>bits_stdcppH;

void rec_parser(ifstream&&);
void construct_bits_stdcppH();

int main(){
	construct_bits_stdcppH();
	rec_parser(ifstream("/dev/shm/a.cpp"));
	for(const auto&x:lines)
		cout<<x<<'\n';
	cout<<flush;
}

bool proc_line(string&s,bool st_comment){
	string t;
	for(size_t i=0;i<s.size();++i){
		if(st_comment){
			if(s[i]=='*'&&i+1<s.size()&&s[i+1]=='/')
				st_comment=false,++i;
		}else{
			if(s[i]=='/'&&i+1<s.size()){
				if(s[i+1]=='/') break;
				if(s[i+1]=='*') st_comment=true;
				else t.push_back(s[i]);
			}else t.push_back(s[i]);
		}
	}
	s=move(t);
	return st_comment;
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
	bool st_comment=false;
	string buf;
	while(getline(ifs,buf)){
		st_comment=proc_line(buf,st_comment);
		if(!st_comment){
			bool for_insert=true;
			if(buf.starts_with("#include")){
				auto[p,q]=pq(buf);
				string b(begin(buf)+p,begin(buf)+q);
				if(included.contains(b)) for_insert=false;
				else{
					included.insert(b);
					if(b=="local.h"){
						for_insert=false;
						rec_parser(ifstream("include/local.h"));
					}else if(b=="bits/stdc++.h"){
						for(const auto&s:bits_stdcppH)
							included.insert(s);
						// 自作ライブラリでもACLでもないのでfor_insertはtrue
					}else{
						string file=library_dir+b;
						if(filesystem::exists(file)){
							for_insert=false;
							rec_parser(ifstream(file));
						}
					}
				}
			}
			if(for_insert) lines.push_back(move(buf));
		}
	}
}

void construct_bits_stdcppH(){
	bits_stdcppH={ "any", "array", "atomic", "algorithm", "bit", "bitset", "barrier", "cfenv", "cmath", "ctime", "cctype", "cerrno", "cfloat", "chrono", "cstdio", "cuchar", "cwchar", "cassert", "ciso646", "climits", "clocale", "codecvt", "compare", "complex", "csetjmp", "csignal", "cstdarg", "cstddef", "cstdint", "cstdlib", "cstring", "ctgmath", "cwctype", "ccomplex", "charconv", "concepts", "cstdbool", "cinttypes", "coroutine", "cstdalign", "condition_variable", "deque", "expected", "exception", "format", "future", "fstream", "filesystem", "functional", "forward_list", "generator", "ios", "iosfwd", "iomanip", "istream", "iostream", "iterator", "initializer_list", "list", "latch", "limits", "locale", "map", "mutex", "memory", "memory_resource", "new", "numbers", "numeric", "ostream", "optional", "print", "queue", "ratio", "regex", "random", "ranges", "set", "span", "stack", "string", "sstream", "stdfloat", "semaphore", "stdexcept", "streambuf", "spanstream", "stacktrace", "stop_token", "syncstream", "string_view", "stdatomic.h", "system_error", "shared_mutex", "source_location", "scoped_allocator", "tuple", "thread", "typeinfo", "typeindex", "type_traits", "utility", "vector", "variant", "version", "valarray", "unordered_map", "unordered_set" };
}