#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    int n;
    string s;
    cin>>n>>s;
    unordered_map<char, pair<int,int> > m;
    m['B'] = {0,0};
    m['C'] = {0,0};
    int count = 0;
    for(int i=0; i<s.length(); i++){
        count++;
        m[s[i]].first++;
        if(s[i] == 'B'){
            if(m['C'].first>0){
                count--;
                m['C'].first--;
                m['B'].second++;
                m['B'].first--;
            }
        }
        if(s[i] == 'A'){
            bool emp = true;
            if(m['B'].first != 0){
                count--;
                m['B'].first--;
            } else if(m['B'].second !=0){
                emp = false;
                count--;
                m['B'].second--;
            }
            if(emp && m['C'].first>0){
                count--;
                m['C'].first--;
            }
        }
    }
    cout<<count;
    return 0;
}
/*
11
ABACACBCCAAC
*/
