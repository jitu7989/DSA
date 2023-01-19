
/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
public class ChefAndBabla
{
    public static void main (String[] args) {
        Scanner in = new Scanner(System.in);

        int tc = in.nextInt();

        while( tc-->0 ){

            int n = in.nextInt();
            int[] arr = new int[n];

            int pos = Integer.MAX_VALUE;
            int neg = Integer.MIN_VALUE;

            for ( int i=0; i<n; i++) {
                arr[i] = in.nextInt();

                if( arr[i]>=0 ) pos = Math.min( pos , arr[i] );
                else neg = Math.max( neg , arr[i] );

            }
            if( pos==0 ) {
                System.out.println(-1);
                continue;
            }
            neg = -(neg+1);
            pos--;

//            System.out.println( pos+" "+neg+""+Math.abs(neg) );
            System.out.println( Math.min( neg , pos ) );


        }

    }
}
