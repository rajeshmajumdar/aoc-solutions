#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// the input file is too long, so I am thinking about reading it from the file itself.

int part1(vector<int> depths) {
    int prevDepth;
    int result = 0;
    for(int i=0; i <= depths.size() - 1; ++i) {
        if (i == 0) 
            prevDepth = depths[i];
        if (depths[i] > prevDepth)
            ++result; 
        prevDepth = depths[i];
    }

    return result;
}

int addNextThree(vector<int> depths, int index) {
    int result = 0;
    result = depths[index] + depths[index + 1] + depths[index + 2];
    return result;
}

int part2(vector<int> depths) {
    // now here we have a concept of sliding windows.
    int prevDepthSum = 0, depthSum = 0, result = 0;
    for(int i=0; i<= depths.size() - 1; ++i) {
        if (i == 0) {
            prevDepthSum = addNextThree(depths, 0);
        } else {
            depthSum = addNextThree(depths, i);
            if (depthSum > prevDepthSum)
                ++result;
            prevDepthSum = depthSum;
        }
    }

    return result;
}

int main() {
    vector<int> depths;
    string depth;
    ifstream inputFile("day1input.txt");
    
    while(getline(inputFile, depth)) {
        depths.push_back(stoi(depth));
    }


    int result1 = part1(depths);
    cout << result1 << endl;

    int result2 = part2(depths);
    cout << result2 << endl;
    return 0;
}
