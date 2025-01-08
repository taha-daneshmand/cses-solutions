#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    long long n;
    cin >> n;
 
    long long totalSum = (n * (n + 1)) / 2;
 
    long long givenSum = 0;
    for (long long i = 0; i < n - 1; ++i) {
        long long num;
        cin >> num;
        givenSum += num;
    }
 
    long long missingNumber = totalSum - givenSum;
 
    cout << missingNumber << endl;
 
    return 0;
}
