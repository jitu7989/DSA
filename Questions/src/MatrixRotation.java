import java.util.*;
import java.io.*;

public class MatrixRotation{

    public static FastReader in = new FastReader();
    public static Utility util = new Utility();

    public static void main(String[] args) {

//      1 3   5 1   7 5   3 7
//      5 7   7 3   3 1   1 5

        int tc = in.nextInt();

        while( tc-- > 0 ){

            int[][] arr = util.create2DArray( 2 , 2 );

            if( ( arr[0][0]<arr[0][1] && arr[0][0]<arr[1][0] && arr[0][1]<arr[1][1] && arr[1][0]<arr[1][1] ) ||
                ( arr[1][0]<arr[0][0] && arr[1][0]<arr[1][1] && arr[0][0]<arr[0][1] && arr[1][1]<arr[0][1] ) ||
                ( arr[1][1]<arr[1][0] && arr[0][1]<arr[0][0] && arr[1][1]<arr[0][1] && arr[1][0]<arr[0][0] ) ||
                ( arr[0][1]<arr[1][1] && arr[0][0]<arr[1][0] && arr[0][1]<arr[0][0] && arr[1][1]<arr[1][0] ) ) {
                System.out.println("YES");
            }
            else {
                System.out.println("NO");
            }
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