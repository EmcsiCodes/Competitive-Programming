#include <iostream>
#include <vector>
using namespace std;
int p;
bool found(int n,vector<int> v){
    int j = 0;
    while(j<v.size()){
        p = v[j];
        bool curr = true;
        for(int i=j; i<=j+n-1; i++){
            if(v[i]!=p){
                curr = false;
                break;
            }
        }
        j += n;
        if(curr) return true;
    }
    return false;
}

int main()
{
    int n,x;
    vector<int> v;
    bool first = true;
    cin>>n>>x;
    v.push_back(x);
    for(int i=1; i<n; i++){
        cin>>x;
        v.push_back(x);
        if(v[i]!=v[i-1]) first = false;
    }
    if(first) cout<<0<<endl<<v[0];
    else{
        int res = 1;
        n=n/2;
        while(!found(n,v)){
            res++;
            n = n / 2;
        }
        cout<<res<<'\n'<<p;        
    }

    return 0;
}