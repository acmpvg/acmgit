#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

#define INF 10000000

int main()
{
	string be;
	cin>>be;
	while(be.compare("*")!=0){
		int n = atoi(be.c_str());
		int c[n+1][2];
		int kx, ky;
		cin>>kx>>ky;
		for (int i = 0; i < n; i++){
			cin>>c[i][0]>>c[i][1];
		}
		c[n][0]=c[0][0];
		c[n][1]=c[0][1];
		
		double mintav=INF;
		for (int i = 0; i < n; i++){
			double ax = c[i][0];
			double bx = c[i+1][0];
			double ay = c[i][1];
			double by = c[i+1][1];
			double nx = by-ay;
			double ny = ax-bx;
			double c = -nx*ax -ny*ay;
			double dist = abs(nx*kx + ny*ky + c) / (sqrt(nx*nx+ny*ny));
			
			double dista = ((ax-kx)*(ax-kx) + (ay-ky)*(ay-ky));
			double distb = ((bx-kx)*(bx-kx) + (by-ky)*(by-ky));
			
			double distab = ((ax-bx)*(ax-bx) + (ay-by)*(ay-by));
			
			if( distab + dista < distb || distab + distb < dista ) mintav = min(min( sqrt(dista) , sqrt(distb) ), mintav);
			else mintav = min( dist, mintav);
			//cout<<mintav<<endl;
		}
		
		printf("%.3f\n",mintav);
		
		//---
		cin>>be;
	}
	return 0;
	
}
