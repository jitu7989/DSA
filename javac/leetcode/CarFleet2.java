package java.leetcode;
import java.text.DecimalFormat;
import java.util.*;
public class CarFleet2 {
    public static double[] getCollisionTimes(int[][] cars) {

        int n = cars.length;
        double[] ans = new double[n];
        DecimalFormat decimalFormat = new DecimalFormat("#.#####");
        Stack<Integer> nextCarToCatch = new Stack<>();
        for (int i = n-1; i >=0 ; i--) {

            ans[i] = -1;
            int currentCarPos = cars[i][0],currentCarSpeed=cars[i][1];
            while(!nextCarToCatch.isEmpty()){
                int j = nextCarToCatch.peek(),nextCarPos = cars[j][0],nextCarSpeed=cars[j][1];
                double nextCollisionCar = 1.0*(nextCarPos-currentCarPos)/(currentCarSpeed-nextCarSpeed);
                if(currentCarSpeed<=nextCarSpeed || ( nextCollisionCar >= ans[j] && ans[j]>0)) nextCarToCatch.pop();
                else break;
            }
            if(!nextCarToCatch.isEmpty()){
                int j = nextCarToCatch.peek(),nextCarPos = cars[j][0],nextCarSpeed=cars[j][1];
                ans[i] = 1.0*(nextCarPos-currentCarPos)/(currentCarSpeed-nextCarSpeed);
            }
            nextCarToCatch.push(i);
        }
        return ans;
    }


}
