#include <iostream>
#include <vector>

using namespace std;

int LongestIncreasingSubsequenceLength(vector<int> v){
    vector<int> lis;
    lis.push_back(v[0]);
    int l=1;
    for(int i : v){
        auto last=l+lis.begin();
        auto it=lower_bound(lis.begin(),last,i);
        if(it==lis.end()){
            lis.push_back(i);
            l++;
        } else {
            *it=i;
        }
    }
    return l;
}

int main()
{
    int n;
    vector<int> v;
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    cout<<"Longest Increasing Subsqeuence Length is: "<<LongestIncreasingSubsequenceLength(v);
    return 0;
}
