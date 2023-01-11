import java.util.Arrays;

public class MathAlgo {

    public static void main(String[] args) {

        int[] arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        System.out.println(Arrays.toString(arr));


    }

    public static boolean[] sieveOfEratosthenes(int n){

        if( n <= 1)
            return new boolean[n+1];

        boolean[] isPrime = new boolean[n+1];
        Arrays.fill(isPrime, true);

        isPrime[0] = false;
        isPrime[1] = false;

        for( int i=2; i*i<=n; i++ ){

            for (int j = 2+i; j<=n ; j+=i)
                isPrime[j] = false;

        }

        return isPrime;
    }

}
