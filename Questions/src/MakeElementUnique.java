import java.util.Arrays;

public class MakeElementUnique {

    public static void main(String[] args) {
        System.out.println( minIncrements( new int[]{4 ,5, 4, 1, 3, 7, 6 ,3 ,3} , 9  ));
    }

    public static long minIncrements(int[] arr, int N) {

        Arrays.sort( arr );
//        System.out.println( Arrays.toString( arr ) );
        int i = 1;
        int compareIdx = 0;
        long[] distinctElement = findDistinctElementRange( 1 ,  N ,arr );
//        System.out.println( Arrays.toString( distinctElement ) );
        long operation = 0;

        while( i<N ){

            if( arr[i] > distinctElement[1] || distinctElement[0]>distinctElement[1] )
                distinctElement = findDistinctElementRange((int) distinctElement[2] + 1, N, arr);

            if( arr[i] == arr[compareIdx] ){
                operation += distinctElement[0] - arr[i];
                arr[i] = (int)distinctElement[0];
                distinctElement[0]++;
            }
            else{
                compareIdx = i;
            }
            i++;

        }

        return operation;
    }

    public static  long[] findDistinctElementRange( int i , int N , int[] arr ){

        while( i<N && arr[i]-arr[i-1]<=1 )
            i++;

        long x = arr[i-1]+1;
        long y = i==N ? Integer.MAX_VALUE : arr[i]-1;
        long z = i;

        return new long[]{ x , y , z };

    }

}