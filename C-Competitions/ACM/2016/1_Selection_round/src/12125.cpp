#include <iostream>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

#define N 201
#define INF 300

struct MaxFlowMinCut {
	int n;
	int co[N][N];
	int s;
	int t;
	
	//set by init
	int cc[N][N];
	int f[N][N];
	int maxflow;
	
	//set by BFS
	int p[N];
	int flow;
	
	
	void init() {
		maxflow = 0;
		
		for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) {
			cc[i][j] = co[i][j];
			f[i][j] = 0;
		}
	}
	
	void calculate() {
		while(BFS()) {
			maxflow+=flow;
			int curr = t;
			int par;
			while(curr!=s) {
				par=p[curr];
				cc[par][curr] = cc[par][curr]-flow;
				cc[curr][par] = cc[curr][par] + flow;
				f[par][curr] = f[par][curr]+flow;
				
				curr = par;
			}
		}
	}
	
	bool BFS() {
		int m[n];
		
		for(int i=0; i<n; ++i) {
			p[i]=-1;
			m[i]=0;
			
		}
		
		m[s] = -2;
		p[s] = -2;
		
		queue<int> frontier;
		
		frontier.push(s);
		int curr;
		while(!frontier.empty()) {
			curr = frontier.front();
			frontier.pop();
			
			for(int i=0; i<n; ++i) if(cc[curr][i]>0 && p[i] == -1) {
				p[i] = curr;
				m[i] = (m[curr] == -2) ? cc[curr][i] : min(cc[curr][i], m[curr]);
				
				if(i==t) {
					flow = m[t];
					return true;
				} else {
					frontier.push(i);
				}
				
			}
		}
		
		flow = 0;
		return false;
	}
};

int main() {
	int t;
	cin >> t;
	
	MaxFlowMinCut mfmc;
	int n;
	double d;
	int penguinnumber;
	
	
	for(int currcase = 0; currcase<t; ++currcase) {
		
		memset(mfmc.co, 0, sizeof(mfmc.co));
		
		cin>>n>>d;
		mfmc.n = 2*n+1;
		int supersource = 2*n;
		
		int penguins[n];
		int strength[n];
		int coords[n][2];
		
		
		penguinnumber = 0;
		for(int i=0; i<n; ++i) {
			cin>>coords[i][0]>>coords[i][1]>>penguins[i]>>strength[i];
			
			penguinnumber += penguins[i];
			
			mfmc.co[supersource][2*i]  = penguins[i];
			mfmc.co[2*i][2*i+1] = strength[i];
			
		}
		
		for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) {
			
			if(((coords[i][0]-coords[j][0])*(coords[i][0]-coords[j][0]) + (coords[i][1]-coords[j][1])*(coords[i][1]-coords[j][1])) <= d*d) {
				mfmc.co[2*i+1][2*j] = INF;
				mfmc.co[2*j+1][2*i] = INF;
			}
		}
		
		bool written = false;
		
		for(int target = 0; target<n; target++) {
				mfmc.s = supersource;
				mfmc.t = 2*target;
				
				mfmc.init();
				mfmc.calculate();
				
				if(mfmc.maxflow == penguinnumber) {
					if(written) cout<<' ';
					cout<<target;
					written = true;
				}
		}
		if(!written) cout<<-1;
		cout<<endl;
	}
	
	return 0;
}
