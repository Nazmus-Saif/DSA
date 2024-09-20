class A{
    A(){
        System.out.println("A");
    }
    A(int a){
        System.out.println("A int");
    }
    
};

public class ConstructorOverloading {
    public static void main(String[] args) {
        A a = new A();
        A a1 = new A(10);
    }
}
