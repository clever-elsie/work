#include <filesystem>
#include <iostream>
#include <cstdlib>
using namespace std;

string gcc;

void rec_compile(const filesystem::path&now){
	for(const auto&to:filesystem::directory_iterator(now)){
		if(to.is_directory()){
			if(to.path().filename().string()[0]!='.')
			if(to.path().filename().string()!="library-checker-problems")
				rec_compile(to.path());
		}else{
			if(to.path().extension()==".hpp"){
				string hppname=to.path().string();
				string gchname=hppname+".gch";
				bool flag=true;
				if(filesystem::exists(gchname))
					if(filesystem::directory_entry(hppname).last_write_time()<filesystem::directory_entry(gchname).last_write_time())flag=false;
				if(flag){
					string command=gcc+" -o "+gchname+" "+hppname;
					int code = system(command.c_str());
					if(code){
						cout<<"[FAIL] "<<hppname<<endl;
						cerr<<"\n\n[FAIL] "<<hppname<<"\n\n";
					}
				}
			}else if(to.path().extension()==".gch"){
				string gchname=to.path().string();
				string hppname=string(gchname.begin(),gchname.begin()+gchname.size()-4);
				if(!filesystem::exists(hppname))
					filesystem::remove(gchname);
			}
		}
	}
}

int main(int argc,char**argv){
	getline(cin,gcc);
	gcc+=" -x c++-header ";
	rec_compile(filesystem::path("./lib_Clever_Elsie"));
}
