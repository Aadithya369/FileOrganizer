import java.util.Scanner;
class TryPrac{
	public static void main(String args[]){
		try{
			int t = 10/0;
		}
		catch(ArithmeticException e){
			System.out.println(e.getMessage());
		}
	}
}
