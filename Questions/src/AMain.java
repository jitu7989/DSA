
import model.A;

public class AMain {

    public static void main(String[] args) {

    }

}


class B{

    static int x = 50;

    static {
        System.out.println("B first static block");
    }

    static void someMethod(){
        System.out.println("B second static method");

    }

    void someMethod2(){

        {
            System.out.println( "something" );
        }

    }

}

