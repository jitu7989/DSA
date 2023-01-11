import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Relevel1 {
    public static int prefixSuffix(int[] arr, int n){

        Map<Integer, List<Integer>> map = new HashMap<>();

        for(int i = 0; i < n; i++) {
            if (map.containsKey(arr[i])) {
                map.get( arr[i] ).set( 1 , i );
            } else {
                List<Integer> list = new ArrayList<>();
                list.add(i);
                list.add(0);
                map.put(arr[i], list);
            }
        }

        // System.out.println(map);
        int i = 0;
        int j = 0;
        int value = 0;
        Integer max = 0;

        for (Map.Entry<Integer, List<Integer>> entry : map.entrySet()) {

            List<Integer> temp = entry.getValue();

            if(max < temp.get(1) - temp.get(0)){

                max = temp.get(1) - temp.get(0);

                i = temp.get(0);
                j = temp.get(1);

                value = entry.getKey();

            }
        }
        // System.out.println(value + " " + i + " " + j);

        for (int k = i; k <= j; k++) {
            arr[k] = value;
        }

        int count = 0;

        Map<Integer, Integer> ans = new HashMap<>();

        for(int k = 0; k < n; k++) {
            if (ans.containsKey(arr[k])) {
                count++;
            } else {
                ans.put(arr[k], 1);
            }
        }

        return ans.size();
    }
    public static void main(String[] args){

        int[] arr = { 1 , 2 ,4 ,5 , 5 ,2 ,4 };

        System.out.println( prefixSuffix(  arr , arr.length ) );



    }
}
