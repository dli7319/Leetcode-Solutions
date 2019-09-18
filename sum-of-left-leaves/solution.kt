/**
 * Example:
 * var ti = TreeNode(5)
 * var v = ti.`val`
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */
class Solution {
    fun sumOfLeftLeaves(root: TreeNode?): Int {
        return sumOfLeftLeaves2(root, false);
    }

    fun sumOfLeftLeaves2(root: TreeNode?, a: Boolean) : Int {
        if (root == null) {
            return 0;
        }
        if (root.left == null && root.right == null) {
            return if (a) root.`val` else 0;
        }
        return sumOfLeftLeaves2(root.left, true) + sumOfLeftLeaves2(root.right, false);
    }
}
