#include <iostream>
#include <deque>

using namespace std;

void lefedes(int h,int n,int k,pair<int,int>a[],deque< pair<int,int> >v){
    int best=a[1].second,i=2;
    v.push_back(make_pair(a[1].first,a[1].second));
    //unordered map hogy megkeressuk az utolso jo elemet
    //double ended queue (deque)
    if(a[1].first>0 || a[n].first+k<h){
        cout<<0;
        return;
    }
    if(n==1) {
        cout<<best;
        return;
    }
    while(!v.empty() && i<=n){
        for(const auto &it : v){
            //cout<<"("<<it.first<<" "<<it.second<<"), ";
        }
    //cout<<"--->>> ";
        while(!v.empty() && a[i].first>=v.front().first+k){
            if(v.size()==1 && a[i].first!=v.front().first+k){
                cout<<0;
                return;
            }
            best = min(best,v.front().second);
            v.pop_front();
        }
        if(!v.empty()) best = min(best,v.front().second);
        while(!v.empty() && a[i].second>=v.back().second){
            v.pop_back();
        }
        v.push_back(make_pair(a[i].first,a[i].second));
        i++;
        for(const auto &it : v){
            //cout<<"("<<it.first<<" "<<it.second<<"), ";
        }
        //cout<<"best: "<<best<<endl;
    }
    best = min(best,v.back().second);
    cout<<best;
}

int main()
{
    int h,n,k;
    pair<int,int>a[100001];
    cin>>h>>n>>k;
    for(int i=1; i<=n; i++){
        cin>>a[i].first>>a[i].second;
    }
    deque< pair<int,int> >v;
    lefedes(h,n,k,a,v);
    return 0;
}
/*
18 10 3
0 2
3 1
4 3
5 5
6 2
8 1
10 4
11 2
12 1
15 3

11 4 5
0 5
2 3
3 2
6 4

7 5 3
0 2
1 3
2 4
3 5
4 6

7 4 5
0 3
2 3
3 3
4 3
*/
