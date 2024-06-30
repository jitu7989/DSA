package java.leetcode;

import java.util.*;

public class OddEvenJump {
    public static int oddEvenJumps(int[] arr) {
        int n = arr.length;
        TreeMap<Integer,Integer> map = new TreeMap<>();
        boolean[][] dp = new boolean[n][2];
        dp[n-1][0] = true;
        dp[n-1][1] = true;
        for (int i = n-1; i >=0 ; i--) {
            Map.Entry<Integer,Integer> ceilingEntry =  map.ceilingEntry(arr[i]);
            Map.Entry<Integer,Integer> floorEntry =  map.floorEntry(arr[i]);
            if(ceilingEntry!=null) dp[i][0]=dp[ceilingEntry.getValue()][1];
            if(floorEntry!=null) dp[i][1]=dp[floorEntry.getValue()][0];
            map.put(arr[i],i);
        }
        int ans = 0;
        for (boolean[] bool : dp) ans = bool[0] ? ans+1:ans;
        return ans;
    }
}
