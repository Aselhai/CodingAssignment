import java.io.*;

public class Assignment42 {
	public static void main(String[] args) {
		int n = 0, m = 0;
		List Graph = null;
				
		try {
			File file = new File("input.txt");
			FileReader fr = new FileReader(file);
			BufferedReader rd = new BufferedReader(fr);
			
			String nm = rd.readLine();
			n = Integer.parseInt(nm.split(" ")[0]);
			m = Integer.parseInt(nm.split(" ")[1]);
			
			Graph = new List(n, m);
			String line = new String();
			
			int v1, v2;
			for(int i = 0; i < m; i++) {
				line = rd.readLine();
				v1 = Integer.parseInt(line.split(" ")[0]);
				v2 = Integer.parseInt(line.split(" ")[1]);
				Graph.InsertEdge(v1, v2);
			}
			
			rd.close();
		} catch(Exception e) {
			System.out.println(e.toString());
		}
		
		
		boolean result = false;
		Cycle cycle;
		cycle = new Cycle(Graph, n);
		for (int i = 0; i < n; i++) {
			if(cycle.FindCycle(i)) {
				result = true;
				break;
			}
		}
		
		try {
			File file = new File("output.txt");
			FileWriter fw = new FileWriter(file);
			BufferedWriter wr = new BufferedWriter(fw);
			if (result) {wr.write("yes");}
			else {wr.write("no");}
			wr.close();
		} catch(Exception e) {
			System.out.println("Error");
		}
	}
}