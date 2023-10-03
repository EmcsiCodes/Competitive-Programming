#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

struct ans{
    int i;
    int peopleInd;
    int day;
};

int main()
{
    int n;
    cin>>n;
    vector< pair<int,int> > v;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        v.push_back({x,i});
    }
    sort(v.begin(),v.end());
    multiset< pair<int,int> > people;
    vector<ans> res;
    people.insert({1,1});
    for(int i=0; i<v.size(); i++){
        auto curr = people.begin();
        if(v[i].first >= curr->first){
            res.push_back({v[i].second,curr->second,curr->first});
            people.erase(curr);
            people.insert({curr->first+1,curr->second});
        } else {
            int peopleNum = people.size() + 1;
            res.push_back({v[i].second,peopleNum,1});
            people.insert({2,people.size()+1});
        }
    } 
    cout<<people.size()<<'\n';
    for(auto i:res) cout<<i.i<<" "<<i.peopleInd<<" "<<i.day<<'\n';
    return 0;
}
/*
7
1
2
1
3
2
2
3
*/