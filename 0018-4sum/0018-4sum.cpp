class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        vector<vector<int>> ans;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n - 2; j++) {

                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int lo = j + 1;
                int hi = n - 1;

                while (lo < hi) {

                    long long sum = 1LL * nums[i] + nums[j] + nums[lo] + nums[hi];

                    if (sum == target) {

                        ans.push_back({nums[i], nums[j], nums[lo], nums[hi]});

                        lo++;
                        hi--;

                        while (lo < hi && nums[lo] == nums[lo - 1])
                            lo++;

                        while (lo < hi && nums[hi] == nums[hi + 1])
                            hi--;
                    }
                    else if (sum < target) {
                        lo++;
                    }
                    else {
                        hi--;
                    }
                }
            }
        }

        return ans;
    }
};