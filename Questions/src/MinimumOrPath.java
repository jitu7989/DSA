/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
    static int n;
    public static void main (String[] args) throws java.lang.Exception {

        Scanner in = new Scanner(System.in);

        int tc = in.nextInt();
        while( tc-- > 0 ){

            n = in.nextInt();

            int[] arr = new int[n];
            int[] dp = new int[n];

            for (int i = 0; i <n ; i++) arr[i] = in.nextInt();

            Arrays.fill( dp , Integer.MAX_VALUE );
            dp[0] = arr[0];

            System.out.println( dp[n-1] == Integer.MAX_VALUE ? -1 : dp[n-1] );

        }

    }
    public static boolean minCost( int[] arr, int i, int[] dp ){

        if( i== arr.length ) return true;

        int path = Math.min( i+arr[i], -1 ) ;

        for (int j = i+1; j <= n; j++) {

            if( minCost( arr , j , dp ) ){

            }

        }

        return false;
    }

}
