import java.io.*;

public class BCC {

	List Graph;
	int n;
	int num, total;
	int[] dfn;
	int[] low;
	boolean[] visited;
	Stack stack, result;
	
	BCC(List Graph, int n) {
		this.Graph = Graph;
		this.n = n;
		num = 1;
		total = 0;
		dfn = new int[n];
		low = new int[n];
		stack = new Stack();
		result = new Stack();
	}

	public void findBCC(int v, int parant) {
		dfn[v] = low[v] = num++;
		for (Node cur = Graph.head[v]; cur != null; cur = cur.next) {
			if (cur.data == parant || dfn[v] < dfn[cur.data]) continue;
			stack.push(v, cur.data);
			if (dfn[cur.data] != 0) {
				if (low[cur.data] < low[v]) low[v] = low[cur.data];
			} else {
				findBCC(cur.data, v);
				if (low[cur.data] < low[v]) low[v] = low[cur.data];
				if (low[cur.data] >= dfn[v]) {
					total++;
					int v1 = 0, v2 = 0;
					int edgeNum = 0;
					String edge = "";
					while (!(v1 == v && v2 == cur.data)){
						edgeNum++;
						edge = stack.pop();
						if (edge.equals("error")) System.out.println("Stack is empty.");
						v1 = Integer.parseInt(edge.split(" ")[0]);
						v2 = Integer.parseInt(edge.split(" ")[1]);
						result.push(v1, v2);
					}
					result.push(-1, -1);
					result.push(edgeNum, edgeNum);
				}
			}
		}
	}
	
	public void BCC() {
		for (int i = 0; i < n; i++) {
			if (dfn[i] == 0) findBCC(i, -1);
		}
		try {
			File file = new File("output.txt");
			FileWriter fw = new FileWriter(file);
			BufferedWriter wr = new BufferedWriter(fw);
			wr.write(total + "\n");
			int v1 = 0, v2 = 0;
			String edge = "";
			while (result.num != 0) {
				edge = result.pop();
				v1 = Integer.parseInt(edge.split(" ")[0]);
				v2 = Integer.parseInt(edge.split(" ")[1]);
				if (v1 == -1) continue;
				if (v1 == v2) {
					wr.write(v1 + "\n");
					continue;
				}
				wr.write(v1 + " " + v2);
				if (result.num != 0) wr.write("\n");
			}
			wr.close();
		} catch(Exception e) {
			System.out.println("Error");
		}
	}
}
