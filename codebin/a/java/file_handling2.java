import java.io.*;

class FileHandling2 {
    public static void main(String[] args) {
        String data = "Hello world!";
        FileOutputStream fos = null;

        try {
            fos = new FileOutputStream("input.txt");
            fos.write(data.getBytes());
            System.out.println("Writing data: " + data);  // Debug print
            System.out.println("Data written successfully");
        } catch (IOException e) {
            System.out.println("An I/O exception occurred!");
            e.printStackTrace();  // Print the full exception stack trace for debugging
        } finally {
            try {
                if (fos != null) {
                    fos.close();
                }
            } catch (IOException e) {
                System.out.println("Error closing the file.");
            }
        }
    }
}
