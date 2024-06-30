package java.leetcode;




import java.util.HashMap;

public class LFUCache {

    private int size;
    private int capacity;
    private int minFrequency;
    private HashMap<Integer,Node> nodeMap;
    private HashMap<Integer,DoublllyLinkList> frequencyNodeMap;

    public LFUCache(int capacity) {
        this.capacity = capacity;
        this.nodeMap = new HashMap<>();
        this.frequencyNodeMap = new HashMap<>();
    }

    public int get(int key) {
        if(!nodeMap.containsKey(key)) return -1;
        Node node = nodeMap.get(key);
        DoublllyLinkList lruCache = frequencyNodeMap.get(node.frequency);
        lruCache.invalidateNode(node);
        if(lruCache.nodes==0 && minFrequency==node.frequency) minFrequency++;
        frequencyNodeMap.put(++node.frequency,frequencyNodeMap.getOrDefault(node.frequency,new DoublllyLinkList()));
        frequencyNodeMap.get(node.frequency).addNode(node);
        return node.value;
    }

    public void put(int key, int value) {
        boolean notContains = !nodeMap.containsKey(key);
        if(notContains && size==capacity) {
            DoublllyLinkList lruCache = frequencyNodeMap.get(minFrequency);
            Node node = lruCache.head.next;
            lruCache.invalidateNode(node);
            nodeMap.remove(node.key);
        }
        if(notContains) {
            minFrequency=1;
            DoublllyLinkList init = frequencyNodeMap.getOrDefault(1,new DoublllyLinkList());
            frequencyNodeMap.put(1,init);
            Node node = new Node(key,value,1);
            init.addNode(node);
            nodeMap.put(node.key,node);
        }
        else{
            Node node = nodeMap.get(key);
            node.value = value;
            DoublllyLinkList lruCache = frequencyNodeMap.get(node.frequency);
            lruCache.invalidateNode(node);
            if(lruCache.nodes==0 && minFrequency==node.frequency) minFrequency++;

            frequencyNodeMap.put(++node.frequency,frequencyNodeMap.getOrDefault(node.frequency,new DoublllyLinkList()));
            frequencyNodeMap.get(node.frequency).addNode(node);
        }
        if(notContains && size<capacity) size++;
    }

    private class DoublllyLinkList {
        int nodes;
        private final Node head;
        private final Node tail;

        public DoublllyLinkList() {
            head = new Node(0,0,0);
            tail = new Node(0,0,0);
            head.next = tail;
            tail.prev = head;
        }

        public void invalidateNode(Node node) {
            Node prevNode = node.prev;
            Node nextNode = node.next;
            node.next = null;
            node.prev = null;
            nextNode.prev = prevNode;
            prevNode.next = nextNode;
            this.nodes--;
        }

        public void addNode(Node node) {
            Node prev = tail.prev;
            prev.next = node;
            tail.prev = node;
            node.prev = prev;
            node.next = tail;
            this.nodes++;
        }

    }
    private class Node {

        int key;
        int value;
        int frequency;
        Node prev;
        Node next;


        public Node(int key, int value, int frequency) {
            this.key = key;
            this.value = value;
            this.frequency = frequency;
        }
    }

    public static void main(String[] args) {
        LFUCache cache = new LFUCache(10);
        int[][] tc = new int[][]{{10},{10,13},{3,17},{6,11},{10,5},{9,10},{13},{2,19},{2},{3},{5,25},{8},{9,22},{5,5},{1,30},{11},{9,12},{7},{5},{8},{9},{4,30},{9,3},{9},{10},{10},{6,14},{3,1},{3},{10,11},{8},{2,14},{1},{5},{4},{11,4},{12,24},{5,18},{13},{7,23},{8},{12},{3,27},{2,12},{5},{2,9},{13,4},{8,18},{1,7},{6},{9,29},{8,21},{5},{6,30},{1,12},{10},{4,15},{7,22},{11,26},{8,17},{9,29},{5},{3,4},{11,30},{12},{4,29},{3},{9},{6},{3,4},{1},{10},{3,29},{10,28},{1,20},{11,13},{3},{3,12},{3,8},{10,9},{3,26},{8},{7},{5},{13,17},{2,27},{11,15},{12},{9,19},{2,15},{3,16},{1},{12,17},{9,1},{6,19},{4},{5},{5},{8,1},{11,7},{5,2},{9,28},{1},{2,2},{7,4},{4,22},{7,24},{9,26},{13,28},{11,26}};
        int[][] tc2 = new int[][]{{3},{1,1},{2,2},{3,3},{4,4},{4},{3},{2},{1},{5,5},{1},{2},{3},{4},{5}};
        for (int i = 0; i < tc.length; i++) {
            int[] a = tc[i];
            if(a.length==2){
                cache.put(a[0],a[1]);
                /*
                1 -> 6 1 4
                2 -> 10 2 3 5
                3 ->
                4 ->
                5 -> 5
                 */
            }
            else {
                cache.get(a[0]);
            }
        }
    }

}
