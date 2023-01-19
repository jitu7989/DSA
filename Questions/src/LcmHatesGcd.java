import java.util.Scanner;

public class LcmHatesGcd {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        int tc = in.nextInt();

        while( tc-->0 ){

            int a = in.nextInt();
            int b = in.nextInt();
            int gcd = gcd(a,b);
            
            System.out.println( lcm( a , gcd ) - gcd(b,gcd) );

        }

    }
    public static int lcm(int a, int b){
        return (a*b)/gcd(a,b);
    }
    public static int gcd(int a, int b){
        if( b==0 ) return a;
        return gcd(b, a%b);
    }

}
