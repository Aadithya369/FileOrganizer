import java.io.*;
import java.util.Scanner;
class CopyFile{
	public static void main(String args[]){
		try{
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter the file to copy");
		String fname = sc.nextLine();
		FileInputStream fis = new FileInputStream(fname);
		System.out.println("Enter the file to write");
		fname = sc.nextLine();
		FileOutputStream fos = new FileOutputStream(fname);
		int Rdata;
		Rdata=fis.read();
		while(Rdata!=-1){
			fos.write(Rdata);
			Rdata = fis.read();	
		}
		}
		catch(IOException e){
			System.out.println("An error occured"+e.getMessage());
		}
		fis.close();
		fos.close();
	}
}
