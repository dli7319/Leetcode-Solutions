/**
 * @param {string} S
 * @return {number}
 */
var scoreOfParentheses = function(S) {
    return helper(S);
    function helper(str) {
        if (str.length == 0) {
            return 0;
        }
        let i = 0;
        let ct = 1;
        let end = 0;
        do {
            end++;
            if (str.substr(end,1) =="(") {
                ct++;
            } else {
                ct--;
            }
        } while (ct > 0);
        if (end == 1) {
            return 1 + scoreOfParentheses(str.substr(end+1));
        } else {
            let a = 2 * scoreOfParentheses(str.substr(1, end-1));
            let b = scoreOfParentheses(str.substr(end+1));
            return a+b;
        }
    }
};
