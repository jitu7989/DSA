import java.util.Arrays;

public class MergeSortOn2DMatrix {

    public static void main(String[] args) {

//        int[][] TwoDArray = {
//                            {  4,  3,  2,  1 },
//                            {  8,  7,  6,  5 },
//                            {  12, 9, 10, 11 },
//                            { 16, 15, 14, 13 },
//                            { 20, 19, 18, 17 }
//                          };

        int[][] TwoDArray = {
            { 5, 12, 17, 21, 23},
            { 1,  2,  4,  6,  8},
            {12, 14, 18, 19, 27},
            {3,  7,  9, 15, 25}
        };

        mergeSort2DArray( TwoDArray );

        for( int[] arr : TwoDArray ){
            System.out.println(Arrays.toString(arr));
        }

    }

    private static int[] copyArray1;
    private static int[] copyArray2;

//    Main Function to start sorting the 2D array
    public static void mergeSort2DArray( int[][] A ){

        int n = A.length, m = A[0].length, i=0, j=0;

        copyArray1 = new int[ (n%2==0 ? n/2 : n/2+1 ) * m ];
        copyArray2 = new int[ (n/2)*m ];

        System.out.println( "copyArray1: " + copyArray1.length + " copyArray2: " + copyArray2.length );

        sort2dArray( A , 0 , n-1 );

        copyArray1=null;
        copyArray2=null;
    }


    static void sort2dArray( int[][] A , int top , int bottom ){

        if( top==bottom ){
            mergeSort( A[top] , 0 , A[top].length-1 );
            return;
        }

        int mid = top + (bottom-top)/2;
        sort2dArray( A , top , mid );
        sort2dArray( A , mid+1 , bottom );

        merge2dArray( A , top , mid , bottom );

    }
    static void mergeSort( int[] A , int l , int r ) {

        if( l==r ) return;

        int mid = l + (r-l)/2;

        mergeSort( A , l , mid );
        mergeSort( A , mid+1 , r );

        mergeArray( A ,l ,mid , r );

    }

    //Merging function for 1d and 2d array
    static void mergeArray( int[] A, int l, int mid, int r ){

        int i=l,j=mid+1,p=l;
        int a =0,b =0;

        copyArray( A , l , mid , copyArray1 );
        copyArray( A , mid+1 , r , copyArray2 );

        while( i<=mid || j<=r ){

            int element1 = (i <= mid ? copyArray1[a] : Integer.MAX_VALUE);
            int element2 = (j <= r   ? copyArray2[b] : Integer.MAX_VALUE);

            if( element1<element2 ) {
                A[p++] = element1; i++; a++;
            }
            else {
                A[p++] = element2; j++; b++;
            }

        }



    }
    static void merge2dArray( int[][] A , int top , int midV, int bottom  ){

        int i=top, j=midV+1, p=top, q=0;

        int size1 = copy2DArray( A , top , midV , copyArray1 );
        int size2 = copy2DArray( A , midV+1 , bottom , copyArray2 );

        i=0;j=0;
        while( i<size1 || j<size2 ){

            int element1 = ( i < size1 ? copyArray1[i] : Integer.MAX_VALUE);
            int element2 = ( j < size2 ? copyArray2[j] : Integer.MAX_VALUE);

            if (element1 < element2) {

                A[p][q++] = element1;
                i++;

            }
            else {

                A[p][q++] = element2;
                j++;

            }
            if( q==A[0].length ){
                p++; q=0;
            }

        }

    }

//    Copy Functions for 1D and 2D Array
    static int copy2DArray(int[][] A ,int top , int  bottom ,int[] copyArray ){

        int n = (bottom-top+1) * A[0].length;
        int a=top,b=0;

        for (int i = 0; i < n; i++) {

            copyArray[i] = A[a][b++];

            if( b==A[0].length ){
                a++; b=0;
            }

        }
        return n;
    }
    public static void copyArray( int[] A , int l , int r , int[] copyArray ){
        int j=0;
        for( int i=l; i<=r; i++ )
            copyArray[j++] = A[i];


    }

}
