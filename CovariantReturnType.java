class A{
    A get(){
        return this;
    }
    void message(){
        System.out.println("Inside A");
    }
}

class B extends A{
    A get(){
        return this;
    }
    void message(){
        System.out.println("Inside B");
    }
}

class C extends B{
    A get(){
        return this;
    }
    void message(){
        System.out.println("Inside C");
    }
}

public class CovariantReturnType {
    public static void main(String[] args){
        A a = new A();
        ((A)a.get()).message();

        B b = new B();
        ((B)b.get()).message();

        C c = new C();
        ((C)c.get()).message();
    }
}
