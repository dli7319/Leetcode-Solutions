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
    fun tree2str(t: TreeNode?): String {
        if (t == null) {
            return ""
        }
        return t.`val`.toString() +
            (if (t.left == null) (if (t.right == null) "" else "()")
             else "(${tree2str(t.left)})") +
            (if (t.right == null) "" else "(${tree2str(t.right)})")
    }
}
