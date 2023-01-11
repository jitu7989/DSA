import java.util.Arrays;

public class EditDistance {

    public static void main(String[] args) {
        System.out.println( minDistance( "sea" , "eat" ) );
    }

    public static int minDistance(String word1, String word2) {

        if( word1.length()==0 ) return word2.length();
        if( word2.length()==0 ) return word1.length();

        int n = word1.length(), m = word2.length();

        int[][] dp = new int[n+1][m+1];
        for( int[] i:dp ) Arrays.fill( i , Integer.MAX_VALUE );

        //        for( int[] i:dp ) System.out.println( Arrays.toString( i ) );
        return midDis( word1, word2 , n , m , dp );

    }
    public static int midDis(
            String word1,
            String word2 ,
            int i , int j,
            int[][] dp
    )
    {

        if( i==0 && j==0 ) return 0;
        if( i==0 ) return j;
        if( j==0 ) return i;

        if( dp[i][j]!=Integer.MAX_VALUE ) return dp[i][j];

        if( word1.charAt(i-1) == word2.charAt(j-1) )
            return midDis( word1 , word2 , i-1 , j-1, dp  );

        int min = Integer.MAX_VALUE;

        int replace = midDis( word1 , word2 , i-1 , j-1 ,dp );
        int insert  = midDis( word1 , word2 ,     i , j-1 ,dp );
        int delete  = midDis( word1 , word2 , i-1 ,     j ,dp );

        min = Math.min( insert , delete );
        min = Math.min( replace, min );

        return min+1;

    }

}
