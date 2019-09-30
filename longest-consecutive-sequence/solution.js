/**
 * @param {number[]} nums
 * @return {number}
 */
var longestConsecutive = function(nums) {
    var low = {};
    var high = {};
    var m = 0;
    for (let i = 0; i < nums.length; i++) {
        let num = nums[i];
        if (typeof low[num+1] == "number") {
            low[num] = 1 + low[num+1];
            m = Math.max(m, low[num]);
        } else if (typeof low[num] != "number") {
            low[num] = 1;
        }
        if (typeof high[num-1] == "number") {
            high[num] = 1 + high[num-1];
            m = Math.max(m, high[num]);
        } else if (typeof high[num] != "number") {
            high[num] = 1;
        }
        let k = num-1;
        while (typeof low[k] == "number" && low[k] > 0) {
            low[k] = Math.max(low[k], 1 + low[k+1]);
            m = Math.max(m, low[k]);
            k--;
        }
        k++;
        let j = num+1;
        while (typeof high[j] == "number" && high[j] > 0) {
            high[j] = Math.max(high[j], 1 + high[j-1]);
            m = Math.max(m, high[j]);
            j++;
        }
        j--;
        let diff = j-k+1;
        high[j] = Math.max(high[j] || 0, diff);
        low[k] = Math.max(low[k] || 0, diff);
        m = Math.max(m, diff);
    }
    return m;
};
