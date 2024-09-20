/**
 * abstraction
 */
abstract class A {
    abstract void sum(int a, int b);
};

class B extends A {
    void sum(int a, int b) {
        System.out.println("sum: " + (a + b));
    }
};

public class Abstraction {
    public static void main(String[] args) {
        A b = new B();
        b.sum(1, 2);
        B c = new B();
        c.sum(2, 3);
        System.out.println(b instanceof A);
        System.out.println(b instanceof B);
        System.out.println(c instanceof B);
        System.out.println(c instanceof A);

    }
}