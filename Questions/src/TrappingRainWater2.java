import java.util.Stack;

public class TrappingRainWater2 {

    public static void main(String[] args) {
        Solution s = new Solution();
//        int[][] arr = {
//                    {78,16,94,36},
//                    {87,93,50,22},
//                    {63,28,91,60},
//                    {64,27,41,27},
//                    {73,37,12,69},
//                    {68,30,83,31},
//                    {63,24,68,36}
//        };
//        int[][] arr = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]];

        int[][] arr = {
                        {3,3,3,3,3},
                        {3,2,2,2,3},
                        {3,2,1,2,3},
                        {3,2,2,2,3},
                        {3,3,3,3,3}
                        };
        System.out.println(s.trapRainWater(arr));
    }

    static class Solution {

        private int min = Integer.MAX_VALUE;
        private int[][] map;

        public int trapRainWater(int[][] heightMap) {

            map = heightMap;

            int n = heightMap.length, m = heightMap[0].length;
            int[][][] v = new int[n][m][2], h = new int[n][m][2];

            for(int i=0; i<n; i++){

                Stack<Integer> x = new Stack<>();
                Stack<Integer> y = new Stack<>();

                for( int p1=0,p2=m-1; p1<m; p1++,p2-- ){

                    while( !x.isEmpty() && map[i][x.peek()] <= map[i][p1] ) x.pop();
                    while( !y.isEmpty() && map[i][y.peek()] <= map[i][p2] ) y.pop();

                    h[i][p1][0] = x.isEmpty() ? -1 : map[i][x.peek()];
                    h[i][p2][1] = y.isEmpty() ? -1 : map[i][y.peek()];

                    x.add( p1 );
                    y.add( p2 );

                }

            }
            for(int i=0; i<m; i++){

                Stack<Integer> x = new Stack<>();
                Stack<Integer> y = new Stack<>();
                for( int p1=0,p2=n-1; p1<n; p1++,p2-- ){

//                  TODO :      v[p1][i][0] = x;
//                              v[p2][i][1] = y;

                    while( !x.isEmpty() && map[x.peek()][i] <= map[p1][i] ) x.pop();
                    while( !y.isEmpty() && map[y.peek()][i] <= map[p2][i] ) y.pop();

                    v[p1][i][0] = x.isEmpty() ? -1 : map[x.peek()][i];
                    v[p2][i][1] = y.isEmpty() ? -1 : map[y.peek()][i];

                    x.add( p1 );
                    y.add( p2 );

                }

            }

            printM(h, n, m, 0);
            printM(h, n, m, 1);
            printM(v, n, m, 0);
            printM(v, n, m, 1);

            boolean[][] visted = new boolean[n][m];

            int units = 0;
            for(int i=1; i<n-1; i++){
                for(int j=1; j<m-1; j++){
                    this.min = Integer.MAX_VALUE;
                    units += getUnits( h, v, i, j , visted );

                }
            }

            return units;

        }
        void printM( int[][][] h ,int n ,int m ,int k){
            System.out.println("================================");
            for(int i=0; i<n; i++){
                System.out.print("[ ");
                for(int j=0; j<m; j++){
                    System.out.print(  h[i][j][k]  +", " );
                }
                System.out.println(" ]");
            }
            System.out.println("================================\n");
        }
        public int getUnits( int[][][] h , int[][][] v , int i , int j , boolean[][] visted ){

            if( i<1 ||
                    j<1 ||
                    i >= visted.length-1 ||
                    j >= visted[0].length-1 ||
                    visted[i][j]
            ) return 0;

            visted[i][j] = true;
            int curr = Integer.MAX_VALUE;/*Math.min(
                    Math.min( h[i][j][1] , h[i][j][0] ) ,
                    Math.min( v[i][j][1] , v[i][j][0] )
            );*/

            if( map[i][j-1] > map[i][j] ) curr = Math.min( curr , h[i][j][0] );
            if( map[i][j+1] > map[i][j] ) curr = Math.min( curr , h[i][j][1] );
            if( map[i-1][j] > map[i][j] ) curr = Math.min( curr , v[i][j][0] );
            if( map[i+1][j] > map[i][j] ) curr = Math.min( curr , v[i][j][1] );


            min =  Math.min( curr, min ) ;
            int units = 0;
//            System.out.println( i+" "+j );
//            if( map[i][j] < curr ) {
                if (map[i + 1][j] < curr ){
                    int temp = v[i+1][j][0];
                    v[i+1][j][0] = v[i][j][0];
                    units += getUnits(h, v, i + 1, j, visted);
                    v[i+1][j][0] = temp;
                }
                if (map[i - 1][j] < curr) {
                    int temp = v[i-1][j][1];
                    v[i-1][j][1] = v[i][j][1];
                    units += getUnits(h, v, i - 1, j, visted);
                    v[i-1][j][1] = temp;
                }
                if (map[i][j + 1] < curr) {
                    int temp = h[i][j+1][0];
                    h[i][j+1][0] = h[i][j][0];
                    units += getUnits(h, v, i, j + 1, visted);
                    h[i][j+1][0] = temp;
//                    units += getUnits(h, v, i, j + 1, visted);
                }

                if (map[i][j - 1] < curr) {
                    int temp = h[i][j-1][1];
                    h[i][j-1][1] = h[i][j][1];
                    units += getUnits(h, v, i, j - 1, visted);
                    h[i][j-1][1] = temp;
                }
//            }
            return units + ( map[i][j]<min ? min-map[i][j]:0 );

        }

    }
}
