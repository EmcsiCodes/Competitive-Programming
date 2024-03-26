#include <iostream>
#include <vector>

using namespace std;

int MaxSubarraySum(vector<int> arr){
    int res = arr[0];
    for(int i=1; i<arr.size(); i++){
        arr[i] = max(arr[i], arr[i-1] + arr[i]);
        res = max(res, arr[i]);
    }
    return res;
}

int MaxSubmatrixSum(vector<vector<int>> matrix){
    int res = 0;
    for(int L = 0; L < matrix[0].size(); L++){
        vector<int> subarr(matrix.size(), 0);
        for(int R = L; R < matrix[0].size(); R++){
            int currsum = 0;
            for(int i = 0; i<matrix.size(); i++){
                subarr[i] += matrix[i][R];
            }
            currsum = MaxSubarraySum(subarr);
            res = max(res, currsum);
        }
    }
    return res;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix(n,vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>matrix[i][j];
        }
    }
    cout<<MaxSubmatrixSum(matrix);
}
/*
4
5
2 1 -3 -4 5
0 6 3 4 1
2 -2 -1 4 -5
-3 3 1 0 3
*/