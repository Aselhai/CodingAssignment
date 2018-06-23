import java.math.BigInteger;

public class HTable {
	int size;
	BigInteger Bsize;
	Node[] table;
	
	public HTable(int size) {
		this.size = size;
		this.Bsize = new BigInteger("" + size);
		table = new Node[size];
	}
	
	public boolean insert(BigInteger i, String s) {
		Node node = new Node(i, s);
		
		int h = i.mod(Bsize).intValue();
		for (Node cur = table[h]; cur != null; cur = cur.next) {
			if (cur.i.equals(i)) return false;
		}
		
		node.next = table[h];
		table[h] = node;
		return true;
	}
	
	public boolean delete(BigInteger i) {
		int h = i.mod(Bsize).intValue();
		
		Node cur = table[h];
		Node prev = table[h];
		
		if (cur == null) return false;
		
		while (!cur.i.equals(i)) {
			if (cur.next == null) return false;
			else {
				prev = cur;
				cur = cur.next;
			}
		}

		if (cur == table[h]) {
			if (cur.next == null) {
				table[h] = null;
			} else  {
				table[h] = cur.next;
			}
		}
		else {
			prev.next = cur.next;
			
		}
		return true;
	}
	
	public String query(BigInteger i) {
		int h = i.mod(Bsize).intValue();
		for (Node cur = table[h]; cur != null; cur = cur.next) {
			if (cur.i.equals(i)) return cur.s;
		}
		return null;
	}
}
