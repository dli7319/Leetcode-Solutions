/**
 * @param {string} s
 * @param {string} t
 * @return {number}
 */
var numDistinct = function(s, t) {
    var memo = [];
    for (let j = 0; j < t.length; j++) {
        memo[j] = 0;
    }
    for (let i = 0; i < s.length; i++) {
        const myLetter = s.substr(i, 1);
        for (let j = Math.min(s.length, t.length)-  1; j >= 0; j--) {
            if (t.substr(j, 1) == myLetter) {
                memo[j] += (j > 0 ? memo[j-1] : 1);
            }
        }
    }
    return memo[t.length-1];
};
