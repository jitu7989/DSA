package java.leetcode;

public class MaximumSumOfSubsequenceWithNonAdjacentElements {
    public static int maximumSumSubsequence(int[] nums, int[][] queries) {
        long mod = 1_000_000_000 + 7L;
        long ans = 0;
        int n = nums.length;
        int[] dp = new int[nums.length];
        for (int i = 0; i < n; i++) {
            dp[i] = Math.max((i > 0 ? dp[i - 1] : 0), (i > 1 ? dp[i - 2] : 0) + Math.max(nums[i], 0));
        }
        for (int[] query : queries) {
            int pos = query[0];
            int num = query[1];
            nums[pos] = num;
            for (int i = pos; i < n; i++) {
                dp[i] = Math.max((i > 0 ? dp[i - 1] : 0), (i > 1 ? dp[i - 2] : 0) + Math.max(nums[i], 0));
            }
            ans += Math.max(dp[n - 1], n - 2 >= 0 ? dp[n - 2] : 0);
            ans = ans % mod;
        }
        return (int) ans;
    }
}
