#include <iostream>
#include <vector>
#include <set>
using namespace std;

    int lengthOfLIS(vector<int>& nums) {
        multiset< pair<int,int> > s;
        s.insert({nums[0],1});
        int res = 1;
        for(int i=1; i<nums.size(); i++){
            auto it = s.lower_bound({nums[i],0});
            if(it == s.begin()) s.insert({nums[i],1});
            else {
                
                int currMax = 1;
                cout<<nums[i]<<"->";
                for(auto p = s.begin(); p!=it; p++){
                    currMax = max(currMax,p->second+1);
                    cout<<currMax<<endl;
                }
                s.insert({nums[i],currMax});
                res = max(res,currMax);
                cout<<" max="<<res<<endl;
            }
        }
        return res;
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
    cout<<lengthOfLIS(v);
    return 0;
}
/*
8
10 9 2 5 3 7 101 18
*/