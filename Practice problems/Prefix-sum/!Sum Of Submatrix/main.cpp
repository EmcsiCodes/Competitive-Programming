#include <iostream>
#include <vector>

using namespace std;

void makePresum(vector<vector<int>> matrix, vector<vector<int>> &presum){
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[0].size(); j++){
            presum[i+1][j+1] = presum[i][j+1] + presum[i+1][j] - presum[i][j] + matrix[i][j];
        }
    }
    //print:
    // for(int i=0; i<presum.size(); i++){
    //     for(int j=0; j<presum[0].size(); j++){
    //         cout<<presum[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix(n,vector<int>(m)), presum(n+1,vector<int>(m+1));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>matrix[i][j];
        }
    }
    makePresum(matrix,presum);
    cout<<"Enter submatrix coords: Top-left, bottom-right: ";
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    cout<<"The sum of submatrix is: ";
    int sum = presum[x2+1][y2+1] - presum[x1][y2+1] - presum[x2+1][y1] + 
    presum[x1][y1];
    cout<<sum;
}