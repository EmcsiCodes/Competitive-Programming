#include <iostream>
#include <vector>

using namespace std;    

int KadanaMaxSumSubarray(vector<int> arr){
    int res = INT_MIN;
    if(arr.size() == 1) return arr[0];
    for(int i=1; i<arr.size(); i++){
        arr[i] = max(arr[i], arr[i-1] + arr[i]);
        res = max(res,arr[i]);
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
    cout<<KadanaMaxSumSubarray(arr);
}