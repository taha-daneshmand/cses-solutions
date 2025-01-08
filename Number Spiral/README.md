<h1>Write-Up: Solution to <a href="https://cses.fi/problemset/task/1071">Number Spiral</a>
</h1>
<h2>Problem Description</h2>
<p> A number spiral is an infinite grid where numbers are arranged in a spiral pattern. The upper-left square contains the number <code>1</code>, and numbers continue in a spiral pattern in both directions. For example, the first five layers of the spiral are: </p>
<pre>
1  2   9  10  25
4  3   8  11  24
5  6   7  12  23
16 15  14  13  22
17 18  19  20  21
</pre>
<p> Given the row <code>y</code> and column <code>x</code> of the spiral, your task is to find the number located at that position in the grid. </p>
<h3>Input:</h3>
<ul>
  <li>An integer <code>t</code> ( <code>1 ≤ t ≤ 10^5</code>), the number of test cases. </li>
  <li>
    <code>t</code> lines, each containing two integers <code>y</code> and <code>x</code> ( <code>1 ≤ y, x ≤ 10^9</code>).
  </li>
</ul>
<h3>Output:</h3>
<p> For each test case, print the number at row <code>y</code> and column <code>x</code>. </p>
<h3>Examples:</h3>
<h4>Input:</h4>
<pre>3
2 3
1 1
4 2
</pre>
<h4>Output:</h4>
<pre>8
1
15
</pre>
<hr>
<h2>Approach to the Solution</h2>
<ol>
  <li>
    <strong>Understanding the Spiral:</strong>
    <p>The number spiral forms concentric square layers where the numbers are arranged as follows:
    <ul>
      <li>In the first layer, the number 1 is at the top left.</li>
      <li>In the second layer, the numbers increase towards the right, down, left, and up to form a closed square.</li>
      <li>Subsequent layers follow a similar pattern, expanding the spiral.</li>
    </ul>
    </p>
  </li>
  <li>
    <strong>Pattern Analysis:</strong>
    <p>The number at a given position <code>(y, x)</code> depends on the maximum value between the row and column, because the largest value defines the outer boundary of the spiral layer:
    <ul>
      <li>If <code>x < y </code>, the spiral will increase horizontally (along rows) from left to right. </li>
      <li>If <code>x > y</code>, the spiral will increase vertically (along columns) from top to bottom. </li>
    </ul>
    </p>
  </li>
  <li>
    <strong>Algorithm:</strong>
    <p>For each test case, compute the number at position <code>(y, x)</code> by determining whether the column <code>x</code> or row <code>y</code> dictates the largest spiral layer, and compute the corresponding number from the formula: </p>

```
if (x < y) {
    if (y % 2 == 1) {
        r = y * y - x + 1;
    } else {
        r = (y - 1) * (y - 1) + x;
    }
} else {
    if (x % 2 == 0) {
        r = x * x - y + 1;
    } else {
        r = (x - 1) * (x - 1) + y;
    }
}
```

  </li>
  <li>
    <strong>Efficiency Considerations:</strong>
    <p>Since the values of <code>y</code> and <code>x</code> can be as large as <code>10^9</code>, the solution must efficiently compute the result in constant time, <code>O(1)</code>, for each query. The time complexity is <code>O(t)</code> where <code>t</code> is the number of test cases. </p>
  </li>
</ol>
<hr>
<h2>Implementation in C++</h2>

```
#include <iostream>;
#include <cmath>;
using namespace std;

int main() {
    long long int tc;
    cin >> tc;

    while (tc--) {
        long int x, y;
        cin >> x >> y;

        long int r;
        if (x < y) {
            if (y % 2 == 1) {
                r = y * y - x + 1;
            } else {
                r = (y - 1) * (y - 1) + x;
            }
        } else {
            if (x % 2 == 0) {
                r = x * x - y + 1;
            } else {
                r = (x - 1) * (x - 1) + y;
            }
        }

        cout << r << endl;
    }

    return 0;
}
```

<hr>
<h2>Explanation of the Code</h2>
<ol>
  <li>
    <strong>Input Handling:</strong>
    <p>The program first reads the number of test cases <code>tc</code>. For each test case, it reads the coordinates <code>x</code> and <code>y</code>. </p>
  </li>
  <li>
    <strong>Determining the Number:</strong>
    <p>For each test case, the program checks whether <code>x</code> is smaller or greater than <code>y</code>, which helps determine how the spiral unfolds at that particular position. Based on that, the program uses conditional logic to compute the number at position <code>(y, x)</code> using arithmetic operations. </p>
  </li>
  <li>
    <strong>Final Output:</strong>
    <p>The result for each test case is printed after computing the corresponding number.</p>
  </li>
</ol>
<hr>
<h2>Complexity Analysis</h2>
<ul>
  <li>
    <strong>Time Complexity:</strong> The solution processes each test case in constant time, <code>O(1)</code>, making the overall time complexity <code>O(t)</code>.
  </li>
  <li>
    <strong>Space Complexity:</strong> The solution uses a constant amount of memory, <code>O(1)</code>.
  </li>
</ul>
<hr>
<h2>Key Insights</h2>
<ul>
  <li>The number spiral grows in layers, and for each position <code>(y, x)</code>, we can determine the value based on the layer's boundaries and the largest coordinate between <code>y</code> and <code>x</code>. </li>
  <li>The solution ensures constant-time processing for each test case, making it optimal even for the maximum input size.</li>
  <li>By understanding the structure of the spiral and leveraging arithmetic properties, the algorithm avoids directly constructing the spiral, ensuring efficiency.</li>
</ul>
