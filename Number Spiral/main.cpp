#include <iostream>
#include <cmath>
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
