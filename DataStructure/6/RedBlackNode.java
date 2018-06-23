public class RedBlackNode {
	public boolean red;
	public int key;
	public String payload;
	public RedBlackNode parent;
	public RedBlackNode left, right;
	

	public RedBlackNode(int key, String payload) {
		this.red = true;
		this.key = key;
		this.payload = payload;
		this.parent = null;
		this.left = null;
		this.right = null;
	}
}
