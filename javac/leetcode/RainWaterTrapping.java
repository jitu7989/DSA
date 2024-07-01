package java.leetcode;

public class RainWaterTrapping {

    public int trap(int[] height) {

        int x = -1, y = -1, n = height.length;
        int[] left = new int[n], right = new int[n];

        for( int i=0, j=n-1; i<n; i++, j--){

            left[i] = x;
            right[j] = y;

            x = Math.max( x , height[i] );
            y = Math.max( y , height[j] );

        }
        int units = 0;
        for( int i=1; i<n-1; i++ ){

            int a = Math.min(left[i],right[i]);

            if( a > height[i] )
                units += a-height[i];


        }
        return units;

    }

}