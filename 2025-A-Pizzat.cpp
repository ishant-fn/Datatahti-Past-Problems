#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int people;
    int pizzas;
    int slices;

    cin >> people >> pizzas >> slices;

    slices *= pizzas;

    int min_slices = slices / people;
    if (slices - (min_slices * people) > 0) {
        cout << min_slices << " " << min_slices + 1;
    } else {
        cout << min_slices << " " << min_slices;
    }

    return 0;
}