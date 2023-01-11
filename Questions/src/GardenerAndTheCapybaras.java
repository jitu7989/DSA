import java.util.*;
import java.io.*;

public class GardenerAndTheCapybaras {

    public static FastReader in = new FastReader();
    public static Utility util = new Utility();

    public static void main(String[] args) {
        
        int tc = in.nextInt();
//        a b baa
//        System.out.println( "a".compareTo( "b" ) + "<---> " + "baa".compareTo("b") );
        while(tc-->0){
            
            String capybaras = in.next();
            int n = capybaras.length();
            
            StringBuilder a = new StringBuilder();
            
            boolean flag = true;
            for (int i = 0; i < n && flag; i++) {
                
                a.append( capybaras.charAt(i) );
                StringBuilder b = new StringBuilder();
                
                for (int j = i+1; j < n && flag; j++) {
                    
                    b.append( capybaras.charAt(j) );
                    StringBuilder c = new StringBuilder();
                    
                    for (int k = j+1; k < n; k++) c.append( capybaras.charAt(k) );
                    
                    String a1 = a.toString();
                    String b1 = b.toString();
                    String c1 = c.toString();
                    int x = a1.compareTo( b1 );
                    int y = c1.compareTo(b1);
                    if( (x<=0 && y<=0) || (x>=0 && y>=0) ){
                        System.out.println( a1+" "+b1+" "+c1 );
                        flag = false;
                    }

                }    
            }
            if(flag) System.out.println(":(");
            
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