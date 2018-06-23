public class CDIterator {
	public DNode cur;
	public DNode header;
	
	public CDIterator(DNode header) {
		this.header = header;
		if (header.next == null) {
			cur = header;
		} else {
			cur = header.next;
		}
	}
	
	public boolean atEnd() {
		return cur == header;
	}
		
	
	public int getValue() {
		if (cur == header) {
			return -1;
		} else {
			return cur.data;
		}
	}
	
	public boolean delete() {
		if (cur == header) {
			return false;
		} else {
			cur.prev.next = cur.next;
			cur.next.prev = cur.prev;
			cur = cur.next;
			return true;
		}
		
	}
	
	public void insertBefore(int x) {
		DNode node = new DNode(x);
		if (cur == header) {
			header.prev.next = node;
			node.next = header;
			node.prev = header.prev;
			header.prev = node;
		} else {
			cur.prev.next = node;
			cur.next.prev = node;
			node.next = cur;
			node.prev = cur.prev;
		}
		
	}
	
	public void insertAfter(int x) {
		DNode node = new DNode(x);
		if (cur == header) {
			header.next.prev = node;
			node.next = header.next;
			node.prev = header;
			header.next = node;
		} else {
			cur.prev.next = node;
			cur.next.prev = node;
			node.next = cur.next;
			node.prev = cur;
		}
	}
	
	public void prev() {
		cur = cur.prev;
	}
	
	public void next() {
		cur = cur.next;
	}
}