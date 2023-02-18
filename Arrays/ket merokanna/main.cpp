#include <iostream>
#include <vector>
using namespace std;

int greatestCommonDiviser(int n,int m){
    if(m==0) return n;
    return greatestCommonDiviser(m, n%m);
}

vector<string> pourBA(int fromCap,int toCap,int d){
    int from = fromCap;
    int to = 0;
    vector<string> res;
    res.push_back("fromFill");
    while(from != d && to != d){
        int pourCap = min(from, toCap - to);
        to += pourCap;
        from -= pourCap;
        res.push_back("fromTo");
        if(from == d || to == d) {
            if(to == d && from != d){
                res.push_back("toClear");
                res.push_back("fromFill");
            }
            break;
        }
        if(from == 0){
            from = fromCap;
            res.push_back("fromFill");
        }
        if(to == toCap){
            to = 0;
            res.push_back("toClear");
        }
    }
    return res;
}

vector<string> pourAB(int fromCap,int toCap,int d){
    int from = fromCap;
    int to = 0;
    vector<string> res;
    res.push_back("fromFill");
    while(from != d && to != d){
        int pourCap = min(from, toCap - to);
        to += pourCap;
        from -= pourCap;
        res.push_back("fromTo");
        if(from == d || to == d) {
            if(from == d && to != d){
                res.push_back("toClear");
                res.push_back("fromFill");
            }
            break;
        }
        if(from == 0){
            from = fromCap;
            res.push_back("fromFill");
        }
        if(to == toCap){
            to = 0;
            res.push_back("toClear");
        }
    }
    return res;
}

void twoJug(int n,int m,int d){
    if((d>n && d>m) || d%greatestCommonDiviser(n,m)!=0) {
        cout<<"NINCS";
        return;
    }
    vector<string> res1, res2, res;
    res1 = pourAB(n,m,d);
    res2 = pourBA(m,n,d);
    if(res1.size() < res2.size()){
        for(auto i:res1){
            if(i == "fromFill"){
                res.push_back("TA");
                continue;
            }
            if(i == "fromTo"){
                res.push_back("AB");
                continue;
            }
            if(i == "toClear"){
                res.push_back("UB");
                continue;
            }
        }
        cout<<res.size()<<'\n';
        for(auto i:res){
            cout<<i<<'\n';
        }
        return;
    } else {
        for(auto i:res2){
            if(i == "fromFill"){
                res.push_back("TB");
                continue;
            }
            if(i == "fromTo"){
                res.push_back("BA");
                continue;
            }
            if(i == "toClear"){
                res.push_back("UA");
                continue;
            }
        }
        cout<<res.size()<<'\n';
        for(auto i:res){
            cout<<i<<'\n';
        }
    }
}

int main()
{
    int d,n,m;
    cin>>d>>n>>m;
    twoJug(n,m,d);
    return 0;
}