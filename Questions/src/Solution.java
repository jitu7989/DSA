import java.util.Arrays;

public class Solution{
    static int[] k_Transformation(int n, int m, int k, int grid[][], int q, int queries[][]){
        // code here
        //We know what is 2D prefix sum, but as per the requirements can we somehow transform it into 3D Prefix sum. 
        int[][][] dp = new int[n][m][k];

        for( int i=0; i<n; i++ ){
            for( int j=0; j<m; j++ ){
                dp[i][j][grid[i][j]]++;
                if( j!=0 ) {
                    for (int l = 0; l < k; l++) {
                        dp[i][j][l] = dp[i][j-1][l]+dp[i][j][l] ;
                    }
                }
            }
        }

        for( int i=0; i<n; i++ ){
            for( int j=0; j<m; j++ ){
                // for( int l=0; l<k; l++ ){
                System.out.print( Arrays.toString( dp[i][j] ) );
                // }
            }
            System.out.println(",");
        }

        int[] ans = new int[q];

        for( int i=0; i<q; i++ ){
            int t = queries[i][0] % k;
            int val = queries[i][1];
            int lx = queries[i][2];
            int ly = queries[i][3];
            int rx = queries[i][4];
            int ry = queries[i][5];
            int count = 0;
            for( int r = lx; r <= rx; r++ ){
                if(ly != 0)
                    count += dp[r][ry][ (t + val) % k ] - dp[r][ly-1][t];
                else
                    count += dp[r][ry][ (t + val) % k ];
            }
            ans[i] = count++;
        }
        return ans;
    }
}