#include <crow.h>
#include <vector>
#include <cstdint>
#include <cstdlib>
#include <fstream>
#include <filesystem>
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
crow::response sample_register(const crow::request&req){
	//{"id":id,"sample_in":data}
	auto data = crow::json::load(req.body);
	vector<string>rm_files;
	for(auto file:filesystem::directory_iterator("/dev/shm")){
		string name=file.path().string();
		if(name.ends_with(".in"))
			rm_files.push_back(name);
	}
	for(auto file:rm_files)
		filesystem::remove(file);
	for(const auto& item:data){
		if(!item.has("id")||!item.has("sample_in")) return crow::response(400,"Missing required fields");
		int64_t id=item["id"].i();
		string sample_in=item["sample_in"].s();
		string file=string("/dev/shm/")+to_string(id)+string(".in");
		ofstream ofs(file);
		ofs<<sample_in<<endl;
	}
	return crow::response(200);
}
