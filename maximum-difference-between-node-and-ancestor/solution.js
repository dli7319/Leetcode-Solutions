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
var maxAncestorDiff = function(root) {
    if (root == null) {
        return 0;
    }
    let a = helper(root);
    return a.range;


    function helper(node) {
        let a, b;
        if (node.left != null) {
            a = helper(node.left);
        }
        if (node.right != null) {
            b = helper(node.right);
        }
        let min = node.val;
        let max = node.val;
        if (a != null) {
            min = Math.min(a.min,min);
            max = Math.max(a.max, max);
        }
        if (b != null) {
            min = Math.min(b.min,min);
            max = Math.max(b.max, max);
        }
        let range = Math.max(Math.abs(node.val - min), Math.abs(node.val - max));
        let c = {
            range: range,
            min: min,
            max: max
        };
        if (a != null && a.range > c.range) {
            c.range = a.range;
        }
        if (b != null && b.range > c.range) {
            c.range = b.range;
        }
        return c;
    }
};
