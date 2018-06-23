public class BSTree {
	public BSTNode root;
	
	public BSTree() {
		root = null;
	}
	
	public BSTree(BSTree bstSmaller, BSTree bstGreater) {
		BSTNode newroot = new BSTNode(bstGreater.FindMin());
		newroot.left = bstSmaller.root;
		newroot.right = bstGreater.root;
		root = newroot;
	}
	
	public void insert(int key) {
		BSTNode cur = root;
		BSTNode node = new BSTNode(key);
		BSTNode prev = null;
		
		if (root == null) {
			 root = node;
			 return;
		}
		
		while (true) {
			prev = cur;
			if (key < prev.key) {
				cur = cur.left;
				if (cur == null) {
					prev.left = node;
					break;
				}
			} else if (key == prev.key) {
				return;
			} else {
				cur = cur.right;
				if (cur == null) {
					prev.right = node;
					break;
				}
			}
		}
	}
	
	public boolean delete(int key) {
		int beforesize = size(root);
		root = dodelete(root, key);
		if (size(root) == beforesize - 1) {
			return true;
		}
		return false;
	}
	
	public BSTNode dodelete(BSTNode root, int key) {
		if (root == null) {
			return root;
		}
		if (key < root.key) {
			root.left = dodelete(root.left, key);
		} else if (key > root.key) {
			root.right = dodelete(root.right, key);
		} else {
			if (root.left == null) {
				return root.right;
			} else if (root.right == null){
				return root.left;
			} else {
			root.key = root.right.FindMin();
			root.right = dodelete(root.right, root.key);
			}
		}
		return root;
	}
	
	public int FindMin() {
		BSTNode cur = root;
		int min = cur.key;
		try {
			while (cur != null) {
				if (cur.key < min) {
					min = cur.key;
				}
				cur = cur.left;
		}
		} catch (Exception e) {}
		return min;
	}
	
	public int size(BSTNode cur) {
		if (cur == null) {
			return 0;
		} else {
			return size(cur.left) + size(cur.right) + 1;
		}
	}
}