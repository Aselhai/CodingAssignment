public class BSTNode {
	public int key;
	public BSTNode left, right;
	
	public BSTNode (int key) {
		this.key = key;
	}
	
	public int FindMin() {
		BSTNode cur = left;
		int min = key;
		while (cur != null) {
			if (cur.key < min) {
				min = cur.key;
			}
			cur = cur.left;
		}
		return min;
	}
}
