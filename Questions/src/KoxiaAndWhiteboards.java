import java.util.*;
import java.io.*;
public class KoxiaAndWhiteboards {

        public static FastReader in = new FastReader();
        public static Utility util = new Utility();

        public static void main(String[] args) throws IOException {

            int t = in.nextInt();
            while(t-->0) {

                int n = in.nextInt(), m = in.nextInt();

                PriorityQueue<Long> pq = new PriorityQueue<>(n+1);
                long sum = 0;

                for( int i=0; i<n; i++ ) {
                    long x = in.nextLong();
                    pq.add( x );
                    sum += x;
                }


                for (int i=0; i<m; i++) {

                    long x = in.nextLong();

                    sum -= pq.remove();
                    sum += x;
                    pq.add( x );
                }

//                while( !pq.isEmpty() )
//                    sum += pq.poll();

                System.out.println(sum);

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

            public long[] nextLongArray(int n) throws IOException {
                long[] arr = new long[n];
                for (int i = 0; i < n; i++) {
                    arr[i] = nextLong();
                }

                return arr;
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