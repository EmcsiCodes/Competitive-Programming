#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
/*
Problem: Given a dictionary of words, the goal is to determine if a target word can be obtained from a given initial word using specific transformation rules. Two transformation rules are allowed:
A. Swap a letter for another.
B. Swap a letter for another or add a letter to the end of a word.

Input:

Number of words in the dictionary (N).
N words in the dictionary.
Transformation rule to be applied (A or B).
Two words from the dictionary (P and Q).
Output:

Minimum number of rule applications needed to transform P into Q. If not possible, output -1.
Total number of words that can be obtained from P using the transformation rules.
Approach:

Implement a depth-first search (DFS) or breadth-first search (BFS) based approach to traverse through the dictionary and generate words using the transformation rules until reaching the target word.
Count the number of steps required to transform P to Q.
Count the total number of words that can be obtained from P.
Algorithm Steps:

Read the input and prepare the dictionary.
Implement DFS or BFS to generate words using the transformation rules until reaching Q.
Count the number of steps needed to reach Q and the total number of words generated.
Example:
Input:
OKOS
ÁKOS
ÁKOM
OKOD
ÁLOM
ALOM
HALOM
Output:
Minimum steps: 3 (OKOS -> ÁKOS -> ÁKOM -> ÁLOM)
Total words: 6 (OKOS, ÁKOS, ÁKOM, OKOD, ÁLOM, HALOM)
This problem involves transforming an initial word into a target word using specific rules and determining the number of words that can be generated following those rules. The task is to calculate the minimum number of steps required to reach the target word and count the total words that can be generated using the given transformation rules.
*/
vector<string> words[21];
map<string, vector<string> > adj;
map<string, bool> visited;
map<string,int> dis;
bool found = false;

bool connect(int l){
    bool nextConnect = false;
    for(int i=0; i<words[l].size(); i++){
        string p = words[l][i].substr(0,l-1);
        if(adj.find(p)!=adj.end()){
            adj[words[l][i]].push_back(p);
            adj[p].push_back(words[l][i]);
            nextConnect = true;
        }
    }
    return nextConnect;
}

void BFS(string start,string end, int n){

    queue<string> q;
    q.push(start);

    while(!q.empty()){
        string node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(visited[i] == false){
                visited[i] = true;
                q.push(i);
                dis[i] = dis[node] + 1;
            }
        }
    }
    if(!found) {
        if(dis[end]!=0) cout<<dis[end]<<'\n';
        else cout<<-1<<'\n';
    }
    int wordNum = 0;
    for(auto i:dis){
        if(i.second!=0) wordNum++;
    }
    cout<<wordNum;
}

int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        string s;
        cin>>s;
        if(visited.find(s)==visited.end()){
            visited[s] = false;
            dis[s] = 0;
            words[s.length()].push_back(s);
        }
    }
    char rule;
    cin>>rule;
    string start, end;
    cin>>start>>end;
    if(end.size()<start.size()) {
        found = true;
        cout<<-1<<'\n';
    }
    if(rule == 'A' && start.size()!=end.size()) {
        found = true;
        cout<<-1<<'\n';
    }
    int l = start.length();

    for(int i=0; i<words[l].size() - 1; i++){
        for(int j=i+1; j<words[l].size(); j++){
            if(words[l][i]!=words[l][j]){
                int diff = 0;
                bool canConnect = true;
                for(int p = 0; p<l; p++){
                    if(words[l][i][p]!=words[l][j][p]) diff++;
                    if(diff>1) {
                        canConnect = false;
                        break;
                    }
                }
                if(canConnect){
                    adj[words[l][i]].push_back(words[l][j]);
                    adj[words[l][j]].push_back(words[l][i]);
                }
            }
        }
    }
    if(rule == 'B'){
        l = start.length() + 1;
        while(connect(l)) l++;
    }
    BFS(start,end,n);
    /*for(auto i:adj){
        cout<<i.first<<": ";
        for(auto j:i.second){
            cout<<j<<" ";
        }
        cout<<endl;
    }*/
    return 0;
}
/*
The goal is to:

Determine the minimum number of rule applications needed to transform the initial word into the target word.
Count the total number of words that can be generated from the initial word using these transformation rules.
Approach:
The code begins by parsing the input, which consists of:

The number of words in the dictionary (N).
N words in the dictionary.
The transformation rule to be applied (A or B).
Two words from the dictionary (P and Q).
It organizes the words in the dictionary into different lengths (word length groups) to optimize later processing. Words of the same length are stored in separate groups.

The code handles two cases based on the transformation rule:

Rule A: Swap a letter for another. If rule A is selected, it ensures that both the start and end words have the same length. If not, it's not possible to transform, and it outputs -1.
Rule B: Swap a letter for another or add a letter to the end of a word. It expands the word length groups to create new words by adding one character to each word until there are no more connections between words.
For each pair of words within the same word length group, the code checks if they can be connected based on the transformation rules:

Words are connected if they differ by only one character.
The code constructs a graph of word connections, where words that can be transformed into each other are connected.

It then uses a breadth-first search (BFS) algorithm to explore this graph starting from the initial word (P) to find the minimum number of steps needed to reach the target word (Q).

After BFS traversal, the code checks if it was possible to reach the target word (Q). If not, it outputs -1.

Finally, it counts the total number of words that can be obtained from the initial word (P) based on the transformation rules. The total number of words corresponds to the vertices visited during BFS traversal.
*/