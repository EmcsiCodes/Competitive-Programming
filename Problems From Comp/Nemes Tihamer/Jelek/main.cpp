#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin>>n;
    set< vector<int> > s;
    vector<int> v;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    while(!v.empty()){
        s.insert(v);
        auto it = v.begin();
        v.erase(it);
    }
    auto start = s.begin();
    auto end = s.end();
    end--;
    int maxDis = 0;
    auto index = s.begin();
    vector<int> res;
    for(auto curr = start; curr!=end; curr++){
        auto next = curr;
        next++;
        int length = min((*curr).size(), (*next).size());
        int currDis = 0;
        for(int i=0; i<length; i++){
            if((*curr)[i] == (*next)[i]) currDis++;
            else break;
        }
        if(currDis>maxDis){
            maxDis = currDis;
            index = curr;
        }
    }
    if((*index).size() == 0) cout<<-1;
    else {
        for(int i=0; i<maxDis; i++){
            cout<<(*index)[i]<<" ";
        }
    }
    return 0;
}
/*
8 3 1 7 9
8 3 1 7 6 8 3 1 7

*/