/*// Implementing normal Thread 

import java.lang.Thread;

public class JavaThread {
    public static void show(int n) {
        for(int i = 0; i < n; i++){
            System.out.println(i);
        }
    }

    public static void main(String[] args) {
        Thread th1 = new Thread(new Runnable() { // thread runnable object
            public void run(){
            show(10);
            }
        });
        th1.start(); // thread start to execute show()
        try{
            th1.join(); // waiting for completion of thread
        }catch(InterruptedException e){
            System.out.println("Problem: " + e);
        }
    }
} */


/* // by extending Thread class
public class JavaThread extends Thread{
    public void run(int a, int b){
        System.out.println("Sum is: " + (a + b));
    }

    public static void main(String[] args) {
        JavaThread th1 = new JavaThread();
        th1.run(5,5);
        th1.start();
    }
} */


/* // by implements runabble interface

class NewThread implements Runnable{
    public void run(){
        System.out.println("Thread is running....");
    }
}

public class JavaThread{
    public static void main(String[] args) {
        NewThread n = new NewThread();
        Thread th1 = new Thread(n);
        th1.start();
    }
} */


// class NewThread implements Runnable {
//     String name;
//     Thread thread;

//     NewThread(String name) {
//         this.name = name;
//         thread = new Thread(this, name);
//         System.out.println("A new thread " + thread + " is created");
//         thread.start();
//     }

//     public void run() {
//         try {
//             for (int i = 5; i > 0; i--) {
//                 System.out.println(name + ": " + i);
//                 Thread.sleep(1000);
//             }
//         } catch (InterruptedException e) {
//             System.out.println(name + " Thread Interrupted");
//         }
//         System.out.println(name + " Exiting");
//     }
// }

// public class JavaThread {
//     public static void main(String[] args) {
//         new NewThread("Thread-1");
//         new NewThread("Thread-2");
//         new NewThread("Thread-3");
//         try {
//             Thread.sleep(8000);
//         } catch (InterruptedException e) {
//             System.out.println("Main Thread Interrupted");
//         }
//         System.out.println("Main Thread Exiting");
//     }
// }

// Concurrency Problem in thread


public class JavaThread extends Thread {
    public static int amount = 0;

    public static void main(String[] args) {
        JavaThread thread = new JavaThread(); // this will call the run method of thread
        thread.start();
        while(thread.isAlive()) {
            System.out.println("Waiting");
        }
        System.out.println(amount);
        amount++;
        System.out.println(amount);
    }

    public void run(){
        amount++;
    }
}

// in the above code concurrency problem occur due to race of the main thread and newly created thread to increment of the value of amount
// when new thread start then main thread will be in while loop and waits on that time new thread increase the value by 1 then main
// thread increate the value again which is 2


// if we not while loop then if main thread execut first that amount will be 0 then 1
// if                                                                        0 then run method execute and amount is 1 then again maint amount is increase by 2
