import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Objects;

public class WordLadder2 {
// ["hot","cog","dot","dog","hit","lot","log"]
//    hit    cog
//    "hot"  "dot",  "dog",  "lot",  "log",  "cog"
//    hit;    hit;
//    hot;    hot;
//    dot;    dot;
//    dog;    dog;
//    log;    cog;
//    cog;
    ArrayList<String> ls = new ArrayList<>();

    public static void main(String[] args) {

        WordLadder2 wl = new WordLadder2();

//        System.out.println(  wl.findLadders( "hit" , "cog" , Arrays.asList( "hot","dot","dog","lot","log","cog" )  ));
//        System.out.println( wl.findLadders( "hit" , "cog" , Arrays.asList( "hot","cog","dot","dog","hit","lot","log" )  ));
        System.out.println( wl.findLadders( "pq" , "sq" , Arrays.asList("si", "go", "se", "cm", "so", "ph", "mt", "db", "mb", "sb", "kr", "ln", "tm", "le", "av", "sm", "ar", "ci", "ca", "br", "ti", "ba", "to", "ra", "fa", "yo", "ow", "sn", "ya", "cr", "po", "fe", "ho", "ma", "re", "or", "rn", "au", "ur", "rh", "sr", "tc", "lt", "lo", "as", "fr", "nb", "yb", "if", "pb", "ge", "th", "pm", "rb", "sh", "co", "ga", "li", "ha", "hz", "no", "bi", "di", "hi", "qa", "pi", "os", "uh", "wm", "an", "me", "mo", "na", "la", "st", "er", "sc", "ne", "mn", "mi", "am", "ex", "pt", "io", "be", "fm", "ta", "tb", "ni", "mr", "pa", "he", "lr", "sq", "ye")  ));
    }
    int differentChar = 0;
    public int findLadders(String beginWord, String endWord, List<String> wordList) {

        if( !wordList.contains( endWord ) ) return 0;

        for( int j=0; j<beginWord.length(); j++ ){
            if( endWord.charAt( j ) != beginWord.charAt( j ) )
                differentChar++;
        }

//        int ans = transform( beginWord , endWord , new boolean[wordList.size()] , wordList );
        System.out.println( wordList.size() );
        return 0;
    }
    public int transform( String currWord , String endWord , boolean[] transformed , List<String> wordList ){

        if(Objects.equals(currWord, endWord)) {
            System.out.println(  ls  );
            return 1;
        }

        int minSteps = Integer.MAX_VALUE;

        for( int i=0; i<wordList.size(); i++ ) {

            if ( !transformed[i] && checkDifferentChars(wordList.get(i), currWord) ){
                transformed[i] = true;
                ls.add( wordList.get(i) );
                int x = transform(wordList.get(i), endWord, transformed, wordList)  ;
                minSteps = Math.min( minSteps , x==0 ? Integer.MAX_VALUE : x+1 );

                ls.remove( ls.size()-1 );
                transformed[i] = false;
            }

        }
        return minSteps==Integer.MAX_VALUE ? 0 : minSteps;
    }

    public boolean checkDifferentChars( String str , String currWord ){
        int differentChar = 0;
        for( int j=0; j<str.length(); j++ ){
            if( currWord.charAt( j ) != str.charAt( j ) )
                differentChar++;
            if( differentChar > 1 ) break;
        }
        return differentChar == 1;
    }


}
