#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
/*
- **Problem Description**:
  You have rented a car for a K-kilometer trip and were given B liters of gasoline. During the trip, you stopped at N different places to refuel. The car consumes L liters of fuel per 100 kilometers.

  Calculate the minimum number of refueling stops necessary from the given refueling stops.

- **Input**:
  - The first line of standard input contains the distance of the trip (1 ≤ K ≤ 100,000), the number of refueling stops (1 ≤ N ≤ 1000), the initial amount of gasoline in the car (1 ≤ B ≤ 100), and the fuel consumption per 100 kilometers (1 ≤ L ≤ 10).
  - The next N lines each contain the distance of the gasoline station from the starting point (1 ≤ Ti ≤ 10,000) and the amount of gasoline refueled (1 ≤ Mi ≤ 100), in the order of refueling. Every distance is divisible by 100.

- **Output**:
  - The program should output a single line containing the minimum number of refueling stops needed.

- **Example**:
  - **Input**:
    ```
    2000 4 40 7
    400 20
    500 80
    800 30
    1200 30
    ```
  - **Output**:
    ```
    2
    ```

- **Constraints**:
  - The constraints ensure the computation can be performed within a reasonable time frame.
  - In 60% of the tests, N < 10.
*/
vector< pair<int,int> > gas;
priority_queue<int> pq;
int main()
{
    double n,fuel,fuelCons;
    int k;
    cin>>n>>k>>fuel>>fuelCons;
    for(int i=1; i<=k; i++){
        int x,y;
        cin>>x>>y;
        gas.push_back({x,y});
    }
    sort(gas.begin(),gas.end());
    double d = 100*(fuel/fuelCons);
    int pos = 0, res = 0;
    while(d<n){
        res++;
        while(pos<gas.size() && gas[pos].first<=d){
            pq.push(gas[pos].second);
            pos++;
        }
        fuel = pq.top();
        pq.pop();
        d += 100*(fuel/fuelCons);
    }
    cout<<res;
    return 0;
}
/*
### Program: "Minimum Refueling Stops"

1. **Understanding the Problem**:
   - We need to determine the minimum number of refueling stops needed for a K-kilometer trip given certain refueling stations and the initial amount of gasoline.

2. **Approach**:
   - Sort the refueling stations based on their distances from the starting point.
   - Keep track of the remaining distance we can travel based on the initial gasoline.
   - Use a priority queue to store the refueling amounts at each station.
   - While the remaining distance is less than the total trip distance:
     - Increment the refueling stop count.
     - Refuel at the station with the maximum gasoline amount in the priority queue.
     - Update the remaining distance based on the refueled amount and fuel consumption.

3. **Algorithm**:
   - Read input values for trip distance, number of refueling stops, initial gasoline amount, and fuel consumption.
   - Create a vector to store refueling stations (distance from starting point, refueled gasoline amount).
   - Sort the vector based on distances in ascending order.
   - Initialize variables for remaining distance, refueling stop count, and position in the vector.
   - While the remaining distance is less than the total trip distance:
     - Increment the refueling stop count.
     - Refuel at the station with the maximum gasoline amount in the priority queue.
     - Update the remaining distance based on the refueled amount and fuel consumption.
   - Print the refueling stop count.

4. **Explanation**:
   - We start from the initial position with a certain amount of gasoline. At each step, we determine the maximum distance we can travel with the remaining gasoline.
   - We select the station that is reachable and has the maximum refueled gasoline amount, refuel there, and update the remaining distance.
   - We continue this process until we can reach the end of the trip.

5. **Time Complexity**:
   - Sorting the refueling stations based on distance: O(N log N)
   - Iterating through the refueling stations: O(N)
   - Total: O(N log N)

This approach ensures that we refuel at the optimal stations to minimize the number of refueling stops needed.
*/