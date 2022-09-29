#include <bits/stdc++.h>

using namespace std;

// Now there is a simpler way to solve this chal, but I am not liking the fact that it
// might have to loop through mutliple times.
//
// There might be some better solution, if not I might go with that only.
// I don't see any better solutions, the only fact we can harness is that this chal
// requires bitwise operations and we can use that, but apart from that we still had to
// run multiple loops, which I am not really a great fan of.

#define D(e) cerr << e << endl
#define E(e) #e << "=" << (e)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ifstream inputFile("day3input.txt");
    string input;
    int samples = 0, length = 0;
    vector<int> bits(0, 0);

    while(getline(inputFile, input)) {
        int len = input.length();
        if (len > length)
            bits.resize(length = len);
        reverse(begin(input), end(input));
        for (int i=0; i < len; ++i)
            if (input[i] & 1)
                ++bits[i];
        ++samples;
    }

    D(E(samples));
    for (int i=0; i < length; ++i) D(E(bits[i]));
    int threshold = (samples + 1) / 2, gamma = 0, epsilon = 0;
    for (int i=0, bit = 1; i < length; ++i, bit += bit)
        if (bits[i] >= threshold)
            gamma |= bit;
        else
            epsilon |= bit;

    cout << (long(epsilon) * gamma) << endl;

    return 0;
}
