public class StackNode {
	int[] v = new int[2];
	StackNode prev, next;
	
	StackNode() {
		prev = null;
		next = null;
	}
	
	StackNode(int v1, int v2) {
		v[0] = v1;
		v[1] = v2;
		prev = null;
		next = null;
	}
}
