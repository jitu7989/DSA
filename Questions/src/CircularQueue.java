import java.util.Arrays;

public class CircularQueue {
    int size; /*- The maximum elements that we can have in the queue.
            ** This value is passed to the object via the constructor*/
    int[] arr; /*- The primitive data structure used*/

    int front = 0;
    int rear = 0;

    public static void main(String[] args) {
        CircularQueue circularQueue =  new CircularQueue(4);

        System.out.println( circularQueue.enqueue(1) +" "+Arrays.toString( circularQueue.arr )+" "+circularQueue.size() +" front: "+circularQueue.front+" end: "+circularQueue.rear );
        System.out.println( circularQueue.enqueue( 2 )+" "+Arrays.toString( circularQueue.arr ) +" "+circularQueue.size()+" front: "+circularQueue.front+" end: "+circularQueue.rear);
        System.out.println( circularQueue.enqueue( 3 )+" "+Arrays.toString( circularQueue.arr ) +" "+circularQueue.size()+" front: "+circularQueue.front+" end: "+circularQueue.rear);
        System.out.println( circularQueue.enqueue( 4 )+" "+Arrays.toString( circularQueue.arr )+" "+circularQueue.size()+" front: "+circularQueue.front+" end: "+circularQueue.rear );
        System.out.println( circularQueue.enqueue( 5) +" "+Arrays.toString( circularQueue.arr )+" "+circularQueue.size() +" front: "+circularQueue.front+" end: "+circularQueue.rear);
        System.out.println( circularQueue.dequeue()+" "+Arrays.toString( circularQueue.arr )+" "+circularQueue.size()+" front: "+circularQueue.front+" end: "+circularQueue.rear );
        System.out.println( circularQueue.enqueue( 6) +" "+Arrays.toString( circularQueue.arr )+" "+circularQueue.size() +" front: "+circularQueue.front+" end: "+circularQueue.rear);
        System.out.println( circularQueue.dequeue() +" "+Arrays.toString( circularQueue.arr )+" "+circularQueue.size()+" front: "+circularQueue.front+" end: "+circularQueue.rear);
        System.out.println( circularQueue.dequeue() +" "+Arrays.toString( circularQueue.arr )+" "+circularQueue.size()+" front: "+circularQueue.front+" end: "+circularQueue.rear);
        System.out.println( circularQueue.dequeue() +" "+Arrays.toString( circularQueue.arr )+" "+circularQueue.size()+" front: "+circularQueue.front+" end: "+circularQueue.rear);
        System.out.println( circularQueue.dequeue() +" "+Arrays.toString( circularQueue.arr )+" "+circularQueue.size()+" front: "+circularQueue.front+" end: "+circularQueue.rear);
        System.out.println( circularQueue.dequeue() +" "+Arrays.toString( circularQueue.arr )+" "+circularQueue.size()+" front: "+circularQueue.front+" end: "+circularQueue.rear);



    }

    public CircularQueue(int size) {
        this.size = size;
        this.arr = new int[size];
        Arrays.fill( this.arr , -1 );
    }

    boolean enqueue(int data){

        if( arr[front] != -1 && rear==front ) return false;
        if(front==-1){
            arr[front]=data;
            rearInc();
            return true;
        }
        arr[rear] = data;
        rearInc();

        return true;
    }/* -> This function helps to insert value inside the queue
   1. This returns true if the value is successfully inserted into the queue, else returns false*/

    boolean dequeue(){
        if( arr[front]==-1 && arr[rear]==-1 ) return false;
        arr[front] = -1;
        frontInc();
        return true;
    }
/*  1. This functions returns false, if the value cannot be removed, else returns true*/
 /*-> This function removes the value at the front of the queue, and prints it
*/
    int size(){

        if(arr[front]==-1 && arr[rear]==-1 ) return 0;
        if( rear < front ) return (size-front)+rear;
        if( front==rear ) return size;

        return rear-front;
    }/* - This functions returns the size of the queue, at any given moment
  ** The size of the queue is equivalent to the number of elements in the stack, at the given instant*/

    void rearInc(){
        rear++;
        if( rear==size ){
            rear = 0;
        }
    }
    void frontInc(){
        front++;
        if( front==size ){
            front = 0;
        }
    }

}
