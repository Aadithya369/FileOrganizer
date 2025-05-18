import java.io.*;
class exception {
	public static void main(String args[]){
		try{
			int a = 10/0;
		}
		catch(ArithmeticException e){
			System.out.println("Exception Handeled (^^)");
		}
	}
}
