public class Main{
  public static void main(String[] args){
    int num = 479598;
    int r = 0;
    for(int i = 10; num > 9; num = num/10){
        r  += num % 10;
    }
    System.out.println(r);
  }
}