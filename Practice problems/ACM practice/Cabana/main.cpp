#include <iostream>
#include <fstream>
using namespace std;

#define LL long long
#define mod 1000000007
int TestNum;
LL n, k;
LL factor[1000001];
LL stirling[1000001];

void precalc(){
    factor[0] = 1;
    for(int i=1; i<=1000000; i++) {
        factor[i] = factor[i - 1] * i % mod;
        stirling[i] = stirling[]
    }
}

LL fast_pow(long long base, long long power) {
    long long result = 1;
    while(power > 0) {

        if(power % 2 == 1) {
            result = (result*base) % mod;
        }
        base = (base * base) % mod;
        power = power / 2;
    }
    return result;
}
int main(){ 
    precalc();
    ifstream in("cabana.in");
    ofstream out("cabana.out");
    in>>TestNum;
    for(int i=0; i<TestNum; i++){
        in>>n>>k;
        out<<(fast_pow(factor[k],n/k) * factor[k]/factor[k - n%k]) % mod<<'\n';
    }
}