import java.util.Scanner;

public class OddEvenBinaryString {

    public static void main (String[] args) throws java.lang.Exception{

        Scanner in = new Scanner(System.in);
        int tc = in.nextInt();

        while( tc-->0 ){

            int n = in.nextInt();
            int[] arr = new int[n];
            int odd = 0;
            int even = 0;
            for (int i = 0; i < n; i++) {
                arr[i] = in.nextInt();
                if( arr[i]%2==0 ) even++;
                else odd++;
            }

            System.out.println( (even%2==0 ? "YES" : "NO" ) );

        }

    }

}
