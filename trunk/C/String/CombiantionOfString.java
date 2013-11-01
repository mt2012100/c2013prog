import java.util.*;
import java.lang.*;
import java.io.*;
 
class PrintCombinations {
 
public static void main(String[] args) {
printcomb("wxyz");
}
 
public static void printcomb(String input){
for(int i=0; i< input.length();i++)
printcomblevel(input,0,0,"",i+1);
}
public static void printcomblevel(String input, int idx,int level, String s, int K){
if ( level == K)
{
System.out.println(s);
 
} else{
for(int i=idx; i<input.length(); i++)
printcomblevel( input, i+1,level+1,s+input.charAt(i),K);
}
}
 
}
