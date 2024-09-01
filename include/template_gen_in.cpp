#include<fstream>
#include<random>
using namespace std;
int main(){
	ofstream ofs("/dev/shm/in");
	random_device seed;
	mt19937_64 gen(seed());
	int n;
	for(int i=0;i<n;i++)
}