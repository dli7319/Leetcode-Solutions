/**
 * @param {string} s
 * @return {string}
 */
var frequencySort = function(s) {
    var ct = {};
    for (let i = 0; i < s.length; i++) {
        const char = s.substr(i, 1);
        if (ct[char] == null) {
            ct[char] = 0;
        }
        ct[char]++;
    }
    var huh = [];
    for (let i in ct) {
        huh.push({
            ct: ct[i],
            ltr: i
        });
    }
    huh.sort((x,y) => y.ct-x.ct);
    let ret = [];
    for (let i of huh) {
        for (let j = 0; j < i.ct; j++) {
            ret.push(i.ltr);
        }
    }
    return ret.join("");
};
