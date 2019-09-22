/**
 * Initialize your data structure here.
 */
var Trie = function() {
    this.t = {};
};

/**
 * Inserts a word into the trie.
 * @param {string} word
 * @return {void}
 */
Trie.prototype.insert = function(word) {
    var m = this.t;
    for (let i = 0; i < word.length; i++) {
        let c = word.charAt(i);
        if (m[c] == null) {
            m[c] = {};
        }
        m = m[c];
    }
    m.contains = true;
};

/**
 * Returns if the word is in the trie.
 * @param {string} word
 * @return {boolean}
 */
Trie.prototype.search = function(word) {
    var m = this.t;
    for (let i = 0; i < word.length; i++) {
        let c = word.charAt(i);
        if (m[c] == null) {
            return false;
        }
        m = m[c];
    }
    return m != null && m.contains == true;
};

/**
 * Returns if there is any word in the trie that starts with the given prefix.
 * @param {string} prefix
 * @return {boolean}
 */
Trie.prototype.startsWith = function(prefix) {
    var m = this.t;
    for (let i = 0; i < prefix.length; i++) {
        let c = prefix.charAt(i);
        if (m[c] == null) {
            return false;
        }
        m = m[c];
    }
    return m != null;
};

/**
 * Your Trie object will be instantiated and called as such:
 * var obj = new Trie()
 * obj.insert(word)
 * var param_2 = obj.search(word)
 * var param_3 = obj.startsWith(prefix)
 */
