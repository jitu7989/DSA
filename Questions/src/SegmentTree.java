public class SegmentTree {

    int[] seg;

    private SegmentTree(int n){
        seg =  new int[4*n];
    };

    public static SegmentTree buildSegTree( int[] arr ){

        SegmentTree tree = new SegmentTree( arr.length );

        tree.build( arr , 0 , 0 , arr.length-1 );

        return tree;

    }

    private void build( int[] arr ,int segIdx, int low, int high  ){

        if(low==high) {
            seg[segIdx] = arr[low];
            return;
        }
        int mid =  low+(high-low)/2;

        build( arr , 2*segIdx+1 , low, mid  );
        build( arr ,  2*segIdx+2,  mid+1 , high );

        this.seg[segIdx] = Math.min( this.seg[2*segIdx+1] , this.seg[2*segIdx+2] );


    }

}
