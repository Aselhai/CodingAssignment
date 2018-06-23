public class RedBlackTree {
	public RedBlackNode root;
	
	public RedBlackTree() {
		root = null;
	}
	
	public boolean isEmpty() {
		if (root == null) return true;
		else return false;
	}
	
	public boolean hasLeftChild(RedBlackNode node) {
		if (node == null || node.left == null) return false;
		else return true;
	}
	
	public boolean hasRightChild(RedBlackNode node) {
		if (node == null || node.right == null) return false;
		else return true;
	}
	
	public void leftrotate(RedBlackNode x) {
		RedBlackNode y = x.right;
		x.right = y.left;
		if (y.left != null) {
			y.left.parent = x;
		}
		y.parent = x.parent;
		if (x.parent == null) root = y;
		else if (x == x.parent.left) x.parent.left = y;
		else x.parent.right = y;
		y.left = x;
		x.parent = y;
	}
	
	public void rightrotate(RedBlackNode x) {
		RedBlackNode y = x.left;
		x.left = y.right;
		if (y.right != null) {
			y.right.parent = x;
		}
		y.parent = x.parent;
		if (x.parent == null) root = y;
		else if (x == x.parent.right) x.parent.right = y;
		else x.parent.left = y;
		y.right = x;
		x.parent = y;
	}
	
	public boolean insert(int k, String p) {
		RedBlackNode x = new RedBlackNode(k, p);
		RedBlackNode cur = root;
		RedBlackNode prev = null;
		x.red = true;
		
		while (cur != null) {
			prev = cur;
			if (k < cur.key) cur = cur.left;
			else if (k == cur.key) return false;
			else cur = cur.right;
		}
		
		x.parent = prev;
		if (prev == null) {x.red = false;root = x;}
		else if (k < prev.key) prev.left = x;
		else prev.right = x;
	
		while (x != root && x.parent.red){
			RedBlackNode grandparent = x.parent.parent;
			if (x.parent == grandparent.left) {
				RedBlackNode uncle = grandparent.right;
				if (uncle != null && uncle.red) {
					x.parent.red = false;
					uncle.red = false;
					grandparent.red = true;
					x = grandparent;
				} else  {
					if (x == x.parent.right) {
						leftrotate(x.parent);
						x = x.parent;
					}
					x.parent.red = false;
					grandparent.red = true;
					rightrotate(grandparent);
					x = root;
				}
			} else {
				RedBlackNode uncle = grandparent.left;
				if (uncle != null && uncle.red) {
					x.parent.red = false;
					uncle.red = false;
					grandparent.red = true;
					x = grandparent;
				} else {
					if (x == x.parent.left) {
						rightrotate(x.parent);
						x = x.parent;
					}
					x.parent.red = false;
					grandparent.red = true;
					leftrotate(grandparent);
					x = root;
				}
			}
		}
		root.red = false;
		return true;
	}
	
	public boolean delete(int k) {
		if (!Search(root, k)) return false;
		
		root = dodelete(root, k);
		
		
		if (!Search(root, k)) return true;
		else return false;
	}
	
	public RedBlackNode dodelete(RedBlackNode root, int key) {
		if (root == null) return root;
		
		if (key < root.key) {
			root.left = dodelete(root.left, key);
		} else if (key > root.key) {
			root.right = dodelete(root.right, key);
		} else {
			if (root.left == null && root.right == null) {
				return null;
			}
			else if (root.left == null) {
				root = root.right;
				deletefixup(root);
				return root;
			} else if (root.right == null){
				root = root.left;
				deletefixup(root);
				return root;
			} else {
				root.red = FindMin(root.left).red;
				root.key = FindMin(root.left).key;
				root.left = dodelete(root.left, root.key);
				deletefixup(root);
			}
		}
		return root;
	}
	
	RedBlackNode FindMin(RedBlackNode x){
		while (x.right != null) {
		    x = x.right;
		}
		return x;
    }
	
	public void deletefixup (RedBlackNode x) {
		while (x != root && !(x.parent.red)){
			if (x == x.parent.left) {
				RedBlackNode sibling = x.parent.right;
				if (sibling.red) {
					sibling.red = false;
					x.parent.red = true;
					leftrotate(x.parent);
				} else  {
					if (!(sibling.left.red) && !(sibling.right.red)) {
						sibling.red = true;
						x = x.parent;
					} else {
						if (!sibling.right.red) {
							sibling.left.red = false;
							sibling.red = true;
							rightrotate(sibling);
						}
						boolean temp = sibling.red;
						sibling.red = x.parent.red;
						x.parent.red = temp;
						sibling.right.red = false;
						leftrotate(x.parent);
						x = root;
					}
				}
			} else {
				RedBlackNode sibling = x.parent.left;
				if (sibling.red) {
					sibling.red = false;
					x.parent.red = true;
					rightrotate(x.parent);
				} else  {
					if (!(sibling.right.red) && !(sibling.left.red)) {
						sibling.red = true;
						x = x.parent;
					} else {
						if (!sibling.left.red) {
							sibling.right.red = false;
							sibling.red = true;
							leftrotate(sibling);
						}
						boolean temp = sibling.red;
						sibling.red = x.parent.red;
						x.parent.red = temp;
						sibling.left.red = false;
						rightrotate(x.parent);
						x = root;
					}
				}
			}
		}
		x.red = false;
	}
	
	public boolean Search(RedBlackNode root, int key)
	{
		return doSearch(root, key);
	}
	
	public boolean doSearch(RedBlackNode x, int key)
	{
		if (x != null) {
			doSearch(x.left, key);
			if (x.key == key) {
				return true;
			}
			doSearch(x.right, key);
			if (doSearch(x.left, key) || doSearch(x.right, key)) return true;
		}
		return false;
	}

	public String query(int k) {
		RedBlackNode cur = root;
		
		if (root == null) {
			return null;
		}
		
		while (true) {
			if (k < cur.key) {
				cur = cur.left;
				if (cur == null) {
					return null;
				}
			} else if (k == cur.key) {
				return cur.payload;
			} else {
				cur = cur.right;
				if (cur == null) {
					return null;
				}
			}
		}
	}
	
	
//	public void Traversal() {
//		doTraversal(root);
//	}
//	public void doTraversal(RedBlackNode x) {
//		if (x != null) {
//			doTraversal(x.left);
//			if (x == root) System.out.print("R ");
//			System.out.print(x.key + " " + x.payload + " " + x.red);
//			if (x.parent == null) System.out.print(" null ");
//			else System.out.print(" " + x.parent.key + " " );
//			if (x.left == null) System.out.print(" null ");
//			else System.out.print(" " + x.left.key + " " );
//			if (x.right == null) System.out.print("null\n");
//			else System.out.print(" " + x.right.key + "\n" );
//			doTraversal(x.right);
//		}
//	}
}
