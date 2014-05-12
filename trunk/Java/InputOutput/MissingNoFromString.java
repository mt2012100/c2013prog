/**
 * 
 */
package org.atl.corejava;

import java.io.BufferedReader;
import java.io.InputStreamReader;

/**
 * @author pratibind_jha
 *
 */
public class MissingNoFromString {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader bfr = new BufferedReader(isr);
		
		String str=null;
		try {
			str = bfr.readLine();
		}catch(Exception e) { }
		
		System.out.println(str);
		
		int missingNum = -1 ;
		int step=0;
		for (int i = 1; i <= (str.length()/2)+1; i++) {
			//char string =  str.charAt(i);
			boolean isMissing = false;
			boolean flag = false;
			
			//boolean flag = false;
			step=i;
			for(int j=0;j<(str.length()/step) ; ) {
				
				String substr1 = str.substring(j,j+step);
				//System.out.println(substr1 + " substr1");
				String substr2 ;
				if(j+step+step > str.length() && i==1) {
					break;
				}
				substr2 = str.substring(j+step,j+step+step);
				//System.out.println(substr2 + " substr2");
				
				int num1 = Integer.parseInt(substr1);
				int num2;
				num2 = Integer.parseInt(substr2);
				System.out.println("Num1: "+num1+" Num2: "+num2);
				
				{
					int nums = num1+1;
					String s1 = nums+"";
					String s2 = num1+"";
					//System.out.println("s1: "+s1 +"s2: "+s2);
					if(s1.length() > s2.length()) {
						
						substr2 = str.substring(j+step,j+step+step+1);
						flag = true;
						step++;
						//j = j-1;
						int num21 = Integer.parseInt(substr2);
						System.out.println("Num21: "+ num21);
						if(num21-num1 == 2) {
							isMissing = true;
							missingNum = num1+1;
							//System.out.println("Missing Num: "+missingNum);
						}else if(Math.abs(num21-num1) > 2 || (num21 < num1)) {
							isMissing = false;
							break;
						}
					}else if(Math.abs(num2-num1)  > 2 || (num2 < num1)){
						isMissing = false;
						break;
					}
					else if(num2-num1 == 2) {
						isMissing = true;
						missingNum = num1+1;
						//j = j+step;
						
					}
				}
				
				if(flag) {
					j= j+i;
					flag = false;
				}
				else{
					j = j+step;
				}
				  
				
			}//end of internal for loop.
			
			if(isMissing) {
				System.out.println("Missing Num: " +missingNum);
				break;
			}
			
			
		}//End of Outer loop
		

	}

}
