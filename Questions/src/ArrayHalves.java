import java.util.*;
import java.lang.*;
import java.io.*;

    /* Name of the class has to be "Main" only if the class is public. */
public class ArrayHalves {

    public static void main (String[] args) throws java.lang.Exception {

            Scanner in = new Scanner(System.in);

            int tc = in.nextInt();
            while( tc-->0 ){

                int n = in.nextInt();
                int m = n*2;
                int[] arr = new int[m+1];

                ArrayList<Integer> a1 = new ArrayList<>();
                ArrayList<Integer> a2 = new ArrayList<>();

                a1.add(0); a2.add(0);

                for (int i=1; i<=m; i++)  arr[i] = in.nextInt();

                for (int i=1; i<=n; i++)
                    if( arr[i] > n )
                        a1.add(i);

                for (int i=n+1; i<=m; i++)
                    if( arr[i] <= n )
                        a2.add(i);

                int operation = 0;
                int len = a1.size()-1;

                for( int i=len, j=1; j<=len; i--,j++){

                    int x = n-a1.get(i);
                    int y = a2.get(j)-(n+1);

                    operation += (x+y+1);

                }
                System.out.println( operation );


            }


        }

}
