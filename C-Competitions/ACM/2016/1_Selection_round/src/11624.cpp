#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

char t[1008][1008];
char uj[1008][1008];

int main() {
	
	int test;
	cin>>test;
	
	while (test --> 0) {
		
		int n,m;
		cin>>n>>m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++){
				cin >> t[i][j];
			}
		}
		
		bool ok = true;
		for (int i = 0; i < n && ok; i++){
			if( t[i][0] == 'J' || t[i][m-1] == 'J' ){
				cout<<1<<endl;
				ok = false;
			}
		}
		
		for (int i = 0; i < m && ok; i++){
			if( t[0][i] == 'J' || t[n-1][i] == 'J' ){
				cout<<1<<endl;
				ok = false;
			}
		}
		
		
		int step = 1;
		while (ok) {
			int joecnt = 0;
			for (int i = 0; i < n; i++){
				for (int j = 0; j < m; j++){
					if (t[i][j] == '#')
						uj[i][j] = '#';
					else if (t[i][j] == 'F') {
						uj[i][j] = 'F';
					}
					else if ((i>0 && t[i-1][j] == 'F' ) || (i<n-1 && t[i+1][j] == 'F') || 
							 (j>0 && t[i][j-1] == 'F' ) || (j<m-1 && t[i][j+1] == 'F')) {
						uj[i][j] = 'F';
					}
					else if ((i>0 && t[i-1][j] == 'J' ) || (i<n-1 && t[i+1][j] == 'J') || 
							 (j>0 && t[i][j-1] == 'J' ) || (j<m-1 && t[i][j+1] == 'J')) {
						uj[i][j] = 'J';
						joecnt++;
						
						if (i == 0 || j == 0 || i == n-1 || j == m-1) {
							// Kijutott
							cout << step+1 << endl;
							//cout << "KIJUtott..................." << endl;
							ok = false;
							i = n+1;
							j = m+1;
						}
					}
					else {
						uj[i][j] = '.';
					}
					
					
				}
				
			}
			
			
			//if (memcmp(t, uj, n*m*sizeof(char)) == 0 || joecnt == 0) {
			bool azonos = true;
			for (int i = 0; i < n && azonos; i++){
				for (int j = 0; j < m && azonos; j++){
					if (t[i][j] != uj[i][j])
						azonos = false;
				}
				
				
			}
			
			if (azonos || joecnt == 0) {
			
				cout << "IMPOSSIBLE" << endl;
				ok = false;
			}
			
			
			cout << "Step: " << step << endl;
			
			cout << "t: " << endl;
			for (int i=0; i<n; i++) {
				for (int j = 0; j < m; j++){
					cout << t[i][j];
				}
				cout << endl;
				
			}
			
			
			cout << "uj: " << endl;
			for (int i=0; i<n; i++) {
				for (int j = 0; j < m; j++){
					cout << uj[i][j];
				}
				cout << endl;
				
			}
			
			
			//memcpy(t, uj, n*m*sizeof(char));
			for (int i = 0; i < n; i++){
				for (int j = 0; j < m; j++){
					t[i][j] = uj[i][j];
				}
				
			}
			
			
			
			step++;
		}
		
		
	}	
}
