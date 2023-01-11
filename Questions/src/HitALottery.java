import java.util.Scanner;

public class HitALottery {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int n = s.nextInt();
        int count = 0;

        if( n/100!=0 ){
            count+=n/100;
            n -= ((n/100)*100);
        }
        if( n/20!=0 ){
            count+=n/20;
            n -= ((n/20)*20);
        }
        if( n/10!=0 ){
            count+=n/10;
            n -= ((n/10)*10);
        }
        if( n/100!=5 ){
            count+=n/5;
            n -= ((n/5)*5);
        }
        if( n!=0 ){
            count+=n;
            n -= n;
        }
        System.out.println( count );
    }

}
