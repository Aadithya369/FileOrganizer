import java.util.*;
public class kata{
  public static void main(String args[]) {
     Scanner sc=new Scanner(System.in);
    int size=sc.nextInt();
    int numbers[]=new int[size];
    for(int i=0;i<size;i++){
      numbers[i]=sc.nextInt();
    }
    int min1=Integer.MAX_VALUE;
    int min1=Integer.MAX_VALUE;
    for(int i=0;i<size;i++){
      if(numbers[i]<min1){
        min2=min1;
        min1=numbers[i];
    }else if(numbers[i]<min2 && num!=min1){
        min2=numbers[i];
    }
        System.out.println(min1);
        System.out.println(min2);
        
      }
  }             
}