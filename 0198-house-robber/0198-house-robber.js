/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function (nums) {
    let cost = []
    cost[0] = nums[0]
    cost[1] = Math.max(nums[0], nums[1])
    const n = nums.length
    for (let i = 2; i < n; i++) {
        cost[i] = Math.max(nums[i] + cost[i - 2], cost[i - 1])
    }

    return cost[n - 1]
};