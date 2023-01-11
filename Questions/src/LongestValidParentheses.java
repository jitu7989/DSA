import java.util.Calendar;
import java.util.Stack;

public class LongestValidParentheses {

    public static void main(String[] args) {
        System.out.println( longestValidParentheses("(())(()") );
        System.out.println( longestValidParentheses(")()())" ) );
        System.out.println( longestValidParentheses( "((()()()))(" ) );
        System.out.println( longestValidParentheses( ")(((((()())()()))()(()))(" ) );
        System.out.println();
    }

//    public static int longestValidParentheses(String s) {
//        
//        int n = s.length();
//        
//        boolean[] dp = new boolean[n];
//
//        for (int i = 0; i < n; i++) {
//            
//        }
//
//        
//        return maxLen;
//    }
    public static int longestValidParentheses(String s) {
        if(s.length()<=1) return 0;
        int n = s.length();

        boolean[] dp = new boolean[n];

        for (int i = 1; i < n; i++) {
            if( s.charAt(i-1)=='(' && s.charAt(i)==')' )
                checkParenthese(s, n, dp, i-1, i);
        }

        int j = 0;
        while( j<n ){

            while( j<n && !dp[j] ) j++;
            int k  = j;
            while( k<n && dp[k]   ) k++;
            checkParenthese(s, n, dp, j-1, k);
            j = k;

        }
        
        int currLen = 0;
        int max = 0;
        boolean prev = dp[0];
        for ( boolean el:dp ) {
            if( el ) currLen++;
            else currLen = 0;
            max = Math.max(max,currLen);
        }

        return max;
    }

    private static void checkParenthese(String s, int n, boolean[] dp, int a, int b) {

        while( a>=0 && b<n && s.charAt(a)=='(' && s.charAt(b)==')' ){
            dp[a--] = true;
            dp[b++] = true;

            while( a>=0 && dp[a] ) a--;
            while( b<n && dp[b]  ) b++;

        }

    }
//(()())


}
