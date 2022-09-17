public class lab1_2 {
    public static void main(String[] args){
        final int Thread_Count = 2; //Runtime.getRuntime().availableProcessors();
        int[] x = {1, 2, 3, 4, 5, 6};
        int[] y = {7, 8, 9, 10, 11, 12};
        int[] z = new int[x.length];
        
        Thread th0 = new Thread(new VectorAddition(x, y, z, 0, Thread_Count));
        Thread th1 = new Thread(new VectorAddition(x, y, z, 1, Thread_Count));
        
        th0.start();
        th1.start();
        
        System.out.print("x:");
        for(int i=0;i < x.length;i++){
            System.out.printf("%3d", x[i]);
        }
        System.out.println();
        
        System.out.print("y:");
        for(int i=0;i < x.length;i++){
            System.out.printf("%3d", y[i]);
        }
        System.out.println();
        
        System.out.print("z(x+y):");
        for(int i=0;i < x.length;i++){
            System.out.printf("%3d", z[i]);
        }
        System.out.println();
    }
}
class VectorAddition implements Runnable{
    int[]vectorX;
    int[]vectorY;
    int[]vectorZ;
    int threadRank;
    int threadCount;
    VectorAddition(int[]vectorX, int[]vectorY, int[]vectorZ, int threadRank, int threadCount){
        this.vectorX = vectorX;
        this.vectorY = vectorY;
        this.vectorZ = vectorZ;
        this.threadRank = threadRank;
        this.threadCount = threadCount;
    }
    
    @Override
    public void run(){
        VectorAdditionMethod();
    }
    void VectorAdditionMethod(){
        int local_m = vectorX.length / threadCount;
        int myFirst = threadRank * local_m;
        int myLast = myFirst + local_m;
        
        for(int i=myFirst; i < myLast; i++){
            vectorZ[i] = vectorX[i] + vectorY[i];
        }
    }
}
