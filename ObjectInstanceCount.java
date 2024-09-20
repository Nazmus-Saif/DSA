public class ObjectInstanceCount {
    // Static counter variable to keep track of the number of instances
    private static int instanceCounter = 0;

    // Constructor of the class
    public ObjectInstanceCount() {
        // Increment the counter whenever a new instance is created
        instanceCounter++;
    }

    // Static method to get the current count of instances
    public static int getInstanceCount() {
        return instanceCounter;
    }

    public static void main(String[] args) {
        // Create several instances of MyClass
        ObjectInstanceCount obj1 = new ObjectInstanceCount();
        ObjectInstanceCount obj2 = new ObjectInstanceCount();
        ObjectInstanceCount obj3 = new ObjectInstanceCount();

        // Output the number of instances created
        System.out.println("Number of instances created: " + ObjectInstanceCount.getInstanceCount());
    }
}
