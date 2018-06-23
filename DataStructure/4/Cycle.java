public class Cycle {
	List Graph;
	int n;
	boolean[] visited1,
			  visited2;
	
	Cycle(List Graph, int n) {
		this.Graph = Graph;
		this.n = n;
		visited1 = new boolean[n];
		visited2 = new boolean[n];
	}

	public boolean FindCycle(int v) {
		if (visited2[v]) return true;
		if (visited1[v]) return false;
		
		visited1[v] = true;
		visited2[v] = true;
		
		for (Node cur = Graph.head[v]; cur != null; cur = cur.next) {
			if(FindCycle(cur.data)) return true;
		}
		visited2[v] = false;
		return false;
	}
}
