
import java.util.*;
import java.io.*;

public class HossamAndTraniee{

    public static FastReader in = new FastReader();
    public static Utility util = new Utility();

    public static void main(String[] args) {

        int tc = in.nextInt();

        while(tc-->0){

            int n = in.nextInt();

            Integer[] arr = new Integer[n];

            for (int i = 0; i <n; i++)
                arr[i] = in.nextInt();

            Arrays.sort( arr , (i,j)->{
                if( i%2!=0 && j%2==0 ) return -1;
                if( i%2==0 && j%2!=0 ) return 1;
                return i-j;
            } );


            if( check(n,arr) ) System.out.println("Yes");
            else System.out.println("No");

        }

    }
    static boolean check( int n, Integer[] arr ){

        if( arr[0]%2==0 && arr[1]%2==0 ) return true;
        int l = 0;
        int r = n-1;

        while( arr[l]%2==0 ) ++l;

        for( int i=l; i<=r-1; i++ ){
            for (int j = i+1; j <=r ; j++) {
                if( lowestCommonDivisor( arr[i] , arr[j] )>1 ) return true;
            }
        }

        return false;
    }

    public static int lowestCommonDivisor( int a , int b ){
        if( a==0 ){
            return b;
        }
        return lowestCommonDivisor( b%a , a );
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