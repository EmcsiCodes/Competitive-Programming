#include <iostream>
#include <set>
using namespace std;
/*
- **Problem Description**:
  Given a computer network with N nodes and bidirectional communication channels between certain pairs of nodes, the goal is to find the largest K-secure subnetwork, where a subnetwork is K-secure if each node within it has at least K neighbors also within the subnetwork.

- **Input**:
  - The first line of standard input contains the number of nodes N (1 ≤ N ≤ 100,000), the number of direct communication channels M (1 ≤ M ≤ 200,000), and the value of K (1 ≤ K ≤ N).
  - The next M lines each contain two integers u and v representing a communication channel between nodes u and v (1 ≤ u ≠ v ≤ N). At most one channel is present between any pair of nodes.

- **Output**:
  - The program should output the number of nodes in the largest K-secure subnetwork on the first line.
  - The second line should contain the node numbers of this subnetwork in increasing order.

- **Example**:
  - **Input**:
    ```
    8 12 3
    8 7
    7 3
    4 3
    8 5
    6 5
    3 1
    2 1
    7 1
    2 7
    2 3
    4 6
    4 7
    ```
  - **Output**:
    ```
    4
    1 2 3 7
    ```

- **Constraints**:
  - The constraints ensure that the computation can be performed within a reasonable time frame.
*/
void be(int &m,int &k,set <int> s[])
{
    cin>>m>>k;
    for(int i=1; i<=m; i++)
    {
       int x,y;
       cin>>x>>y;
       s[x].insert(y);
       s[y].insert(x);
    }
}

void torol(int n,int i,int k,set <int> s[])
{
    if(!s[i].empty())
    {
        set<int >::iterator it ;
    it=s[i].begin();
    s[*it].erase(s[*it].find(i));
    s[i].erase(s[i].begin());
    if(s[*it].size()<k) {
        torol(n,*it,k,s);
    }
    torol(n,i,k,s);
    }
}

void halozat_mod(int n,int k,set <int> s[])
{
    for(int i=1; i<=n; i++)
    {
        if(s[i].size()<k && !s[i].empty())
        {
            torol(n,i,k,s);
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(s[i].size()>k) {
            s[i].erase(s[i].begin(),s[i].end());
            halozat_mod(n,k,s);
        }
    }
}

void halozat(int n,int k,set <int> s[])
{
    halozat_mod(n,k,s);
    int max=0;
    int index=0;
    for(int i=1; i<=n; i++)
    {
        if(s[i].size()>max)
        {
            max=s[i].size();
            index=i;
        }
    }
    if(max==0) cout<<0<<endl<<0;
    else{
    cout<<max+1<<endl;
    set<int>::iterator it;
    s[index].insert(index);
    for(it=s[index].begin(); it!=s[index].end(); it++)
    {
        cout<<*it<<" ";
    }
    }

}

int main()
{
    int n,m,k;
    cin>>n;
    set <int> s[n+1];
    be(m,k,s);
    halozat(n,k,s);
}
/*
### Largest K-Secure Subnetwork

#### Approach:
- The problem involves finding the largest K-secure subnetwork in a computer network, where each node within it has at least K neighbors also within the subnetwork.
- The program reads the input, builds the network based on communication channels, and recursively removes nodes that do not satisfy the K-secure condition.
- Finally, it identifies the largest K-secure subnetwork and outputs its size and node numbers.

#### Pseudocode:
1. Read input: number of nodes `n`, number of communication channels `m`, and K.
2. Build the network based on communication channels.
3. Implement functions:
   - `be`: Reads communication channels and builds the network.
   - `torol`: Removes nodes that do not satisfy the K-secure condition.
   - `halozat_mod`: Modifies the network based on the K-secure condition.
   - `halozat`: Calls the necessary functions and identifies the largest K-secure subnetwork.
4. Output the number of nodes in the largest K-secure subnetwork and the node numbers.

#### Time Complexity:
- The time complexity depends on the number of nodes and communication channels, and also the recursive operations to modify the network.
- Overall time complexity: O(m + n log n).

### Code Explanation:

1. **`be` function**: Reads communication channels and builds the network.
2. **`torol` function**: Removes nodes that do not satisfy the K-secure condition recursively.
3. **`halozat_mod` function**: Modifies the network based on the K-secure condition recursively.
4. **`halozat` function**: Calls necessary functions and identifies the largest K-secure subnetwork.
5. **`main` function**: Reads input, calls the necessary functions, and outputs the results.
*/
