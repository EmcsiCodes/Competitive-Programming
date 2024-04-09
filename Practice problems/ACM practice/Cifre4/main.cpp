#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool valid(long long n){
    while(n > 0){
        if(n%10 != 2 && n%10 != 3 && n%10 != 5 && n%10 != 7) return false;
        n /= 10;
    }
    return true;
}

long long findNum(long long n,long long p){
    long long k = 0;
    while(k*p + n < 10000000000000){
        if(valid(k*p + n)) return k*p + n;
        k++;
    }
    return -1;
}

int main(){
    ifstream in("cifre4.in");
    ofstream out("cifre4.out");
    int TestNum;
    in>>TestNum;
    for(int i=0; i<TestNum; i++){
        long long n,p;
        in>>n>>p;
        out<<findNum(n,p)<<'\n';
    }
    return 0;
}