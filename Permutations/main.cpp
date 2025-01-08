#include <iostream>
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
