#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct in{
    int n;
    char bolygo;
    char c;
};

struct Compare{
    bool operator()(in const& p1,in const& p2){
        if(p1.n == p2.n) return p1.c<p2.c;
        return p1.n<p2.n;
    }
};

int main()
{
    int a,b;
    cin>>a>>b;
    vector<in> v;
    for(int i=1; i<=a; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,'a','x'});
        v.push_back({y,'a','y'});
    }
    for(int i=1; i<=b; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,'b','x'});
        v.push_back({y,'b','y'});
    }
    sort(v.begin(),v.end(),Compare());
    bool A = false;
    bool B = false;
    vector<int> start;
    vector<int> end;
    for(int i=0; i<v.size(); i++){
        if(v[i].c == 'x' && v[i].bolygo == 'a') {
            A = true;
            if(!B) start.push_back(v[i].n);
            else end.push_back(v[i].n - 1);
        }
        if(v[i].c == 'x' && v[i].bolygo == 'b') {
            //Bstart = v[i].n;
            B = true;
            if(!A) start.push_back(v[i].n);
            else end.push_back(v[i].n - 1);
        }
        if(v[i].c == 'y' && v[i].bolygo == 'a') {
            //Aend = v[i].n;
            A = false;
            if(B) start.push_back(v[i].n + 1);
            else end.push_back(v[i].n);
        }
        if(v[i].c == 'y' && v[i].bolygo == 'b') {
            //Bend = v[i].n;
            B = false;
            if(A) start.push_back(v[i].n + 1);
            else end.push_back(v[i].n);
        }
        if(!start.empty() && !end.empty() &&
        start.back() - 1 == end.back()) {
            start.pop_back();
            end.pop_back();
        }
        cout<<v[i].n<<":"<<A<<" "<<B<<endl;
        //if(A && !B) 
    }
    cout<<start.size()<<'\n';
    for(int i=0; i<start.size(); i++){
        cout<<start[i]<<" "<<end[i]<<'\n';
    }
    return 0;
}
/*
2 2
1 5
12 14
3 10
15 18
*/