#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int MaxSumSubmatrix(vector<vector<int>>v){
    int maxSum = 0;
    for(int l = 0; l < v.size(); l++){
        vector<int> currArray(v.size(),0);
        for(int r = l; r < v.size(); r++){
            int currSum = -1;
            int nextSum = 0;
            for(int i = 0; i < v.size(); i++){
                currArray[i] += v[r][i];
                nextSum = nextSum + currArray[i] >= 0 ? nextSum + currArray[i] : 0;
                currSum = max(currSum, nextSum);
            }
            maxSum = max(maxSum, currSum);
        }
    }
    return maxSum;
}

int main()
{
    ifstream in("vladut.in");
    ofstream out("vladut.out");
    int testCases;
    in>>testCases;
    for(int testNum = 1; testNum <= testCases; testNum++){
        int n;
        in>>n;
        vector<vector<int>>v(n,vector<int>(n));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                in>>v[i][j];
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int x;
                in>>x;
                v[i][j] -= x;
            }
        }
        out<<testNum<<':'<<MaxSumSubmatrix(v)<<'\n';
    }
    return 0;
}