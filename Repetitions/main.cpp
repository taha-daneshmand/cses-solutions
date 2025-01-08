#include <iostream>
#include <string>
using namespace std;
 
int main() {
    string dna;
    cin >> dna;
 
    long long maxRepetition = 1;
    long long currentRepetition = 1;
 
    for (int i = 1; i < dna.length(); ++i) {
        if (dna[i] == dna[i - 1]) {
            currentRepetition++;
        } else {
            maxRepetition = max(maxRepetition, currentRepetition);
            currentRepetition = 1;
        }
    }
 
    maxRepetition = max(maxRepetition, currentRepetition);
 
    cout << maxRepetition << endl;
 
    return 0;
}
