import java.util.*;
import java.io.*;

public class HossamAndFriends{

    public static FastReader in = new FastReader();
    public static Utility util = new Utility();

    public static void main(String[] args) {

        int tc = in.nextInt();

            while(tc-->0){

                int n = in.nextInt();
                int m = in.nextInt();
                int[] arr = new int[n+2];

                Arrays.fill( arr , n+1 );

                for( int i=0; i<m; i++ ){

                    int x = in.nextInt();
                    int y = in.nextInt();

                    int min = Math.min( x , y );
                    int max = Math.max( x , y );

                    arr[ min ] = Math.min( arr[min] , max );

                }
//                System.out.println( Arrays.toString(arr) );
                int min = Integer.MAX_VALUE;
                long sum = 0;
                for( int i=n; i>0; i-- ) {

                    min = Math.min(min, arr[i]);
                    arr[i] = min;
//                    System.out.println( arr[i] + " - " + i );
                    sum += (long)(arr[i]-i);
                }

                System.out.println( sum );

            }

    }

    private static int recursive( int i,int curr, HashMap<Integer, Set<Integer> > map, int[] dp) {

        if( map.containsKey( i ) && map.get( i ).contains( curr ) ){
            return recursive( i , curr+1 , map , dp );
        }

return 0;

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