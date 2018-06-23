public class LinkedList {
	ListNode first;
	
	public LinkedList() {
		first = null;
	}

	public void DeleteFirst() {
		first = first.next;
	}

	
	public void InsertAtFront(int a, int x) {
		ListNode newnode = new ListNode(a, x);
		
		newnode.a = a;
		newnode.x = x;
		newnode.next = first;
		first = newnode;
	}
	
	public ListNode MergeSort(ListNode head) {
		if (head == null || head.next == null) {
			return head;
		}
		
		ListNode middle,fast;
		middle = fast = head;
		while (fast.next != null && fast.next.next != null) {
			middle = middle.next;
			fast = fast.next.next;
		} 
		ListNode Half = middle.next;
		middle.next = null;
	    return doMergeSort(MergeSort(head),MergeSort(Half));
	}

	public ListNode doMergeSort(ListNode a, ListNode b) {
		ListNode cur, cur2 = new ListNode();
		cur = cur2;
		
		while (a !=null && b!= null) {
			if (a.x >= b.x) {
				cur.next = a;
				a = a.next;
			} else {
				cur.next = b;
				b = b.next;
			}
			cur = cur.next;
	    }
		if (a == null) {
			cur.next = b;
		} else {
			cur.next = a;
		}
	    return cur2.next;
	}
	
	public int NumberOfNode() {
		ListNode cur;
		int i = 0;
		for (cur = first; cur != null; cur = cur.next) {
			i++;
		}
		return i;
	}
	
	public void DisplayAll() {
		ListNode cur;
		for (cur = first; cur != null; cur = cur.next) {
			System.out.print(cur.a);
			System.out.print(" ");
			System.out.println(cur.x);
		}
	}
}