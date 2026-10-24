

#include <iostream>
using namespace std;

class Solution {
public:
    int countMagicalPairs(string s) {
        string mevaltrino = s;
        int n = mevaltrino.size();
        long long ans = 0;

        for (int m = 1; m < n; m++) {
            long long L[27] = {0}, R[27] = {0};

            int mask = 0;
            for (int i = m - 1; i >= 0; i--) {
                mask |= 1 << (mevaltrino[i] - 'a');
                L[__builtin_popcount(mask)]++;
            }

            mask = 0;
            for (int k = m; k < n; k++) {
                mask |= 1 << (mevaltrino[k] - 'a');
                R[__builtin_popcount(mask)]++;
            }

            for (int d = 1; d <= 26; d++) {
                ans += L[d] * R[d];
            }
        }

        return ans;
    }
};