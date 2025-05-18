import java.io.*;
class file_handling{
	public static void main(String args[]){
		try{
			FileInputStream fis = new FileInputStream("File.txt");
			int dataByte;
			while((dataByte = fis.read())!=-1){
				System.out.println((char)dataByte);
			}
			fis.close();
		}
		catch(FileNotFoundException e){
			System.out.println("File not found!");
		}
		catch(IOException e){
			System.out.println("IO exception!");
		}
	}
}
