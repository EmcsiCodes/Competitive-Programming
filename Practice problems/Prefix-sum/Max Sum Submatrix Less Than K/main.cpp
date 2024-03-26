#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map> 

using namespace std;

class Solution {
public:

    int maxSumSubarray(vector<int> arr, int k){
        int res = INT_MIN;
        int sum = 0;
        set<int> s;
        s.insert(0);
        for(int i=0; i<arr.size(); i++){
            sum += arr[i];
            auto it = s.lower_bound(sum - k);
            if(it != s.end()) res = max(res, sum - *it);
            s.insert(sum);
        }
        return res;
    }

    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int res = INT_MIN;
        for(int L = 0; L < matrix[0].size(); L++){
            vector<int> subarr(matrix.size(), 0);
            for(int R = L; R < matrix[0].size(); R++){
                for(int i = 0; i<matrix.size(); i++){
                    subarr[i] += matrix[i][R];
                }
                res = max(res, maxSumSubarray(subarr,k));
            }
        }
        return res;
    }

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> matrix(n,vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>matrix[i][j];
        }
    }
    return 0;
}