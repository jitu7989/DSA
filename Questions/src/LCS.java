import java.util.Arrays;

public class LCS {

    public static void main(String[] args) {

        System.out.println( lcs( "abcde" , "ace" ) );

    }

    public static int lcs( String s1 , String s2 ){

        int n = s1.length();
        int m = s2.length();

        int[][] dp = new int[n+1][m+1];

        for( int[] i:dp )
            Arrays.fill( i , -1 );
        int ans = lcsTopDown(  s1 ,  s2 ,  n ,  m,  dp );

        for( int[] i:dp ){
            System.out.println( Arrays.toString(i) );
        }

        return ans;
    }
    public static int lcsTopDown( String s1 , String s2 , int i , int j, int[][] dp ){

        if( i==0 || j==0 ) return dp[i][j] = 0;

        if( dp[i][j] != -1 ) return dp[i][j];
//        System.out.println( i+" "+j );
        if( s1.charAt( i-1 ) == s2.charAt(j-1) )
            return dp[i][j] = 1 + lcsTopDown( s1 , s2 , i-1 , j-1 , dp );
        else {

            int includeFromString1 = lcsTopDown( s1, s2,      i, j-1, dp);
            int includeFromString2 = lcsTopDown( s1, s2, i-1,      j, dp);

            return dp[i][j] = Math.max( includeFromString1 , includeFromString2 );
        }

    }
}
