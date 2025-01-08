<h1>Write-Up: Solution to <a href="https://cses.fi/problemset/task/1070">Permutations</a>
</h1>
<h2>Problem Description</h2>
<p>A permutation of integers <code>1, 2, ..., n</code> is called beautiful if there are no adjacent elements whose difference is 1. Given <code>n</code>, the task is to construct a beautiful permutation if it exists. </p>
<h3>Input:</h3>
<ul>
  <li>An integer <code>n</code> ( <code>1 ≤ n ≤ 10^6</code>), representing the size of the permutation. </li>
</ul>
<h3>Output:</h3>
<p>If a beautiful permutation exists, print it. If no solution exists, print <code>NO SOLUTION</code>. </p>
<h3>Examples:</h3>
<h4>Example 1:</h4>
<pre>Input:
5
Output:
4 2 5 3 1
</pre>
<h4>Example 2:</h4>
<pre>Input:
3
Output:
NO SOLUTION
</pre>
<hr>
<h2>Approach to the Solution</h2>
<ol>
  <li>
    <strong>Understanding the Problem:</strong>
    <p>To ensure no adjacent elements have a difference of 1, a simple observation can be made: separating even and odd numbers ensures the required property. Place all even numbers first, followed by all odd numbers.</p>
  </li>
  <li>
    <strong>Key Observations:</strong>
    <ul>
      <li>If <code>n = 1</code>, the only permutation is <code>1</code>. </li>
      <li>If <code>n = 2</code> or <code>n = 3</code>, it's impossible to form a beautiful permutation, so the output is <code>NO SOLUTION</code>. </li>
      <li>For <code>n ≥ 4</code>, placing even numbers first and then odd numbers ensures no adjacent numbers differ by 1. </li>
    </ul>
  </li>
  <li>
    <strong>Algorithm:</strong>
    <ul>
      <li>Print all even numbers from <code>2</code> to <code>n</code>. </li>
      <li>Print all odd numbers from <code>1</code> to <code>n</code>. </li>
    </ul>
  </li>
  <li>
    <strong>Efficiency Considerations:</strong>
    <p>The solution involves two simple loops, making it efficient with <code>O(n)</code> time complexity. </p>
  </li>
</ol>
<hr>
<h2>Implementation in C++</h2>

```cpp
#include <iostream>;
using namespace std;

int main() {
    long long n;
    cin >> n;

    if (n == 1) {
        cout << "1" << endl;
    } else if (n == 2 || n == 3) {
        cout << "NO SOLUTION" << endl;
    } else {
        for (long long i = 2; i <= n; i += 2) {
            cout << i << " ";
        }
        for (long long i = 1; i <= n; i += 2) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
```
<hr>
<h2>Explanation of the Code</h2>
<ol>
  <li>
    <strong>Input Handling:</strong>
    <p>Read the value of <code>n</code>. </p>
  </li>
  <li>
    <strong>Edge Cases:</strong>
    <p>For <code>n = 1</code>, print <code>1</code>. For <code>n = 2</code> or <code>n = 3</code>, print <code>NO SOLUTION</code>. </p>
  </li>
  <li>
    <strong>Generating the Permutation:</strong>
    <ul>
      <li>Use a loop to print all even numbers from <code>2</code> to <code>n</code>. </li>
      <li>Use a second loop to print all odd numbers from <code>1</code> to <code>n</code>. </li>
    </ul>
  </li>
</ol>
<hr>
<h2>Complexity Analysis</h2>
<ul>
  <li>
    <strong>Time Complexity:</strong> Two loops iterate over the numbers from <code>1</code> to <code>n</code>, resulting in <code>O(n)</code> time complexity.
  </li>
  <li>
    <strong>Space Complexity:</strong> The solution uses a constant amount of memory ( <code>O(1)</code>).
  </li>
</ul>
<hr>
<h2>Key Insights</h2>
<ul>
  <li>Separating even and odd numbers ensures that no two adjacent numbers differ by 1.</li>
  <li>The problem can be solved efficiently with a simple greedy approach.</li>
  <li>Special cases ( <code>n = 1</code>, <code>n = 2</code>, <code>n = 3</code>) must be handled explicitly to ensure correctness. </li>
</ul>
