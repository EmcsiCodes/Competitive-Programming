#include <iostream>
#include <vector>

using namespace std;

    int coordx[8] = {-2,-1,1,2,2,1,-1,-2};
    int coordy[8] = {1,2,2,1,-1,-2,-2,-1};

    bool checkValidGrid(vector<vector<int>>& grid) {
        int i = 0;
        int j = 0;
        int curr = 0;
        int n = grid.size();
        bool valid = true;
        while(valid){
            valid = false;
            for(int i=0; i<=7; i++){
                int x = i + coordx[i];
                int y = j + coordy[i];
                cout<<i<<"+"<<coordx[i]<<" es "<<j<<"+"<<coordy[i]<<endl;
                if(x<n && x>=0 && y<n && y>=0 && grid[x][y] == curr + 1){
                    cout<<"<-";
                    valid = true;
                    i = x;
                    j = y;
                    curr++;
                    break;
                }
            }
        }
        cout<<curr+1<<endl;
        if(curr+1 == n*n) return true;
        return false;
    }

int main()
{
    int n;
    cin>>n;
    vector<vector<int>>grid(n,vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>grid[i][j];
        }
    }
    checkValidGrid(grid);
    return 0;
}
/*5
0 11 16 5 20
 17 4 19 10 15
 12 1 8 21 6
 3 18 23 14 9 24
13 2 7 22
*/