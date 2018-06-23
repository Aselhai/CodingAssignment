import java.math.BigInteger;

public class Node {
	BigInteger i;
	String s;
	Node next;
	
	public Node() {
		next = null;
	}
	public Node(BigInteger i, String s) {
		this.i = i;
		this.s = s;
		next = null;
	}
}