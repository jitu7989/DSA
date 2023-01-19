

import java.util.*;
import java.io.*;

public class Boredom {

    public static FastReader in = new FastReader();
    public static Utility util = new Utility();

    public static void main(String[] args) {

        int n = in.nextInt();
        int[] arr = new int[100001];
        long[] dp = new long[100001];
        for (int i = 0; i < n; i++) arr[ in.nextInt() ]++;

        for( int i=1; i< dp.length; i++ ){

            int idx1 = i==1 ? 0 : i-2;
            int idx2 = i<=2 ? 0 : i-3;
            long max = Math.max( dp[idx1] , dp[idx2] );
            dp[i] = max + ((long) arr[i] *i );

        }
        System.out.println( Math.max( dp[dp.length-1] , dp[dp.length-2] ) );

    }

    public int minFlipsMonoIncr(String s) {

        int n = s.length()-1;
        int leftZero = 0;
        int leftOne = 0;
        int rightZero = 0;
        int rightOne = 0;

        for( int i=n; i>=0; i-- )
            if( s.charAt(i) == '0' ) rightZero++;
            else rightOne++;

        int min = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {

            if( leftOne + rightZero < min ) min = leftOne + rightZero;

            if( s.charAt(i) == '0' ){
                leftZero++;
                rightZero--;
            }
            else{
                leftOne++;
                rightOne--;
            }

        }
        return min;
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