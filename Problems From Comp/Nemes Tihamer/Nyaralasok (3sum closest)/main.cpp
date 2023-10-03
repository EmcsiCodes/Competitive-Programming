#include <iostream>
#include <vector>

using namespace std;

struct triple{
    int one;
    int two;
    int three;
};
vector<int> v;
int closest = 0;
triple res = {0,0,0};

void threeSumClosest(int n,int k){
    for(int i=0; i<v.size(); i++){
        int r = v.size()-1;
        int l = i+1;
        while(l<r){
            int sum = v[i] + v[l] + v[r];
            if(sum <= k){
                if(closest < sum){
                    closest = sum;
                    res = {i+1,l+1,r+1};
                    
                    if(closest == k) return;
                }
                l++;
            }
            if(sum > k){
                r--;
            }
        }
    }
}

int main()
{
    int n,k;
    cin>>n>>k;
    
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    threeSumClosest(n,k);
    if(closest != 0){
        cout<<res.one<<" "<<res.two<<" "<<res.three;
    } else cout<<-1;
    return 0;
}