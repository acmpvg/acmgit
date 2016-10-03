#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	
	int c, n, m;
	string code;
	cin>>c;
	
	
	while (1) {}
	
	for(int i=0; i<c; ++i) {
		cin>>n>>m;
		int tmp = max(n,m);
		n = min(n,m);
		m = tmp;
		
		cin>>code;
		for(int j=0; j<n; ++j) {
				cout<<code.substr(j*m, m);
				if(!(j==n-1 && i==c-1)) cout<<endl;
		}
	}
	return 0;
}

