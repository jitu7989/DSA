import java.util.*;
import java.io.*;

public class UnlockYourPhone {

    public static FastReader in = new FastReader();
    public static Utility util = new Utility();

    public static int n;
    public static int m;
    public static int ans;
    public static void main(String[] args) {

        n = in.nextInt();
        m = in.nextInt();
        int[][] grid = {
                {0,0,0},
                {0,0,0},
                {0,0,0}
        };
        if( n>m ){
            System.out.println( 0 );return;
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                gridPattern( grid,i,j ,1);
            }
        }
        System.out.println( ans );

    }

    private static void gridPattern(int[][] grid, int i, int j , int count) {

        if( i<0 || j<0 || i>=3 || j>=3 || grid[i][j]==1 || count>m ) return;
        grid[i][j] = 1;

        if( count>=n ) ans++;

        gridPattern( grid,i+1,j,count+1);
        gridPattern( grid,i-1,j,count+1);
        gridPattern( grid,i,j+1,count+1);
        gridPattern( grid,i,j-1,count+1);

        if( i==0 && j==1 ){
            gridPattern( grid,1,0,count+1);
            gridPattern( grid,1,2,count+1);
            gridPattern( grid,2,0,count+1);
            gridPattern( grid,2,2,count+1);
        }

        if( i==2 && j==1 ){

            gridPattern( grid,1,0,count+1);
            gridPattern( grid,1,2,count+1);
            gridPattern( grid,0,0,count+1);
            gridPattern( grid,0,2,count+1);

        }

        if( i==1 && j==0 ){

            gridPattern( grid,0,1,count+1);
            gridPattern( grid,2,1,count+1);
            gridPattern( grid,0,2,count+1);
            gridPattern( grid,2,2,count+1);

        }
        if( i==1 && j==2 ){

            gridPattern( grid,0,1,count+1);
            gridPattern( grid,2,1,count+1);
            gridPattern( grid,0,0,count+1);
            gridPattern( grid,2,0,count+1);

        }

        if( i==0 && j==0 ){

            gridPattern( grid,1,2,count+1);
            gridPattern( grid,2,1,count+1);

        }
        if( i==2 && j==0 ){
            gridPattern( grid,0,1,count+1);
            gridPattern( grid,1,2,count+1);
        }
        if( i==2 && j==2 ){
            gridPattern( grid,0,1,count+1);
            gridPattern( grid,1,0,count+1);
        }
        if( i==0 && j==1 ){
            gridPattern( grid,1,0,count+1);
            gridPattern( grid,2,1,count+1);
        }
        if( i==1 && j==1 ){

            gridPattern( grid,0,0,count+1);
            gridPattern( grid,2,2,count+1);
            gridPattern( grid,0,2,count+1);
            gridPattern( grid,2,0,count+1);

        }

        grid[i][j] = 0;

    }


    static class FastReader{

        BufferedReader br;

        StringTokenizer st;

        public FastReader(){
            br=new BufferedReader(new InputStreamReader(System.in));
        }

        String next(){
            while(st==null || !st.hasMoreTokens()){
                try {
                    st=new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt(){
            return Integer.parseInt(next());
        }

        long nextLong(){
            return Long.parseLong(next());
        }

        double nextDouble(){
            return Double.parseDouble(next());
        }

        String nextLine(){
            String str="";
            try {
                str=br.readLine().trim();
            } catch (Exception e) {
                e.printStackTrace();
            }
            return str;
        }



    }

    static class Utility{

        int[] createIntArray(){

            String s = in.nextLine();

            return Arrays.stream( s.split(" ") )
                    .mapToInt( Integer::parseInt )
                    .toArray();


        }

        int[] createIntArray(int n){

            int[] arr = new int[n];
            for(int i=0; i<n; i++) arr[i] = in.nextInt();


            return arr;


        }

        int[] createSortedIntArray(int n){

            int [] arr = createIntArray(n);
            Arrays.sort( arr );

            return arr;
        }

        int[][] create2DArray( int n , int m ){

            int[][] arr = new int[n][m];
            for(int i=0; i<n; i++)
                arr[i] = createIntArray( m );

            return arr;



        }

        < T > String joinArray( T[] arr , String s ){

            StringBuilder sb = new StringBuilder("");

            for(int i=0; i<arr.length; i++)
                sb.append( arr[i] + s  );

            return sb.toString();
        }

        <T> String  joinList(List<T> arr, String s ){

            StringBuilder sb = new StringBuilder("");

            for(int i=0; i<arr.size(); i++)
                sb.append( arr.get(i) + s  );

            return sb.toString();
        }

    }


}