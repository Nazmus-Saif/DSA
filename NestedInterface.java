import java.lang.reflect.InaccessibleObjectException;

interface OuterNestedInterface {
    void print();
    interface InnerNestedInterface {
        void show();
    }
}

public class NestedInterface implements OuterNestedInterface.InnerNestedInterface {
    public void show(){
        System.out.println("Method of Inner Nested Interface");
    }

    public void print(){
        System.out.println("Method of Outer Nested Interface");
    }

    public static void main(String[] args) {
        NestedInterface obj = new NestedInterface();
        OuterNestedInterface.InnerNestedInterface obj1 = new NestedInterface();
        obj.show();
        obj1.show();
        obj.print();
    }
}
