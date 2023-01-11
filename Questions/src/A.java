public class A {

    static int n = 10;

    static {
        m2();
        System.out.println( "A First Static Block" );
    }

    public static void main(String[] args) {
        m2();
        System.out.println("A Main");
    }

    public static void m2(){
        System.out.println(n);
    }

    static {
        System.out.println("A Second Static Block");
    }

    static int m = 20;

}
