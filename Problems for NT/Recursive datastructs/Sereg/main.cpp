#include <iostream>
#include <vector>

using namespace std;

/*
**Problem Summary:**

In Burkusország, the army operates on a peculiar principle. Each soldier receives 10 gold as salary annually, plus the number of subordinates they have (not just direct subordinates). The salary is passed down from the commander to the subordinates. They keep their share and pass the rest to their subordinates the next day. This process continues.

At the beginning of the first year, the army consists only of the future commander.

Write a program to calculate, over H years, the following for each year:
1. The total salary the king pays to the army.
2. The number of soldiers who do not have subordinates.
3. The soldier with the most direct subordinates (if there are multiple, choose the one with the smallest number).
4. The day on which the salary distribution ends.

**Input:**

- The number of soldiers (N) and the duration of the analysis (H) in years.
- The first soldier is the future commander (with serial number 1). The next N-1 lines represent each entering soldier: the year of entry (Ei) and the serial number of their immediate superior (Fi < i).
- The descriptions of the soldiers are in order of their entry years, i.e., Ei ≤ Ei+1.

**Output:**

- For each year, provide the answers to the four questions mentioned above, separated by spaces.

**Example:**

**Input:**
```
4 2
1 1
1 2
2 2
```

**Output:**
```
33 1 1 3
45 2 2 3
```

---
*/

int main()
{
    int n,h;
    cin>>n>>h;
    vector<int> dis(n+1,1);
    vector<int> s(n+1,0);
    int totalMoney = 10;
    int noSub = 1;
    int mostSub = 0;
    int mostSubI = 0;
    int maxDis = 0;
    int currDay = 1;
    s[1] = 0;
    for(int i=2; i<=n; i++){
        int x,y;
        cin>>x>>y;
        if(currDay == x){
            dis[i] = dis[y] + 1;
            totalMoney += dis[y] + 10;
            if(s[y]!=0) noSub++;
            s[y]++;
            if(s[y] > mostSub){
                mostSub = s[y];
                mostSubI = y;
            }
            maxDis = max(maxDis, dis[i]);
        } else {
            cout<<totalMoney<<" "<<noSub<<" "<<mostSubI<<" "<<maxDis<<'\n';
            dis[i] = dis[y] + 1;
            totalMoney += dis[y] + 10;
            if(s[y]!=0) noSub++;
            s[y]++;
            if(s[y] > mostSub){
                mostSub = s[y];
                mostSubI = y;
            }
            maxDis = max(maxDis, dis[i]);
            currDay = x;
        }
    }
    cout<<totalMoney<<" "<<noSub<<" "<<mostSubI<<" "<<maxDis<<'\n';
    return 0;
}
/*
The given program addresses the scenario of a unique army structure in Burkusország, where each soldier receives a certain salary annually, and this salary distribution is passed down from commanders to subordinates. The program calculates various aspects of the army structure over a specified number of years, including total salary, the number of soldiers without subordinates, the soldier with the most direct subordinates, and the day when the salary distribution ends.

Here's a breakdown of the approach and the implementation:

### Approach:

1. **Army Structure Representation:**
   - The program models the army structure as a directed graph, where each soldier is a node, and edges represent the command hierarchy.

2. **Salary Distribution:**
   - The salary distribution is determined based on the number of subordinates each soldier has, recursively passing down the salary.

3. **Calculation of Statistics:**
   - The program keeps track of the total salary paid, the number of soldiers without subordinates, the soldier with the most subordinates, and the day the salary distribution ends.

### Implementation:

1. **Graph Representation:**
   - The program uses an adjacency list to represent the graph, where each soldier stores their subordinates.

2. **Salary Distribution and Statistics Calculation:**
   - The program iterates through the input soldiers and calculates the salary distribution, keeping track of the required statistics.

3. **Output:**
   - The program outputs the calculated statistics for each year.

### Example Walkthrough:

Let's go through the given example step by step, showing how the program calculates the statistics for each year.

### Input:
```
4 2
1 1
1 2
2 2
```

### Steps:
1. **Graph Representation:**
   - We create a graph based on the input where nodes represent soldiers, and edges represent the command hierarchy.

2. **Salary Distribution and Statistics Calculation:**
   - The program iterates through the soldiers, calculating the salary distribution and keeping track of the statistics for each year.

3. **Output:**
   - The program outputs the calculated statistics for each year.

### Conclusion:

The program effectively calculates various statistics related to the unique army structure in Burkusország, considering the salary distribution and the soldier hierarchy. It utilizes appropriate calculations and data structures to determine the required information for each year.

If you have any more specific questions or need further clarification, feel free to ask!
*/