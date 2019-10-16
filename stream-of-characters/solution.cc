/**
 * @param {string[]} words
 */
var StreamChecker = function(words) {
    this.trie = {};
    for (let str of words) {
        let a = this.trie;
        for (let i = 0; i < str.length; i++) {
            let c = str.substr(i, 1);
            a[c] = a[c] || {};
            a = a[c];
        }
        a.isWord = true;
    }
    this.potential = [];
};

/**
 * @param {character} letter
 * @return {boolean}
 */
StreamChecker.prototype.query = function(letter) {
    let newPotential = [];
    let r = false;
    if (this.trie[letter] != null) {
        newPotential.push(this.trie[letter]);
        if (this.trie[letter].isWord) {
            r = true;
        }
    }
    for (let old of this.potential) {
        if (old[letter] != null) {
            newPotential.push(old[letter]);
            if (old[letter].isWord) {
                r = true;
            }
        }
    }
    this.potential = newPotential;
    return r;
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * var obj = new StreamChecker(words)
 * var param_1 = obj.query(letter)
 */
