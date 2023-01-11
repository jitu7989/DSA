//
//import java.util.*;
//import java.io.*;
//
//
//public class RainWaterTrapping {
//
//    public static Main.FastReader in = new Main.FastReader();
//    public static Main.Utility util = new Main.Utility();
//
//    public static void main(String[] args) {
//
//        int tc = in.nextInt();
//
//        while(tc-->0){
//
//            int n = in.nextInt();
//            int[] arr = util.createIntArray( n );
//
//            int[] left  = new int[n];
//            int[] right = new int[n];
//
//            int ml = -1;
//            int mr = -1;
//            for( int i=0; i<n; i++ ){
//
//                left[i] = ml;
//                right[n-1-i] = mr;
//
//                ml = Math.max( ml , arr[i] );
//                mr = Math.max( mr , arr[n-1-i] );
//
//            }
//            System.out.println(  Arrays.toString( left ) );
//            System.out.println(  Arrays.toString( right ) );
//
//
//        }
//
//    }
//
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
//}
//
