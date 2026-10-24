// Difference Between Peaks and Valleys


#include <vector>
using namespace std;

class Solution {
public:
    int peakValleyDifference(vector<int>& nums) {
        int peakSum = 0;
        int valleySum = 0;
        int n = nums.size();

        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                peakSum += nums[i];
            } else if (nums[i] < nums[i - 1] && nums[i] < nums[i + 1]) {
                valleySum += nums[i];
            }
        }

        return peakSum - valleySum;
    }
};