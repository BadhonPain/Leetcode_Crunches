class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> pair_sum;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (pair_sum.find(complement) != pair_sum.end())
                return {pair_sum[complement], i};
            else
                pair_sum[nums[i]] = i;
        }
        return {};
    }
};