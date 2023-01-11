
import java.util.*;
import java.io.*;

public  class Coloring{

    public static FastReader in = new FastReader();
    public static Utility util = new Utility();

    public static void main(String[] args) {

        int tc = in.nextInt();

        while (tc-->0){

            long n = in.nextLong(); // TODO: This Variable Represent the No of Cell to Paint
            int m  = in.nextInt();  // TODO: No of Colors
            int k = in.nextInt();   // TODO: NO of Distinct elements

            long sum = 0;
            Integer[] arr = new Integer[m];

            for (int i = 0; i < m; i++) {

                arr[i]=in.nextInt();
                sum += arr[i];

            }

            if( sum != n ) {
                System.out.println( "NO" );
                continue;
            }

//            Arrays.sort( arr , Collections.reverseOrder() );

            int limitOfOneValue =  (int) n/k ;
            int allowedValues = ((int)n)%k;

            boolean possible = true;


            boolean used = false;
            boolean odd = n%2==1;

            for (int i = 0; i < m && possible; i++) {
                if (arr[i] > limitOfOneValue) {
                    if( arr[i] == limitOfOneValue+1 && allowedValues-->0 )
                        continue;

                    possible = false;
                }
            }

            System.out.println( possible ? "YES":"NO" );


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