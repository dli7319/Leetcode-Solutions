/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
    let a = {};
    for (let n of nums) {
        if (a[n]) {
            return true;
        }
        a[n] = true;
    }
    return false;
};
