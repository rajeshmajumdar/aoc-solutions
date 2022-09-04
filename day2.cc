#include <bits/stdc++.h>

using namespace std;

int part1(vector<string> cmds) {
    int horiz = 0, depth = 0;
    for (int i = 0; i <= cmds.size() - 1; i += 2) {
        if (cmds[i] == "forward")
            horiz = horiz + stoi(cmds[i + 1]);
        else if (cmds[i] == "down")
            depth = depth + stoi(cmds[i + 1]);
        else if (cmds[i] == "up")
            depth = depth - stoi(cmds[i + 1]);
        else
            cout << "Unknown command at line: " << i + 1 << endl;
    }
    return horiz * depth;
}

int part2(vector<string> cmds) {
    int horiz = 0, depth = 0, aim = 0;
    for (int i = 0; i <= cmds.size() - 1; i += 2) {
        if (cmds[i] == "up")
            aim = aim - stoi(cmds[i + 1]);
        else if (cmds[i] == "down")
            aim = aim + stoi(cmds[i + 1]);
        else if (cmds[i] == "forward") {
            horiz = horiz + stoi(cmds[i + 1]);
            depth = depth + (aim * stoi(cmds[i + 1]));
        }
        else {
            cout << "Unknown command at line: " << i + 1 << endl;
        }
    }

    return horiz * depth;
}

int main() {
    string command;
    vector<string> cmds;
    ifstream inputFile("day2input.txt");
    while(getline(inputFile, command)) {
        stringstream ss(command);
        string token;
        while (ss >> token) {
            cmds.push_back(token);
        }
    }

    int res1 = part1(cmds);
    cout << res1 << endl;

    int res2 = part2(cmds);
    cout << res2 << endl;

    return 0;
}
