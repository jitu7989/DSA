import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;

class CountWords{

    class ClassRepresentative{
        public static void main(String args[]){
            Scanner sc = new Scanner(System.in);
            int n=sc.nextInt();
            int[] num=new int[n];
            for(int i=0;i<n;i++)
            {
                num[i]=sc.nextInt();
            }
            System.out.println(classRepresentative(num,n));
        }

        static String classRepresentative(int[] num,int n){

            boolean inc= true;
            boolean dec= true;

            for (int i = 0; i+2 < num.length ; i+=2) {

                if( num[i] > num[i+2] ) inc = false;

                if( num[i] < num[i+2] ) dec = false;


            }
            if( inc ) return "increasing";
            if( dec ) return "decreasing";
            return "none";
        }
    }
}


