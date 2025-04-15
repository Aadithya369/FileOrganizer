import java.util.Scanner;
interface Shape{
	double calculateArea();
}
class circle implements Shape{
	double radius;
	circle(double radius){
		this.radius = radius;
	}
	public double calculateArea(){
		return 3.14 * radius * radius;
	}
}
class Rectangle implements Shape{
	double length;
	double breadth;
	Rectangle(double length, double breadth){
		this.length = length;
		this.breadth = breadth;	
	}
	public double calculateArea(){
		return length * breadth;
	}
}
class Triangle implements Shape{
	double Tbreadth;
	double height;
	Triangle(double Tbreadth, double height){
		this.Tbreadth = Tbreadth;
		this.height = height;
	}
	public double calculateArea(){
		return Tbreadth * height;
	}
}
class ShapeInterface{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		double radius = sc.nextDouble();
		double length = sc.nextDouble();
		double breadth = sc.nextDouble();
		double Tbreadth = sc.nextDouble();
		double height = sc.nextDouble();

		circle c = new circle(radius);
		Rectangle  r = new Rectangle(length, breadth);
	        Triangle t = new Triangle(Tbreadth, height);
		
		System.out.println(c.calculateArea());
		System.out.println(r.calculateArea());
		System.out.println(t.calculateArea());
	}
}

