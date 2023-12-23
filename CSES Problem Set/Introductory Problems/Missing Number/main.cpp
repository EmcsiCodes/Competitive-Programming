#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<bool> v(n+1,false);
    v[0] = true;
    for(int i=0; i<n-1; i++){
        int x;
        cin>>x;
        v[x] = true;
    }
    for(int i=0; i<=n; i++){
        if(v[i] == false) {
            cout<<i;
        }
    }
    return 0;
}