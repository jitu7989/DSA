import java.util.Arrays;

public class MaxPointsOnALine {
    public static void main(String[] args) {
        int[][] arr = {{0,0},{4,5},{7,8},{8,9},{5,6},{3,4},{1,1}};
        System.out.println(maxPoints( arr ));
    }
    static int max = 0;
    public static int maxPoints(int[][] points) {

        Arrays.sort( points , (a, b) -> {
            return a[0]-b[0];
        } );

        max = 1;
//        System.out.println( Arrays.toString(points) );

        for( int i=0; i<points.length; i++ ){

            int x1 = points[i][0];
            int y1 = points[i][1];

            for( int j=i+1; j<=points.length-max; j++ ){

                int x2 = points[j][0];
                int y2 = points[j][1];

                int curr = 2;

                for( int k=j+1; k<points.length; k++ ){

                    int x3 = points[k][0];
                    int y3 = points[k][1];

                    if( (double)(x1*( y2-y3 ) + x2*(y3-y1) + x3*( y1-y2 ) )/2 == 0.000 ) curr++;

                }

                max = Math.max( max , curr );

            }

        }
        return max;
    }

}
