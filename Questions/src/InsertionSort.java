import java.util.Arrays;

public class InsertionSort {

    public static void main(String[] args) {

        int[] arr = { 9,8,7,6,5,4,3,2,1 };

        int i = 1;

        while( i<arr.length ){

            int j = i-1;
            int element = arr[i];
            while( j>=0 && arr[j]>element ) arr[j+1] = arr[j--];
            arr[j+1] = element;
            i+=1;
        }

        System.out.println(Arrays.toString( arr ));

        i = 1;

        while( i<arr.length ){

            int j = i-1;
            int element = arr[i++];

            while( j>-1 && arr[j]<element ) arr[j+1] = arr[j--];
            arr[j+1] = element;

        }
        Arrays.sort(new Integer[10]);
        System.out.println(Arrays.toString( arr ));
    }
//    Initialization: It is true prior to the frst iteration of the loop.
//    Maintenance: If it is true before an iteration of the loop, it remains true before the
//    next iteration.
//    Termination: When the loop terminates, the invariant gives us a useful property
//    that helps show that the algorithm is correct

}
