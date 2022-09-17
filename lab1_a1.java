public class lab1_1 {
    public static void main(String[] args) {
        final int Thread_Count = Runtime.getRuntime().availableProcessors();
        
        Runnable task1 = new Hello (0, Thread_Count);
        Runnable task2 = new Hello (1, Thread_Count);
        
        Thread th0 = new Thread(task1);
        Thread th1 = new Thread(task2);
        
        th0.start();
        th1.start();
    }
}
class Hello implements Runnable{
    int threadRank;
    int threadCount;
    
    Hello(int threadRank, int threadCount){
        this.threadRank=threadRank;
        this.threadCount=threadCount;
    }
    
    @Override
    public void run(){
        printMessage();
    }
    
    void printMessage(){
        System.out.printf("Hello from Thread %d out of %d\n",threadRank,threadCount);
    }
}
