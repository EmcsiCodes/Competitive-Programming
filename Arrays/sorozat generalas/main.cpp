#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>
#include<math.h>

using namespace std;

#define LL long long
set< pair<LL,int> > s;
vector < pair<LL,int> > v;
unordered_map<LL,int> umap;

void solve(int m,int x,int a,int b,int n,int k){
    LL h=pow(10,m);
    x=(x*a+b)%(h*h*h)/(h);
    int i=1,si=n;
    while(umap.count(x)==0 && si>0){
        umap[x]=i; i++;
        v.push_back(make_pair(x,1));
        x=(x*a+b)%(h*h*h)/(h);
        si--;
    }
    int first=umap[x];
    int last=i-1;
    int minDis=last-first+1;
    int numatk;
    n=n-last;
    if(k!=0){
        int c=n/minDis;
        int c1=n%minDis;
        for(int i=first; i<=last; i++){
        v[i].second+=c;
        if(i<=c1) v[i].second++;
        }
    }
    for(int i=0; i<last; i++){
        s.insert(make_pair(v[i].first,v[i].second));
    }
    /*for(int i=0; i<v.size(); i++){
        cout<<"("<<v[i].first<<", "<<v[i].second<<") ";
    }
    cout<<endl;*/
    auto index=s.begin();
    while(k>0){
        k-=index->second;
        index++;
    }
    index--;
    numatk=index->first;
    cout<<minDis<<endl<<numatk;
}

int main()
{
    LL m,x,a,b,n,k;
    cin>>m>>x>>a>>b>>n>>k;
    solve(m,x,a,b,n,k);
    return 0;
}
