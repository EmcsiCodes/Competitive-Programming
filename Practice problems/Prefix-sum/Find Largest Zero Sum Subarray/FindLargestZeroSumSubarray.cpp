/*
Given an array,
find the largest subarray, where the sum of the elements is 0.
Return the start index and the length of the subarray.

Example:
Input: v = [1,2,-3,3,1]
Output: 0,3

 
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> findLargestZeroSumSubarray(vector <int> &v){
    vector<int> presum(v.size() + 1,0);
    vector<int> res(2,0);
    for(int i=0; i<v.size(); i++){
        presum[i+1] = v[i] + presum[i];
        if(v[i] == 0) {
            res = {i,1};
        }
    }
    unordered_map<int, vector<int> > m;
    for(int i=0; i<presum.size(); i++){
        if(m[presum[i]].size() == 2){
            m[presum[i]][0] = min(m[presum[i]][0],i);
            m[presum[i]][1] = max(m[presum[i]][1],i);
        } else m[presum[i]].push_back(i);
    }
    for(auto i:m){
        if(i.second.size() == 2 && i.second[1] - i.second[0]> res[1]){
            res = {i.second[0], i.second[1] - i.second[0]};
        }
    }
    return res;
}

int main(){
    vector<int> v;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    vector<int> answer = findLargestZeroSumSubarray(v);
    cout<<"\n[";
    for(int i:answer){
        cout<<i<<",";
    }
    cout<<"\b]\n";
}