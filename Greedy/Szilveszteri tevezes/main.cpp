#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Here's a summary of the problem "Szilveszteri tévézés" (New Year's Eve TV Watching):

- **Problem Description**:
  On your TV set, you can tune in to N television channels simultaneously. On New Year's Eve, each channel broadcasts movies, and you want to watch as many complete movies as possible. However, you can only watch one movie at a time and you won't start watching a movie if you've missed even a minute of it.

- **Task**:
  Create a program that selects the maximum number of movies you can watch and lists their details.

- **Input**:
  - The first line of standard input contains the number of movies N (1 ≤ N ≤ 100).
  - The next N lines each contain the description of a movie in the format: channel number, start time (hour, minute), end time (hour, minute).

- **Output**:
  - The program should output two numbers in the first line: the maximum M of watchable movies and their total time in minutes.
  - The following M lines should contain the indices of the selected movies, in the order of their start times.

- **Example**:
  - **Input**:
    ```
    5
    1 18 0 22 0
    1 6 0 10 0
    3 8 0 10 0
    3 14 0 18 0
    2 12 0 20 0
    ```
  - **Output**:
    ```
    3 720
    2
    4
    1
    ```

- **Constraints**:
  - The constraints ensure that the computation can be performed within a reasonable time frame.
*/
struct in{
    int start;
    int end;
    int i;
};

struct Compare{
    bool operator()(in const& p1,in const& p2){
        return p1.end < p2.end;
    }
};

int main()
{
    int n;
    cin>>n;
    vector<in> v;
    for(int i=1; i<=n; i++){
        int a,ko,kp,vo,vp,x,y;
        cin>>a>>ko>>kp>>vo>>vp;
        x = kp + 60 * ko;
        y = vp + 60 * vo;
        v.push_back({x,y,i});
    }
    sort(v.begin(),v.end(),Compare());
    vector<int> res;
    int time = 0;
    auto start = v.begin();
    while(start!=v.end()){
        time += start->end - start->start;
        res.push_back(start->i);
        auto it = start;
        while(it!=v.end() && it->start < start->end) it++;
        start = it;
    }
    cout<<res.size()<<" "<<time<<'\n';
    for(auto i:res) cout<<i<<" ";
    return 0;
}
/*
This program solves the problem of selecting the maximum number of movies to watch on New Year's Eve based on their start and end times. Here's a step-by-step explanation:

1. **Understanding the Problem**:
   - The program takes input for the number of movies `N`.
   - For each movie, it takes input in the format: channel number, start time (hour, minute), and end time (hour, minute).

2. **Approach**:
   - It represents each movie by its start and end times in minutes from midnight.
   - It sorts the movies based on their end times in non-decreasing order.
   - It iterates through the sorted movies and selects each movie that has a start time greater than or equal to the end time of the previous selected movie.
   - It keeps track of the total time spent watching the selected movies.

3. **Output**:
   - The program outputs the maximum number of selected movies `M` and their total time in minutes.
   - It also outputs the indices of the selected movies in the order of their start times.

4. **Explanation**:
   - The program efficiently selects movies to maximize the total watch time while ensuring that no movie is missed due to overlapping time frames.
   - It considers each movie's start and end times and selects them based on their end times.

5. **Time Complexity**:
   - The time complexity of the algorithm is O(N log N) due to the sorting of the movies based on their end times.

This approach effectively selects the maximum number of non-overlapping movies to watch, optimizing the total watch time.
*/