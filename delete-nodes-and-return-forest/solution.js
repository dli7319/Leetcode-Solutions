/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number[]} to_delete
 * @return {TreeNode[]}
 */
var delNodes = function(root, to_delete) {
    var h = {};
    for (let i of to_delete) {
        h[i] = true;
    }
    var t = h[root.val]? [] : [root];
    helper(root);
    return t;

    function helper(myNode) {
        if (myNode == null) {
            return false;
        }
        var left = helper(myNode.left);
        var right = helper(myNode.right);
        if (!left) {
            myNode.left = null;
        }
        if (!right) {
            myNode.right = null;
        }
        if (h[myNode.val]) {
            if (left) {
                t.push(myNode.left);
            }
            if (right) {
                t.push(myNode.right);
            }
            return false;
        }
        return true;
    }
};
