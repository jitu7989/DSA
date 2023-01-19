package model;

public class A{

    static int x = 100;

    static {
        System.out.println("A first static block");
    }

    static void someMethod(){
        System.out.println("A second static method");
    }

}