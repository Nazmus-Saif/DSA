class Address{
    String village, thana, zilla;

    public Address(String village, String thana, String zilla) {
        this.village = village;
        this.thana = thana;
        this.zilla = zilla;
    }
}

class Employee{
    int id;
    String name, age;
    Address address; // this is a aggregation or has-a relationship

    Employee(int id, String name, String age, Address address){
        this.id = id;
        this.name = name;
        this.age = age;
        this.address = address;
    }

    void display(){
        System.out.println("ID     : "+id+"\n"+
                           "Name   : "+name+"\n"+
                           "Age    : "+age);
        System.out.println("Village: "+address.village+"\n"+
                           "Thana  : "+address.thana+"\n"+
                           "Zilla  : "+address.zilla);
    }
};

public class AggregationInJava {
    public static void main(String[] args) {
        Employee e1 = new Employee(201400040, "Nazmus Saif", "24", new Address("Ratanpur", "Nabinagar", "Brahmanbaria"));
        e1.display();
    }
}
