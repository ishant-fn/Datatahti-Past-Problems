#include <bits/stdc++.h>
using namespace std;
 
int InterpretCommands (vector<int> &output, map<string, int> &vars, vector<pair<string, string>> &commands, int &location) {
    string command = commands[location].first;
    string variable = commands[location].second;
    vector<pair<string, string>> Repeatcommands;
    int howManyRepeats;
    if (command == "INCREASE") {
        ++vars[variable];
    } else if (command == "CLEAR") {
        vars[variable] = 0;
    } else if (command == "PRINT") {
        output.push_back(vars[variable]);
    } else if (command == "REPEAT") {
        int howManyRepeats = vars[variable];
        location += 2;
        while (commands[location].first != ")") {
            Repeatcommands.push_back({commands[location].first, commands[location].second});
            location += 1;
        }
 
        for (int x = 0; x < howManyRepeats; ++x) {
            for (int i = 0; i < Repeatcommands.size(); ++i) {
                if (Repeatcommands[i].first == "INCREASE") {
                    ++vars[Repeatcommands[i].second];
                } else if (Repeatcommands[i].first == "CLEAR") {
                    vars[Repeatcommands[i].second] = 0;
                } else if (Repeatcommands[i].first == "PRINT") {
                    output.push_back(vars[Repeatcommands[i].second]);
                }
            }
        }
    }
    return 0;
}
 
int main () {
    vector<int> output;
 
    map<string, int> vars =
    {{"A", 0}, {"B", 0}, {"C", 0}, {"D", 0}, {"E", 0}, {"F", 0}, {"G", 0}, {"H", 0}, {"I", 0},
    {"J", 0}, {"K", 0}, {"L", 0}, {"M", 0}, {"N", 0}, {"O", 0}, {"P", 0}, {"Q", 0}, {"R", 0},
    {"S", 0}, {"T", 0}, {"U", 0}, {"V", 0},  {"W", 0}, {"X", 0}, {"Y", 0}, {"Z", 0}};
 
    vector<string> commandsUnformatted;
    vector<pair<string, string>> commands;
    string commandAndVar;
    string commandstoStore;
    string variable;
    string command;
 
    while (getline(cin, commandAndVar)) {
        size_t pos = commandAndVar.find("#");
        if (pos != string::npos) {
                commandAndVar = commandAndVar.substr(0, pos);
        }
        stringstream extractCommandandVar(commandAndVar);
        while (extractCommandandVar >> commandstoStore) {
            commandsUnformatted.push_back(commandstoStore);
        }
    }
 
    int i = 0;
 
    while (i < commandsUnformatted.size()) {
        if (commandsUnformatted[i] == ")") {
            commands.push_back({commandsUnformatted[i], "placeholder"});
            i += 1;
        } else {
            commands.push_back({commandsUnformatted[i], commandsUnformatted[i + 1]});
            i += 2;
        }
    }
 
    for (int x = 0; x < commands.size(); ++x) {
        command = commands[x].first;
        variable = commands[x].second;
        InterpretCommands(output, vars, commands, x);
    }
 
    for (int currentOutput : output) {
        cout << currentOutput << " ";
    }
}
