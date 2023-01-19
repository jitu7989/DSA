import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class LongestPathWithDifferentAdjacentCharacters {

    public static void main(String[] args) {

        System.out.println( longestPath( new int[]{-1,0,0,1,1,2}, "abacbe" ));

    }

    public static int maxPathLen;

    public static int longestPath(int[] parent, String s) {

        int n = parent.length;

        List< List<Integer> > graph = new ArrayList<>();
        maxPathLen = 0;

        for (int i = 0; i < n; i++) graph.add( new ArrayList<>() );

        for (int i = 1; i < n; i++)
            graph.get( parent[i] ).add( i );


        findLongestPath( 0 , s ,  graph );


        return maxPathLen;
    }

    public static int findLongestPath(
                                        int currNode,
                                        String nodeCharacter,
                                        List<List<Integer> > graph
                                      )
    {

        List<Integer> connectedNodes = graph.get( currNode );
        char elementOnCurrNode = nodeCharacter.charAt(currNode);

        int[] twoMaxPath = new int[2];

        for (int i:connectedNodes ) {

            int path = findLongestPath( i , nodeCharacter ,  graph );

            if( path!=-1 && elementOnCurrNode != nodeCharacter.charAt( i ) ){
                path += 1;
                if( twoMaxPath[0] < path ){
                    twoMaxPath[1] = twoMaxPath[0];
                    twoMaxPath[0] = path;
                } else if (twoMaxPath[1] < path) {
                    twoMaxPath[1] = path;
                }

            }

        }

        maxPathLen = Math.max( twoMaxPath[0]+twoMaxPath[1]+1 , maxPathLen );

        return twoMaxPath[0];
    }

}
