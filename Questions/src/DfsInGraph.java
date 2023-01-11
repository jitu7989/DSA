import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class DfsInGraph {

    void bfsSearch(int[][] graph, int start, int n){

        boolean[] visited = new boolean[n];
        Arrays.fill(visited, false);

        Queue<Integer> queue = new LinkedList<>();
        queue.add(start);

        while(!queue.isEmpty()){
            int node = queue.poll();
            visited[node] = true;

            for(int i=0; i<n; i++){
                if(graph[node][i] == 1 && !visited[i]){
                    queue.add(i);
                }
            }

        }

    }

}
