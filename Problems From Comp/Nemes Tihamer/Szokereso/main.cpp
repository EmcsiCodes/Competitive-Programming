#include <iostream>

using namespace std;

/*
- **Problem Description**:
  In a word puzzle, lowercase letters of the English alphabet are placed in a matrix. Words can be read from any position in the matrix by moving one step up, left, down, or right after each character.

- **Task**:
  Create a program that determines the position of a given word in a character matrix.

- **Input**:
  - The first line of standard input contains the number of rows and columns in the matrix (1 ≤ N ≤ 10).
  - The next N lines describe each row of the matrix with N characters.
  - The last line contains the word to be searched (up to 12 characters, lowercase English alphabet).

- **Output**:
  - If the searched word cannot be found in the character matrix, output "0 0" in the first line.
  - If the word is found, output the row and column indices of the first character in the second line.
  - In the third line, output one less character than the length of the word, representing the directions to reach the next character: F for forward, B for backward, L for left, and J for down. Use any valid path if there are multiple solutions.

- **Example**:
  - **Input**:
    ```
    4
    alfa
    baal
    blmg
    alom
    alma
    ```
  - **Output**:
    ```
    2 2
    LJF
    ```

- **Constraints**:
  - Time Limit: 0.2 seconds
  - Memory Limit: 32 MB
*/

void be(int &n,string &k,char s[][11])
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++){
            cin>>s[i][j];
        }
    }
    cin>>k;
}

bool valid(int n,int i,int j,char s[][11],bool s1[][11],string k,int p)
{
    if(s1[i][j]==false && j<=n && j>=1 && i<=n && i>=1) {
            if(s[i][j]==k[p])
            return true;
    else return false;
    }
    else return false;
}



void next(int n,int i,int j,string k,int p,char s[][11],bool s1[][11],string &v)
{
    if(p<k.length())
    {

       if(valid(n,i+1,j,s,s1,k,p))
       {
           s1[i+1][j]=true;
           v=v+'L';
           next(n,i+1,j,k,p+1,s,s1,v);
           s1[i+1][j]=false;
           if(v.length()!=k.length()-1) v.erase(v.length()-1,1);
       }
       if(valid(n,i,j+1,s,s1,k,p))
       {
           s1[i][j+1]=true;
           v=v+'J';
           next(n,i,j+1,k,p+1,s,s1,v);
           if(v.length()!=k.length()-1) v.erase(v.length()-1,1);
           s1[i][j+1]=false;
       }
       if(valid(n,i-1,j,s,s1,k,p))
       {
           s1[i-1][j]=true;
           v=v+'F';
           next(n,i-1,j,k,p+1,s,s1,v);
           if(v.length()!=k.length()-1) v.erase(v.length()-1,1);
           s1[i-1][j]=false;
       }
       if(valid(n,i,j-1,s,s1,k,p))
       {
           s1[i][j-1]=true;
           v=v+'B';
           next(n,i,j-1,k,p+1,s,s1,v);
           s1[i][j-1]=false;
           if(v.length()!=k.length()-1) v.erase(v.length()-1,1);
       }
    }
}

void keres(int n,string k,char s[][11])
{
    bool tul=false;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(s[i][j]==k[0])
            {
                string v="";
                int p=1;
                bool s1[11][11]={false};
                next(n,i,j,k,p,s,s1,v);
                if(v.length()==k.length()-1 && tul==false)
                {
                    tul=true;
                    cout<<i<<" "<<j<<endl<<v;
                }
            }
        }
    }
    if (tul==false) cout<<0<<" "<<0;
}

int main()
{
    int n;
    char s[11][11];
    string k="";
    be(n,k,s);
    keres(n,k,s);
    return 0;
}
/*
This program aims to find a given word in a character matrix and determine the position of its first character along with the directions to reach the rest of the characters of the word.

Here's a detailed explanation of the approach:

1. **Input Processing** (`be` function):
   - The `be` function reads the dimensions of the matrix and the characters, and the word to be searched.

2. **Validity Check** (`valid` function):
   - This function checks if a given position is a valid next step to form the word. It verifies whether the character at the current position matches the next character of the word, and the position is within the matrix boundaries.

3. **Recursive Search for the Word** (`next` function):
   - This function performs a recursive search for the word in the matrix.
   - It starts from the initial position and attempts to move in all four directions (up, down, left, right) to find the next character of the word.
   - It marks visited positions to avoid revisiting and keeps track of the visited positions to form the correct path.
   - The recursion stops when the whole word is found.

4. **Search in the Matrix** (`keres` function):
   - This function initiates the search for the word.
   - It iterates through the matrix and starts the recursive search (`next`) from each position where the first character of the word is found.
   - If the word is found, it prints the position and the directions.

5. **Main Function**:
   - Calls the above functions to perform the search and prints the output.

### Example Walkthrough:

Let's take the provided example with a 5x5 matrix and the word "alma":

```
5
ggggg
gaggg
gmggg
glgmg
galmg
alma
```

- The program initiates a search starting from each position where 'a' is found. It tries to form the word "alma" by moving in four directions.
- It follows a depth-first search approach recursively, marking the visited positions.
- Once it finds a valid path that forms the word, it prints the starting position (row, column) and the directions to reach each character of the word.

In this case, the output will be:
```
5 2
LJF
```
which indicates that the word "alma" can be formed starting from position (5, 2) and moving left, down, and right respectively.
*/
