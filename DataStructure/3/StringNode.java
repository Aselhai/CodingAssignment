public class StringNode {
	String data;
	StringNode prev, next;
	
	StringNode() {
		prev = null;
		next = null;
	}
	
	StringNode(String data) {
		this.data = data;
		prev = null;
		next = null;
	}
}
