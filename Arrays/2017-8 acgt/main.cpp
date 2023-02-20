#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int n = s.length();
    int l = 0, r = 0;
    unordered_map<char,int> m;
    m['A'] = 0;
    m['C'] = 0;
    m['G'] = 0;
    m['T'] = 0;
    int minDis = 0;
    while(r<n){
        m[s[r]] += 1;
        if(m['A']>0 && m['C']>0 && m['G']>0 && m['T']>0){
            minDis = max(minDis,r-l+1);
            m[s[l]] -= 1;
            l++;
        }
        r++;
    }
    r--;
    if(!(m['A']>0 && m['C']>0 && m['G']>0 && m['T']>0)) l--;
    minDis = max(minDis,r-l+1);
    cout<<minDis;
    return 0;
}
//ACCGTTAA
