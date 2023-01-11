//
//import java.util.*;
//import java.io.*;
//
//public class HossamAndALetter  {
//
//    public static FastReader in = new FastReader();
//    public static Utility util = new Utility();
//    public static int n,m,maxCellCanForm = -1;
//
//    static char[][] board;
//    static int[][] closestMediumCellBelow;
//    static int[][] closestBadCellBelow;
//    static int[][] closestMediumCellToRight;
//    static int[][] closestBadCellToRight;
//
//    public static void main(String[] args) {
//
//        n = in.nextInt();
//        m = in.nextInt();
//
//        board = new char[n][m];
//
//        for (int i = 0; i < n; i++)  board[i] = in.next().toCharArray();
//
//        closestMediumCellBelow   = new int[n][m];
//        closestBadCellBelow      = new int[n][m];
//        closestMediumCellToRight = new int[n][m];
//        closestBadCellToRight    = new int[n][m];
//
//        for (int col = 0; col<m; col++) {
//            int closestBadCell = -1, closestMediumCell = -1;
//            for (int row = n-1; row>=0 ; row--) {
//
//                closestBadCellBelow[row][col] = closestBadCell;
//                closestMediumCellBelow[row][col] = closestMediumCell;
//
//                if(board[row][col] == '#') closestBadCell = row;
//                if(board[row][col] == 'm') closestMediumCell = row;
//
//            }
//        }
//
//        for( int row=0; row<n; row++ ){
//            int closestBadCell = -1, closestMediumCell = -1;
//            for(int col=m-1; col>=0; col--){
//
//                closestBadCellToRight[row][col] = closestBadCell;
//                closestMediumCellToRight[row][col] = closestMediumCell;
//
//                if(board[row][col] == '#') closestBadCell = col;
//                if(board[row][col] == 'm') closestMediumCell = col;
//
//
//            }
//        }
//
//        for (int i = 0; i < n-3; i++) {
//            for (int j = 0; j < m-3; j++) {
//
////              Following code is check weather first vertical line can be formed or not From line no 63 to line no 76
//
////              Step 1: check if there is a bad cell in the matrix
//                if( board[i][j] == '#' || closestBadCellBelow[i][j]-i <= 3 ) continue;
//
////              Step 2: Create a Variable to check presence of a medium cell in the matrix
//                boolean mediumCellFound = false;
//
////              Step 3: Check if there is a medium cell at the current position in the matrix
//                if (board[i][j] == 'm')  mediumCellFound = true;
//
////              Step 4: Check if there is a medium cell in the next two rows
//                if( closestMediumCellBelow[i][j]-i < 3 ){
//                    if( mediumCellFound ) continue;
//                    mediumCellFound = true;
//                }
//
//
////              This variable keep track till where we can draw 1st verticle line
//                int maxLengthOfVerticalLine1 = closestBadCellBelow[i][j];
//
//                if( closestMediumCellBelow[i][j] )
//
//            }
//        }
//
//        System.out.println(maxCellCanForm);
//
//    }
//
//
//    public static void fromingWallOfH( char[][] ground , int row , int col ) {
//
//        if( row+3 > n || col+3 > m || ground[row][col]=='#' )  return ;
//
//         // This varaible will hold the maximum number of cells that can be formed by the wall of H
//
//        int mediumCellLength = 0; // This variable will hold the number of the medium cell
//
//        for( int k=row; k<row+3; k++ ){  // this loop will check if the wall of H is valid or not
//
//            if( ground[k][col]=='m' && mediumCellLength<1 ) mediumCellLength++; // this condition will check if the medium cell is valid or not
//            else if( ground[k][col]=='#' || (ground[k][col]=='m' && mediumCellLength==1)  ) return ; // this condition will check if the mediumCellLength is valid or not
//
//        }
//
//        int verticalCellLength = 3; // This variable will hold the number of the vertical cell
//
//        for (int i = row+2; i < n; i++) { // this loop is intended to check the maximum possible vertical line length
//
//            if( ground[i][col]=='m' && mediumCellLength<1  ) mediumCellLength++; // this condition will check if the medium cell is valid or not
//            else if( ground[i][col]=='#' || ( i!=row+2 && ground[i][col]=='m' && mediumCellLength==1)  ) break; // this condition will check if the mediumCellLength is valid or not
//
////            System.out.println( "verticalCellLength: " + verticalCellLength );
//
//            for( int j=m-1; j>=col+2; j-- ){  // this loop will increase the distance between two vertical lines of the wall of H
//
//                if( maxCellCanForm>=verticalCellLength*2 + j-1-col  ) continue;
//
//                boolean twoVerticalLineFormed = true; // this variable will check if the second vertical lines of the wall of H is formed or not at the index j
//                boolean mediumCellFormed = false; // this variable will check if the medium cell is present in this vertical line or not this will help to backtrack
//
//                for (int k = row; k <row+verticalCellLength && twoVerticalLineFormed ; k++) { // this loop will check if the second vertical lines of the wall of H is formed or not at the index j
//
//                    if( ground[k][j]=='m' && mediumCellLength<1 ) {
//                        mediumCellFormed = true;
//                        mediumCellLength++;
//                    }
//                    else if( ground[k][j]=='m' && mediumCellLength==1  || ground[k][j]=='#' )  twoVerticalLineFormed = false;
//
//                }
//
//
//                if( twoVerticalLineFormed ){
//
//                    boolean HFormed = false; // this variable will check if the wall of H is formed completely or not so that we can increase the length of the vertical line
//
//                    //Making horizontal line
//                    for (int k = row+1; k <row+verticalCellLength-1 ; k++) {
//                        // this loop will check if the horizontal line is formed or not in row k it runs till the second last row of the vertical line
//
//                        boolean oneHorizontalLineFormed = true; // this variable will check if the horizontal line is formed or not in row k
//                        boolean mediumCellFormedInHorizontalLine = false; // this variable will check if the medium cell is present in this horizontal line or not this will help to backtrack
//
//                        for( int l=col+1; l<j && oneHorizontalLineFormed ; l++ ){
//
//                            if( ground[k][l]=='#' || (ground[k][l]=='m' && mediumCellLength>=1) ) {
//                                oneHorizontalLineFormed = false;
//                            }
//                            if( ground[k][l]=='m' && mediumCellLength<1 ) {
//                                mediumCellFormedInHorizontalLine = true;
//                                mediumCellLength++;
//                            }
//
//                        }
//                        if( mediumCellFormedInHorizontalLine ) mediumCellLength--;
//
//                        if( oneHorizontalLineFormed ){
//                            //Made the H calculating cells
//                            maxCellCanForm = Math.max( verticalCellLength*2 + j-1-col , maxCellCanForm );
//                            HFormed = true;
//                            break;
//                        }
//
//
//
//                    }
//
//                    if(HFormed){
//                        if( mediumCellFormed ) mediumCellLength--;
//                        break;
//                    }
//
//                }
//
//                if( mediumCellFormed ) mediumCellLength--; // backtracking the mediumCellLength
//            }
//
//            verticalCellLength++;
//        }
//
//    }
//
//    static class FastReader{
//
//        BufferedReader br;
//
//        StringTokenizer st;
//
//        public FastReader(){
//            br=new BufferedReader(new InputStreamReader(System.in));
//        }
//
//        String next(){
//            while(st==null || !st.hasMoreTokens()){
//                try {
//                    st=new StringTokenizer(br.readLine());
//                } catch (IOException e) {
//                    e.printStackTrace();
//                }
//            }
//            return st.nextToken();
//        }
//
//        int nextInt(){
//            return Integer.parseInt(next());
//        }
//
//        long nextLong(){
//            return Long.parseLong(next());
//        }
//
//        double nextDouble(){
//            return Double.parseDouble(next());
//        }
//
//        String nextLine(){
//            String str="";
//            try {
//                str=br.readLine().trim();
//            } catch (Exception e) {
//                e.printStackTrace();
//            }
//            return str;
//        }
//
//
//
//    }
//
//    static class Utility{
//
//        int[] createIntArray(){
//
//            String s = in.nextLine();
//
//            return Arrays.stream( s.split(" ") )
//                    .mapToInt( Integer::parseInt )
//                    .toArray();
//
//
//        }
//
//        int[] createIntArray(int n){
//
//            int[] arr = new int[n];
//            for(int i=0; i<n; i++) arr[i] = in.nextInt();
//
//
//            return arr;
//
//
//        }
//
//        int[] createSortedIntArray(int n){
//
//            int [] arr = createIntArray(n);
//            Arrays.sort( arr );
//
//            return arr;
//        }
//
//        int[][] create2DArray( int n , int m ){
//
//            int[][] arr = new int[n][m];
//            for(int i=0; i<n; i++)
//                arr[i] = createIntArray( m );
//
//            return arr;
//
//
//
//        }
//
//        < T > String joinArray( T[] arr , String s ){
//
//            StringBuilder sb = new StringBuilder("");
//
//            for(int i=0; i<arr.length; i++)
//                sb.append( arr[i] + s  );
//
//            return sb.toString();
//        }
//
//        <T> String  joinList(List<T> arr, String s ){
//
//            StringBuilder sb = new StringBuilder("");
//
//            for(int i=0; i<arr.size(); i++)
//                sb.append( arr.get(i) + s  );
//
//            return sb.toString();
//        }
//
//    }
//
//
//}