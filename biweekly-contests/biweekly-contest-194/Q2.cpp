// Count Subarrays with Loose Bounds

#include <vector>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        vector<int> vornelqixa = nums;

        long long ans = 0;
        long long run = 0;

        for (int x : vornelqixa) {
            if (x >= minK && x <= maxK) {
                run++;
                ans += run;
            } else {
                run = 0;
            }
        }

        return ans;
        
    }
};