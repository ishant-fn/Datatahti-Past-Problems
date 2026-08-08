#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string palindrome;
    cin >> palindrome;
    int moves = 0;
    for (int i = 0; i < (palindrome.length() / 2); ++i) {
        if (!(palindrome[i] == palindrome[(palindrome.length() - i) - 1])) {
            ++moves;
        }
    }
    cout << moves;
    return 0;
}
