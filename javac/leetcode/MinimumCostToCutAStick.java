package java.leetcode;

import java.util.Arrays;

public class MinimumCostToCutAStick {
    public static int minCost(int n, int[] cuts) {
        Arrays.sort(cuts);
        int[][] dp = new int[101][101];
        for (int[] i : dp) Arrays.fill(i, -1);
        return minCostDis(cuts, 0, n, 0, cuts.length - 1, dp);
    }

    public static int minCostDis(int[] cuts, int i, int j, int left, int right, int[][] dp) {
        if (i >= j || left > right) return 0;
        int min = Integer.MAX_VALUE;
        if (dp[left][right] != -1) return dp[left][right];
        for (int idx = left; idx <= right; idx++) {
            min = Math.min(min, minCostDis(cuts, i, cuts[idx], left, idx - 1, dp) +
                    minCostDis(cuts, cuts[idx], j, idx + 1, right, dp)
            );
        }
        return dp[left][right] = min + (j - i);
    }

}
