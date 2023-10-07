#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
**Problem Summary:**

Given the ages of the oldest and newest fossils for several extinct animal species, determine the maximum number of species that lived during a single year and identify the oldest year in which this occurred.

**Input:**

- The age of the oldest fossil and the number of species (M, N).
- N lines, each containing the age of the oldest and newest fossil for a species.

**Output:**

- The number of species that lived in a single year (K).
- The oldest year in which K species were alive.

**Example:**

- **Input:**
  ```
  10 5
  8 3
  2 1
  9 6
  10 10
  7 5
  ```

- **Output:**
  ```
  3
  7
  ```

This means that 3 species lived in a single year, and this happened 7 years ago.


*/
struct in{
    int n;
    char c;
};

struct Compare{
    bool operator()(in const& p1,in const& p2){
        if(p1.n == p2.n) return p1.c<p2.c;
        return p1.n<p2.n;
    }
};

int main()
{
    int m,n;
    cin>>m>>n;
    vector<in> v;
    for(int i=1; i<=n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({y,'x'});
        v.push_back({x,'y'});
    }
    sort(v.begin(),v.end(),Compare());
    int count = 0;
    int maxTime = 0, index = 0;
    for(int i=0; i<v.size(); i++){
        if(v[i].c == 'x') count++;
        else {
            if(count == maxTime) index = max(index,v[i].n);
            count--;
        }
        maxTime = max(maxTime,count);
    }
    cout<<maxTime<<'\n'<<index;
    return 0;
}
/*
Of course! Let's delve into the approach in more detail, step by step.

### 1. Input Processing:
The program starts by reading two integers, `M` and `N`, representing the age of the oldest fossil and the number of species, respectively. After that, it reads `N` lines, each containing two integers: the age of the oldest and newest fossil for a species. This information is stored in a vector of structures (`v`), where each structure (`in`) contains the age and a character `'x'` or `'y'` representing the newest and oldest fossils, respectively.

### 2. Sorting by Age:
For each species, the program creates two entries in the vector `v`, one for the oldest fossil (`'y'`) and one for the newest fossil (`'x'`). It then sorts the vector based on the ages in ascending order, ensuring that the oldest fossils are considered first.

### 3. Finding Maximum Number of Species in a Year:
The program iterates through the sorted vector, maintaining three variables:
- `count`: The count of species for the current year.
- `maxTime`: The maximum count of species in a year seen so far.
- `index`: The year (oldest fossil age) where the maximum count occurred.

When encountering the newest fossil (`'x'`), it increases the `count`, indicating that one more species is present in the current year. When encountering the oldest fossil (`'y'`), it decreases the `count`, indicating that a species from the current year has ended. It then updates `maxTime` and `index` accordingly.

### 4. Output:
Finally, the program prints the maximum number of species that lived in a single year (`maxTime`) and the oldest year in which this maximum count occurred (`index`).

### Example Walkthrough:
Let's revisit the provided example and follow the algorithm's steps:

- **Input**:
  ```
  10 5
  8 3
  2 1
  9 6
  10 10
  7 5
  ```

- **Sorting by Age**:
  - The vector `v` is constructed and sorted based on the ages:
    ```
    [(1, 'y'), (2, 'y'), (3, 'x'), (5, 'y'), (6, 'x'), (7, 'y'), (8, 'y'), (9, 'x'), (10, 'x'), (10, 'y')]
    ```

- **Finding Maximum Number of Species in a Year**:
  - The algorithm processes the sorted vector and tracks the maximum number of species in a year (`maxTime`) and the oldest year where this occurred (`index`).

- **Output**:
  ```
  3
  7
  ```

This means that 3 species lived in a single year, and this happened 7 years ago.

The program efficiently determines the maximum number of species in a year and the corresponding oldest year.
*/