class Animal{
    void eat(){
        System.out.println("Animal is Eating.");
    }
};

class Dog extends Animal{
    void bark(){
        System.out.println("Dog is Barking.");
    }
};

public class UpcastingDowncasting {
    public static void main(String[] args) {
        Animal a = new Dog(); // upcasting - dog is upcasted to animal
        a.eat();
        Dog d = (Dog) a; // downcasting - animal is downcasted to dog
        d.bark();

        if(a instanceof Dog){
            System.out.println("Yes, it is a Dog.");
        }
        if(a instanceof Animal){
            System.out.println("Yes, it is an Animal.");
        }
        if(d instanceof Dog){
            System.out.println("Yes, it is a Dog.");
        }
        if(d instanceof Animal){
            System.out.println("Yes, it is an Animal.");
        }
    }
}
