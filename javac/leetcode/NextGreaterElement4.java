package java.leetcode;

import java.util.LinkedList;

public class NextGreaterElement4 {
    public static int[] secondGreaterElement(int[] nums) {
        int n = nums.length;
        final LinkedList<Integer> fs = new LinkedList<>(), ss = new LinkedList<>();
        final int[] res = new int[nums.length];
        for (int i = 0; i<n; i++) {
            while(!ss.isEmpty() && nums[i]>nums[ss.peekLast()]) res[ss.pollLast()] = nums[i];
            LinkedList<Integer> stackToReverse = new LinkedList<>();
            while(!fs.isEmpty() && nums[i]>nums[fs.peekLast()])  stackToReverse.addLast(fs.pollLast());
            while(!stackToReverse.isEmpty()) ss.addLast(stackToReverse.pollLast());
            fs.addLast(i);
        }
        while(!fs.isEmpty()) res[fs.pop()] = -1;
        while(!ss.isEmpty()) res[ss.pop()] = -1;
        return res;
    }
}
