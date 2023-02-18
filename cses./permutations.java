import java.util.*;
import java.io.*;

public class permutations {

	public static void main(String[] args) {
		// TODO Auto-generated method stub'
		Scanner input = new Scanner(System.in);
	     PrintWriter out=new PrintWriter(System.out);

		long num = input.nextLong();
		if(num ==1 ) {
			out.print("1");
		}
		else if(num <=3 ) {
		out.print("NO SOLUTION");
		}
		else if(num == 4) {
		out.print("2 4 1 3 ");
		}
		else if(num%4 == 0){
			for(long i = 1; i<=num; i+=4) {
			out.print((i+1)+ " "+(i+3)+ " "+ (i) + " "+(i+2)+ " ");
			
			}
		}
		
		else if(num%4 ==1){
			out.print(num + " ");
			for(long i = 1; i<=num-1; i+=4) {
				out.print((i+1)+ " "+(i+3)+ " "+ (i) + " "+(i+2)+ " ");
			}
		out.println();
		}
		else if(num%4 ==2){
			out.print(num + " ");
			for(long i = 1; i<=num-2; i+=4) {
				out.print((i+1)+ " "+(i+3)+ " "+ (i) + " "+(i+2)+ " ");
			}
			out.print(num-1 + " ");
			out.println();
		}
		else if(num%4 ==3){
			out.print(num+ " "+(num-2)+ " ");
			for(long i = 1; i<=num-3; i+=4) {
			out.print((i+1)+ " "+(i+3)+ " "+ (i) + " "+(i+2)+ " ");
			}
		out.print(num-1+ " ");
			out.println();
		}
		out.flush();
	}
	
}

