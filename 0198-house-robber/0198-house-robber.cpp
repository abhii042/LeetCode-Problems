/*class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return helper(0, nums, dp);
    }

    int helper(int i, vector<int>& nums, vector<int>& dp) {
        if (i >= nums.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int taken = nums[i] + helper(i + 2, nums, dp);
        int nottaken = helper(i + 1, nums, dp);

        dp[i] = max(taken, nottaken);
        return dp[i];
    }
};*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        vector<int> dp(n, 0);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            int taken = nums[i] + dp[i - 2];
            int nottaken = dp[i - 1];

            dp[i] = max(taken, nottaken);
        }

        return dp[n - 1];
    }
};