import java.util.*;
import java.io.*;

public class TriplesStones {

    public static FastReader in = new FastReader();
    public static Utility util = new Utility();
    public static int k;
    public static void main(String[] args) {

        int n = in.nextInt();
        k = in.nextInt();
        TreeMap<Integer,Integer> tm = new TreeMap<>();
        int[] arr = new int[n];

        for( int i=0; i<n; i++ ){
            arr[i] = in.nextInt();
            addKey( tm , arr[i] );
        }
        tm.remove( arr[0] );


        int combination = 0;
        for(int i=1; i<n; i++){

            long x = arr[i];
            removeKey( tm , (int)x );

            for( int j = i-1; j>=0; j-- ){

                long y = arr[j];
//                System.out.println((int)(k/(x*y)));
                Set<Map.Entry<Integer, Integer>> set = tm.headMap( (int)(k/(x*y))+1 ).entrySet();
                if( set!=null || (!set.isEmpty()) ) {
                    for (Map.Entry<Integer, Integer> z : set)
                        combination += z.getValue();
                }
//                System.out.println( tm.headMap( (int)(k/(x*y))+1 ).entrySet() );
            }

        }
        System.out.println(combination);
    }
    public static void addKey( TreeMap<Integer,Integer> tm, int key ){
        if( !tm.containsKey(key) ) tm.put( key , 0 );
        tm.put( key , tm.get(key)+1 );
    }

    public static void removeKey( TreeMap<Integer,Integer> tm, int key ){

        tm.put( key , tm.get(key)-1 );
        if(tm.get(key) == 0) tm.remove(key);

    }

    public static int binarySearch( int[] arr , int low, int high, long product ){

        while( low+1<high ){

            int mid = low+(high -low)/2;

            if( (long)arr[mid]*product <= product ) low = mid+1;
            else high = mid-1;

        }

        if( high<arr.length && arr[high]*product<=k ) return high;
        if( low<arr.length && arr[low]*product<=k ) return low;
        return -1;

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
