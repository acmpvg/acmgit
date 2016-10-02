#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <set>
using namespace std;

const int MAXN = 10008;
const int INF = 100000000;

typedef	struct Edge {
	
	int a,b;
	int w;
} Edge;

typedef struct Becsles {
	
	int csucs;
	int w;
	
	const bool operator< (const Becsles& b) const{
		return w > b.w;
	}
} Becsles;

vector< pair<int,int> >  e[MAXN]; /// Csucs + suly
bool ready[MAXN] = {false};
int mintav[MAXN];
vector<int> honnan[MAXN];

set< pair<int,int> > flowers;

void visszamegy(int csucs) {
	
	if (csucs == 0)
		return;
		
	for (unsigned i = 0; i < honnan[csucs].size(); i++) {
		flowers.insert(make_pair(csucs, honnan[csucs][i]));
		flowers.insert(make_pair(honnan[csucs][i], csucs));
		visszamegy(honnan[csucs][i]);
	}
}

int main() {
	
	//while(1) {}
	int n, m;
	cin>>n;
	
	while (cin.good()) {
		
		cin>>m;
		int x,y,z;
		int total = 0;
		for (int i = 0; i < m; i++) {
			cin >> x >> y >> z;
			
			e[x].push_back( make_pair(y,z) );
			e[y].push_back( make_pair(x,z) );
		}
		
		//memset(ready, false, MAXN*sizeof(bool));
		//memset(mintav, INF, MAXN*sizeof(int));
		
		for (int i = 0; i < n; i++) {
			ready[i] = false;
			mintav[i] = INF;
			honnan[i] = vector<int>();
		}
		
		flowers = set< pair<int,int> >();
		
		/*for (int i=0; i<n; i++) {
			cout << i << "  ";
			for (auto it : e[i]) {
				cout << "(" << it.first << " " << it.second << ") ";
			}
			cout << endl;
		}*/
		
		
		priority_queue< Becsles > pq;
		
		mintav[0] = 0;
		pq.push( {0,0} );
		
		while (!pq.empty()) {
			Becsles p = pq.top();
			pq.pop();
			
			int curr = p.csucs;
			int currw = p.w;
			
			if (ready[curr]) {
				continue;
			}
			
			//mintav[curr] = currw;
			
			for (auto it : e[curr]) {
				
				//cout << "Vizsgal: " << curr << " " << it.first << " " << it.second << endl;
				
				if (!ready[it.first] && currw + it.second < mintav[it.first]) {
					mintav[it.first] = currw + it.second;
					pq.push( {it.first, currw + it.second} );
					honnan[it.first] = vector<int>();
					honnan[it.first].push_back(curr);
					//cout << "push: " << it.first << " " << it.second << endl;
				}
				else if (!ready[it.first] && currw + it.second == mintav[it.first]) {
					honnan[it.first].push_back(curr);
				}
			}
			
			ready[curr] = true;
		}
		
		/*for (int i = 0; i < n; i++) {
			cout << i << " " << mintav[i] << " [";
			for (auto it : honnan[i])
				cout << it << " ";
			cout << "]   " << ready[i] << endl;
		}*/
		
		visszamegy(n-1);
		
		/*cout << "flowers: " << endl;
		for (auto it : flowers) {
				cout << it.first << " " << it.second << endl;
		}
		cout<<"-----"<<endl;*/
		
		for (auto it : flowers) {
			
			int mn = 1<<28;
			for (auto iit : e[it.first]) {
				if (iit.first == it.second && iit.second < mn)
					mn = iit.second;
			}
			//cout << it.first << " " << it.second << " | " << mn << endl;
			for (auto iit : e[it.first]) {
				if (iit.first == it.second && iit.second == mn) 
					total += mn;
			}
		}
		
		cout << total << endl;
		
		
		//cout << "-----------------------------------------" << endl;
		cin>>n;
	}
	
	
	return 0;
}

