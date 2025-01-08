#include <iostream>
#include <vector>
using namespace std;
 
vector<long long> weird_algorithm(long long n) {
    vector<long long> sequence;
    sequence.push_back(n);
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = 3 * n + 1;
        }
        sequence.push_back(n);
    }
    return sequence;
}
 
int main() {
    long long n;
    cin >> n;
 
    vector<long long> sequence = weird_algorithm(n);
 
    for (long long num : sequence) {
        cout << num << " ";
    }
    cout << endl;
 
    return 0;
}
