/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function (n) {
    if (n <= 2) return n

    let ways = []
    ways[0] = 1
    ways[1] = 2

    for (let i = 2; i < n; i++) {
        ways[i] = ways[i - 1] + ways[i - 2]
    }
    return ways[n - 1]
};