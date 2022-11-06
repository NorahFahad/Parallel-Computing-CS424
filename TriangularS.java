import java.util.Scanner;

public class TriangularS {
public static void main(String[] args) {
    try (Scanner input = new Scanner(System.in)) {
        System.out.println("**Triangular number Series (serial)**");
        System.out.print("Enter number n:");
        int n_number= input.nextInt();//read the number from the user

        while(true){
            if (n_number>0){ //if the user enter positive n break
            break;
            }
            else{//if the user enter non positive n
                System.out.println("Previous entry is invalid\n  Enter the n again :"); 
                n_number= input.nextInt(); //read the number from the user
            }
        }

        long startTime =System.currentTimeMillis();//calculate current time for the start time

        Triangular_number_Series(n_number); //call method

        long endTime=System.currentTimeMillis();//calculate current time for the end time

        System.out.println("The Time elapsed is: "+(endTime-startTime)+" milliseconds.");//print the time elapsed
    }//end try
}//end main

    public static void Triangular_number_Series(int n){
        for (int i=1; i<=n; i++) {
            System.out.printf("(Itration:%d) (Dots%d)\n", i, (i*(i+1))/2); //operation 
        }//end for
    }//end Triangular_number_Series
}//end class TriangularS
