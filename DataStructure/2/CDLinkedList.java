public class CDLinkedList {
	/* You can easily understand by drawing figure! */
	public final DNode header;
	
	public CDLinkedList() {
		header = new DNode(-1);
		header.prev = header;
		header.next = header;
	}
	
	public void insertAtFront(int x) {
		DNode node = new DNode(x);
		node.prev = header;
		node.next = header;
		
		if (header.next == null) {
			header.prev = node;
		} else {
			header.next.prev = node;
			node.next = header.next;
			node.prev = header;
		}
		header.next = node;
	}
	
	public void insertAtEnd(int x) {
		DNode node = new DNode(x);
		node.prev = header;
		node.next = header;
		
		if (header.prev == null) {
			header.next = node;
		} else {
			header.prev.next = node;
			node.next = header;
			node.prev = header.prev;
		}
		header.prev = node;
	}
	
	public int deleteFromFront() {
		if (header.next == null) {
			return -1;
		}
		int data = header.next.data;
		header.next.next.prev = header;
		header.next = header.next.next;
		return data;
	}
	
	public int deleteFromEnd() {
		if (header.prev == null) {
			return -1;
		}
		int data = header.prev.data;
		header.prev.prev.next = header;
		header.prev = header.prev.prev;
		return data;
	}
	
	public CDIterator getIterator() {
		return new CDIterator(header);
	}
	
}
