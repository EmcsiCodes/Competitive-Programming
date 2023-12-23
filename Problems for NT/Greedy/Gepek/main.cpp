#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
/*
Here's a summary of the problem "Gépek" (Machines):

- **Problem Description**:
  An entrepreneur receives orders for the next N days. Each job can be completed in a single day. M orders have been placed, each specifying the deadline for the requested work. The entrepreneur needs to calculate the minimum number of machines needed to complete all the requested work by the deadlines.

- **Task**:
  Create a program that calculates the minimum number of machines required to complete all the ordered work within the specified deadlines. The program should also specify the day and the machine for each order.

- **Input**:
  - The first line of standard input contains the number of workdays N (1 ≤ N ≤ 10,000) and the number of orders M (1 ≤ M ≤ 100,000).
  - The second line contains M integers separated by spaces, denoting the deadlines of the orders (1 ≤ hi ≤ N).

- **Output**:
  - The program should output M+1 lines. The first line contains an integer G, the minimum number of machines needed.
  - The following M lines each contain two integers, separated by a space, denoting the day and the machine for each order.

- **Example**:
  - **Input**:
    ```
    10 8
    3 2 3 2 4 5 6 2
    ```
  - **Output**:
    ```
    2 2
    1 1
    3 1
    2 1
    3 2
    4 1
    4 2
    1 2
    ```

- **Constraints**:
  - Time Limit: 0.1 seconds
  - Memory Limit: 32 MB
*/
int main()
{
    int n,m;
    cin>>n>>m;
    vector< pair<int,int> > v,res(m+1);
    multiset< pair<int,int > > robots;
    for(int i=1; i<=m; i++){
        int x;
        cin>>x;
        v.push_back({x,i});
    }
    sort(v.begin(),v.end());
    robots.insert({1,1});
    int totalRobots = 1;
    for(int i=0; i<v.size(); i++){
        auto currRobot = robots.begin();
        if(currRobot->first <= v[i].first) {
            res[v[i].second] = {currRobot->first,currRobot->second};
            robots.erase(currRobot);
            robots.insert({currRobot->first+1,currRobot->second});
            
        } else {
            totalRobots++;
            robots.insert({2,totalRobots});
            res[v[i].second] = {1,totalRobots};
        }
    }
    cout<<totalRobots<<'\n';
    for(int i=1; i<=m; i++) cout<<res[i].first<<" "<<res[i].second<<'\n';
    return 0;
}
/*
### Program: "Machines"

1. **Understanding the Problem**:
   - The problem involves determining the minimum number of machines needed to complete a set of orders within their specified deadlines.
   - Each order needs to be completed in a single day.
   - The goal is to assign each order to a machine in a way that minimizes the number of machines used.

2. **Approach**:
   - Sort the orders based on their deadlines.
   - Assign each order to a machine. If the order can be assigned to an existing machine, do so; otherwise, assign it to a new machine.
   - Output the minimum number of machines used and the assignment of orders to machines.

3. **Algorithm**:
   - Read input values for the number of workdays N, the number of orders M, and the deadlines of the orders.
   - Create a vector to store the deadlines and order numbers.
   - Sort the vector based on the deadlines.
   - Iterate through the orders:
     - Assign each order to a machine, minimizing the number of machines used.
   - Output the minimum number of machines used and the assignment of orders to machines.

4. **Explanation**:
   - We sort the orders based on their deadlines.
   - We assign each order to a machine, ensuring we use the minimum number of machines possible.
   - We output the minimum number of machines used and the assignment of orders to machines.

5. **Time Complexity**:
   - Sorting the orders based on deadlines: O(M log M)
   - Iterating through the orders and assigning them to machines: O(M)
   - Total: O(M log M)

This approach calculates the minimum number of machines needed and specifies the assignment of orders to machines, satisfying the problem requirements.
*/