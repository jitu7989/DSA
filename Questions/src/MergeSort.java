import java.util.*;


public class MergeSort {

    public static void main(String[] args) {

        int[] arr1 = {1};
        int[] arr2 = {9,8,7,6,5,4,3,2,1};
        int[] arr3 = {9,8,7,6,5,4,3,2,1,0};
        int[] arr4 = {9,8,7,6,5,4,3,2};
        int[] arr5 = {9,8,7,6,5,4,3};
        int[] arr6 = {9,8,7,6,5,4};
        int[] arr7 = {9,8,7,6,5};
        int[] arr8 = {9,8,7,6};
        int[] arr9 = {9,8,7};
        int[] arr10 = {9,8,7};

        ternaryMergeSort( arr1 , 0 , arr1.length-1 );
        ternaryMergeSort( arr2 , 0 , arr2.length -1);
        ternaryMergeSort( arr3 , 0 , arr3.length-1 );
        ternaryMergeSort( arr4 , 0 , arr4.length-1 );
        ternaryMergeSort( arr5 , 0 , arr5.length-1 );
        ternaryMergeSort( arr6 , 0 , arr6.length-1 );
        ternaryMergeSort( arr7 , 0 , arr7.length-1 );
        ternaryMergeSort( arr8 , 0 , arr8.length-1 );
        ternaryMergeSort( arr9 , 0 , arr9.length-1 );
        ternaryMergeSort( arr10 , 0 , arr10.length-1 );

        System.out.println(Arrays.toString(arr1));
        System.out.println(Arrays.toString(arr2));
        System.out.println(Arrays.toString(arr3));
        System.out.println(Arrays.toString(arr4));
        System.out.println(Arrays.toString(arr5));
        System.out.println(Arrays.toString(arr6));
        System.out.println(Arrays.toString(arr7));
        System.out.println(Arrays.toString(arr8));
        System.out.println(Arrays.toString(arr9));
        System.out.println(Arrays.toString(arr10));


    }

    public static void ternaryMergeSort( int[] arr, int l , int r ){

        if( r-l<1 ) return;
        else if( r-l<2 ){

            if( arr[r]<arr[l] ) swap( arr , l , r );

            return;
        }

        int point1 = l + ( r-l )/3;
        int point2 = point1 + (r-l+1)/3;

        ternaryMergeSort( arr , l , point1 );
        ternaryMergeSort( arr , point1+1 , point2 );
        ternaryMergeSort( arr , point2+1 , r );

        merge( arr , l , point1 , point2 , r );

    }

    static void merge( int[] arr , int l , int point1 , int point2 , int r ){

        int[] firstDivision  = copyArray( arr , l , point1 );
        int[] secondDivision = copyArray( arr , point1+1 , point2 );
        int[] thirdDivision  = copyArray( arr , point2+1 , r );

        int i=l,p1=0,p2=0,p3=0;
        int element1,element2,element3;
        while( i<=r ){

            element1 = p1 == firstDivision.length ?  Integer.MAX_VALUE:firstDivision[p1] ;
            element2 = p2 == secondDivision.length ? Integer.MAX_VALUE:secondDivision[p2];
            element3 = p3 == thirdDivision.length ? Integer.MAX_VALUE:thirdDivision[p3];

            int min = Math.min( element1 , Math.min(element2 , element3 ) );

            if( min==element1 ) p1++;
            else if( min==element2 ) p2++;
            else p3++;

            arr[i] = min;
            i++;

        }
        return;

    }

    static int[] copyArray( int[] arr , int l , int r ){

        int[] subPart = new int[r-l+1];
        int p = 0,i = l;

        while ( i<=r )  subPart[p++] =  arr[i++];

        return subPart;

    }

    static void swap( int[] arr , int i, int j  ){
        int temp = arr[j];
        arr[j] = arr[i];
        arr[i]=temp;
    }

    static class Main {

        public static void main(String[] args) {

            Scanner in = new Scanner(System.in);

            int n = in.nextInt();
            int[] arr = new int[n];

            for( int i=0; i<n; i++ )
                arr[i] = in.nextInt();

            StringBuilder sb = new StringBuilder();
            ternaryMergeSort( arr, 0 , n-1 );
            for(int i=0;i<n;i++ ){
                System.out.print(arr[i]+" ");
            }
//            for( int i=0; i<n; i++ ) sb.append( arr[i] ).append(" ");
//
//            System.out.println( sb );
        }

        public static void ternaryMergeSort( int[] arr, int l , int r ){

            if( r-l<1 ) return;
            else if( r-l<2 ){

                if( arr[r]<arr[l] ) swap( arr , l , r );

                return;
            }

            int point1 = l + ( r-l )/3;
            int point2 = point1 + (r-l+1)/3;

            ternaryMergeSort( arr , l , point1 );
            ternaryMergeSort( arr , point1+1 , point2 );
            ternaryMergeSort( arr , point2+1 , r );

            merge( arr , l , point1 , point2 , r );

        }

        static void merge( int[] arr , int l , int point1 , int point2 , int r ){

            int[] firstDivision  = copyArray( arr , l , point1 );
            int[] secondDivision = copyArray( arr , point1+1 , point2 );
            int[] thirdDivision  = copyArray( arr , point2+1 , r );

            int i=l,p1=0,p2=0,p3=0;
            int element1,element2,element3;
            while( i<=r ){

                element1 = p1 == firstDivision.length ?  Integer.MAX_VALUE:firstDivision[p1] ;
                element2 = p2 == secondDivision.length ? Integer.MAX_VALUE:secondDivision[p2];
                element3 = p3 == thirdDivision.length ? Integer.MAX_VALUE:thirdDivision[p3];

                int min = Math.min( element1 , Math.min(element2 , element3 ) );

                if( min==element1 ) p1++;
                else if( min==element2 ) p2++;
                else p3++;

                arr[i] = min;
                i++;

            }
            return;

        }

        static int[] copyArray( int[] arr , int l , int r ){

            int[] subPart = new int[r-l+1];
            int p = 0,i = l;

            while ( i<=r )  subPart[p++] =  arr[i++];

            return subPart;

        }

        static void swap( int[] arr , int i, int j  ){
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i]=temp;
        }

    }

}

