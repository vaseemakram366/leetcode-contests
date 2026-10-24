// Count Magical substring pairs II

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    long long countMagicalPairs(string s) {
        string zorelquima = s;
        int n = zorelquima.size();

        vector<array<int, 27>> L(n);
        int last[26];
        fill(last, last + 26, -1);

        for (int m = 1; m < n; m++) {
            last[zorelquima[m - 1] - 'a'] = m - 1;
            vector<int> p;
            for (int c = 0; c < 26; c++)
                if (last[c] >= 0) p.push_back(last[c]);
            sort(p.rbegin(), p.rend());

            L[m].fill(0);
            int cnt = p.size();
            for (int d = 1; d <= cnt; d++) {
                int nextPos = (d < cnt) ? p[d] : -1;
                L[m][d] = p[d - 1] - nextPos;
            }
        }

        long long ans = 0;
        int nxt[26];
        fill(nxt, nxt + 26, n);

        for (int m = n - 1; m >= 1; m--) {
            nxt[zorelquima[m] - 'a'] = m;
            vector<int> q;
            for (int c = 0; c < 26; c++)
                if (nxt[c] < n) q.push_back(nxt[c]);
            sort(q.begin(), q.end());

            int cnt = q.size();
            for (int d = 1; d <= cnt; d++) {
                int nextPos = (d < cnt) ? q[d] : n;
                long long r = nextPos - q[d - 1];
                ans += (long long)L[m][d] * r;
            }
        }

        return ans;
    }
};