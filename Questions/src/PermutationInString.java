import java.util.*;

public class PermutationInString {

    public static void main(String[] args) {
        System.out.println( checkInclusion( "hello" ,"ooallboolleh" ) );
    }

    public static boolean checkInclusion(String s1, String s2) {

        int[] arr1 = new int[26];
        int[] arr2 = new int[26];


        for( int i=0; i<s1.length(); i++ ) {
            arr1[ s1.charAt(i) - 'a' ]++;
            arr2[ s2.charAt(i) - 'a' ]++;
        }

        for( int i=s1.length(),j=0 ; i<s2.length(); i++,j++ ){

            arr2[ s2.charAt(j) - 'a' ]--;
            arr2[ s2.charAt(i) - 'a' ]++;

            if( compare( arr1 ,arr2 ) ) return true;

        }



        return false;
    }
    public static boolean compare(int[] arr1,int[] arr2){
        boolean flag = true;
        for( int z =0 ; z<26;z++ ){
            if( arr1[z]!=arr2[z] ){
                flag = false;
                break;
            }
        }
        return flag;
    }

}
