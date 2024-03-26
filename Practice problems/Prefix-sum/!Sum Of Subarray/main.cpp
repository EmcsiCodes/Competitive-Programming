#include <iostream>
#include <vector>

using namespace std;

void makePresum(vector<int> arr, vector<int> &presum){
    for(int i=0; i<arr.size(); i++){
        presum[i+1] = presum[i] + arr[i];
    }
} 

int main(){
    int n;
    cin>>n;
    vector<int> arr(n), presum(n+1,0);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    makePresum(arr,presum);
    int a,b;
    cout<<"Enter the interval in the array: ";
    cin>>a>>b;
    cout<<"The sum in the interval is: "<<presum[b+1] - presum[a];
    return 0;
}