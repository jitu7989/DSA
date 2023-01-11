import java.util.Arrays;

public class FindStockProfitsDAndC {

//    Divide and Conquer

    public static void main(String[] args) {

//        int[] tradeDays = { 5,4,3,4,1 };
        int[] tradeDays = { 100,80,50,30,20,10,5,1 };
//        int[] tradeDays = {100, 113, 110, 85, 105, 102, 86, 63, 81, 101, 94, 106, 101, 79, 94, 90, 97};
//                              13    -3  -25  20   -3  -16 -23 18  20    7   12    5  22  15   4   7
//        int[] volumeChange = {0, 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5 , -22,  15,  -4  , 7};
        System.out.println(Arrays.toString( findMaximumSubArray(tradeDays , 0 , tradeDays.length-1 )));
//        System.out.println(Arrays.toString( findMaximumSubArray( volumeChange , 0 , tradeDays.length-1 )));

    }
//    FIND-MAX-CROSSING-SUBARRAY.A; low; mid; high/

    public static int[] findMaxCrossingSubArray(int[] A, int low , int mid , int high ){

        int leftSum = Integer.MIN_VALUE, sum = 0, rightSum = Integer.MIN_VALUE;

        int maxLeft=-1, maxRight=-1;


        for( int i=mid; i>=low; i-- ){
            sum += i==0 ? 0 : A[i]-A[i-1];

            if( sum>leftSum ){
                leftSum = sum;
                maxLeft = i-1;
            }

        }

        sum = 0;
        for (int i = mid+1; i <= high ; i++) {

            sum += i==0 ? 0 : A[i]-A[i-1];

            if( sum>rightSum ){
                rightSum = sum;
                maxRight = i;
            }

        }

        return new int[]{maxLeft-1, maxRight, leftSum + rightSum};

    }

    public static int[] findMaximumSubArray( int[] A , int low , int high ){

        if( low==high ){
            return new int[]{ low==0 ? low :low-1, high , low==0 ? 0 : A[low]-A[low-1] };
        }

        int mid = low+(high-low)/2;

        int[] left  = findMaximumSubArray( A , low , mid );
        int[] right = findMaximumSubArray( A , mid+1 , high );
        int[] crossingMid = findMaxCrossingSubArray( A , low , mid , high );

        if( left[2]>=right[2] && left[2] >= crossingMid[2]  ) return left;

        if( left[2]<=right[2] && right[2] >= crossingMid[2] ) return right;

        return crossingMid;

    }

}
