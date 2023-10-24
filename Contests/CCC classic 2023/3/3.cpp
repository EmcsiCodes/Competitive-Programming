#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <map>
#include <queue>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <string>

using namespace std;
#define inf 100000000
char a[300][300];

ofstream db("debug.out");

int invc=0;

void pintvis(bool vis[][260], int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            db<<vis[i][j];
        }
        db<<endl;
    }
    db<<endl;
    db<<"fasz "<<invc<<endl;
    db<<endl;
    invc++;
}

vector<pair<int,int>> paths;

bool BFS(int n,char a[][300]){
    
    bool visited[250][250];
    bool vis_corner[260][260];
    memset(visited, false, sizeof(visited));
    memset(vis_corner, false, sizeof(vis_corner));
    int x1 = paths[0].second;
    int y1 = paths[0].first;
    visited[x1][y1] = true;
    int i = 1;
    if(paths.size() == 1) return true;
    while(i < paths.size()){
        visited[x1][y1] = true;
        int x2 = paths[i].second;
        int y2 = paths[i].first;
        
        if(x1 != x2 && y1 != y2) //atlos
        {
            //jobb fel
            cout<<x1<<" "<<y1<<"  ->  "<<x2<<" "<<y2<<endl;
            if(x2<x1 && y1<y2)
            {
                int cx = x1;
                int cy = y1 + 1;
                if(vis_corner[cx][cy] || visited[x2][y2])
                {
                    pintvis(vis_corner,n+1);
                    
                    return false;
                }
                else
                {
                    vis_corner[cx][cy] = true;
                    cout<<cx<<" "<<cy<<" itt jartunk"<<endl;    
                }
            }//ball fel
            else if(x2<x1 && y1>y2)
            {
                int cx = x1;
                int cy = y1;
                if(vis_corner[cx][cy] || visited[x2][y2])
                {
                    pintvis(vis_corner,n+1);
                    return false;
                }
                else
                {
                    vis_corner[cx][cy] = true;
                    cout<<cx<<" "<<cy<<" itt jartunk"<<endl;
                }
            }//jobb le
            else if(x2>x1 && y1<y2)
            {
                int cx = x1 + 1;
                int cy = y1 + 1;
                if(vis_corner[cx][cy] || visited[x2][y2])
                {
                    pintvis(vis_corner,n+1);
                    return false;
                }
                else
                {
                    
                    vis_corner[cx][cy] = true;
                    cout<<cx<<" "<<cy<<" itt jartunk"<<endl;
                }
            }
            //bal le    
            else if(x2>x1 && y1>y2)
            {
                int cx = x1 + 1;
                int cy = y1;
                if(vis_corner[cx][cy] || visited[x2][y2])
                {
                    pintvis(vis_corner,n+1);
                    return false;
                }
                else
                {
                    vis_corner[cx][cy] = true;
                    cout<<cx<<" "<<cy<<" itt jartunk"<<endl;
                }
            }
        } else {
            if(visited[x2][y2])
            {
                invc++;
                return false;
            }
        }
        visited[x2][y2] = true;
        i++;
        x1=x2;
        y1=y2;
       // cout<<"szia";
    }
   // cout<<"szia";
    return true;
}

int main()
{
    ifstream f("level3_5.in");
    ofstream g("level3_5.out");
    int n;
    f>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            f>>a[i][j];
        }
    }
    int x1,y1,x2,y2;
    int count = 5232;
    f>>count;
    string ss;
    getline(f,ss);
    while(count--)
    {
        //cout<<count<<" adik bemenet"<<endl;
        string s;
        int x,y;
        getline(f,s);
        cout<<s<<endl;
        string buff = "";
        for(int i=0;i<s.length();i++){
            if(s[i] == ' ')
            {
                y = stoi(buff);
                buff = "";
                paths.push_back({x,y});
                continue;
            }
            if(s[i] == ',')
            {
                x = stoi(buff);
                buff = "";
                continue;
            }
            buff += s[i];
        }
        y=stoi(buff);
        paths.push_back({x,y});
        if(BFS(n,a)) g<<"VALID"<<endl;
        else g<<"INVALID"<<endl;
        paths.clear();
    }
    return 0;
}
