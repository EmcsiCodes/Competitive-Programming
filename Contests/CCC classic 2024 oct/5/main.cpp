#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>
#include <set>
#include <map>
#include <cstring>
#include <queue>
#include <stack>
#include <chrono>
#include <random>
#include <functional>
#include <limits>

using namespace std;

#define ll long long
#define inf INT_MAX
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim)
{
    uniform_int_distribution<int> uid(0, lim - 1);
    return uid(rang);
}
int mpow(int base, int exp);
void ipgraph(int n, int m);
void dfs(int u, int par);

const int mod = 1'000'000'007;
const int N = 3e5, M = N;
//=======================

vi g[N];
int a[N];

int mpow(int base, int exp)
{
    base %= mod;
    int result = 1;
    while (exp > 0)
    {
        if (exp & 1)
            result = ((ll)result * base) % mod;
        base = ((ll)base * base) % mod;
        exp >>= 1;
    }
    return result;
}

void ipgraph(int n, int m)
{
    int i, u, v;
    while (m--)
    {
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
}

void dfs(int u, int par)
{
    for (int v : g[u])
    {
        if (v == par)
            continue;
        dfs(v, u);
    }
}

void selfDestruct(char *argv)
{
    char *process_name = argv;
    char command[256] = "rm ";
    strcat(command, process_name);
    system(command);
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ifstream f("level5_1.in");
    ofstream g("level5_1.out");

    int n,m;
    f>>n;
    
    for(int t=0; t<n; t++){
        int x,y,z;
        bool ye = true;
        vector<vector<char>> v(1000, (vector<char>(1000,'.')));
        f>>x>>y>>z;
        
        if(x%2 == 1){

            int i,j;
            for(i=0; i+3<y || i == y - 2; i = i + 3){
                for(j=0; j<x; j=j+2){
                    v[i][j] = 'X';
                    v[i+1][j] = 'X';
                }
            }
            if(i == y-1){
                for(j=0; j<x; j=j+3){
                    v[i][j] = 'X';
                    v[i][j+1] = 'X';
                }
            }
            if(i == y-3){
                for(j=0; j<x; j=j+3){
                    v[i][j] = 'X';
                    v[i][j+1] = 'X';    
                    v[i+2][j] = 'X';
                    v[i+2][j+1] = 'X';                
                }
                v[i][x-1] = 'X';
                v[i+1][x-1] = 'X';
            }
        } else if(x%3 == 2){

            int i,j;
            for(i=0; i+2<y || i == y-1; i = i + 2){
                for(j=0; j<x; j = j  + 3){
                    v[i][j] = 'X';
                    v[i][j + 1] = 'X';
                }
            }
            if(i + 2 == y){
                for(j=0; j<x; j=j+2){
                    v[i][j] = 'X';
                    v[i+1][j] = 'X';
                }
            }
        } else {

            int i,j;
            for(i=0; i+3<y || i == y - 2; i=i+3){
                for(j=0; j<x-3;j=j+2){
                    v[i][j]='X';
                    v[i+1][j]='X';
                }
            }
            //utolsom sor
            //g<<i<<y<<endl;
            if(i == y-1){

                for(j=0; j<x-3; j=j+3){
                    v[i][j] = 'X';
                    v[i][j+1] = 'X';
                }           
                for(i=0; i<y; i=i+2){
                    v[i][x-2]='X';
                    v[i][x-1]='X';
                }
                
            }
            else if(i == y-3){
                for(j=0; j<x-3; j=j+3){
                    v[i][j] = 'X';
                    v[i][j+1] = 'X';    
                    v[i+2][j] = 'X';
                    v[i+2][j+1] = 'X';                
                }
                for(i=0; i<y-3; i=i+2){
                    v[i][x-2]='X';
                    v[i][x-1]='X';
                }

            }
            else if(i == y+1){
                for(i=0; i<y; i=i+2){
                    v[i][x-2]='X';
                    v[i][x-1]='X';
                }
            }
 
        }

        for(int i=0; i<y; i++){
            for(int j=0; j<x; j++){
                g<<v[i][j];
            }
            g<<endl;
        }
        g<<endl;
    }


    selfDestruct(argv[0]);

    return 0;
}