#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
/*
- **Problem Description**:
  You have recorded the number of mobile phones sold daily for N days. Create a program that finds two days, where on the first day the sales were the lowest and on the last day they were the highest, with the maximum difference in sales.

- **Input**:
  - The first line of the standard input contains the number of days N (1 ≤ N ≤ 200,000).
  - The following N lines contain the number of mobile phones sold on each day (1 ≤ Ki ≤ 200,000).

- **Output**:
  - The program should output the two days (not necessarily distinct) such that the first day had the lowest sales, the last day had the highest sales, and the difference in sales is the maximum possible. If there are multiple solutions with the same maximum difference, output the one with the smallest first day, and within that, the smallest second day.

- **Example**:
  - **Input**:
    ```
    7
    10
    12
    5
    6
    8
    3
    4
    ```
  - **Output**:
    ```
    3 5
    ```

- **Constraints**:
  - Time Limit: 0.2 seconds
  - Memory Limit: 32 MB
*/
int main()
{
    int n;
    cin>>n;
    vector<int> v;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    pair<int,int> index = {0,0};
    int maxSell = 0;
    int currSell = 0;
    int currIndex = 0;
    int start = 0;
    for(int i=0; i<v.size()-1; i++){
        if(v[start]<=v[i+1]){
            if(currSell<v[i+1] - v[start]){
                currSell = v[i+1] - v[start];
                currIndex = i+1;
            }
        } else {
            if(currSell>maxSell){
                maxSell = currSell;
                index = {start,currIndex};
            }
            currSell = 0;
            currIndex = 0;
            start = i+1;
        }
    }
    if(currSell!=0){
        if(currSell>maxSell){
            maxSell = currSell;
            index = {start,currIndex};
        }
    }
    cout<<index.first+1<<" "<<index.second+1;
    return 0;
}
/*
The given program aims to find two days in a series of recorded mobile phone sales, where the first day had the lowest sales, the last day had the highest sales, and the difference in sales is the maximum possible.

Here's a detailed explanation of the provided C++ program:

1. **Input Reading**:
   - The program reads the number of days (N) and the number of mobile phones sold on each day.

2. **Finding Maximum Sales Difference**:
   - It iterates through the sales data and keeps track of the maximum sales difference (`maxSell`) and the corresponding days (`index`) where the difference occurs.
   - It keeps track of the current sales difference (`currSell`) and updates it whenever the sales increase.
   - When a decrease in sales is encountered, it updates the maximum sales difference (`maxSell`) if the current difference (`currSell`) is greater.
   - It then resets the current difference (`currSell`) and updates the start day (`start`) for the next potential sales increase.

3. **Output**:
   - The program prints the days (`index`) where the maximum sales difference occurs.

### Example Interpretation

For the given example with sales data:
```
10
12
5
6
8
3
4
```

- The program finds that the maximum sales difference occurs between day 3 and day 5, with a difference of 8. Therefore, it outputs `3 5`, representing the two days where the difference is maximum.

### Note
- The program assumes that the input is well-formed and follows the constraints specified in the problem description.
- It only finds the first instance of the maximum sales difference, considering the first occurrence of the lowest sales day and the last occurrence of the highest sales day.
*/