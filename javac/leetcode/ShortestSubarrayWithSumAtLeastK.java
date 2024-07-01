package java.leetcode;

import java.util.ArrayDeque;

public class ShortestSubarrayWithSumAtLeastK {
    public static int shortestSubarray(int[] nums, int k) {
        int n = nums.length;
        ArrayDeque<long[]> deque = new ArrayDeque<>();
        long currSum = 0;
        long ans = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            currSum+=nums[i];
            if(currSum>=k) ans = Math.min(i+1,ans);
            while(!deque.isEmpty() && currSum-deque.peekFirst()[0]>=k ){
                long[] arr = deque.pollFirst();
                ans = Math.min(i-arr[1],ans);
            }
            while(!deque.isEmpty() && deque.peekLast()[0]>currSum ) deque.pollLast();
            deque.add(new long[]{currSum,i});
        }
        return (int)(ans==Integer.MAX_VALUE?-1:ans);
    }
}
