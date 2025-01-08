# Write-Up: Solution to [Repetitions](https://cses.fi/problemset/task/1069)

## Problem Description

The problem involves finding the longest repetition in a given DNA sequence. A repetition is defined as a maximum-length substring containing only one type of character (A, C, G, or T).

### Input:
- A single string of length \( n \) (\( 1 ≤ n ≤ 10^6 \)).

### Output:
- A single integer: the length of the longest repetition.

### Example:
#### Input:
```
ATTCGGGA
```

#### Output:
```
3
```

---

## Approach to the Solution

1. **Understanding the Problem**:  
   - The task is to identify the longest contiguous substring in the DNA sequence where all characters are the same.  

2. **Efficiency Considerations**:  
   - Given the constraints (\( n ≤ 10^6 \)), the solution must operate in \( O(n) \) time to ensure it runs efficiently for large inputs.  

3. **Algorithm**:  
   - Traverse the string from left to right, keeping track of:
     - The current repetition count currentRepetition.
     - The maximum repetition count observed so far maxRepetition.
   - If the current character matches the previous character, increment currentRepetition.  
   - Otherwise, compare currentRepetition with maxRepetition, update maxRepetition if needed, and reset currentRepetition to 1.  
   - At the end of the traversal, perform a final comparison to ensure maxRepetition accounts for the last repetition.

---

## Implementation in C++

The following code implements the described solution:

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string dna;
    cin >> dna;

    long long maxRepetition = 1;   // Maximum repetition length
    long long currentRepetition = 1; // Current repetition length

    // Iterate through the DNA sequence
    for (int i = 1; i < dna.length(); ++i) {
        if (dna[i] == dna[i - 1]) {
            currentRepetition++; // Increase repetition length
        } else {
            // Update maxRepetition and reset currentRepetition
            maxRepetition = max(maxRepetition, currentRepetition);
            currentRepetition = 1;
        }
    }

    // Final update for maxRepetition
    maxRepetition = max(maxRepetition, currentRepetition);

    // Output the result
    cout << maxRepetition << endl;

    return 0;
}
```

---

## Explanation of the Code

1. **Input Handling**:  
   - The DNA sequence is read as a string.  

2. **Iterating Through the String**:  
   - The loop starts from the second character and compares it with the previous character:
     - If the characters match, currentRepetition is incremented.  
     - Otherwise, maxRepetition is updated (if needed), and currentRepetition is reset to 1.  

3. **Final Update**:  
   - After the loop, maxRepetition is updated to ensure the last repetition is considered.  

4. **Output**:  
   - The length of the longest repetition is printed.

---

## Complexity Analysis

1. **Time Complexity**:  
   - The solution iterates through the string once, making it \( O(n) \).  

2. **Space Complexity**:  
   - The solution uses a constant amount of additional memory (\( O(1) \)).  

---

## Key Insights

- The algorithm uses a single pass to compute the result, making it highly efficient for large input sizes.  
- The problem is well-suited for a sliding-window or two-pointer-like approach, though a simple iteration suffices.  
- The use of basic operations (comparisons and increments) ensures the solution is both fast and lightweight.  
