/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var maxLevelSum = function(root) {
    let myNums = helper(root);
    let myMax = -99999;
    let myMaxLvl = -1;
    for (let i = 0; i < myNums.length; i++) {
        if (myNums[i] > myMax) {
            myMaxLvl = i+1;
            myMax = myNums[i];
        }
    }
    return myMaxLvl;

    function helper(node) {
        if (node == null) {
            return [];
        }
        let l = helper(node.left);
        let r = helper(node.right);
        let m = [node.val];
        while (l.length > 0 || r.length > 0) {
            m.push((l.shift() || 0) + (r.shift() || 0));
        }
        return m;
    }
};
