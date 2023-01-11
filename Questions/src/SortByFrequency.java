import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.TreeMap;

public class SortByFrequency {

    public static void main(String[] args) {
        var x = new SortByFrequency();
        System.out.println( x.frequencySort2("Aabb") );
    }

    public String frequencySort(String s) {

        Character[] arr = new Character[ s.length() ];
        TreeMap<Character,Integer> map = new TreeMap<>(  );

        for(int i=0; i<arr.length; i++) {
            arr[i] = s.charAt(i);
            map.put( arr[i], map.getOrDefault(arr[i], 0) + 1);
        }

        Arrays.sort( arr , (a, b) ->
                                map.get( b )-map.get( a ) != 0 ?
                                            map.get( b )-map.get( a ) : b -(char)a
                    );

        StringBuilder sb = new StringBuilder( s.length() );
        for( Character i:arr )
            sb.append(i);

        return sb.toString();
    }

    public String frequencySort2(String s) {

        Pair[] arr = new Pair[128];

        for(int i=0; i<128; i++)
            arr[i]=new Pair( i );

        for(int i=0; i<s.length(); i++)
            arr[i].freq = arr[i].freq + 1;

        System.out.println( Arrays.toString(  arr ) );
        Arrays.sort(arr);

        StringBuilder sb = new StringBuilder( s.length() );
        for( int i=0; i<128; i++ ){
            if( arr[i].freq==0 )break;
            while( arr[i].freq>0 ){
                sb.append( arr[i].getC() );
                arr[i].freq--;
            }
        }

        return sb.toString();
    }
    class Pair implements Comparable<Pair>{

        private Character c;
        int freq;

        public Pair(int i) {
            this.c = (char)i;
            this.freq = 0;
        }

        public char getC() {
            return c;
        }

        public void setC(char c) {
            this.c = c;
        }

        public Pair(char c, int freq) {
            this.c = c;
            this.freq = freq;
        }

        @Override
        public int compareTo(Pair o) {
            if( this.freq==o.freq ) return this.c - o.getC();
            return o.freq  -  this.freq;
        }

        @Override
        public String toString() {
            return "Pair{" +
                    "c=" + this.c +
                    ", freq=" + freq +
                    '}';
        }
    }

}
