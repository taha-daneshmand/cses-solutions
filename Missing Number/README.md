# Write-Up: Solution to [Missing Number](https://cses.fi/problemset/task/1083)

## Problem Description

You are tasked with finding a missing number from the sequence \( 1, 2, …, n \). The input provides \( n - 1 \) numbers, each distinct and within the range \( 1 \) to \( n \). Your goal is to determine the single missing number.

### Input:
1. The first line contains an integer \( n \) (\( 2 ≤ n ≤ 2 ⋅ 10^5 \)).
2. The second line contains \( n - 1 \) integers, each between \( 1 \) and \( n \), and all distinct.

### Output:
- Print the missing number.

### Example:
#### Input:
```
5
2 3 1 5
```

#### Output:
```
4
```

---

## Approach to the Solution

1. **Understanding the Problem**:
   - The numbers \( 1 \) through \( n \) are consecutive integers, and their sum can be computed using the formula:
     ```math 
     \text{Sum} = \frac{n ⋅ (n + 1)}{2}
     ```
   - By subtracting the sum of the given \( n-1 \) numbers from this total sum, we can determine the missing number.

2. **Constraints Handling**:
   - The input size (\( n \)) can be large (\( 2 ⋅ 10^5 \)), so the solution must be efficient, requiring only \( O(n) \) time and \( O(1) \) additional space.

3. **Efficiency**:
   - Using arithmetic operations ensures constant-time computation for the total sum.
   - Iterating through the input sequence to compute the sum of given numbers requires linear time, making the overall solution optimal.

---

## Implementation in C++

The following code implements the described algorithm:

```cpp
#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n; // Read the value of n

    // Compute the total sum of numbers from 1 to n
    long long totalSum = (n * (n + 1)) / 2;

    // Compute the sum of the given numbers
    long long givenSum = 0;
    for (long long i = 0; i < n - 1; ++i) {
        long long num;
        cin >> num;
        givenSum += num;
    }

    // The missing number is the difference between the total sum and the given sum
    long long missingNumber = totalSum - givenSum;

    cout << missingNumber << endl; // Output the missing number

    return 0;
}
```

---

## Explanation of the Code

1. **Reading Input**:
   - The first input line gives \( n \), the total number of integers.
   - The second input line contains \( n - 1 \) integers, which are read in a loop.

2. **Calculating Total Sum**:
   - The formula for the sum of the first \( n \) integers is used to compute totalSum.

3. **Calculating Given Sum**:
   - A loop iterates through the \( n-1 \) numbers, accumulating their sum into givenSum.

4. **Finding the Missing Number**:
   - The missing number is calculated as:
     ```math
     \text{missingNumber} = \text{totalSum} - \text{givenSum}
     ```

5. **Output**:
   - The missing number is printed.

---

## Complexity Analysis

1. **Time Complexity**:
   - Computing totalSum is \( O(1) \).
   - Calculating givenSum requires a single pass through the \( n-1 \) numbers, making this step \( O(n) \).
   - The overall complexity is \( O(n) \).

2. **Space Complexity**:
   - The solution uses a constant amount of additional space (\( O(1) \)).

---

## Key Insights

- This problem leverages the arithmetic progression formula to efficiently find the missing number.
- The constraints of the problem are well-suited to an \( O(n) \)-time, \( O(1) \)-space solution.
- The approach avoids the need for extra data structures like arrays or hash sets, ensuring minimal memory usage.
