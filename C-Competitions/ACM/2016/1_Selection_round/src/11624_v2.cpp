#include <iostream>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;

char t[1008][1008];

int joetav[1008][1008];
int firetav[1008][1008];

const int inf = 110000000;

int main() {
	
	int test;
	cin>>test;
	
	while (test --> 0) {
		
		int n,m;
		cin>>n>>m;
		
		queue< pair<int,int> > jq;
		queue< pair<int,int> > fq;
		
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++){
				cin >> t[i][j];
				joetav[i][j] = inf;
				firetav[i][j] = inf;
				if (t[i][j] == 'J') {
					jq.push(make_pair(i,j));
					joetav[i][j] = 0;
				}
				if (t[i][j] == 'F') {
					fq.push(make_pair(i,j));
					firetav[i][j] = 0;
				}
				
			}
			
		}
		
		// Joe
		while (!jq.empty()) {
			
			pair<int,int> p = jq.front();
			jq.pop();
			
			int x = p.first, y = p.second;
			
			if (x>0 && joetav[x-1][y] == inf && t[x-1][y] != '#') {
				jq.push(make_pair(x-1, y));
				joetav[x-1][y] = joetav[x][y] + 1;
			}
			if (x<n-1 && joetav[x+1][y] == inf && t[x+1][y] != '#') {
				jq.push(make_pair(x+1, y));
				joetav[x+1][y] = joetav[x][y] + 1;
			}
			if (y<m-1 && joetav[x][y+1] == inf && t[x][y+1] != '#') {
				jq.push(make_pair(x, y+1));
				joetav[x][y+1] = joetav[x][y] + 1;
			}
			if (y>0 && joetav[x][y-1] == inf && t[x][y-1] != '#') {
				jq.push(make_pair(x, y-1));
				joetav[x][y-1] = joetav[x][y] + 1;
			}
		}
		
		/*for (int i=0; i<n; i++) {
			for (int j = 0; j < m; j++){
				cout << joetav[i][j] << " ";
			}
			cout << endl;
		}*/
		
		
		// Fire
		while (!fq.empty()) {
			
			pair<int,int> p = fq.front();
			fq.pop();
			
			int x = p.first, y = p.second;
			
			if (x>0 && firetav[x-1][y] == inf && t[x-1][y] != '#') {
				fq.push(make_pair(x-1, y));
				firetav[x-1][y] = firetav[x][y] + 1;
			}
			if (x<n-1 && firetav[x+1][y] == inf && t[x+1][y] != '#') {
				fq.push(make_pair(x+1, y));
				firetav[x+1][y] = firetav[x][y] + 1;
			}
			if (y<m-1 && firetav[x][y+1] == inf && t[x][y+1] != '#') {
				fq.push(make_pair(x, y+1));
				firetav[x][y+1] = firetav[x][y] + 1;
			}
			if (y>0 && firetav[x][y-1] == inf && t[x][y-1] != '#') {
				fq.push(make_pair(x, y-1));
				firetav[x][y-1] = firetav[x][y] + 1;
			}
		}
		
		/*for (int i=0; i<n; i++) {
			for (int j = 0; j < m; j++){
				cout << firetav[i][j] << " ";
			}
			cout << endl;
		}*/
		
		int minjoe = inf;
		
		for (int i=0; i<n; i++) {
			if (joetav[i][0] < firetav[i][0])
				minjoe = min(minjoe, joetav[i][0]);
			if (joetav[i][m-1] < firetav[i][m-1])
				minjoe = min(minjoe, joetav[i][m-1]);
		}
		for (int j=0; j<m; j++) {
			if (joetav[0][j] < firetav[0][j])
				minjoe = min(minjoe, joetav[0][j]);
			if (joetav[n-1][j] < firetav[n-1][j])
				minjoe = min(minjoe, joetav[n-1][j]);
		}
		
		if (minjoe == inf) {
			cout << "IMPOSSIBLE" << endl;
		}
		else cout << minjoe + 1 << endl;
		
	}
			
		
		
}

