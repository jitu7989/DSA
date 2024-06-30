package java.leetcode;

public class MaxPointsOnALine {

    public int maxPoints(int[][] points) {

        if( points.length<=2 ) return points.length;

        int max = 0;
        int n = points.length;
        for( int i=0; i<n; i++ ){
            for( int j=0; j<n; j++ ){

                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int noOfPointOnStraightLine = 2;
                for( int k=0; k<n; k++ ){

                    int x3 = points[k][0];
                    int y3 = points[k][1];

                    int LHS = (y2-y1)*(x3-x2);
                    int RHS = (y3-y2)*(x2-x1);

                    if( LHS == RHS && i!=j && i!=k && k!=j ) noOfPointOnStraightLine++;

                }
                max = Math.max( max , noOfPointOnStraightLine );

            }
        }

        return max;
    }


}
