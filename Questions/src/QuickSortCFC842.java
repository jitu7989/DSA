//Problem link https://codeforces.com/contest/1768/problem/B


import java.util.*;
import java.io.*;

public class QuickSortCFC842 {

        public static FastReader in = new FastReader();
        public static Utility util = new Utility();

        public static void main(String[] args) {

            int tc = in.nextInt();

            while( tc-->0 ){

                int n = in.nextInt();
                int k = in.nextInt();

                int[] arr = util.createIntArray(n);
                int[] dp = new int[n];
                int max = Integer.MIN_VALUE;

                for( int i=n-1; i>=0; i-- ){

                    int val = 1;
                    int j = i+1;
                    while( j<n && arr[i] > arr[j] ){
                        j++;
                    }
                    if( j<n ) val += dp[j];
                    dp[i] = val;
                    max = Math.max( max , val );
                }
                System.out.println( n-max );

            }

        }

        static class Pair{

            int noOfGreaterEl;
            int idxToNextNode;

            public Pair(int noOfGreaterEl, int idxToNextNode) {
                this.noOfGreaterEl = noOfGreaterEl;
                this.idxToNextNode = idxToNextNode;
            }
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
