#include <iostream>
#include <vector>

using namespace std;
/*
- **Problem Description**:
  A mountain climber needs to climb a mountain which has a path passing through N camps. The duration to travel between the camps varies, including different durations for going up and coming down. The climber starts from the first camp, reaches the last camp at the summit, then descends back to the first camp. During the journey, the climber can rest at the camps. Additionally, it is known how many minutes the climber can walk without resting.

- **Task**:
  Create a program that determines the minimum number of places and where the climber needs to rest.

- **Input**:
  - The first line of standard input contains the number of camps N (1 ≤ N ≤ 10,000) and the maximum duration the climber can walk without resting M (1 ≤ M ≤ 1000).
  - The following N-1 lines each contain two integers Feli and Lei (1 ≤ Feli, Lei ≤ M), representing the duration needed to travel from the i-th camp to the (i+1)-th camp, both going up and coming down.

- **Output**:
  - The first line of the output should contain an integer H, the minimum number of places where the climber needs to rest.
  - The second line should contain H integers, the indices of the camps where the climber rests, in the order of the rests.

- **Example**:
  - **Input**:
    ```
    6 100
    20 20
    30 20
    60 30
    10 30
    30 10
    ```
  - **Output**:
    ```
    3
    3 6 2
    ```

- **Constraints**:
  - The constraints ensure that the computation can be performed within a reasonable time frame.
*/
int main()
{
    int n,p;
    cin>>n>>p;
    vector< pair<int,int> > v;
    for(int i=1; i<n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    int sum = 0;
    vector<int> res;
    for(int i=0; i<v.size(); i++){
        sum += v[i].first;
        if(sum>p){
            i--;
            res.push_back(i+2);
            sum = 0;
        }
    }
    for(int i=v.size()-1; i>=0; i--){
        sum += v[i].second;
        if(sum>p){
            i++;
            res.push_back(i+1);
            sum = 0;
        }
    }
    cout<<res.size()<<'\n';
    for(auto i:res) cout<<i<<" ";
    return 0;
}
/*
The provided code attempts to solve the problem of determining the minimum number of places where a climber needs to rest while climbing a mountain with various camps and travel durations. Here's a step-by-step explanation of the code:

1. **Understanding the Problem**:
   - The program takes input for the number of camps (N) and the maximum duration the climber can walk without resting (M).
   - Each camp is associated with a travel duration needed to reach the next camp and the duration needed to descend back.

2. **Approach**:
   - The program iterates through the camps, calculating the cumulative duration of travel and checks if it exceeds the maximum duration without resting (M).
   - If it exceeds M, it considers the current camp as a rest point and resets the cumulative duration.

3. **Algorithm**:
   - Read the number of camps (N) and the maximum duration without resting (M).
   - Iterate through the camps, accumulating the travel durations and considering rest points when the cumulative duration exceeds M.
   - Iterate in reverse order to consider rest points during the descent as well.
   - Output the minimum number of rest points and the indices of the camps where the climber rests.

4. **Output**:
   - Output the minimum number of rest points (`res.size()`) and the indices of the camps where the climber rests.

5. **Time Complexity**:
   - The time complexity of the algorithm is O(N), where N is the number of camps.

Overall, the program efficiently calculates the minimum number of places where the climber needs to rest based on the given camps and travel durations.
*/