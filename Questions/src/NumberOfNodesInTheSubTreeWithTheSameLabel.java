import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;

public class NumberOfNodesInTheSubTreeWithTheSameLabel {

    public static void main(String[] args) {

        System.out.println(Arrays.toString(countSubTrees(7, new int[][]{{0, 1}, {0, 2}, {1, 4}, {1, 5}, {2, 3}, {2, 6}}, "abaedcd")));

    }

    public static int[] countSubTrees(int n, int[][] edges, String labels) {

        ArrayList< ArrayList<Integer> > graph = new ArrayList<>();
        HashSet<Integer> visited = new HashSet<>();

        for (int i = 0; i < n; i++) graph.add(new ArrayList<>());

        for ( int[] i:edges ) {
            graph.get( i[0] ).add( i[1] );
            graph.get( i[1] ).add( i[0] );
        }

        int[] ans = new int[n];

        countLabel( 0 , graph , visited , labels , ans );
        return ans;

    }

    public static int[] countLabel( int currNode , ArrayList< ArrayList<Integer> > graph , HashSet<Integer> visited, String label , int[] labelValues ){

        if( visited.contains( currNode ) ) return null;

        visited.add( currNode );

        ArrayList<Integer> list = graph.get( currNode );
        int[] table = new int[26];

        table[label.charAt(currNode)-'a']++;


        for( int i:list ){

            int[] ans = countLabel( i, graph, visited, label, labelValues );
            if( ans!=null ) {
                for (int j = 0; j < 26; j++) {
                    table[j] += ans[j];
                }
            }

        }

        labelValues[ currNode ] = table[ label.charAt(currNode) - 'a' ];

        return table;

    }

}
