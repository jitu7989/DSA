import java.util.Arrays;

public class ZeroOneMatrix {

    public static void main(String[] args) {
        int[][] arr = {
        {1,0,1,1,0,0,1,0,0,1},
        {0,1,1,0,1,0,1,0,1,1},
        {0,0,1,0,1,0,0,1,0,0},
        {1,0,1,0,1,1,1,1,1,1},
        {0,1,0,1,1,0,0,0,0,1},
        {0,0,1,0,1,1,1,0,1,0},
        {0,1,0,1,0,1,0,0,1,1},
        {1,0,0,0,1,1,1,1,0,1},
        {1,1,1,1,1,1,1,0,1,0},
        {1,1,1,1,0,1,0,0,1,1}
    };
        int[][] expected = { {1,0,1,1,0,0,1,0,0,1},
        {0,1,1,0,1,0,1,0,1,1},
        {0,0,1,0,1,0,0,1,0,0},
        {1,0,1,0,1,1,1,1,1,1},
        {0,1,0,1,1,0,0,0,0,1},
        {0,0,1,0,1,1,1,0,1,0},
        {0,1,0,1,0,1,0,0,1,1},
        {1,0,0,0,1,2,1,1,0,1},
        {2,1,1,1,1,2,1,0,1,0},
        {3,2,2,1,0,1,0,0,1,1}};
        int[][] recieved = updateMatrix( arr );

        for (int i = 0; i < recieved.length; i++) {
            for (int j = 0; j < recieved[0].length; j++) {
                if( recieved[i][j] != expected[i][j] ) {
                    System.out.println( false );
                    return;
                }
            }
        }
        System.out.println( true );
    }
    public static int[][] updateMatrix(int[][] mat) {

        int n = mat.length , m = mat[0].length;
        int[][] dp = new int[n][m];
        boolean[][] visited = new boolean[n][m];

        for (int i = 0; i < mat.length ; i++)
            for (int j = 0; j < mat[0].length; j++)
                if( mat[i][j]!=0 ) dp[i][j] = Integer.MAX_VALUE;

        for( int[] i:dp )  System.out.println( Arrays.toString( i ) );

        for( int i=0; i<n; i++ )
            for( int j=0; j<m; j++ ) {
                dp[i][j] = nearestZero(mat, i, j, dp, visited);
                visited[i][j] = true;
            }


         for( int[] i:dp )  System.out.println( Arrays.toString( i ) );

        return dp;
    }

    static int nearestZero(int[][] mat , int i , int j , int[][] dp,boolean[][] visited ){

        if( i<0 || j<0 || i>=mat.length || j>= mat[0].length || dp[i][j]==Integer.MAX_VALUE-10)
            return Integer.MAX_VALUE-10;

        if( visited[i][j] ) return dp[i][j];
        if( dp[i][j] == 0 ) return 0;

        int min = Integer.MAX_VALUE;
        int temp = dp[i][j];

        dp[i][j] = Integer.MAX_VALUE-10;

        min = Math.min( nearestZero( mat , i+1 ,      j , dp , visited ) + 1 , min );
        min = Math.min( nearestZero( mat , i-1 ,      j , dp , visited ) + 1 , min );
        min = Math.min( nearestZero( mat ,      i , j+1 , dp , visited ) + 1 , min );
        min = Math.min( nearestZero( mat ,      i , j-1 , dp , visited ) + 1 , min );

        dp[i][j] = temp;

        if( min == Integer.MAX_VALUE ) return min;

        return dp[i][j] = Math.min( min , dp[i][j] );

    }



}
