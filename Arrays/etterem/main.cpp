#include <iostream>
#include <map>
using namespace std;
/*
Summary of the Programming Problem "Étterem":

A chef in a restaurant provided information about the quantity and type of ingredients used for each dish they prepare.

Write a program that determines the total amount of each ingredient used in the restaurant.

Input:

The first line of the standard input contains the number of dishes (N) (1≤N≤100).
The next N lines contain the ingredients for each dish.
In each line, the first number represents the number of ingredients used (0≤Alapi≤100), followed by Alapi pairs of numbers representing the ingredient code (1≤Si,j≤100,000) and the quantity used (1≤Mi,j≤100).
Output:

The output should first list the number K of unique ingredients used.
The following K lines should contain the ingredient code and the total quantity used, in ascending order of the ingredient code.
Example:

Given the number of dishes and the ingredients for each dish, determine the total quantity of each ingredient used in the restaurant.
Constraints:

Time limit for input processing: 0.1 seconds
Memory limit: 32 MB
In 33% of the tests, N=2.
*/
int main()
{
    int n;
    map<int, int> m;

    // Step 1: Read the number of dishes (N)
    cin >> n;

    // Step 2: Iterate through each dish and its ingredients
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;

        // Step 3: Count the quantity of each ingredient
        for (int j = 1; j <= k; j++)
        {
            int x, y;
            cin >> x >> y;
            m[x] += y;
        }
    }

    // Step 4: Output the number of unique ingredients and their total quantities
    cout << m.size() << endl;
    for (auto i = m.begin(); i != m.end(); i++)
    {
        cout << i->first << " " << i->second << endl;
    }

    return 0;
}
/*
Explanation of the Program's Approach:

Input Reading:

The program starts by reading the number of dishes (n).
Iterate through Each Dish:

For each dish, it reads the number of ingredients (k) and the ingredient codes along with their quantities.
Counting Ingredients:

It counts the total quantity of each ingredient by using a map. The map's key is the ingredient code, and the value is the total quantity of that ingredient.
Output:

Finally, it prints the number of unique ingredients and their total quantities in ascending order of the ingredient code.
The program efficiently determines the total quantity of each ingredient used in the restaurant based on the given inputs and constraints.
*/