import java.util.*;
import java.io.*;

public class DoremyConnectingPlan {

    public static FastReader in = new FastReader();
    public static Utility util = new Utility();

    public static void main(String[] args) {

        int tc = in.nextInt();

        while(tc-->0){
            solve();
        }


    }


   static class Pair{

        Long min;
        Long sum;

        ArrayList<Long> idxs = new ArrayList<>();

        public Pair(Long idx, Long sum) {
            this.min = idx+1;
            this.sum = sum;
            idxs.add(idx);
        }

        public Long getMin(){
            return min;
        }
        public Long getSum(){
            return sum;
        }
        public void addIdx(Pair p){
            this.min = Math.min(this.min, p.min);
            this.sum += p.sum;
            idxs.addAll(p.idxs);
        }

    }


    private static void solve() {

        Long n = in.nextLong(), c = in.nextLong();

        Long[] arr = new Long[n.intValue()];
        for (int i = 0; i < n; i++)  arr[i] = in.nextLong();

        List<Pair> ls = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            ls.add(new Pair( (long)i , arr[i]));
        }

        while( ls.size() > 1 ){
            int size1 = ls.size()-1;
            int size2 = ls.size();
            boolean f = true;
            for (int i = 0; i < size1; i++) {
                for (int j = i+1; j < size2; j++) {

                    Pair p1 = ls.get(i);
                    Pair p2 = ls.get(j);

                    if( p1.getSum()+ p2.getSum() >= p1.getMin()*p2.getMin()*c){
                        p2.addIdx(ls.remove(j));
                    }

                }
            }
        }
        System.out.println(ls.size()==1 ? "YES" : "NO");
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

