
import java.util.*;
import java.io.*;

public class MashaAndABeautifulTree {

    public static FastReader in = new FastReader();
    public static Utility util = new Utility();
    public static int[] arr;

    public static void main(String[] args) {

        int tc = in.nextInt();

        while( tc-- > 0 ){

            int n = in.nextInt();
            arr = util.createIntArray( n );

            int swap = beautifulTree(  0 ,n-1  );
            boolean flag = true;
            for (int i = 1; i <n ; i++) {
                if(arr[i-1]>=arr[i]) {
                    flag = false;
                    break;
                }
            }
            System.out.println( flag ? swap : -1 );
        }

    }

    public static int beautifulTree( int left , int right ){

        if( left>=right ) return 0;
        int mid = left+(right-left)/2;

        int operations = beautifulTree( left , mid ) + beautifulTree( mid+1, right);

        boolean swap = false;
        for (int i = left,j=mid+1; i <=mid ; i++,j++ ) {
            if( arr[i]>arr[j] ){
                swap = true;
                break;
            }
        }

        if( swap ){

            int[] temp = new int[ mid-left+1 ];

            for (int i = left,j=0; i <=mid ; j++,i++) {
                temp[j] = arr[i];
            }

            for (int i=left, j=mid+1, k=0;  i <=mid;  i++,j++,k++ ) {
                arr[i] = arr[j];
                arr[j] = temp[k];
            }
            return operations+1;
        }

        return operations;
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
//        4
//        8
//        6 5 7 8 4 3 1 2
//        4
//        3 1 4 2
//        1
//        1
//        8
//        7 8 4 3 1 2 6 5
