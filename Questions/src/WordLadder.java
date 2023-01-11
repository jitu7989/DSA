import java.util.*;

public class WordLadder {

    public static void main(String[] args) {

        WordLadder wl = new WordLadder();

        System.out.println( wl.ladderLength( "hit" , "cog" , Arrays.asList( "hot","cog","dot","dog","hit","lot","log" )  ));
//        System.out.println( wl.ladderLength( "pq" , "sq" , Arrays.asList("si", "go", "se", "cm", "so", "ph", "mt", "db", "mb", "sb", "kr", "ln", "tm", "le", "av", "sm", "ar", "ci", "ca", "br", "ti", "ba", "to", "ra", "fa", "yo", "ow", "sn", "ya", "cr", "po", "fe", "ho", "ma", "re", "or", "rn", "au", "ur", "rh", "sr", "tc", "lt", "lo", "as", "fr", "nb", "yb", "if", "pb", "ge", "th", "pm", "rb", "sh", "co", "ga", "li", "ha", "hz", "no", "bi", "di", "hi", "qa", "pi", "os", "uh", "wm", "an", "me", "mo", "na", "la", "st", "er", "sc", "ne", "mn", "mi", "am", "ex", "pt", "io", "be", "fm", "ta", "tb", "ni", "mr", "pa", "he", "lr", "sq", "ye")  ));


    }

    public int ladderLength(String beginWord, String endWord, List<String> wordList) {

        HashMap< String , ArrayList<String> > graph = new HashMap<>();
        TreeSet<String> visted = new TreeSet<>( wordList );

        visted.add( beginWord );
        graph.put( beginWord , new ArrayList<>() );

        for (String s : wordList) graph.put(s, new ArrayList<>());

        if( !visted.contains( endWord ) ) return 0;

        for( String i : graph.keySet() ){
            for( int j=0; j< wordList.size(); j++ ){
                if( checkDifferentChar( wordList.get( j ) , i ) ){
                    graph.get( i ).add( wordList.get(j) );
                }
            }
        }

        LinkedList<String> q = new LinkedList<>();
        q.add(beginWord);
        int level = 1;

        while( !q.isEmpty() ){

            int len = q.size();

            for (int i=0; i<len; i++){

                String s = q.removeFirst();
                ArrayList<String> connections = graph.get( s );

                for( String x:connections ){

                    if( x.equals( endWord ) ) return level+1;
                    if(visted.contains(x)){
                        q.add(x);
                        visted.remove(x);
                    }

                }

            }
            level++;

        }

        return 0;
    }
    boolean checkDifferentChar( String s1 , String s2 ){

        int differentChar = 0;
        for( int j=0; j<s1.length(); j++ ){
            if( s1.charAt( j ) != s2.charAt( j ) )
                differentChar++;
            if( differentChar > 1 ) break;
        }
        return differentChar == 1;

    }

}
