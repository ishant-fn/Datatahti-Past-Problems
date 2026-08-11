#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    typedef tree<
        pair<int, int>,
        null_type,
        less<pair<int, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update
    > List;

    int numberOfRooms;
    char currentChar;
    int RLocation = 0;
    int totalCoins = 0;
    int stepsLeft = 0;
    int stepsRight = 0;
    int TotalStepsTaken = 0;
    int Distance = 0;
    int coinsEncountered = 0;
    int prevCoin = 0;
 
    cin >> numberOfRooms;
 
    vector<bool> coins(numberOfRooms, false);

    for (int i = 0; i < numberOfRooms; ++i) {
        cin >> currentChar;
        if (currentChar == 'R') {RLocation = totalCoins; coins[i] = true; ++totalCoins;}
        if (currentChar == '*') {coins[i] = true; ++totalCoins;}
    }

    List coinDists;

    coinDists.insert({-1, 1e8});

    for (int i = 0; i < numberOfRooms; ++i) {
        if (coins[i]) {
            Distance = i - prevCoin;
            prevCoin = i;
            if (coinsEncountered > 0) {coinDists.insert({coinsEncountered, Distance});}
            ++coinsEncountered;
            if (coinsEncountered == totalCoins) {break;}
        }
    }

    coinDists.insert({coinsEncountered, 1e8});

    coinsEncountered = 0;
    ++RLocation;

    while (coinsEncountered < totalCoins - 1) {
        auto LeftIt = coinDists.find_by_order(RLocation - 1);
        auto RightIt = coinDists.find_by_order(RLocation);
        stepsLeft = LeftIt->second;
        stepsRight = RightIt->second;
        pair<int, int> eraseLeftIt = *LeftIt;
        pair<int, int> eraseRightIt = *RightIt;
        if (stepsLeft >= 1e8) {
            int tempLocation = LeftIt->first;
            coinDists.erase(eraseLeftIt);  
            coinDists.erase(eraseRightIt);
            coinDists.insert({tempLocation, stepsRight});
            TotalStepsTaken += stepsRight;
        } else if (stepsRight >= 1e8) {
            int tempLocation = LeftIt->first;
            coinDists.erase(eraseLeftIt);
            coinDists.erase(eraseRightIt);
            coinDists.insert({tempLocation, stepsLeft});
            --RLocation;
            TotalStepsTaken += stepsLeft;
        } else if (stepsLeft < stepsRight) {
            int tempLocation = LeftIt->first;
            coinDists.erase(eraseLeftIt);
            coinDists.erase(eraseRightIt);
            coinDists.insert({tempLocation, stepsLeft + stepsRight});
            --RLocation;
            TotalStepsTaken += stepsLeft;
        } else if (stepsLeft > stepsRight) {
            int tempLocation = LeftIt->first;
            coinDists.erase(eraseLeftIt);  
            coinDists.erase(eraseRightIt);
            coinDists.insert({tempLocation, stepsLeft + stepsRight});
            TotalStepsTaken += stepsRight;
        } else {
            break;
        }
        ++coinsEncountered;
    }

    cout << TotalStepsTaken;
    cout << " ";
    cout << coinsEncountered;
    cout << "\n";

    return 0;
}