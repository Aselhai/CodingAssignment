import java.io.*;

public class Assignment31 {
	public static void main(String[] args) {
		StringStack stack = new StringStack();
		String infix = "",
			   postfix = "";
		
		try {
			File file = new File("input.txt");
			FileReader fr = new FileReader(file);
			BufferedReader rd = new BufferedReader(fr);
			
			infix = rd.readLine();
			
			rd.close();
		} catch(Exception e) {
			System.out.println("Error");
		}
		
		for (int i = 0; i < infix.length(); i++) {
			String inner = Character.toString(infix.charAt(i));
			if (!(inner.equals("*") || inner.equals("/") ||
				inner.equals("+") || inner.equals("-"))) {
				stack.push(inner);
			} else {
				String b = stack.pop();
				String a = stack.pop();
				String temp = "(" + a + inner + b + ")";
				stack.push(temp);
			}
		}
		
		postfix = stack.pop();
		
		try {
			File file = new File("output.txt");
			FileWriter fw = new FileWriter(file);
			BufferedWriter wr = new BufferedWriter(fw);
			
			wr.write(postfix);
			wr.newLine();
			
			wr.close();
			} catch(Exception e) {
				System.out.println("Error");
			}
	}
}
