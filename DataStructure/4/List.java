public class List {
	Node[] head;
	int numberV;
	public List(int n, int m) {
		numberV = n;
		head = new Node[n];
	}

	public void InsertEdge(int v1, int v2) {
		Node node = new Node(v2);
		node.next = head[v1];
		head[v1] = node;
	}
	
	public void DisplayAll() {
		Node cur = new Node();
		for (int i = 0; i < numberV; i++) {
			System.out.print(i);
			for (cur = head[i]; cur != null; cur = cur.next) {
				
				System.out.print(" -> "+ cur.data);
			}
			System.out.println(" -> null");
		}
	}
}