
import java.util.*;
import java.io.*;

public class HossamAndCombinatorics {

    public static FastReader in = new FastReader();
    public static Utility util = new Utility();

    public static void main(String[] args) {

        int tc = in.nextInt();

            while(tc-->0){

                int n = in.nextInt();
                int[] arr = util.createSortedIntArray(n);

                if( arr[0]==arr[n-1] ){
                    System.out.println(  ((long) n *(n-1)) );
                    continue;
                }
                int upper = upperBound( arr , arr[0] )+1;
                int lower = n-lowerBound(arr, arr[n-1]);

                long ans = ((long)(2 * ((long) upper * lower )));

                System.out.println( ans );

            }


    }

    static int upperBound( int[] arr , int target ){

        int low = 0;
        int high = arr.length-1;

        int idx = -1;

        while( low<=high ){

            int mid = low+(high-low)/2;

            if(arr[mid]==target) idx = Math.max( mid , idx );
            if( arr[mid]<=target ) low = mid+1;
            else high = mid-1;

        }

        return idx;

    }
    static int lowerBound( int[] arr , int target ){

        int low = 0;
        int high = arr.length-1;

        int idx = Integer.MAX_VALUE;

        while( low<=high ){

            int mid = low+(high-low)/2;

            if(arr[mid]==target) idx = Math.min( mid , idx );
            if( arr[mid]<target ) low = mid+1;
            else high = mid-1;

        }

        return idx;

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