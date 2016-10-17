#include<iostream>
using namespace std;

class Die{
	int t,b,n,e,w,s;
	int tt,bb,nn,ee,ww,ss;
	
public:
	void print(){
		cout<<t<<endl;
	}
	void init(){
		t=1;
		n=2;
		w=3;
		b=6;
		s=5;
		e=4;
	}
	void north(){
		tt=s; nn=t; bb=n; ss=b;
		t=tt; n=nn; b=bb; s=ss;
	}
	void south(){
		tt=n; nn=b; bb=s; ss=t;
		t=tt; n=nn; b=bb; s=ss;
	}
	void east(){
		tt=w; ww=b; bb=e; ee=t;
		t=tt; w=ww; b=bb; e=ee;
	}
	void west(){
		tt=e; ww=t; bb=w; ee=b;
		t=tt; w=ww; b=bb; e=ee;
	}
};

int main(){
	
	int t;
	string s;
	Die die;
	cin>>t;
	while(t){
		die.init();
		for(int i=0; i<t; ++i){
			cin>>s;
			if(s=="north")die.north();
			if(s=="west") die.west();
			if(s=="east") die.east();
			if(s=="south") die.south();
		} 
		die.print();
		cin>>t;
	}
	return 0;
}
