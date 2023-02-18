#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int n,p;
    cin>>n>>p;
    vector< vector<int> > v;
    for(int i=0; i<p; i++){
        vector<int> curr;
        for(int j=0; j<n; j++){
            int x;
            cin>>x;
            curr.push_back(x);
        }
        v.push_back(curr);
    }
    map<pair<int,int>, pair<int,int >> m;
    for(int i=0; i<v.size(); i++){
        pair<int,int> pairs={v[i][0],i};
        m[pairs]={i,0};
    }

    pair<int,int> best,pairs;
    pairs = m.begin()->first;
    best.first = pairs.first;
    pairs = m.rbegin()->first;
    best.second = pairs.first;

    while(true){
        bool isLegal = false;
        pair<int,int> index, pairs;
        for(auto k = m.begin(); k!=m.end(); k++){
            index = k->second;
            if(index.second + 1 < n){
                isLegal = true;
                break;
            }
        }
        if(!isLegal) break;
        else {
            //cout<<"toroljuk:"<<v[index.first][index.second]<<", uj elem:"<<v[index.first][index.second+1]<<endl;
            pairs = {v[index.first][index.second],index.first};
            m.erase(pairs);
            pairs = {v[index.first][index.second + 1],index.first};
            m[pairs] = {index.first,index.second + 1};

            pairs = m.rbegin()->first;
            int newDiff = pairs.first;
            pairs = m.begin()->first;
            newDiff -= pairs.first;
            int bestDiff = best.second - best.first;
            if(newDiff < bestDiff) {
            pairs = m.begin()->first;
            best.first = pairs.first;
            pairs = m.rbegin()->first;
            best.second = pairs.first;
            }            
        }
    }
    cout<<best.first<<" "<<best.second;
    return 0;
}