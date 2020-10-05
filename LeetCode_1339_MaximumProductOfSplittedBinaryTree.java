/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    static int MOD = 1000000007;
    public int maxProduct(TreeNode root) {
        List<Long> sums = new ArrayList<>();
        long total = helper(root, sums);
        long max = 0;
        for(long sum : sums){
            Long p = sum * (total - sum);
            max = Math.max(max, p);
        }
        return (int)(max % MOD);
    }

    public long helper(TreeNode node, List<Long> sums){
        if(node == null)
            return 0;

        long left = helper(node.left, sums);
        long right = helper(node.right, sums);
        long sum = node.val + left + right;
        sums.add(sum);
        return sum;
    }
}