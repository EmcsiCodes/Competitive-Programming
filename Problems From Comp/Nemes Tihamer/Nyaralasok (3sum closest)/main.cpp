#include <iostream>
#include <vector>

using namespace std;
/*
- **Problem Description**:
  You have a budget of F for a vacation over the next N weeks. There are N travel packages advertised by a travel agency, one for each week. You can choose exactly 3 weeks to go on a vacation.

- **Task**:
  Write a program that determines the three weeks in which you should go on vacation to spend the exact amount F most accurately.

- **Input**:
  - The first line of standard input contains the number of weeks, N (3 ≤ N ≤ 5000), and the budget F (1 ≤ F ≤ 1,000,000).
  - The next N lines contain the prices of each travel package, Ki (1 ≤ Ki ≤ 1,000,000), in non-decreasing order.

- **Output**:
  - The program should output the numbers of the three weeks in increasing order, where the total cost is not more than F and is the closest to F. If there is no solution, output -1.

- **Example**:
  - **Input**:
    ```
    6 28
    3
    3
    7
    9
    15
    19
    ```
  - **Output**:
    ```
    1 4 5
    ```

- **Constraints**:
  - Time Limit: 0.1 seconds
  - Memory Limit: 32 MB
*/
struct triple{
    int one;
    int two;
    int three;
};
vector<int> v;
int closest = 0;
triple res = {0,0,0};

void threeSumClosest(int n,int k){
    for(int i=0; i<v.size(); i++){
        int r = v.size()-1;
        int l = i+1;
        while(l<r){
            int sum = v[i] + v[l] + v[r];
            if(sum <= k){
                if(closest < sum){
                    closest = sum;
                    res = {i+1,l+1,r+1};
                    
                    if(closest == k) return;
                }
                l++;
            }
            if(sum > k){
                r--;
            }
        }
    }
}

int main()
{
    int n,k;
    cin>>n>>k;
    
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    threeSumClosest(n,k);
    if(closest != 0){
        cout<<res.one<<" "<<res.two<<" "<<res.three;
    } else cout<<-1;
    return 0;
}
/*
This program aims to solve a problem where the task is to determine the three weeks for a vacation out of given travel packages that fit within a budget `F`. The objective is to find a combination of three weeks that is closest to the budget `F` without exceeding it.

Here's a step-by-step explanation of the approach:

1. **Reading Input**:
   - The program first reads the number of weeks, `N`, and the budget, `F`.
   - It then reads the prices of each travel package, `Ki`, for each week.

2. **Three-Sum Closest Approach**:
   - The problem can be effectively reduced to finding the closest sum of three numbers to a given target (`F`) without exceeding it.
   - A typical three-pointer approach is used where for each element `v[i]`, two pointers (`l` and `r`) are used to scan the rest of the array to find the closest sum to the target.
   - The `l` pointer starts from `i+1`, and the `r` pointer starts from the end of the array.
   - We keep track of the closest sum encountered and the indices (`i+1`, `l+1`, `r+1`) of the elements that contributed to this sum.

3. **Finding the Closest Sum**:
   - Iterate through the array and for each element `v[i]`, initialize pointers `l = i + 1` and `r = n - 1` (where `n` is the size of the array).
   - While `l` is less than `r`, calculate the sum of the three elements `v[i]`, `v[l]`, and `v[r`.
   - If the sum is less than or equal to `F`, check if it's closer to the current closest sum and update accordingly.
   - Adjust the pointers (`l` and `r`) based on the sum to get closer to the target sum.

4. **Outputting Results**:
   - Print the indices of the three elements that contribute to the closest sum, or `-1` if no valid combination is found.

The key idea here is to use the three-pointer approach to find the closest sum of three numbers to the given target (`F`) without exceeding it. The code then prints the indices of these elements to provide a valid solution.
*/