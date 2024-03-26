#include <iostream>
#include <vector>
#include <set>

using namespace std;

int MaxSumSubarrLessThanK(vector<int> arr, int k){
    int res = INT_MIN;
    vector<int> presum(arr.size()+1,0);
    for(int i=0; i<arr.size(); i++){
        presum[i+1] = presum[i] + arr[i];
    }
    //after finding presum, we ned to find two indices s.t. the subarray between is less than k
    set<int> s;
    s.insert(0);
    for(int i=1; i<presum.size(); i++){
        auto it = s.lower_bound(presum[i] - k);
        if(it!=s.end()){
            res = max(res,presum[i] - *it);
        }
        s.insert(presum[i]);
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    cout<<MaxSumSubarrLessThanK(arr,k);
    return 0;
}
/*
5
5 -2 6 3 -5
9
*/