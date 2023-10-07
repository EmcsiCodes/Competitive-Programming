#include <iostream>
#include <vector>
#include <set>
using namespace std;
/*
Here's a summary of the problem "Tűzijáték" (Fireworks):

- **Problem Description**:
  A company wants to organize fireworks in some towns along a road. According to environmental regulations, any two fireworks must be at least T kilometers apart. The company expects to have fireworks at its headquarters.

- **Task**:
  Create a program that calculates the maximum number of fireworks the company can organize and which towns they should be organized in.

- **Input**:
  - The first line of standard input contains the number of towns N (1 ≤ N ≤ 100,000), the town number where the company is headquartered S (1 ≤ S ≤ N), and the minimum distance between fireworks T (1 ≤ T ≤ 100,000).
  - The second line contains the distances of the towns from the first town, in increasing order (0 ≤ Tavi ≤ 50,000,000) - the first number is 0 since the first town is at a distance of 0 from itself.

- **Output**:
  - The program should output the maximum number of fireworks that can be organized, followed by the town numbers where the fireworks should be organized in increasing order.

- **Example**:
  - **Input**:
    ```
    6 4 100
    0 70 110 210 230 500
    ```
  - **Output**:
    ```
    4
    1 3 4 6
    ```

- **Constraints**:
  - The constraints ensure that the computation can be performed within a reasonable time frame.
*/
int main()
{
    int n,start,t;
    cin>>n>>start>>t;
    vector<int> v;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    set<int> res;
    res.insert(start-1);
    int last = v[start-1];
    for(int i=start; i<v.size(); i++){
        if(last + t <= v[i]) {
            last = v[i];
            res.insert(i);
        }
    }
    last = v[start-1];
    for(int i = start - 2; i>=0; i--){
        if(last - t >= v[i]){
            last = v[i];
            res.insert(i);
        }
    }
    cout<<res.size()<<endl;
    for(auto i:res) cout<<i+1<<" ";
    return 0;
}
/*
The provided code efficiently calculates the maximum number of fireworks the company can organize and determines the towns where they should be organized. Here's a step-by-step explanation of the code:

1. **Understanding the Problem**:
   - The program takes input for the number of towns, the town number where the company is headquartered, and the minimum distance between fireworks.
   - The task is to determine the maximum number of fireworks that can be organized, given the constraint of minimum distance between fireworks.

2. **Approach**:
   - The program iterates through the towns, starting from the headquarters (town S), and determines the towns where fireworks can be organized while maintaining the minimum distance constraint.
   - It uses a set to store the indices of towns where fireworks can be organized.

3. **Algorithm**:
   - Starting from the headquarters, it iterates through the towns:
     - If the current town's distance is at least the minimum distance plus the distance of the last organized fireworks (initially set to the distance of the headquarters), it adds this town to the set and updates the last distance of organized fireworks.
   - It repeats the above step in both forward and backward directions from the headquarters to cover all possible fireworks locations.

4. **Output**:
   - The program outputs the maximum number of fireworks that can be organized and the town numbers where the fireworks should be organized, in increasing order.

5. **Time Complexity**:
   - The time complexity of the algorithm is O(N), where N is the number of towns.
   - The algorithm iterates through the towns once in both forward and backward directions, and inserting elements into the set has a time complexity of O(log N).

Overall, the program efficiently calculates the maximum number of fireworks that can be organized and determines the towns where they should be organized, considering the minimum distance constraint.
*/