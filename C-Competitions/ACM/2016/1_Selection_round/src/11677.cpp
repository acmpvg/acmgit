#include <iostream>
using namespace std;
int main() {
    int h1, m1, h2, m2;
    cin>>h1>>m1>>h2>>m2;

    int p1, p2;
    int ejf = 24*60;

    while(0<(h1+m1+h2+m2)) {
        p1 = h1*60+m1;
        p2 = h2*60+m2;

        if(p2-p1 < 0)
            cout<<(ejf-p1) + p2<<endl;
        else
            cout<<p2-p1<<endl;
        cin>>h1>>m1>>h2>>m2;
    }

    return 0;
}
