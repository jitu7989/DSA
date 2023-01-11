import java.util.Scanner;

public class HallOfFame {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        int tc = in.nextInt();

        while( tc-- > 0 ){

            int n = in.nextInt();

            String s = in.next();

            int lr = -1;
            boolean rl = false;


            for( int i=1; i<n; i++ ){

                if( s.charAt(i-1)=='L' &&  s.charAt(i)=='R' ) lr = i;
                if( s.charAt(i-1)=='R' &&  s.charAt(i)=='L' ) rl = true;


            }

            if( rl ) System.out.println( 0 );
            else System.out.println(lr);

        }

    }

}
