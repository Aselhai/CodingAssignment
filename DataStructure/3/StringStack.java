public class StringStack {
	StringNode cur;
	
	StringStack() {
		cur = new StringNode();
	}
	
	public void push(String data) {
		StringNode node = new StringNode(data);
		node.prev = cur;
		cur.next = node;
		if (node.next == null) {
			cur = node;
		}
	}
	
	public String pop() {
		String data = "";
		if (cur.prev == null) {
			return data;
		} else {
			data = cur.data;
			cur.prev.next = null;
			cur = cur.prev;
			return data;
		}
	}
}
