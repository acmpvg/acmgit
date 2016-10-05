#include <iostream>
#include <cstring>
using namespace std;

int scores[40];
int dp[2][40000];

int main () {
	int t;
	cin>>t;
	
	int n;
	int maxscore;
	float p;
	
	for(int testcase = 0; testcase<t; ++testcase) {
		
		cin>>n;
		cin>>p;
		
		maxscore = 0;
		for(int i=0; i<n; ++i) {
			cin>>scores[i];
			maxscore+=scores[i];
		}
		
		//First row.
		dp[0][0] = 1;
		dp[0][scores[0]] = 1;
		
		//for(int j=0; j<=maxscore; ++j) {
		//	cout<<dp[0][j]<<' ';
		//}
		//
		//cout<<endl;
		
		//Other rows.
		for(int i=1; i<n; ++i) {
			for(int j=0; j<=maxscore; ++j) {
		
			dp[i%2][j] = dp[(i-1)%2][j];
			if(scores[i]<=j) dp[i%2][j] += dp[(i-1)%2][j-scores[i]];
			
			//cout<<dp[i%2][j]<<' ';
		
			}
			
			//cout<<endl;
		}
		
		long long allcases = 0;
		for(int j=0; j<=maxscore; ++j) {
			allcases += dp[(n-1)%2][j];
		}
		
		long long goodcases = 0;
		for(int j=0; j<=maxscore; ++j) {
			goodcases += dp[(n-1)%2][j];
			if(p*allcases < goodcases) {
				cout<<j<<endl;
				break;
			}
		}
		
		memset(scores,0,sizeof(scores));
		memset(dp,0,sizeof(dp));
	}
	
	return 0;
}
