import java.io.*;
import java.util.ArrayList;

public class Assignment11 {
   public static void main(String[] args) {
      ArrayList<String> input = new ArrayList<String>(); // Define ArrayList, input, to store every line. 
      try {
         /* Reading input.txt */ 
         File file = new File("input.txt");
         FileReader fr = new FileReader(file);
         BufferedReader rd = new BufferedReader(fr);
         String line = "i"; // Define line with "i" to pass while loop.
         /* Storing every line in Arraylist, until line is null */ 
         while(line != null) {
            line = rd.readLine();
            input.add(line);
         }
         rd.close();
      } catch(Exception e) {
         System.out.println("Error");
      }
      /* Define n to store input's zero index. Because ArrayList's zero index value is number of goods */
      int n = Integer.parseInt((String) input.get(0)); 
      input.remove(0); // And remove.
      int[] price = new int[n]; // Define array, price, which store price.
      String[] name = new String[n]; // Define array, name, which store name.
      for (int i = 0; i < input.size(); i++) {
         String temp = (String) input.get(i); // Define String, temp, to store input's any element.
         if (temp == null) {
            break;
         }
         String number = "";
         String str = "";
         for (int j = 0; j < temp.length(); j++) {
        	 /* If temp string's element is integer, then add to number.
        	  * If string's element is not integer, then it's make a substring and break loop. */
            if (48 <= temp.charAt(j) && temp.charAt(j) <= 57) {
               number += temp.charAt(j);
            } else {
               str = temp.substring(j + 1, temp.length());
               break;
            }
         }
         /* Setting string number, str to array. */
         price[i] = Integer.parseInt(number);
         name[i] = str;
      }
      /* Finding mininum value and set it's index to where. */
      int min = price[0],
    	  where = 0;
      for (int i = 0; i < n; i++) {
         if (min > price[i]) {
            min = price[i];
            where = i;
         }
      }
      try {
         File file = new File("output.txt");
         FileWriter fw = new FileWriter(file);
         BufferedWriter wr = new BufferedWriter(fw);
         wr.write(name[where]);
         wr.newLine();
         wr.close();
      } catch(Exception e) {
         System.out.println("Error");
      }
   }
}