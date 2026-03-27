/**
 * @param {number[]} cost
 * @return {number}
 */
var minCostClimbingStairs = function (cost) {
    let cost1 = cost[0]
    let cost2 = cost[1]
    const n = cost.length
    for (let i = 2; i < n; i++) {
        let levelCost = Math.min(cost1, cost2) + cost[i]
        cost1 = cost2;
        cost2 = levelCost;
    }
    return Math.min(cost1, cost2);
};