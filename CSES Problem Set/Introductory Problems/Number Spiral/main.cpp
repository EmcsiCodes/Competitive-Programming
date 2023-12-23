#include <iostream>
using namespace std;

int main()
{
    int test;
    cin>>test;
    for(int i=0; i<test; i++){
        long long x,y;
        long long res;
        cin>>x>>y;
        if(y>=x){
            res = (long long)((long long)(y - !(y%2))*(y - !(y%2)) + (long long)(y%2 == 1 ? (-1)*x + 1 : x));
        } else {
            res = (long long)((long long)(x - x%2)*(x - x%2) + (long long)(x%2 == 1 ? y - 1: (-1)*y) + 1);
        }
        cout<<res<<endl;
    }
    return 0;
}