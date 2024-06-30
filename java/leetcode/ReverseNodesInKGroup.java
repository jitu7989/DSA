package java.leetcode;

public class ReverseNodesInKGroup {
    public class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }
    public ListNode reverseKGroup(ListNode head, int k) {

        if( head==null )  return null;

        ListNode toRet = null;
        ListNode prevGroupStart = null;
        ListNode prevGroupEnd = head;
        ListNode currMiddleHead = head;

        while( currMiddleHead!=null ){

            int i = 0;

            ListNode prev = null;
            ListNode curr = currMiddleHead;
            ListNode next = currMiddleHead.next;

            while( i < k && curr!=null ) {

                curr.next = prev;
                prev = curr;
                curr = next;
                next = next==null ? null : next.next;
                i++;
            }

            if( i==k ){

                if( toRet == null ){

                    toRet = prev;
                    prevGroupStart = prev;
                    currMiddleHead = curr;

                }
                else{

                    prevGroupEnd.next = prev;
                    prevGroupEnd = currMiddleHead;
                    prevGroupStart = currMiddleHead;


                }

            }
            else{

                curr = prev;
                prev=null;
                next = curr.next;

                while( curr!=null ) {
                    curr.next = prev;
                    prev = curr;
                    curr = next;
                    next = next==null ? null : next.next;
                    i++;
                }

                if( toRet==null )
                    return prev;

                prevGroupEnd.next = currMiddleHead;
                break;

            }

            currMiddleHead = curr;

        }
        // <-1 <- 2 <- 3 <- 4 5 6 7 8 9 1 2
        // 4 3 2 1 8 7 6 5 9 1 2
        return toRet;

    }

}

