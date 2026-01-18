class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n);
        stack<int> st;
        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i % n])
                st.pop();

            v[i % n] = (st.empty()) ? -1 : nums[st.top()];
            st.push(i % n);
        }

        return v;
    }
};