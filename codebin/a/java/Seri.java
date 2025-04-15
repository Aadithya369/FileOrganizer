import java.util.*;
class Seri implements Serializable{
	String content ="Hello wolrd!";
	FileOutputStream fos = new FileOutputStream("empty.txt");
	ObjectOutputStream oos = new ObjectOutputStream(fos);
	oos.ObjectWrite("Hello world:wq
			:");
	oos.close();
}
