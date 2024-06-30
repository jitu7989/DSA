package java.leetcode;

import java.util.*;
public class LargestRectangleInHistogram {

    public int maximalRectangle(char[][] matrix) {
        int[] dp = new int[matrix[0].length];
        int max = 0;
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                if(matrix[i][j]=='0') dp[j]++;
                else  dp[j] = 0;
            }
            max = Math.max(max,largestRectangleArea(dp));
        }
        return max;
    }
    public  int largestRectangleArea(int[] heights) {

        int max = 0,n= heights.length;
        int[] left = new int[n];
        int[] right = new int[n];

        Stack<Integer> ls = new Stack<>();
        Stack<Integer> rs = new Stack<>();
        for (int i = 0,j=n-1; i < n; i++,j--) {
            while(!ls.isEmpty() && heights[i]<=heights[ls.peek()] ) ls.pop();
            while(!rs.isEmpty() && heights[j]<=heights[rs.peek()] ) rs.pop();
            if(ls.isEmpty()) left[i] = -1;
            else left[i] = ls.peek();
            if(rs.isEmpty()) right[j] = n;
            else right[j] = rs.peek();
            ls.push(i);
            rs.push(j);
        }
        for (int i = 0; i < n; i++)
            max = Math.max( heights[i]*(right[i]-(left[i]+1)),max);


        return max;
    }

}
