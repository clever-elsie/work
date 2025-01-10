#include <crow.h>
#include <vector>
#include <cstdint>
#include <cstdlib>
#include <fstream>
#include <filesystem>
#include <string>
using namespace std;

crow::response sample_register(const crow::request&);

int main(){
	crow::SimpleApp app;
	app.port(3000);
	CROW_ROUTE(app, "/conpro/sample_register")
			.methods(crow::HTTPMethod::POST)(sample_register);
	app.run();
}

#include<iostream>
void rm_files_with_suffix(const string&,const string&);

crow::response sample_register(const crow::request&req){
	//{"id":id,"sample_in":data}
	auto data = crow::json::load(req.body);
	rm_files_with_suffix(string("/dev/shm"),string(".in"));
	for(const auto& item:data){
		if(!item.has("id")||!item.has("sample_in")) return crow::response(400,"Missing required fields");
		string sample_in=item["sample_in"].s();
		int64_t id=item["id"].i();
		if(id==-1ll){
			string file("/dev/shm/url");
			ofstream ofs(file);
			ofs<<sample_in<<endl;
			ofs.close();
			const char command[]="./venv/bin/python3 ./reg_sample.py";
			int _ = system(command);
			if(_) return crow::response(500,"Failed on url requests");
		}else{
			string file=string("/dev/shm/")+to_string(id)+string(".in");
			ofstream ofs(file);
			ofs<<sample_in<<endl;
		}
	}
	return crow::response(200);
}

void rm_files_with_suffix(const string&dir,const string&ext){
	vector<string>rm_files;
	for(auto file:filesystem::directory_iterator(dir)){
		string name=file.path().string();
		if(name.ends_with(ext))
			rm_files.push_back(name);
	}
	for(auto file:rm_files)
		filesystem::remove(file);
}