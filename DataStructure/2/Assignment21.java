import java.io.*;

public class Assignment21 {
	public static LinkedList add(LinkedList f, LinkedList g) {
		/* Defining add function which Input linkedlist f, g to parameter. */
		ListNode f_node = f.first;
		ListNode g_node = g.first; // Defining f_node, g_node which pointing f.first and g.first.
		LinkedList h = new LinkedList(); //  Defining new LinkedList h which is return value.
		/* Processing while two node is null. Their's biggest degree insert to h until when two node's degree is same. */
		while (f_node != null && g_node != null) {
			if (f_node.x > g_node.x) {
				h.InsertAtFront(f_node.a, f_node.x);
				f_node = f_node.next;
			} else if (f_node.x < g_node.x) {
				h.InsertAtFront(g_node.a, g_node.x);
				g_node = g_node.next;
			} else {
				h.InsertAtFront(f_node.a + g_node.a, f_node.x);
				f_node = f_node.next;
				g_node = g_node.next;
			}
		}
		return h;
	}
	
	public static void main(String[] args) {
		int f_n, g_n;
		String bool = null;
		LinkedList f = new LinkedList();
		LinkedList g = new LinkedList();
		
		try {
			File file = new File("input.txt");
			FileReader fr = new FileReader(file);
			BufferedReader rd = new BufferedReader(fr);
			
			/* Storing polynomial to LikedList f and g.
			 * f_n and g_n are number of terms.
			 * bool is 'plus' or 'times'*/
			f_n = Integer.parseInt(rd.readLine());
			for (int i = 0; i < f_n; i++) {
				String temp = rd.readLine();
				int a = Integer.parseInt(temp.split(" ")[0]),
				x = Integer.parseInt(temp.split(" ")[1]);
				f.InsertAtFront(a, x);
			}
			
			bool = rd.readLine();
			
			g_n = Integer.parseInt(rd.readLine());
			for (int i = 0; i < g_n; i++) {
				String temp = rd.readLine();
				int a = Integer.parseInt(temp.split(" ")[0]),
				x = Integer.parseInt(temp.split(" ")[1]);
				g.InsertAtFront(a, x);
			}
			
			rd.close();
		} catch(Exception e) {
			System.out.println("Error");
		}
		
		LinkedList h = new LinkedList(); // Defining LinkedList, h, which is return linkedlist.
		h.InsertAtFront(0, 0);
		if (bool.equals("plus")) {
			h = add(f, g);
		} else if (bool.equals("times")) {
			/* NoGaDa!!! for every term. It may be O(mn).*/
			for (ListNode f_node = f.first; f_node != null; f_node = f_node.next) {
				for (ListNode g_node = g.first; g_node != null; g_node = g_node.next) {
					h.InsertAtFront(f_node.a * g_node.a, f_node.x + g_node.x);
				}
			}
			h.first = h.MergeSort(h.first);
			LinkedList i = new LinkedList();
			int a = 0;
			/* If current node and next node's power is same, then save their coefficient to a.
			 * else insert to i*/
			for (ListNode h_node = h.first; h_node != null; h_node = h_node.next) {
				if (h_node.next != null && h_node.x == h_node.next.x) {
					a += h_node.a;
				} else {
					a += h_node.a;
					i.InsertAtFront(a, h_node.x);
					a = 0;
				}
			}
			h = i;
		}
		
		try {
			File file = new File("output.txt");
			FileWriter fw = new FileWriter(file);
			BufferedWriter wr = new BufferedWriter(fw);
			/* Defining int, num, which is number of terms.
			 * If coeffieint is 0, then num--. */
			int num = h.NumberOfNode();
			for (ListNode cur = h.first; cur != null; cur = cur.next) {
				if (cur.a == 0) {
					num--;
				}
			}
			if (num <= 0) {
				wr.write("1");
				wr.newLine();
				wr.write("0 0");
				wr.newLine();
			} else {
				wr.write(Integer.toString(num));
				wr.newLine();
				for (ListNode cur = h.first; cur != null; cur = cur.next) {
					if (cur.a != 0) {
						wr.write(Integer.toString(cur.a) + " " +Integer.toString(cur.x));
						wr.newLine();
					}
				}
			}
			wr.close();
			} catch(Exception e) {
				System.out.println("Error");
			}
	}
}