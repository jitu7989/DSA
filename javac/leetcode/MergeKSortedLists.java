package java.leetcode;

import java.util.Comparator;
import java.util.PriorityQueue;

public class MergeKSortedLists {

    public class ListNode {
        int val;
        ListNode next;

        ListNode() {
        }

        ListNode(int val) {
            this.val = val;
        }

        ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
    }

    public ListNode mergeKLists(ListNode[] lists) {

        PriorityQueue<ListNode> heap = new PriorityQueue<>(Comparator.comparingInt(o -> o.val));
        for (ListNode list : lists) if (list != null) heap.add(list);
        ListNode head = heap.poll();
        if (head == null) return null;
        if (head.next != null) heap.add(head.next);
        ListNode curr = head;
        while (!heap.isEmpty()) {
            ListNode polled = heap.poll();
            curr.next = polled;
            if (polled.next != null) heap.add(polled.next);
            curr = polled;
        }
        return head;
    }

}
