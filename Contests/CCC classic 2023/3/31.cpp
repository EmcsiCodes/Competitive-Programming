#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <map>
#include <fstream>

using namespace std;
#define inf 100000000

int main()
{
    ifstream f("level3_5.in");
    ofstream g("level3_5.out");
    int n;
    f>>n;

    for(int i=0; i<n; i++){
        string s;
        int a,b;
        f>>b>>a;
        int valid[100][100];
        //g<<a<<" "<<b<<endl;
        for(int ii=0;ii<a;ii++)
        {
            for(int jj=0;jj<b;jj++)
            {
                char c;
                f>>c;
                if(c == '.') valid[ii][jj] = 0;
                else valid[ii][jj] = 1;
            }
        }
        f>>s;
        int x,y;
        x=y=0;
        int maxup, maxdown, maxleft, maxright;
        maxup = 0;
        maxright = 0;
        maxleft = 0;
        maxdown = 0;
        for(int j=0;j<s.length();j++)
        {
            if(s[j] == 'W') x++;
            if(s[j] == 'S') x--;
            if(s[j] == 'A') y--;
            if(s[j] == 'D')  y++;
            maxup = max(maxup, x);
            maxdown = min(maxdown, x);
            maxright = max(maxright, y);
            maxleft = min(maxleft, y);
        }
        int iy = -maxleft;
        int ix = maxup;
        bool val = true;
        //g<<ix<<":"<<iy<<endl;
        if(ix<0 || ix>=a) {
            val = false;
            ix = 0;
        }
        if(iy<0 || iy>=b){
            val = false;
            iy = 0;
        }
        if(valid[ix][iy] == 1) {
            val = false;
        }
        valid[ix][iy] = 1;
        
        for(int j=0; val == true && j<s.length(); j++){
            if(s[j] == 'W'){
                ix--;
            }
            if(s[j] == 'S'){
                ix++;
            }
            if(s[j] == 'A'){
                iy--;
            }
            if(s[j] == 'D'){
                iy++;
            }   
            if(valid[ix][iy] == 1) {
                //g<<valid[ix][iy]<<": "<<ix<<" "<<iy<<endl;
                val = false;
                break;
            }
            valid[ix][iy] = 1;
        }
        for(int ii=0;val == true && ii<a;ii++)
        {
            for(int jj=0;jj<b;jj++)
            {
                if(valid[ii][jj] == 0) {
                    //g<<"err3 "<<ii<<" "<<jj<<endl;
                    val = false;
                }
            }
        }
        if(val){
            g<<"VALID"<<endl;
        } else g<<"INVALID"<<endl;
    }   
    return 0;
}