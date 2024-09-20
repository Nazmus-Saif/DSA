class Bike{
    int speed = 50;
    void run(){
        System.out.println("running safely");
    }
}

class Honda extends Bike{
    int speed = 100;
    void run(){
        System.out.println("running safely with 60km");
    }
}

public class RunTimePolymorphisim {
    public static void main(String[] args) {
        Bike b = new Honda(); // upcasting
        b.run();
        System.out.println(b.speed); // it will print 50 because run time polymorphism 
                                     // can not achieved by data member or variable or field

        Honda h = (Honda) b;
        h.run();

        Bike b1 = new Bike();
        b1.run();

        Honda h1 = new Honda();
        h1.run();
    }
}