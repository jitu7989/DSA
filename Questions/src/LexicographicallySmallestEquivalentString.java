import java.sql.ClientInfoStatus;
import java.util.*;

public class LexicographicallySmallestEquivalentString {

    public static void main(String[] args) {
//        System.out.println( smallestEquivalentString( "parker" , "morris" , "parser" ) );
        System.out.println( smallestEquivalentString( "gmerjboftfnqseogigpdnlocmmhskigdtednfnjtlcrdpcjkbj" ,
                                                      "fnnafafhqkitbcdlkpiloiienikjiikdfcafisejgeldprcmhd" ,
                                                   "ezrqfyguivmybqcsvibuvtajdvamcdjpmgcbvieegpyzdcypcx").equals("azaaayauavayaaaavaauvaaaavaaaaaaaaaavaaaaayzaayaax")
                                                    );

//        a=b=c=d=e=f=g=h=i=j=k=l=m=n=o=p=q=r=s=t
//

//        "aza c ayauavaya c aavaauvaaaavaaaaaaaaaavaaaaayzaayaax"
//        System.out.println( smallestEquivalentString( "leetcode" , "programs" , "sourcecode" ) );
    }

    public static String smallestEquivalentString(String s1, String s2, String baseStr) {

        List<TreeSet<Character>> sets = new ArrayList<>();

        int n = s1.length();
        int m = s2.length();

        for ( int i=0; i<n; i++ ){

            int[] toJoin = new int[2];
            int idx = 0;

            char c1 = s1.charAt(i);
            char c2 = s2.charAt(i);

            for ( int j=0; j<sets.size() && idx<2; j++ ){
                TreeSet<Character> set = sets.get(j);
                if( set.contains( c1 ) || set.contains( c2 ) )
                    toJoin[idx++] = j;
            }

            if( idx==0 ){

                TreeSet<Character> set = new TreeSet<>();
                set.add( c1 );
                set.add( c2 );
                sets.add( set );

            }
            else if( idx==1 ){
                sets.get( toJoin[0] ).add( c1 );
                sets.get( toJoin[0] ).add( c2 );
            }
            else sets.get( toJoin[0] ).addAll( sets.remove( toJoin[1] ) );


        }

        StringBuilder sb = new StringBuilder();
        for( int i=0; i<baseStr.length(); i++ ){

            char c = baseStr.charAt(i);

            for( TreeSet<Character> set:sets )
                if( set.contains(c) ){
                    c = set.first();
                    break;
                }

            sb.append( c );
        }

        return sb.toString();

    }



//    public static String smallestEquivalentString(String s1, String s2, String baseStr) {
//
//        HashMap< Character , TreeSet<Character>> hm = new HashMap<>();
//        int n = s1.length();
//        int m = baseStr.length();
//
//        for (int i = 'a'; i <= 'z'; i++)
//            hm.put( (char)i , new TreeSet<>() );
//
//
//        for( int i=0; i<n; i++ ){
//
//            char c1 = s1.charAt( i );
//            char c2 = s2.charAt( i );
//            char c3 = i<m ? baseStr.charAt(i) : '-';
//
//            hm.get( c1 ).add( c2 );
//            hm.get( c2 ).add( c1 );
//
//            if( i<m ){
//
//                hm.get( c3 ).add( c1 );
//                hm.get( c3 ).add( c2 );
//
//                hm.get( c1 ).add( c3 );
//                hm.get( c2 ).add( c3 );
//            }
//
//            for( char el : hm.get( c1 ) ) {
//
//                hm.get(el).add(c2);
//                hm.get(c2).add(el);
//
//                if( i<m ){
//                    hm.get(el).add(c3);
//                    hm.get(c2).add(c3);
//                }
//
//            }
//            for( char el : hm.get( c2 ) ) {
//                hm.get(el).add(c1);
//                hm.get(c1).add(el);
//
//                if( i<m ){
//                    hm.get(el).add(c3);
//                    hm.get(c1).add(c3);
//                }
//
//            }
//            if( i<m ){
//
//                for ( char el:hm.get( c3 ) ){
//                    hm.get( el ).add( c1 );
//                    hm.get( el ).add( c2 );
//                }
//
//            }
//
//
//        }
//        for ( Map.Entry< Character , TreeSet<Character>> el:hm.entrySet() ) {
//            System.out.println(  el.getKey() +" "+ el.getValue() );
//        }
//
//        StringBuilder sb = new StringBuilder();
//        for( int i=0; i<baseStr.length(); i++ ){
//
//            char c = baseStr.charAt(i);
//            TreeSet<Character> set = hm.get( c );
//
//            if(set.size()!=0 ){
//                for( char el:set ){
//                    if( el<c ) c= el;
//                    break;
//                }
//            }
//
//            sb.append( c );
//        }
//
//        return sb.toString();
//    }


}
