public class B extends A{

    static int x = 100;

    static {
        m2();
        System.out.println("B first static block");
    }

    public static void main(String[] args) {
        m2();
        System.out.println("B main");
    }
    public static void m2(){
        System.out.println(y);
    }

    static {
        System.out.println("B second static block");
    }

    static  int y = 200;
}
