import model.A;

import java.util.Arrays;
import java.util.Scanner;

public class Candies {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        int tc = in.nextInt();

        while( tc-- > 0 ) {

            int n = in.nextInt();
            int m = in.nextInt();

            int[] money = new int[n];
            int[] bonus = new int[m];

            for (int i = 0; i < n; i++) {
                money[i] = in.nextInt();
            }
            for (int i = 0; i < m; i++) {
                bonus[i] =  in.nextInt();
            }

            int max = 0;
            for (int i = 0; i < m; i++) {
                int sum = 0;
                for (int j = 0; j < n; j++)
                    sum += (money[j]/(i+1))*bonus[i];
                max = Math.max( max , sum );
            }
            System.out.println( max );
        }

    }

}
