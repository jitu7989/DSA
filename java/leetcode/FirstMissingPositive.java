package java.leetcode;

public class  FirstMissingPositive {

    public int firstMissingPositive(int[] nums) {
        
        boolean[] vis = new boolean[1000000];

        for(int i:nums){
            if(i>=0 && i<vis.length)
                vis[i]=true;
        }
        for(int i=1;i<vis.length;i++)
            if(!vis[i]) return i;
        return nums.length;

    }

}