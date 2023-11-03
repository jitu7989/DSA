//
//import java.util.*;
//import java.io.*;
//
//public class SymmetricSwaps{
//
//    public static FastReader in = new FastReader();
//    public static Utility util = new Utility();
//
//    public static void main(String[] args) {
//
//        int tc = in.nextInt();
//
//        while(tc-->0){
//
//            int n = in.nextInt();
//            Pair[] arr = new Pair[n];
//
//            for( int i=0; i<n; i++ )
//                arr[i] = new Pair( in.nextInt() , 0 );
//
//            for (int i = 0; i < n; i++)
//                arr[i].b = in.nextInt();
//
//            Arrays.sort( arr );
//
//        }
//
//    }
//    public static int calMinimumSwaps( Pair[] arr , int i, int j ){
//
//
//
//    }
//    static class Pair implements Comparable<Pair>{
//        int a;
//        int b;
//        Pair(int a, int b){
//            this.a = a;
//            this.b = b;
//        }
//
//        @Override
//        public int compareTo(Pair o) {
//            return this.a - o.a;
//        }
//    }
//
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
//