#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;

int main() {
	
	int a,b;
	cin>>a;
	while (cin.good()) {
		cin>>b;
		cout<<max(a,b)<<endl;
		
		
		
		cin>>a;
	}
	return 0;
}
