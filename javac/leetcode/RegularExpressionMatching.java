package java.leetcode;

public class RegularExpressionMatching {

    public static void main(String[] args) {

        System.out.println( isMatch("aaca","ab*a*c*a" ) );

    }


    public static boolean isMatch(String s, String p) {

        return regMatch(s , p , 0 , 0);
    }

    public static boolean regMatch( String s , String p , int sIdx , int pIdx   ){

        if( s.length()<=sIdx && p.length()<=pIdx ) return true;
        if( p.length()<=pIdx ) return false;
        if( s.length()<=sIdx ) {

            while( pIdx+1<p.length() && p.charAt(pIdx+1) == '*' ) pIdx+=2;
            return p.length()<=pIdx;
        }

        char sChar = s.charAt(sIdx);
        char pChar = p.charAt(pIdx);

        char pCharNext = pIdx+1 < p.length() ? p.charAt( pIdx+1 ) : '~';


        if( pCharNext == '*' ){

            if( regMatch( s , p , sIdx , pIdx+2 ) ) return true;
            int i = 0;

            while( sIdx+i<s.length() &&  (pChar=='.' || s.charAt( sIdx+i ) == pChar) ){
                i++;
                if( regMatch( s , p , sIdx+i , pIdx+2 ) ) return true;

            }

        }
         else if( pChar=='.' || sChar==pChar) {
            return regMatch(s, p, sIdx + 1, pIdx + 1);
        }

        return false;
    }


}
