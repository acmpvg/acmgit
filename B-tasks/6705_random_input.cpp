#include <iostream>
#include <ctime>
using namespace std;
int main () {
	srand(time(NULL));
	cout<<"10"<<endl;
	for(int i=0; i<10; ++i) {
		cout<<"40 0.9"<<endl;
		for(int i=0; i<40; ++i) cout<<rand()%1000+1<<" ";
		cout<<endl;
	}
	return 0;
}
