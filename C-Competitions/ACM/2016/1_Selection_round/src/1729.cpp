#include <iostream>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#define inf 100000000



int main() {
	
	int test;
	cin>>test;
	
	char buf[100008];
	
	for (int t=1; t<=test; t++) {
		
		scanf("%s", buf);
		
		int len = strlen(buf);
		
		map<char,int> m;
		
		for (int i = 0; i < len; i++){
			m[ buf[i] ] ++;
		}
		
		int minc=inf;
		for(char c='a'; c<='z'; ++c){ 
			minc = min( m [c] , minc );
		}
		
			cout<<"Case "<<t<<": "<<minc<<endl;
		
		
	}
	return 0;
}
