import java.io.*;
class fwrite{
	public static void main(String args[]){
		try{
			FileWriter fw = new FileWriter("output.txt",true);
			BufferedWriter bf = new BufferedWriter(fw);
			bf.write("Hello world!");
			bf.newLine();
			bf.write("I am aadithya!");
			System.out.println("Success!");
			bf.close();
		}
		catch(Exception e){
			System.out.println(e.getMessage());
		}
	}
}
