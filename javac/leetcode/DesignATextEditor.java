package java.leetcode;

public class DesignATextEditor {
    private int leftCharacters;
    private int rightCharacters;

    private final Node head;
    private final Node tail;
    private final Node cursor;

    public DesignATextEditor() {
        head = new Node(null);
        tail = new Node(null);
        this.cursor=new Node('|');
        head.next = cursor;
        cursor.next = tail;
        tail.prev = cursor;
        cursor.prev = head;
    }

    public void addText(String text) {
        for (int i = 0; i < text.length(); i++) {
            char c = text.charAt(i);
            leftCharacters++;
            Node prev = cursor.prev;
            Node insert = new Node(c);
            insert.prev = prev;
            prev.next = insert;
            insert.next = cursor;
            cursor.prev = insert;
        }
    }

    public int deleteText(int k) {
        int deleted = Math.min(k,leftCharacters);
        if(deleted==0) return 0;
        Node node = cursor.prev;
        node.next = null;
        cursor.prev = null;
        for (int i = 0; i < deleted-1; i++)  {
            leftCharacters--;
            node = node.prev;
        }
        leftCharacters--;
        Node prevNode = node.prev;
        node.prev=null;
        prevNode.next=cursor;
        cursor.prev=prevNode;
        return deleted;
    }

    public String cursorLeft(int k) {
        Node node = cursor.prev;
        if(node.character!=null) {
            cursor.prev.next = cursor.next;
            cursor.next.prev = cursor.prev;
            cursor.prev = null;
            cursor.next = null;

            while (node.character != null && (k--)>0) {
                node = node.prev;
                leftCharacters--;
                rightCharacters++;
            }
            Node next = node.next;
            node.next = cursor;
            cursor.prev = node;
            next.prev = cursor;
            cursor.next = next;
        }

        int nodesToReturn = Math.min(10,leftCharacters);
        StringBuilder sb =new StringBuilder();
        Node curr = cursor;
        for (int i = 0; i < nodesToReturn; i++) {
            curr=curr.prev;
            sb.append(curr.character);
        }
        return sb.reverse().toString();
    }

    public String cursorRight(int k) {
        Node node = cursor.next;
        if(node.character!=null) {
            cursor.prev.next = cursor.next;
            cursor.next.prev = cursor.prev;
            cursor.prev = null;
            cursor.next = null;
            while (node.character != null && (k--)>0) {
                node = node.next;
                leftCharacters++;
                rightCharacters--;
            }
            Node prev = node.prev;
            prev.next = cursor;
            cursor.prev = prev;
            cursor.next = node;
            node.prev = cursor;
        }

        int nodesToReturn = Math.min(10,leftCharacters);
        StringBuilder sb =new StringBuilder();
        Node curr = cursor;
        for (int i = 0; i < nodesToReturn; i++) {
            curr=curr.prev;
            sb.append(curr.character);
        }
        return sb.reverse().toString();
    }


    private class Node {

        Character character;
        Node prev;
        Node next;
        public Node(Character c) {
            this.character = c;
        }
    }


}
