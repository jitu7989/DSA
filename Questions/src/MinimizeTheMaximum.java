
import java.util.*;
import java.io.*;

public class MinimizeTheMaximum {

    public static FastReader in = new FastReader();
    public static Utility util = new Utility();

    public static void main(String[] args) {

        int tc = in.nextInt();
        while( tc-->0 ){

            int n = in.nextInt();
            long[] arr = util.createLongArray(n);

            LinkedList<Pair> list = new LinkedList<>();
            list.addFirst( new Pair( arr[n-1] , 1 ) );
//            System.out.println();
            for( int i=n-2; i>=0; i-- ){

                Pair prev = list.getFirst();

                if( arr[i] > arr[i+1] )
                    list.addFirst( new Pair( arr[i] , 1 ) );
                else
                    prev.add( arr[i] );

            }

            boolean flag = true;
//            System.out.println( list );
            while( flag ){
                int count = 0;

                for (int i = list.size()-1; i >0 ; i--) {

                    Pair curr = list.get(i);
                    Pair prev = list.get(i-1);

//                    System.out.println( "Start"+ list );
                    if( curr.max >= prev.max ){

                        prev.add( curr.sumOfElement , curr.noOfElements );
                        list.remove(i);
                        count++;

                    }
//                    System.out.println( "End"+list );

                }
                if( count==0 ) flag = false;

            }
            int max = 0;
            for (Pair pair : list)  {
                max = Math.max( max , pair.max );
            }
            System.out.println( max );
        }

    }

    static class Pair{

        long sumOfElement;
        int noOfElements;
        int max;

        public Pair( long sumOfElement , int noOfElements ){

            this.sumOfElement = sumOfElement;
            this.noOfElements = noOfElements;
            this.max = (int)Math.ceil( (double) (this.sumOfElement/noOfElements) );

        }

        public void add(long l) {
            this.noOfElements++;
            this.sumOfElement += l;
            updateMax();
        }
        public void add(long l,int noOfElements) {
            this.noOfElements += noOfElements;
            this.sumOfElement += l;
            updateMax();
        }
        private void updateMax(){
            this.max = (int)Math.ceil( ((double)this.sumOfElement/(double)this.noOfElements) );
        }

        @Override
        public String toString() {
            return "Pair{" +
                    "sumOfElement=" + sumOfElement +
                    ", noOfElements=" + noOfElements +
                    ", max=" + max +
                    '}';
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
        long[] createLongArray(int n){

            long[] arr = new long[n];
            for(int i=0; i<n; i++) arr[i] = in.nextLong();
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

