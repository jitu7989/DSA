
import java.util.*;
import java.io.*;

public  class DoremyPaint3 {

    public static FastReader in = new FastReader();
    public static Utility util = new Utility();

    public static void main(String[] args) {

        int tc = in.nextInt();
        while(tc-->0){
            solve();
        }

    }

    private static void solve() {
        int n = in.nextInt();
        int[] arr = util.createIntArray(n);
        if(n==2 || n==1) {
            System.out.println("Yes");
            return;
        }
        HashMap<Integer,Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++)
            map.put(arr[i], map.getOrDefault(arr[i],0)+1);

        if(map.size()==1) {
            System.out.println("Yes");
            return;
        }
        if(map.size()==2){
            List<Map.Entry<Integer,Integer>> keys = new ArrayList<>(map.entrySet());
            if(n%2==1 && Math.abs(keys.get(0).getValue()-keys.get(1).getValue()) == 1 ){
                System.out.println("Yes");
                return;
            }
            if(n%2==0 && Math.abs(keys.get(0).getValue()-keys.get(1).getValue()) == 0 ){
                System.out.println("Yes");
                return;
            }
        }
        System.out.println("No");

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