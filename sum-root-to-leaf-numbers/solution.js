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
var sumNumbers = function(root) {

    let s = 0;
    let stack = [];
    trav(root);
    return s;

    function trav(me) {
        if (me == null) {
            return 0;
        }
        if (me.left == null && me.right == null) {
            s += parseInt(stack.join('') + me.val.toString());
            return;
        }
        stack.push(me.val.toString());
        trav(me.left);
        trav(me.right);
        stack.pop();
    }
};
