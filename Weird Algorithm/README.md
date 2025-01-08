# Write-Up: Solution to [Weird Algorithm](https://cses.fi/problemset/task/1068)

## Problem Description

The problem involves simulating a simple algorithm for a given positive integer \( n \). The algorithm works as follows:

1. If \( n \) is even, divide it by 2.
2. If \( n \) is odd, multiply it by 3 and add 1.
3. Repeat the above steps until \( n \) becomes 1.

The task is to output all intermediate values of \( n \), starting from the given input and ending at 1.

### Input:
- A single integer \( n \) such that \( 1 ≤ n ≤ 10^6 \).

### Output:
- A single line containing the sequence of values of \( n \) during the simulation.

### Example:
#### Input:
```
3
```

#### Output:
```
3 10 5 16 8 4 2 1
```

---

## Approach to the Solution

1. **Understand the Algorithm**: The process is straightforward; apply the given rules iteratively to the value of \( n \). The termination condition is when \( n = 1 \).

2. **Constraints Handling**: Since \( n \) can go up to \( 10^6 \), and the intermediate values can grow significantly (though they eventually decrease), the use of a 64-bit integer (`long long` in C++) is necessary to handle large numbers.

3. **Output Requirements**: The sequence is stored in a vector and then printed in a single line with spaces separating the numbers.

4. **Efficiency**: The time complexity of this algorithm depends on the sequence length, which varies but is reasonable for the given constraints.

---

## Implementation in C++

The following code implements the described algorithm:

```cpp
#include <iostream>
#include <vector>
using namespace std;
 
vector<long long> weird_algorithm(long long n) {
    vector<long long> sequence;
    sequence.push_back(n); // Add the initial value to the sequence
    while (n != 1) {       // Continue until n becomes 1
        if (n % 2 == 0) {
            n /= 2;        // If even, divide by 2
        } else {
            n = 3 * n + 1; // If odd, multiply by 3 and add 1
        }
        sequence.push_back(n); // Add the new value to the sequence
    }
    return sequence; // Return the complete sequence
}
 
int main() {
    long long n;
    cin >> n; // Read the input value of n
 
    vector<long long> sequence = weird_algorithm(n);
 
    for (long long num : sequence) {
        cout << num << " "; // Print the sequence
    }
    cout << endl; // End the output with a newline
 
    return 0;
}
```

---

## Explanation of the Code

1. **Function `weird_algorithm`**:
   - Takes the input \( n \) and initializes a vector to store the sequence.
   - Applies the algorithm iteratively until \( n \) becomes 1.
   - Pushes each intermediate value of \( n \) into the vector.
   - Returns the complete sequence.

2. **Main Function**:
   - Reads the input \( n \).
   - Calls the `weird_algorithm` function to get the sequence.
   - Outputs the sequence in the required format.

---

## Complexity Analysis

1. **Time Complexity**:
   - The number of steps required to reach 1 for a given \( n \) is dependent on the sequence generated, but empirical evidence suggests it is logarithmic on average.
   - For \( n \) within the range \( 1 ≤ n ≤ 10^6 \), the algorithm efficiently terminates.

2. **Space Complexity**:
   - The space complexity is \( O(k) \), where \( k \) is the length of the sequence. The sequence is stored in a vector for output.

---

## Key Insights

- The problem is a variation of the "Collatz Conjecture," an unsolved mathematical problem.
- The sequence will always terminate at 1 for all positive integers \( n \) according to the conjecture.
- The solution efficiently handles the constraints by using 64-bit integers and avoids unnecessary computations.
