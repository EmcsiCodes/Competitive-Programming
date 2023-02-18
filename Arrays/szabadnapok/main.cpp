//ez nem a leghatekonyabb megoldas.
//lehet ehhez hasznalni trie-okat hogy hatekonyabb legyen

#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>
using namespace std;

int main()
{
    int n,m;
    unordered_map < set<int>, int > occurDays;
    set< set<int> > days, sol;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        int size;
        cin>>size;
        set<int> currSet;
        for(int j=0; j<size; j++){
            int x;
            cin>>x;
            currSet.insert(x);
        }
        if(occurDays.find(currSet)==occurDays.end()){
            occurDays[currSet] = 1;
        } else occurDays[currSet]++;
    }
    for(auto i:occurDays){
        if(i.second==1){
            days.insert(i.first);
        }
    }
    
    auto p = prev(days.end());
    sol.insert(*p);
    for(auto s=days.rbegin(); s!=days.rend(); s++){
        set<int> curr = *s;
        for(auto p=sol.begin(); p!=sol.end(); p++){
            set<int> cont = *p;
            if(!includes(cont.begin(), cont.end(), curr.begin(), curr.end())){
                sol.insert(curr);
                break;
            }
        }
    }
    cout<<sol.size();
    return 0;
}