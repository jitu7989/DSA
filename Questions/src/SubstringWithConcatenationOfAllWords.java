//import java.util.*;
//import java.io.*;
//
//public class SubstringWithConcatenationOfAllWords {
//
//    public static void main(String[] args) {
//        System.out.println( findSubstring( "barfoothefoobarman" , new String[]{ "foo" , "bar" } ) );
//    }
//    public static List<Integer> findSubstring(String s, String[] words) {
//
//        ArrayList<Integer> ans = new ArrayList<>();
//        int nx = words[0].length();
//
//        ArrayList< HashSet<String>  > list = new ArrayList<>(26);
//        for ( int i=0; i<26; i++ ) list.add( new HashSet<>() );
//
//        for ( String i:words ) list.get( i.charAt(0)-'a' ).add( i );
//
//        StringBuilder sb = new StringBuilder( s.length() );
//
//        for (int i = 0; i < nx; i++)
//            sb.append( s.charAt(i) );
//
//        if( list.get( s.charAt(0)-'a' ).contains( sb.toString() ) ){
//            ans.add( 0 );
//            list.get( s.charAt(0)-'a' ).remove( sb.toString() );
//        }
////        System.out.println( list );
//        for( int i=0, j=nx; j<s.length(); j++,i++ ){
//
//            sb.deleteCharAt( 0);
//            sb.append( s.charAt(j) );
//
//            if( list.get( s.charAt(i+1)-'a' ).contains( sb.toString() ) ){
//                ans.add( i+1 );
//                list.get( s.charAt(i+1)-'a' ).remove( sb.toString() );
//            }
//
//        }
////        System.out.println( list );
//        return ans;
//
//    }
//
//    public static boolean function( int[] freq, ArrayList<Pair> strings ){
//
//        for( int i=0; i<strings.size(); i++){
//
//            boolean flag = true;
//            Pair pair = strings.get( i );
//
//            if( pair==null ) continue;
//
//            for (int j = 0; j < 26; j++)
//                if( freq[j] != pair.freq[j] ) {
//                    flag = false;
//                    break;
//                }
//
//            if( flag ){
//                strings.set( i , null );
//                return true;
//            }
//
//        }
//
//        return true;
//    }
//    Object
//    static class Pair{
//
//        String word;
//        int[] freq = new int[26];
//
//        public Pair( String word ){
//
//            this.word = word;
//            for (int i = 0; i < word.length(); i++)  freq[ word.charAt(i)-'a' ]++;
//
//        }
//
//    }
//
//}
