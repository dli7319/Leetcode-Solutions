/**
 * @param {string[]} A
 * @return {number}
 */
var numSpecialEquivGroups = function(A) {
    let g = new Set();
    for (let a of A) {
        let s = split2(a);
        s[0].sort();
        s[1].sort();
        g.add(merge(s[0],s[1]).join(''));
    }
    return g.size;

    function split2(a) {
        let b = [];
        let c = [];
        for (let i = 0; i < a.length; i++) {
            if (i % 2 == 0) {
                b.push(a.substr(i,1));
            } else {
                c.push(a.substr(i,1));
            }
        }
        return [b,c];
    }


    function merge(a, b) {
        let c = [];
        while (a.length > 0 || b.length > 0) {
            if (a.length > 0) {
                c.push(a.shift());
            }
            if (b.length > 0) {
                c.push(b.shift());
            }
        }
        return c;
    }
};
