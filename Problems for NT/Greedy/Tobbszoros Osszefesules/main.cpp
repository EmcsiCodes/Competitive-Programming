#include <iostream>
#include <vector>
#include <set>
using namespace std;
/*
Here's a summary of the problem "Többszörös összefésülés" (Multiple Merging):

- **Problem Description**:
  Given a list of class sizes in a school, your task is to find the minimum number of steps required to merge the class lists into a single sorted list using a merging algorithm. The merging algorithm can merge two sorted sequences into a single sorted sequence, and the number of steps is the sum of the lengths of the input sequences.

- **Task**:
  Create a program that calculates the minimum number of steps needed to merge the class lists into a single sorted list.

- **Input**:
  - The first line of standard input contains the number of classes N (1 ≤ N ≤ 100,000).
  - The second line contains the number of students in each class Ti (1 ≤ Ti ≤ 1,000).

- **Output**:
  - The program should output the minimum number of steps required to merge the class lists.

- **Example**:
  - **Input**:
    ```
    3
    10 3 4
    ```
  - **Output**:
    ```
    24
    ```

- **Constraints**:
  - The constraints ensure that the computation can be performed within a reasonable time frame.
*/
int main()
{
    int n;
    cin>>n;
    multiset<int> s;
    for(int i=1; i<=n; i++){
        int x; cin>>x;
        s.insert(x);
    }
    int res = 0;
    while(s.size()>1){
        auto last2 = s.begin();
        auto last1 = last2;
        last2++;
        int curr = *last1 + *last2;
        res += curr;
        s.erase(last1);
        s.erase(last2);
        s.insert(curr);
    }
    cout<<res;
    return 0;
}
/*
The provided code efficiently calculates the minimum number of steps required to merge class lists into a single sorted list using a merging algorithm. Here's a step-by-step explanation of the code:

1. **Understanding the Problem**:
   - The program takes input for the number of classes and the number of students in each class.
   - The task is to merge the class lists using a merging algorithm, where each merge step involves merging two sorted sequences into one.

2. **Approach**:
   - The program uses a `multiset` to keep track of the sizes of the classes.
   - It iteratively performs merges, where at each step, it merges the two smallest class sizes.
   - The number of steps is calculated as the sum of the sizes of the merged classes in each step.

3. **Merging Algorithm**:
   - At each step:
     - It retrieves the two smallest class sizes by accessing the first and second elements in the `multiset`.
     - It calculates the sum of these two sizes, which represents the merged class size.
     - It adds this merged class size to the result.
     - It removes the two smallest sizes from the `multiset`.
     - It inserts the merged class size into the `multiset`.

4. **Output**:
   - The program outputs the minimum number of steps required to merge the class lists.

5. **Time Complexity**:
   - The time complexity of the merging algorithm is O(N log N), where N is the total number of students across all classes.
   - The merging algorithm iterates until there is only one merged class left.

Overall, the program efficiently calculates the minimum number of steps needed to merge class lists into a single sorted list using a merging algorithm. It uses a `multiset` to keep track of class sizes and performs merges iteratively, summing the merged class sizes to determine the total number of steps.
*/