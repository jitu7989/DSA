import java.util.*;
import java.io.*;

public class GardenerAndTheCapybarasHardVersion {

    public static FastReader in = new FastReader();
    public static Utility util = new Utility();

    public static void main(String[] args) {
        System.out.println( "god" );
        int tc = in.nextInt();

        while(tc-->0){

            String capybaras = in.next();
            int n = capybaras.length();

            char[] capy = capybaras.toCharArray();

            StringBuilder a = new StringBuilder(),
                          b = new StringBuilder(),
                          c = new StringBuilder();

            if( capy[0] == 'a' ){

                int i=0;
                while( i<n && capy[i]=='a' ) i++;

                if( i==n ){

                    int j =  (n/2)-1;
                    int k =  (n/2)+1;

                    copytStringBuilder( capy , 0   , j  , a );
                    copytStringBuilder( capy , j+1 ,  k-1  , b );
                    copytStringBuilder( capy , k , n-1 , c );

                    System.out.println( a +" "+ b +" "+ c );

                    continue;
                }

                int j = i;
                while( j<n && capy[j]=='b') j++;

                if( j==n ){

                    if( n-i == 1 ){
                        copytStringBuilder( capy , 0   , i-2  , a );
                        copytStringBuilder( capy , i-1 , i-1 , b );
                        copytStringBuilder( capy , i , n-1 , c );
                    }
                    else{
                        copytStringBuilder( capy , 0   , i-1  , a );
                        copytStringBuilder( capy , i , n-2 , b );
                        copytStringBuilder( capy , n-1 , n-1 , c );
                    }


                }
                else{

                    copytStringBuilder( capy , 0   , i-1  , a );
                    copytStringBuilder( capy , i , j-1 , b );
                    copytStringBuilder( capy , j , n-1 , c );

                }

                System.out.println( a +" "+ b +" "+ c );

            }
            if( capy[0] == 'b' ){

                int i=0;
                while( i<n && capy[i]=='b' ) i++;

                if( i==n ){

                    int j =  (n/2)-1;
                    int k =  (n/2)+1;

                    copytStringBuilder( capy , 0   , j  , a );
                    copytStringBuilder( capy , j+1 ,  k-1  , b );
                    copytStringBuilder( capy , k , n-1 , c );

                    System.out.println( a +" "+ b +" "+ c );

                    continue;
                }

                int j = i;
                while( j<n && capy[j]=='a') j++;

                if( j==n ){

                    if( n-i == 1 ){
                        copytStringBuilder( capy , 0   , 0  , a );
                        copytStringBuilder( capy , 1 , i-1 , b );
                        copytStringBuilder( capy , i , n-1 , c );
                    }
                    else{
                        copytStringBuilder( capy , 0   , i-1  , a );
                        copytStringBuilder( capy , i , i , b );
                        copytStringBuilder( capy , i+1 , n-1 , c );
                    }


                }
                else{

                    copytStringBuilder( capy , 0   , i-1  , a );
                    copytStringBuilder( capy , i , j-1 , b );
                    copytStringBuilder( capy , j , n-1 , c );

                }

                System.out.println( a +" "+ b +" "+ c );

            }

        }


    }

    public static void copytStringBuilder( char[] arr, int i , int j , StringBuilder sb ){

        for (int k = i; k <= j ; k++) sb.append( arr[k] );

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