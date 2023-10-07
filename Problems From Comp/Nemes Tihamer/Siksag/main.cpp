#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> v;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    multiset<int> s;
    int l = 0;
    int r = 0;
    int diff = 0;
    pair<int,int> res = {1,1};
    while(r<v.size()){
        s.insert(v[r]);
        if(s.size()>1) diff = *s.rbegin() - *s.begin();
        if(s.size()>1 && diff <= 1 && res.first < r - l + 1){
            res = {r - l + 1,l + 1};
        } else {
            while(diff > 1){
                auto it = s.find(v[l]);
                s.erase(it);
                diff = *s.rbegin() - *s.begin();
                l++;
            }
        }
        r++;
    }
    cout<<res.first<<" "<<res.second;
    return 0;
}
/*
16
2 3 3 4 3 5 5 4 3 3 2 3 2 2 1 3
*/
/*
int time;
int mySanity = 100;

cin >> time;
int daysBeforeProgrammingCompetiton = time;

while(daysBeforeProgrammingCompetiton > 0 && mySanity > 0) {
    solveProblems();
    mySanity--;
    daysBeforeProgrammingCompetiton--;
}

if(mySanity == 0) die;

*/