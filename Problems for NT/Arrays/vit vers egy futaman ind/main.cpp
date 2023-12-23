#include <iostream>
#include <vector>
#include <map>

using namespace std;
/*
The problem involves a sailing race with multiple races (F futams). For each race, there is a list of participants and their IDs. The task is to identify those participants who participated in exactly one race and list their IDs in ascending order. The input specifies the number of races and the participants for each race,
and the output should provide the count and IDs of participants who participated in exactly one race.
Input Description:

The input starts with the number of races (F) that were held (1 ≤ F ≤ 10).
This is followed by F lines, each containing information about the participants in a particular race. The line starts with the number of participants (Indi) in that race (0 ≤ Indi ≤ 100), followed by the IDs of those participants (up to 4-digit positive integers).
Output Description:

The output begins with the count (K) of participants who participated in exactly one race.
The next line contains the IDs of these participants in ascending order.
Problem Constraints:

The number of races (F) is between 1 and 10.
The number of participants (Indi) in a race is between 0 and 100.
Participant IDs are positive integers up to 4 digits.
There are constraints on the time and memory limits for the program.
Task and Objective:

The goal is to identify participants who were exactly in one race and list their IDs in ascending order.
Example:

Given F = 3 (three races), and the participant lists for each race, the program should determine the participants who participated in exactly one race and output their IDs in ascending order.
Scoring:

The problem has a specific scoring scheme where it's worth 33% of the score when F=2. This implies that getting the correct solution for 2 races is particularly important.
*/
int main() {
    int f;
    cin >> f;  // Number of races
    vector<vector<int>> v;

    // Reading information for each race
    for (int i = 0; i < f; i++) {
        int x;
        vector<int> v1;
        cin >> x;  // Number of participants in this race
        for (int j = 0; j < x; j++) {
            int y;
            cin >> y;  // Participant ID
            v1.push_back(y);
        }
        v.push_back(v1);
    }

    map<int, int> m;

    // Counting occurrences of participant IDs across races
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            m[v[i][j]]++;
        }
    }

    int c = 0;

    // Counting participants who participated in exactly one race
    for (auto it : m) {
        if (it.second == 1)
            c++;
    }

    if (c == 0)
        cout << 0;  // No participants participated in exactly one race
    else {
        cout << c << endl;  // Number of participants who participated in exactly one race
        for (auto it : m) {
            if (it.second == 1)
                cout << it.first << " ";  // IDs of participants who participated in exactly one race
        }
    }

    return 0;
}
/*
Input Reading:

The program starts by reading the number of races, f, from the user.
It then creates a vector of vectors, v, to store the participant IDs for each race.
Reading Participant Information:

For each race:
Read the number of participants in the current race, denoted as x.
Create a vector v1 to store the participant IDs for this race.
Read each participant's ID and add it to the vector v1.
Add the vector v1 to the main vector v, representing the current race.
Counting Participants:

Create a map, m, to count the occurrence of each participant's ID across all races.
Iterate through each race and count the occurrences of participant IDs using the map m.
Identifying Participants in Exactly One Race:

Iterate through the map m and count the participants who participated in exactly one race.
Print the count and the IDs of these participants in ascending order.
*/