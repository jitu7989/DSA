package java.leetcode;

public class MedianOfTwoSortedArray {

    public static void main(String[] args) {

        System.out.println( new MedianOfTwoSortedArray().findMedianSortedArrays(new int[]{  }, new int[]{2,3,4,5}) );
    }

    public double findMedianSortedArrays( int[] A , int[] B ) {
        if( A.length > B.length ){
            int[] temp = A;
            A = B;
            B = temp;
        }

        int mergedLength = B.length + A.length;
        int mergedMid = mergedLength/2;

        if(mergedLength%2!=0) mergedMid++;
        int low = 0, high = A.length;

        while( low<=high ){

            int aPartition = low + (high-low)/2;
            int bPartition = mergedMid - aPartition;

            int aMin = aPartition == 0 ? Integer.MIN_VALUE : A[aPartition-1];
            int bMin = bPartition == 0 ? Integer.MIN_VALUE : B[bPartition-1];

            int aMax = aPartition == A.length ? Integer.MAX_VALUE : A[aPartition];
            int bMax = bPartition == B.length ? Integer.MAX_VALUE : B[bPartition];

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

    public double findMedianSortedArraysV2(int[] a, int[] b) {
        int n = a.length;
        int m = b.length;
        if(m < n) return findMedianSortedArrays(b,a);

        int low = 0;
        int high = n;

        int ml = n + m;
        int lengthMid = (n + m + 1) >> 1;

        while(low <= high){
            int aMid  = (low + high ) >> 1;
            int bMid  = lengthMid - aMid;

            int al = Integer.MIN_VALUE;
            int bl = Integer.MIN_VALUE;
            int ar = Integer.MAX_VALUE;
            int br = Integer.MAX_VALUE;

            if(aMid-1 >= 0) al = a[aMid-1];
            if(aMid < n)    ar = a[aMid];
            if(bMid-1 >= 0) bl = b[bMid-1];
            if(bMid < m)    br = b[bMid];

            if(al <= br && bl <= ar){
                if(ml%2 == 1) return Math.max(al,bl);
                else return (double) (Math.max(al,bl) + Math.min(ar,br)) / 2.0;
            }
            else if(al > br)
                high = aMid-1;
            else
                low = aMid + 1;
        }
        return 0;
    }

}
