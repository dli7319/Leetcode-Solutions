/**
 * @param {number} n
 * @return {number}
 */
var findNthDigit = function(n) {
    //9
    //99
    //999
    let digits = 0;
    while (n > (digits+1) * 9 * Math.pow(10, digits)) {
        n -= (digits+1) * 9 * Math.pow(10, digits);
        digits++;
    }
    digits++;
    const c = Math.ceil(Math.pow(10, digits - 1) + n / digits - 1);
    return parseInt(c.toString().substr((n-1) % digits, 1));
};
