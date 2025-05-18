import java.io.*;
class EChallange{
	public static void main(String args[]){
		EChallange ref = new EChallange();
		System.out.println(ref.div(10,2));
	}
	int div(int a, int b){
		int t=0;
		try{
			t = a/b;
			
		}
		catch(ArithmeticException e){
			System.out.println(e);
		}
		return t;
	}
}
