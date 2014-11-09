/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;


// find four numbers in an array such that they equals to X
 class Pair{
     int i;
     int j;

     Pair(int x,int y){
         i=x;
         j=y;
     }
 }

class FindNumbersEqualsSum {
    public static void main(String[] args) {

         int num[]={1,2,3,4,12,43,32,53,8,-10,4};

         get4Numbers(num, 17);

         get4Numbers(num, 55);
    }

 public static void get4Numbers(int a[],int sum){

    int len=a.length;

    Map<Integer, Pair> sums = new HashMap<Integer, Pair>(); 
    for (int i = 0; i < len; ++i) {
        // 'sums' hastable holds all possible sums a[k] + a[l]
        // where k and l are both less than i

        for (int j = i + 1; j < len; ++j) {
            int current = a[i] + a[j];
            int rest = sum - current;
            // Now we need to find if there're different numbers k and l
            // such that a[k] + a[l] == rest and k < i and l < i
            // but we have 'sums' hashtable prepared for that
            if (sums.containsKey(rest)) {
                // found it
                Pair p = sums.get(rest);
                System.out.println(a[i]+" + "+a[j]+" + "+a[p.i] +" + "+a[p.j]+" = "+sum);

            }
        }

        // now let's put in 'sums' hashtable all possible sums
        // a[i] + a[k] where k < i
        for (int k = 0; k < i; ++k) {
            sums.put(a[i] + a[k],new Pair(i, k));
        }
    }
 }
}
