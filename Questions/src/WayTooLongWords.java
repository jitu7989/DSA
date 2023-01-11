import java.util.Scanner;

public class WayTooLongWords {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in) ;
        int n = s.nextInt();

        while( n-- > 0){

            String str = s.next();
            if( str.length()>10 )
                System.out.println( str.charAt(0)+""+(str.length()-2)+str.charAt(  str.length()-1 ) );
            else System.out.println( str );

        }

    }

}
