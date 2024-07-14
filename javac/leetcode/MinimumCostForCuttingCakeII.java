package javac.leetcode;

import java.util.Arrays;

public class MinimumCostForCuttingCakeII {

    public static void main(String[] args) {
        int[] A = {1, 2, 4, 3};
        int[] B = {1, 3, 1, 4};
    }

    public int minimumCost(int n, int m, int[] hc, int[] vc) {
        Integer[] horizontalCuts = new Integer[n-1];
        Integer[] verticalCuts = new Integer[m-1];

        for (int i = 0; i < n-1; i++) horizontalCuts[i] = hc[i];
        for (int i = 0; i < m-1; i++) verticalCuts[i] = vc[i];

        Arrays.sort(horizontalCuts,(t1, t2) -> t2-t1);
        Arrays.sort(verticalCuts,(t1, t2) -> t2-t1);

        long hCount = 1,vCount = 1;
        int hi=0,vi=0;

        long ans = 0;
        while(hi<(n-1) || vi<(m-1)){

            if(hCount==n){
                ans += (verticalCuts[vi]*hCount);
                vi++;
                vCount++;
            }
            else if(vCount==m){
                ans += (horizontalCuts[hi]*vCount);
                hi++;
                hCount++;
            }
            else{

                if(horizontalCuts[hi]>verticalCuts[vi]){
                    ans += (horizontalCuts[hi]*vCount);
                    hi++;
                    hCount++;
                }
                else if(horizontalCuts[hi]<verticalCuts[vi]){
                    ans += (verticalCuts[vi]*hCount);
                    vi++;
                    vCount++;
                }
                else{
                    if(hCount>vCount){
                        ans += (verticalCuts[vi]*hCount);
                        vi++;
                        vCount++;
                    }
                    else{
                        ans += (horizontalCuts[hi]*vCount);
                        hi++;
                        hCount++;
                    }
                }
            }

        }

        return (int) ans;
    }

}
