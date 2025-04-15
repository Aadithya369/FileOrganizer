import java.util.Scanner;
class try{
	public static void main(String args[]){
		try{
			int t = 10/0;
		}
		catch(ArithmeticError e){
			System.out.println(e.getMessage());
		}
	}
}
