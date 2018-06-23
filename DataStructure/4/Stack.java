public class Stack {
	StackNode cur;
	int num;
	Stack() {
		cur = new StackNode();
		num = 0;
	}
	
	public void push(int v1, int v2) {
		StackNode node = new StackNode(v1, v2);
		node.prev = cur;
		cur.next = node;
		if (node.next == null) {
			cur = node;
		}
		num++;
	}
	
	public String pop() {
		String v = "error";
		if (cur.prev == null) {
			return v;
		} else {
			num--;
			v = String.valueOf(cur.v[0]) + " " + String.valueOf(cur.v[1]); 
			cur.prev.next = null;
			cur = cur.prev;
			return v;
		}
	}
}
