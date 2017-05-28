#include <iostream>

using namespace std;

long long mod_pow(long long num, long long pow, long long mod) {
   
    long long res = 1;
    long long sq = num%mod;
    
    for(long long bit=0; (1<<bit) <= pow; ++bit) {
        
        if ((1<<bit) & pow) {
            res *= sq;
            res = res%mod;
        }
        
        sq = (sq*sq)%mod;
    }

    return res;
}

int main() {

    cout<<mod_pow(1,64,34)<<endl;
    cout<<mod_pow(2,10,1025)<<endl;
    cout<<mod_pow(3,2,5)<<endl;

    return 0;
}

