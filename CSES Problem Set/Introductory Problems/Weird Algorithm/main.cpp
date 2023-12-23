#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    long long t = n;
    cout<<t<<" ";
    while(t!=1){
        if(t%2 == 1) t = t*3 + 1;
        else t /= 2;
        cout<<t<<" ";
    }
    return 0;
}