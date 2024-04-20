#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
int TestNum, n;
int dicWords;
string book;
vector<string> words;

int solve(){
    vector<int> res(book.size() + 1, 0);
    for(int i=1; i<=book.size(); i++){
        res[i] = i;
    }
    for(int i=1; i<res.size(); i++){
        for(string w : words){
            if(w.size() > i) continue;
            if(book.substr(i - w.size(), w.size()) == w) {
                res[i] = min(res[i], res[i - w.size()]);
            }
        }
        res[i] = min(res[i], res[i-1] + 1);
        // for(int i=0; i<res.size(); i++) cout<<res[i]<<" ";
        // cout<<'\n';
    }
    return res[book.size()];
}

int main(){
    ifstream in("carte.in");
    ofstream out("carte.out");
    in>>TestNum;
    for(int i=0; i<TestNum; i++) {
        in>>book;
        in>>dicWords;
        for(int j=0; j<dicWords; j++){
            string x;
            in>>x;
            words.push_back(x);
        }
        out<<solve()<<'\n';
    }
}