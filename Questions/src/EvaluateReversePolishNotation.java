
import java.util.*;
import java.io.*;

public class EvaluateReversePolishNotation {





    public static FastReader in = new FastReader();
    public static Utility util = new Utility();

    public static void main(String[] args) {

        String[] arr = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
        System.out.println( evalRPN( arr ) );

    }

    public static int evalRPN(String[] tokens) {

        Stack<Integer> nums  = new Stack<>();

        for ( String i:tokens) {

            switch (i) {
                case "+" -> nums.push(nums.pop() + nums.pop());
                case "*" -> nums.push(nums.pop() * nums.pop());
                case "-" -> {
                    int a = nums.pop();
                    int b = nums.pop();
                    nums.push(b-a );
                }
                case "/" -> {
                    int a = nums.pop();
                    int b = nums.pop();
                    nums.push(b / a);
                }
                default -> nums.push(Integer.parseInt(i));
            }


        }

        return nums.peek();
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