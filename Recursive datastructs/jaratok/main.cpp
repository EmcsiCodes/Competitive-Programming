#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> v(2*m+2,0);
    vector<int> index(n+1,0);
    int mid = m;
    v[mid] = 1;
    index[1] = mid;
    int l = mid;
    int r = mid;
    for(int i=1; i<n; i++){
        int x,y;
        char c;
        cin>>x>>c>>y;
        if(c == 'J') {
            v[index[x] + 1] = y;
            r = max(index[x] + 1, r);
            index[y] = index[x] + 1;
        } else {
            v[index[x] - 1] = y;
            l = min(index[x] - 1, l);
            index[y] = index[x] - 1;
        }
    }
    cout<<r - l + 1<<'\n';
    for(int i=l; i<=r; i++){
        cout<<v[i]<<" ";
    }
    return 0;
}
/*
10 9
1 J 2
1 B 3
3 B 6
3 J 5
2 J 4
5 B 7
5 J 8
7 J 10
7 B 9
*/
