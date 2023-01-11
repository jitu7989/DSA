import java.util.*;
public class LongestSumSubArray {
    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        int x = in.nextInt();

        int[] arr = new int[n];

        for (int i = 0; i < arr.length; i++)
            arr[i] = in.nextInt();

        HashMap<Integer, Integer> map = new HashMap<>();
        int sum = 0;
        int len = 0;

        for (int i = 0; i < arr.length; i++) {

            sum += arr[i];
            if( sum==x ) len = i+1;
            if (!map.containsKey(sum) ) map.put(sum, i);

        }

        sum = 0;
        for (int i = 0; i < n; i++) {

            sum += arr[i];
            if( map.containsKey(sum-x) )
                len = Math.max( len, i - map.get(sum-x) );


        }

        System.out.println(len);

    }

}
//
//        6
//        10 5 2 7 1 9