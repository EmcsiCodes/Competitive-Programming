#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

/*
- **Problem Description**:
  Algernon found a piece of cheese and wants to feed his n mice with it.
  The cheese has the shape of an isosceles triangle, with a base of length b and a height of length h.

  To divide the cheese among the n mice, Algernon wants to make n-1 cuts parallel
  to the base of the triangle, so that the resulting n pieces have the same area.
  Algernon needs to determine where to make these cuts, specifying, in ascending order,
  the distances from the base where the cuts should be made.

- **Input**:
  - The input file "soricei.in" contains the number of test cases t on the first line.
  The following t lines each contain three integers, separated by spaces:
  b (the length of the base), h (the length of the height), and n (the number of mice).

- **Output**:
  - The output file "soricei.out" should contain one line for each test case.
  Each line should print the n-1 distances from the base where the cuts should be made.

  The n-1 distances should be in ascending order and displayed with at least 4 decimal places.

- **Example**:
  - **Input** (soricei.in):
    ```
    1
    4 5 3
    ```
  - **Output** (soricei.out):
    ```
    0.917517 2.113249
    ```

- **Constraints**:
  - 1 ≤ t ≤ 20
  - 1 ≤ b, h ≤ 5000
  - 2 ≤ n ≤ 100
  - Each displayed value can deviate by at most 10^(-4) from the correct answer
*/

int main()
{
    ifstream in("soricei.in");
    ofstream out("soricei.out");
    int testNum;
    in>>testNum;
    for(int i=1; i<=testNum; i++){
        double b,h,n;
        in>>b>>h>>n;
        double curr, prev = 0;
        for(int i=1; i<n; i++){
            curr = (h - prev)*(1 - sqrt((n - i)/(n - i + 1))) + prev;
            out<<fixed<<setprecision(6)<<curr<<" ";
            prev = curr;
        }
    }
    return 0;
}
/*
This program aims to determine where to make cuts on a cheese triangle
to divide it among a specific number of mice evenly.

Here's a step-by-step explanation of the program:

1. **Input Reading**:
   - The program reads the input from a file named "soricei.in".
   - It reads the number of test cases, `testNum`, from the first line.
   - For each test case, it reads three integers: `b` (base length), `h` (height), and `n` (number of mice).

2. **Calculating Cut Positions**:
   - It calculates the positions to make cuts in the cheese so that the resulting pieces have the same area.
   - It iterates `i` from 1 to `n-1` and calculates the cut position, `curr`, using the formula:

     ```
     curr = (h - prev) * (1 - sqrt((n - i) / (n - i + 1))) + prev
     ```

     where `prev` is the previous cut position (initialized to 0 for the first cut),
     `h` is the height, and `n` is the number of mice.

3. **Output Writing**:
   - It writes the calculated cut positions for each test case to the output file "soricei.out".
   - The positions are displayed with exactly 6 decimal places using the `fixed` and `setprecision` manipulators.

### Why this Works:

- The program follows the given geometric approach to divide the cheese triangle into
equal area parts by calculating the appropriate cut positions along the base of the triangle.

Overall, the program accurately calculates the positions to make cuts in the cheese
triangle for each test case and provides the correct output accordingly.
*/