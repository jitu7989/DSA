import java.util.Arrays;

public class StringToInteger {

    public static char[] max =  (Integer.MAX_VALUE+"").toCharArray() ;
    public static char[] min =  (Integer.MIN_VALUE+"").toCharArray() ;

    public static void main(String[] args) {
        System.out.println(myAtoi("42"));
    }

    public static int myAtoi(String s) {

        StringBuilder ans = new StringBuilder();
        System.out.println(Arrays.toString(min)  + "\n"+  Arrays.toString(max) );

        boolean isFirstChar = true;
        boolean isNegative = false;

        for (int i = 0; i < s.length(); i++) {

            if( Character.isDigit( s.charAt(i) ) ){
                if( isFirstChar && isNegative )  ans.append( s.charAt(i) );
                else ans.append( s.charAt(i) );
                isFirstChar = false;
            }
            else if( s.charAt(i) == '-' )
                isNegative = true;
            else if ( Character.isWhitespace( s.charAt(i) ) )
                continue;
            else {break;};

        }

        char[] nums =  ans.toString().toCharArray();

        if( nums.length == 0 ) return 0;

        if( !checkOutOfRange( nums ,isNegative ) ) return Integer.parseInt( isNegative ? "-"+new String( nums ) : new String( nums ) );



        return 0;

    }

    static boolean checkOutOfRange( char[] a , boolean isNegative ){

        if( a.length > max.length ) return true;
        else if( a.length < max.length ) return false;

        for(int i=0; i<a.length; i++){
            if(!isNegative) {
                if (a[i] > max[i]) return true;
                else if (a[i] < max[i]) return false;
            }
            else{
                if( a[i]>max[i] ) return true;
                else if( a[i]<max[i] ) return false;
            }
        }
        return false;


    }



}
