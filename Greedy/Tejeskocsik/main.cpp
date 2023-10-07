#include <iostream>
#include <vector>

using namespace std;
/*
Here's a summary of the problem "Tejeskocsik" (Milk Trucks):

- **Problem Description**:
  Milk producers deliver milk to a collection point according to a predefined schedule, using containers of various sizes. From the collection point, the milk is transported to the processing facility using milk trucks, and the milk must be transported in the order of arrival. At any given time, a maximum of two producers can bring in milk. Each producer's milk can be loaded into only one milk truck. The collection point does not support long-term milk storage, so all milk must be transported from there within at most T time units.

- **Task**:
  Create a program that calculates the minimum number of milk trucks needed to transport all the milk.

- **Input**:
  - The first line of standard input contains the number of milk producers N (1 ≤ N ≤ 100,000), the milk truck's capacity K (1 ≤ K ≤ 1,000), and the maximum time that milk can stay at the collection point T (1 ≤ T ≤ 100).
  - The next N lines, in the order of arrival, contain the arrival time of each milk producer Ei (1 ≤ Ei ≤ 100,000) and the quantity of milk they brought Mi (1 ≤ Mi ≤ K).

- **Output**:
  - The program should output the minimum number of milk trucks needed.

- **Example**:
  - **Input**:
    ```
    5 100 10
    1 30
    6 50
    8 30
    19 50
    28 40
    ```
  - **Output**:
    ```
    3
    ```

- **Constraints**:
  - The constraints ensure that the computation can be performed within a reasonable time frame.
*/
struct in{
    int time;
    int cap;
};

int main()
{
    int n,c,t;
    cin>>n>>c>>t;
    vector<in> v;
    for(int i=1; i<=n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    int i = 0, res = 0;
    while(i<v.size()){
        int currCap = 0;
        int maxTime = v[i].time + t;
        while(i<v.size() && v[i].time <= maxTime && currCap + v[i].cap <= c){
            currCap += v[i].cap;
            i++;
        }
        res++;
    }
    cout<<res;
    return 0;
}
/*
The provided program efficiently solves the problem of determining the minimum number of milk trucks needed to transport all the milk within the given constraints. Here's a step-by-step explanation of the code:

1. **Understanding the Problem**:
   - The program takes input for the number of milk producers `N`, the milk truck's capacity `K`, and the maximum time `T`.
   - For each milk producer, it takes input for the arrival time and the quantity of milk they brought.

2. **Approach**:
   - It processes the milk producers in the order of their arrival time.
   - It keeps track of the current capacity of the milk truck and the maximum allowed time for a milk producer to load their milk into a truck.
   - It iterates through the milk producers, and for each producer:
     - If the current capacity plus the producer's milk quantity exceeds the truck's capacity and the producer's arrival time is within the allowed time, it increments the milk truck count and resets the current capacity and maximum allowed time.
     - Otherwise, it adds the producer's milk quantity to the current capacity and updates the maximum allowed time.

3. **Output**:
   - The program outputs the minimum number of milk trucks needed to transport all the milk.

4. **Explanation**:
   - The program efficiently determines the minimum number of milk trucks required by considering each producer's milk quantity and their arrival time while adhering to the truck's capacity and time constraints.

5. **Time Complexity**:
   - The time complexity of the algorithm is O(N) since it processes each milk producer once.

Overall, the program effectively calculates the minimum number of milk trucks needed to transport all the milk, optimizing the use of the available milk truck capacity and time limits.
*/