import java.util.*;

public class MinimumTimeToCollectAllApplesInATree {

    public static void main(String[] args) {
        int[][] edges = { {0,1} , {0,2},{1,4},{1,5},{2,3},{2,6} };
        Boolean[] hasAppple = {false,false,true,false,true,true,false};

        System.out.println( minTime( 7 ,edges,  Arrays.asList( hasAppple ) ) );
    }

    public static int minTime(int n, int[][] edges, List<Boolean> hasApple) {

        HashMap<Integer, List<Integer> > map = new HashMap<>();
        for( int i=0; i<n; i++ )
            map.put( i , new ArrayList<>() );

        for( int[] i:edges ){
            map.get( i[0] ).add( i[1] );
            map.get( i[1] ).add( i[0] );
        }

        HashSet<Integer> visited = new HashSet<>();
        Pair p = min( 0 , visited , hasApple , map );
        return p.time;
    }

    public static Pair min( int currNode, HashSet<Integer> visited, List<Boolean> hasApple, HashMap<Integer,List<Integer>> map  ){

        if( visited.contains( currNode ) ) return new Pair(0 , false);

        List<Integer> connectedNodes = map.get( currNode );
        Pair p = new Pair( 0 , hasApple.get(currNode) );

        visited.add(currNode);
        for (int i = 0; i < connectedNodes.size(); i++) {

            if( !visited.contains( connectedNodes.get(i) ) ) {

                Pair p1 = min(connectedNodes.get(i), visited, hasApple, map);
                if( p1.childNodeHasApple ){
                    p.childNodeHasApple = true;
                    p.time += p1.time;
                }

            }

        }

        if( p.childNodeHasApple && currNode!=0 ) p.time+=2;

        return p;

    }

    static class Pair{

        int time;
        boolean childNodeHasApple;

        public Pair(int time, boolean childNodeHasApple) {
            this.time = time;
            this.childNodeHasApple = childNodeHasApple;
        }


    }

}
