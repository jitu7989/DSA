public class MedianOfTwoSortedArray {

    public static void main(String[] args) {

        System.out.println( new MedianOfTwoSortedArray().findMedianSortedArrays(new int[]{  }, new int[]{2,3}) );
    }

    public double findMedianSortedArrays( int[] A , int[] B ) {
        int[] a,b;

        if( A.length > B.length ){
            a = B;
            b = A;
        }
        else{
            a = A; b = B;
        }

        int mergedLength = b.length + a.length;
        int mergedMid = mergedLength/2;

//        if( mergedLength==2 ) return calculateMedian( a[0],b[0], 2 );

        if(mergedLength%2!=0) mergedMid++;
        int low = 0, high = a.length;

        while( low<=high ){

            int aPartition = low + (high-low)/2;
            int bPartition = mergedMid - aPartition;

            int aMin = aPartition == 0 ? Integer.MIN_VALUE : a[aPartition-1];
            int bMin = bPartition == 0 ? Integer.MIN_VALUE : b[bPartition-1];

            int aMax = aPartition == a.length ? Integer.MAX_VALUE : a[aPartition];
            int bMax = bPartition == b.length ? Integer.MAX_VALUE : b[bPartition];

            if( aMin<=bMax && bMin<=aMax )
                return calculateMedian( Math.max( aMin , bMin ) , Math.min( aMax , bMax ) , mergedLength );
            else if( bMin >= aMax )
                low = aPartition+1;
            else high = aPartition-1;

        }
        return 0;

    }
    public double calculateMedian( int o , int t , int size ){

        if( size%2==0 )
            return (double) (o+t)/2;

        return o;
    }


}
