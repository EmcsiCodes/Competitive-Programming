#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
/*
- **Problem Description**:
  You have rented a car for a trip of K kilometers and received it with B liters of fuel. During the trip, you stop at N locations to refuel. The car's consumption is L liters per 100 kilometers.

- **Task**:
  Write a program that calculates the minimum number of refueling stops required during the trip.

- **Input**:
  - The first line of standard input contains the length of the trip K (1 ≤ K ≤ 100100), the number of refueling stops N (1 ≤ N ≤ 1000), the initial fuel in the car B (1 ≤ B ≤ 100), and the consumption per 100 kilometers L (1 ≤ L ≤ 10).
  - The following N lines each contain two integers Holi and Mennyiti, indicating the distance from the starting point to the gas station Holi (1 ≤ Holi < Holi+1 ≤ K) and the amount of fuel refilled Mennyiti (1 ≤ Mennyiti ≤ 100), in the order of refueling.

- **Output**:
  - The program should output the minimum number of refueling stops needed during the trip.

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
  - The constraints ensure that the computation can be performed within a reasonable time frame.
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
The provided code attempts to solve the problem of calculating the minimum number of refueling stops needed during a trip with a rented car. Below is a step-by-step explanation of the code:

1. **Understanding the Problem**:
   - The program receives input for the length of the trip (K), the number of refueling stops (N), the initial fuel in the car (B), the consumption per 100 kilometers (L), and the distances and amounts of fuel refilled at each refueling stop.
   - The goal is to calculate the minimum number of refueling stops needed during the trip.

2. **Approach**:
   - The program uses a priority queue to keep track of the maximum fuel that can be refueled at each gas station.
   - It iterates through the gas stations in order of distance, refueling the car to maximize the amount of fuel at each stop and minimize the number of stops.

3. **Algorithm**:
   - Read the input values for trip length (K), number of refueling stops (N), initial fuel (B), and consumption per 100 kilometers (L).
   - Read the distances and amounts of fuel refilled at each refueling stop, and store them in a vector (gas).
   - Sort the gas stations based on their distance.
   - Calculate the maximum distance that can be covered with the initial fuel (d = 100 * (fuel / fuelCons)).
   - Initialize variables for position (pos) and result (res).
   - Iterate while the maximum distance is less than the trip length (n).
     - Increment the result (res) for each refueling stop.
     - Iterate through the gas stations, refueling the car and updating the maximum distance.
   - Output the minimum number of refueling stops (res).

4. **Output**:
   - Output the minimum number of refueling stops needed during the trip.

5. **Time Complexity**:
   - The time complexity of the algorithm is O(N log N) due to sorting the gas stations based on distance.
   - The overall time complexity is dominated by the sorting operation.

Overall, the program efficiently calculates the minimum number of refueling stops needed during the trip based on the given trip length, fuel capacity, fuel consumption, and gas station information.
*/