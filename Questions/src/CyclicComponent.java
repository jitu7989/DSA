
import java.util.*;
import java.io.*;

public class CyclicComponent{

    public static FastReader in = new FastReader();
    public static Utility util = new Utility();

    public static void main(String[] args) {

        int nodes = in.nextInt();
        int vertex = in.nextInt();

        HashMap<Integer, ArrayList<Integer>> graph = new HashMap<>();
        for (int i = 1; i <= nodes ; i++)
            graph.put( i , new ArrayList<>() );

        for (int i = 0; i < vertex ; i++) {
            int x = in.nextInt();
            int y = in.nextInt();
            graph.get( x ).add( y );
            graph.get( y ).add( x );
        }

        HashMap<Integer,Integer> visited = new HashMap<>();

        int ans = 0;
        Set<Map.Entry<Integer,ArrayList<Integer>>> set = graph.entrySet();
        for( Map.Entry<Integer,ArrayList<Integer>> i:set ){

            if(  !visited.containsKey( i.getKey() ) && dfs( i.getKey() , i.getKey() , 1 , graph,  visited )){
               ans++;
            }
        }
        System.out.println(ans);

    }

    public static boolean dfs( int currNode , int startNode , int depth, HashMap<Integer, ArrayList<Integer>> graph , HashMap<Integer,Integer> visted ){


        visted.put( currNode , depth );

        ArrayList<Integer> list = graph.get( currNode );

        for (Integer integer : list) {
            if(  visted.containsKey( integer ) && depth-visted.get( integer )>=2  ) return true;
            if( !visted.containsKey( integer ) && dfs( integer, startNode, depth + 1, graph , visted ) )  return true;

        }
        return false;
    }
    static class Pair implements Comparable<Pair>{

        int node;
        int depth;

        public Pair( int node , int depth ){
            this.node = node;
            this.depth = depth;
        }
        @Override
        public int compareTo(Pair o) {
            return this.depth-o.depth;
        }

        @Override
        public boolean equals(Object obj) {
            if( obj instanceof Pair ){
                Pair p = (Pair) obj;
                return this.node == p.node;
            }
            return false;
        }

        @Override
        public int hashCode() {
            return Objects.hash( this.node );
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