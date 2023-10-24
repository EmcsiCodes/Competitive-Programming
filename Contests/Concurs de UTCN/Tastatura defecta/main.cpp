#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>

using namespace std;

/*
- **Problem Description**:
  Elena is participating in a programming contest, but she notices with surprise that her keyboard has a defect.
  Specifically, when pressing certain keys, the character is transmitted to the computer twice.
  Elena wants to find out how many keys have this defect, so she randomly types a text and looks at the result.

  Given the typed text and the text that appears on the screen, count how many keys are definitely defective.

- **Input**:
  - The input file "tastatura2.in" contains multiple test examples. Each example consists of exactly two lines,
  representing the text typed by Elena and the text that appears on the screen.

  Both strings are composed of lowercase letters, digits, and spaces.
  It is known that the space key cannot be defective.

  The file ends with a line containing the character *.

- **Output**:
  - The output file "tastatura2.out" contains one line for each test example,
  printing the number of defective keys.

- **Example**:
  - **Input** (tastatura2.in):
    ```
    ana are mere
    aanaa aarre merre
    telefon 0721333445
    tellefonn 0721333333445
    *
    ```
  - **Output** (tastatura2.out):
    ```
    2
    3
    ```

- **Constraints**:
  - 1 ≤ |s| ≤ |t| ≤ 2000 (length of the strings)
  - The number of tests does not exceed 50
*/

int main()
{
    ifstream in("tastatura2.in");
    ofstream out("tastatura2.out");
    string s1, s2;
    getline(in,s1);
    while(s1!="*"){
        getline(in,s2);
        unordered_map<char,int> freq1, freq2;
        for(int i=0; i<s1.length(); i++){
            freq1[s1[i]]++;
        }
        for(int i=0; i<s2.length(); i++){
            freq2[s2[i]]++;
        }
        int res = 0;
        for(auto i:freq1){
            if(i.second!=freq2[i.first]) res++;
        }
        out<<res<<'\n';
        getline(in,s1);
    }
    return 0;
}
/*
This program aims to count the number of defective keys on a keyboard by comparing the text typed
by a user and the resulting text displayed on the screen, where some keys may produce double characters.

Here's a step-by-step explanation of the program:

1. **Input Reading**:
   - The program reads the input from a file named "tastatura2.in".
   - It reads two lines for each test example: the text typed by Elena (`s1`) and the
   text that appears on the screen (`s2`).

2. **Defective Key Counting**:
   - It uses two unordered maps, `freq1` and `freq2`, to count the frequency of each character
   in the typed text and the resulting text on the screen, respectively.
   - For each character in the typed text (`s1`), it increments its count in `freq1`.
   - For each character in the resulting text on the screen (`s2`), it increments its count in `freq2`.

3. **Comparison and Counting Defective Keys**:
   - It then compares the frequencies of characters between `freq1` and `freq2`.
   - If the frequency of a character in `freq1` is different from its frequency in `freq2`,
   it means that key is defective, so it increments the result counter `res`.

4. **Output Writing**:
   - It writes the result (the count of defective keys) for each test example to the output file "tastatura2.out".

5. **Loop for Multiple Test Examples**:
   - The program repeats the above steps for each test example present in the input file
   until it encounters an asterisk (*) indicating the end of the input.

### Why this Works:

- The program effectively counts the frequency of each character in both the typed text and the resulting text.
- By comparing these frequencies, it identifies the defective keys where the frequency of a
character differs between the typed text and the resulting text, indicating a double press.

Overall, the program efficiently calculates the number of defective keys for each test example
and provides the correct output accordingly.
*/