import java.util.*;
import java.io.*;
public class VanyaAndExams {


    public static FastReader in = new FastReader();
    public static Utility util = new Utility();

    public static void main(String[] args) {



        int noOfExams = in.nextInt();
        long obtainingLimitInEachExam = in.nextLong();
        long avgMarksNeedToGetScholarship = in.nextLong();

        long totalMarksObtained = 0;
        long totalMarksNeeded = avgMarksNeedToGetScholarship*noOfExams;

        Subject[] examSubjects = new Subject[ noOfExams ];

        for (int i = 0; i < noOfExams; i++) {
            examSubjects[i] = new Subject(in.nextLong(), in.nextLong());
            totalMarksObtained += examSubjects[i].obtained;
        }

        Arrays.sort( examSubjects , (a,b)-> Long.compare( a.costToIncrementOneMarks , b.costToIncrementOneMarks ) );
        long ans = 0;
        for ( Subject i:examSubjects ) {

            long canObtain = Math.max( obtainingLimitInEachExam-i.obtained , 0 ); // value shouldn't be in minus

            if( totalMarksNeeded<=totalMarksObtained ) break;

            canObtain = Math.min( canObtain , totalMarksNeeded-totalMarksObtained );

            ans += (canObtain*i.costToIncrementOneMarks);
            totalMarksObtained += canObtain;

        }

        System.out.println( ans );


    }
    static class Subject {
        long obtained;
        long costToIncrementOneMarks;

        public Subject(long gained, long costToIncrement) {
            this.obtained = gained;
            this.costToIncrementOneMarks = costToIncrement;
        }

        @Override
        public String toString() {
            return "Subject{" +
                    "gained=" + obtained +
                    ", costToIncrement=" + costToIncrementOneMarks +
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