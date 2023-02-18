#include <iostream>

using namespace std;
int k,a[501];

void dleft(string &s){
    s = s + "0";
}

void dright(string &s){
    s = s + "1";
}

void up(string &s){
    s.pop_back();
}

void left(string &s){
    string p="";
    while(s.back()=='0'){
        p = p + "1";
        s.pop_back();
    }
    s[s.length()-1]='0';
    s = s + p;
}

void right(string &s){
    string p="";
    while(s.back()=='1'){
        p = p + "0";
        s.pop_back();
    }
    s[s.length()-1]='1';
    s = s + p;
}

void solve(int sor,string s){
    cin>>k;
    for(int i=1; i<=k; i++){
        cin>>a[i];
    }
    for(int i=1; i<=k; i++){
        if(a[i]==0){
            dleft(s);
            sor++;
            continue;
        }
        if(a[i]==1){
            dright(s);
            sor++;
            continue;
        }
        if(a[i]==2){
            up(s);
            sor--;
            continue;
        }
        if(a[i]==3){
            left(s);
            continue;
        }
        if(a[i]==4){
            right(s);
            continue;
        }
    }
    while(s.front()=='0') s.erase(0,1);
    if(s=="") s = "0";
    cout<<sor<<"\n"<<s;
}

int main()
{
    /*
6
0 1 4 2 1 0
    */
    int sor=0;
    string s="0";
    solve(sor,s);
    return 0;
}
