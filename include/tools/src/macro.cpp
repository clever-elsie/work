#include<iostream>
#include<fstream>
#include<filesystem>
#include<list>
#include<string>
#include<vector>
#include<unordered_set>
#include<regex>
using namespace std;

const static string library_dir("/usr/local/include/lib_Clever_Elsie/"); // from pwd == ./work
unordered_set<string>included;
list<string>lines;
vector<string>bits_stdcppH;

void rec_parser(const string&);
void construct_bits_stdcppH();

int main(){
    construct_bits_stdcppH();
    rec_parser("/dev/shm/a.cpp");
    for(const auto&x:lines)
        cout<<x<<'\n';
    cout<<flush;
}

void rec_parser(const string&filename){
    auto pq=[](const string&s) {
        size_t p=s.find('<'),q=s.find('>');
        bool is_relative_first=false;
        if(p==string::npos){
            p=s.find('\"');
            q=s.find('\"',p+1);
            is_relative_first=true;
        }
        return std::make_tuple(p+1,q,is_relative_first);
    };
    ifstream ifs(filename);
    string buf;
    while(getline(ifs,buf)){
        if(regex_match(buf.begin(),buf.end(),regex("\\s*#\\s*include.*"))){
            auto[p,q,r]=pq(buf);
            string b(begin(buf)+p,begin(buf)+q);
            if(r){
                try{
                    filesystem::path file=filesystem::canonical(filesystem::path(filename).parent_path()/b);
                    rec_parser(file.string());
                    continue;
                }catch(...){
                    // 相対パスが無い場合は無視して次の処理をすればいいので無視してOK
                }
            }
            if(included.contains(b)) continue;
            else{
                included.insert(b);
                if(b=="local.h"){
                    rec_parser("include/local.h");
                    continue;
                }else if(b=="bits/stdc++.h"){ // bits/stdc++.hに限らず標準ヘッダはそのまま
                    for(const auto&s:bits_stdcppH)
                        included.insert(s);
                }else{
                    // ライブラリルートからのパス
                    string file=library_dir+b;
                    if(filesystem::exists(file)){
                        rec_parser(file);
                        continue;
                    }
                }
            }
        }
        lines.push_back(move(buf));
    }
}

void construct_bits_stdcppH(){
    bits_stdcppH={ "any", "array", "atomic", "algorithm", "bit", "bitset", "barrier", "cfenv", "cmath", "ctime", "cctype", "cerrno", "cfloat", "chrono", "cstdio", "cuchar", "cwchar", "cassert", "ciso646", "climits", "clocale", "codecvt", "compare", "complex", "csetjmp", "csignal", "cstdarg", "cstddef", "cstdint", "cstdlib", "cstring", "ctgmath", "cwctype", "ccomplex", "charconv", "concepts", "cstdbool", "cinttypes", "coroutine", "cstdalign", "condition_variable", "deque", "expected", "exception", "format", "future", "fstream", "filesystem", "functional", "forward_list", "generator", "ios", "iosfwd", "iomanip", "istream", "iostream", "iterator", "initializer_list", "list", "latch", "limits", "locale", "map", "mutex", "memory", "memory_resource", "new", "numbers", "numeric", "ostream", "optional", "print", "queue", "ratio", "regex", "random", "ranges", "set", "span", "stack", "string", "sstream", "stdfloat", "semaphore", "stdexcept", "streambuf", "spanstream", "stacktrace", "stop_token", "syncstream", "string_view", "stdatomic.h", "system_error", "shared_mutex", "source_location", "scoped_allocator", "tuple", "thread", "typeinfo", "typeindex", "type_traits", "utility", "vector", "variant", "version", "valarray", "unordered_map", "unordered_set" };
}