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
var maxPathSum = function(root) {
    if (root == null) {
        return 0;
    }
    const a = helper(root);
    return Math.max(a.using, a.nusing);

    function helper(me) {
        if (me == null) {
            return null;
        }
        if (me.left == null && me.right == null) {
            return {
                using: me.val,
                nusing: Number.NEGATIVE_INFINITY
            };
        }
        if (me.left == null) {
            const r = helper(me.right);
            return {
                using: Math.max(r.using + me.val, me.val),
                nusing: Math.max(r.using, r.nusing)
            };
        }
        if (me.right == null) {
            const l = helper(me.left);
            return {
                using: Math.max(l.using + me.val, me.val),
                nusing: Math.max(l.using, l.nusing)
            };
        }
        const r = helper(me.right);
        const l = helper(me.left);
        return {
            using: Math.max(me.val, l.using + me.val, r.using + me.val),
            nusing: Math.max(l.using, l.nusing, r.using, r.nusing, l.using + r.using + me.val)
        };
    }
};
