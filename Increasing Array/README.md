<h1>Write-Up: Solution to <a href="https://cses.fi/problemset/task/1094">Increasing Array</a>
</h1>
<h2>Problem Description</h2>
<p>You are given an array of <code>n</code> integers. The goal is to make the array "increasing," where each element is at least as large as the previous one. You are allowed to increase any element's value by 1 in a single move. The task is to determine the minimum number of moves required to achieve this. </p>
<h3>Input:</h3>
<ul>
  <li>An integer <code>n</code> ( <code>1 ≤ n ≤ 2 ⋅ 10 <sup>5</sup></code>), representing the size of the array. </li>
  <li>A sequence of <code>n</code> integers <code>x_1, x_2, ..., x_n</code> ( <code>1 ≤ x_i ≤ 10 <sup>9</sup></code>), representing the contents of the array. </li>
</ul>
<h3>Output:</h3>
<p>A single integer: the minimum number of moves required to make the array increasing.</p>
<h3>Example:</h3>
<h4>Input:</h4>
<pre>5
3 2 5 1 7
</pre>
<h4>Output:</h4>
<pre>5
</pre>
<hr>
<h2>Approach to the Solution</h2>
<ol>
  <li>
    <strong>Understanding the Problem:</strong>
    <p>For an array to be "increasing," every element must satisfy <code>x[i] ≥ x[i-1]</code> for <code>i ≥ 2</code>. If <code>x[i] &lt; x[i-1]</code>, the current element <code>x[i]</code> must be increased to <code>x[i-1]</code> to satisfy the condition. The number of moves required is the difference <code>x[i-1] - x[i]</code>. </p>
  </li>
  <li>
    <strong>Algorithm:</strong>
    <p>Start from the first element and iterate through the array. Maintain a counter to track the total moves required. Compare each element with the previous one:</p>
    <ul>
      <li>If <code>x[i] &lt; x[i-1]</code>, add the difference to the counter. </li>
      <li>Otherwise, update the previous element to the current one.</li>
    </ul>
  </li>
  <li>
    <strong>Efficiency Considerations:</strong>
    <p>Since <code>n</code> can be as large as <code>2 ⋅ 10 <sup>5</sup></code>, the solution must operate in <code>O(n)</code> time to handle large inputs efficiently. </p>
  </li>
</ol>
<hr>
<h2>Implementation in C++</h2>

```cpp
using namespace std;
int main() {
    int n;
    cin >> n;
    long long moves = 0;  // Counter for the number of moves
    int prev;             // Previous element in the array
    cin >> prev;          // Read the first element
    for (int i = 1; i < n; ++i) {
        int current;
        cin >> current;
        if (current < prev) {
            // Add the difference to the moves counter
            moves += prev - current;
        } else {
            // Update prev to the current element
            prev = current;
        }
    }
    cout << moves << endl; // Output the total moves required
    return 0;
}
```

<hr>
<h2>Explanation of the Code</h2>
<ol>
  <li>
    <strong>Input Handling:</strong>
    <p>The first input line gives <code>n</code>, the size of the array. The second line contains the array elements. </p>
  </li>
  <li>
    <strong>Iterating Through the Array:</strong>
    <p>The first element is stored as <code>prev</code>. For each subsequent element, compare it with <code>prev</code>: </p>
    <ul>
      <li>If <code>current &lt; prev</code>, calculate the difference and add it to the <code>moves</code> counter. </li>
      <li>Otherwise, update <code>prev</code> to <code>current</code>. </li>
    </ul>
  </li>
  <li>
    <strong>Final Output:</strong>
    <p>After completing the iteration, the total number of moves required is printed.</p>
  </li>
</ol>
<hr>
<h2>Complexity Analysis</h2>
<ul>
  <li>
    <strong>Time Complexity:</strong> The solution iterates through the array once, making it <code>O(n)</code>.
  </li>
  <li>
    <strong>Space Complexity:</strong> The solution uses a constant amount of additional memory ( <code>O(1)</code>).
  </li>
</ul>
<hr>
<h2>Key Insights</h2>
<ul>
  <li>The algorithm uses a single pass to compute the result, ensuring efficiency for large input sizes.</li>
  <li>The problem is a classic example of using a greedy approach to minimize the number of operations.</li>
  <li>Basic arithmetic operations (comparisons and additions) ensure the solution is both fast and lightweight.</li>
</ul>
