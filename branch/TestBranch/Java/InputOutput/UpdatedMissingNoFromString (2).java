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
		//System.out.println("round: "+ Math.round(12.5));
		int missingNum = -1 ;
		int step=0;
		for (int i = 1; i <= Math.round(str.length()/2); i++) {
			//char string =  str.charAt(i);
			boolean isMissing = false;
			boolean flag = false;
			
			//boolean flag = false;
			step=i;
			int k =  (str.length()/step)-1;
			int count = 0;
			for(int j=0;count< k ; ) {
				count++;
				String substr1 = str.substring(j,j+step);
				//System.out.println(substr1 + " substr1");
				String substr2 ;
				if(j+step+step > str.length() ) {
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
						if(num21 == num1) {
							str = str.substring(j+step+1);
							k =  Math.round(str.length()/step);
							count=0;
						}
						if(num21-num1 == 2) {
							isMissing = true;
							missingNum = num1+1;
							System.out.println("Missing Num: "+missingNum);
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
					System.out.println("hi");
				}
				  
				
			}//end of internal for loop.
			
			if(isMissing) {
				System.out.println("Missing Num: " +missingNum);
				break;
			}
			
			
		}//End of Outer loop
		

	}

}
