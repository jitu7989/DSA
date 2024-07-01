package java.leetcode;

import java.util.LinkedList;

public class SlidingWindowMaximum {
    public static int[] maxSlidingWindow(int[] nums, int k) {
        int n = nums.length;
        int[] ans = new int[n-k+1];
        LinkedList<Integer> list = new LinkedList<>();
        for (int i = 0; i < k; i++) {
            int num = nums[i];
            while(!list.isEmpty() && list.getLast() < num ) list.removeLast();
            list.add(num);
        }
        ans[0] = list.getFirst();
        for (int i = k; i<n; i++) {
            int curr = nums[i];
            int prev = nums[i-k];
            if(prev==list.getFirst())  list.removeFirst();
            while(!list.isEmpty() && list.getLast() < curr ) list.removeLast();
            list.add(curr);
            ans[i-k+1] = list.peekFirst();
        }
        return ans;
    }
}
