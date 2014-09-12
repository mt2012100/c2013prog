/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Ideone
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		Stack<String> st1 = new Stack<String>();
		st1.push("Hi");
		st1.push("How");
		st1.push("r");
		st1.push("u");
		System.out.println(st1.peek());
		
		System.out.println(st1);
		System.out.println(st1.pop());
		PriorityQueue<String> st2 = new PriorityQueue<String>();
		st2.add("Hi");
		st2.add("AHow");
		st2.add("r");
		st2.add("u");
		System.out.println(st2.peek());
	}
}/* package whatever; // don't place package name! */