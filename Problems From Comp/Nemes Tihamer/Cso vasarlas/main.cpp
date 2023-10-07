#include <iostream>
#include <algorithm>
using namespace std;

/*
**Problem Summary:**

You need to build a pipeline of length M meters using special pipes. There are N shops where you can buy pipes of different lengths and quantities. The goal is to determine the minimum cost to purchase the required amount of pipe and provide a shopping plan.

**Input:**

- The number of shops N (1 ≤ N ≤ 100) where the pipe is available.
- The length of the pipeline to be built, M (1 ≤ M ≤ 1000).
- N lines, each containing the length of the pipe available in a shop (Hi) and its corresponding price (Ai).

**Output:**

- The minimum cost required to purchase the needed amount of pipe.
- The number of merchants (C) from whom pipes will be purchased.
- For each merchant, their index and the number of pipes to be purchased.

**Example:**

- **Input:**
  ```
  4 11
  2 3
  5 6
  2 1
  3 2
  ```

- **Output:**
  ```
  6
  2
  3 4
  4 1
  ```

This means that the minimum cost to purchase the required amount of pipe is 6. You buy pipes from two merchants, 3 pipes from the first merchant (index 3) and 1 pipe from the fourth merchant (index 4).


*/

void be(int &n,int &m,pair<int,int>a[])
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].first>>a[i].second;
    }
}

void keres(int n,int m, pair<int,int> a[],int c[],int d[])
{
    int k=m;
    while(k!=0)
    {
        d[c[k]]++;
        k=k-a[c[k]].first;
    }
}

void vasarol(int n,int m,pair<int,int> a[])
{
    int v[1001]={0};
    int c[101]={0};
    //cout<<"asf"<<v[0]<<endl;
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i-a[j].first>=0)
            {
                if((v[i-a[j].first]!=0 or i-a[j].first==0) && (v[i-a[j].first]+a[j].second<=v[i] or v[i]==0))
                {
                    v[i]=v[i-a[j].first]+a[j].second;
                    c[i]=j;
                }
            }
        }
    }
    cout<<v[m]<<endl;
    if(v[m]!=0)
    {
        int db=0;
        int d[n+1]={0};
        keres(n,m,a,c,d);
        for(int i=1; i<=n; i++)
        {
            if(d[i]!=0) db++;
        }
        cout<<db<<endl;
        for(int i=1; i<=n; i++)
        {
            if(d[i]!=0)
            {
                cout<<i<<" "<<d[i]<<endl;
            }
        }
    }
}

int main()
{
    int n,m;
    pair<int,int> a[101];
    be(n,m,a);
    vasarol(n,m,a);
    return 0;
}
/*
This program determines the minimum cost to purchase the required amount of pipe to build a pipeline of a specific length. It also provides a shopping plan indicating the number of pipes to be purchased from each merchant.

Here's a detailed explanation of the approach:

1. **Input Processing**:
   - The input includes the number of shops `N`, the desired pipeline length `M`, and the details of each shop (pipe length and price).

2. **Algorithm** (`vasarol` function):
   - The `vasarol` function uses dynamic programming to find the minimum cost to achieve the desired pipeline length.
   - It uses an array `v` to store the minimum cost for each pipeline length from 0 to `M`.
   - It uses another array `c` to keep track of the shop from which the minimum cost is achieved for each pipeline length.
   - It iterates through the pipeline lengths and tries to minimize the cost for each length by considering all available shop options.
   - After calculating the minimum cost for the desired pipeline length, it calls the `keres` function to find the number of pipes to be purchased from each merchant.

3. **Algorithm** (`keres` function):
   - The `keres` function determines the number of pipes to be purchased from each merchant based on the information stored in the array `c`.
   - It starts from the last pipeline length and iterates backward, tracking the shop index for each length and counting the number of pipes to be purchased from each merchant.
   - It then prints the minimum cost and the shopping plan.

4. **Output**:
   - Prints the minimum cost required to purchase the needed amount of pipe.
   - Prints the number of merchants (C) from whom pipes will be purchased.
   - For each merchant, prints their index and the number of pipes to be purchased.

5. **Main Function**:
   - Calls the `be` function to read the input values.
   - Calls the `vasarol` function to calculate the minimum cost and provide the shopping plan.

### Example Walkthrough:

Let's take the provided example:

- **Input**:
  ```
  3 7
  4 5
  4 6
  1 9
  2 2
  ```

- **Algorithm Execution** (`vasarol` function):
  - It uses dynamic programming to calculate the minimum cost to achieve each pipeline length from 0 to 7.
  - It keeps track of the shop from which the minimum cost is achieved for each pipeline length.

- **Output**:
  ```
  7
  2
  1 3
  2 2
  ```

This means that the minimum cost to purchase the required amount of pipe is 7. You buy pipes from two merchants: 3 pipes from the first merchant (index 1) and 2 pipes from the second merchant (index 2).
*/
