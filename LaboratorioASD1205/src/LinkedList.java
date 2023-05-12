
public class LinkedList{       
    private class Node{
    int data;
    Node next;
    }
    
    private Node head;

    public boolean isEmpty(){
        return head == null;
    }

    public void insertAsFirst(int x){
        Node n = new Node();
        n.data = x;
        n.next = head;
        head = n;
    }

    public void insertAsLast(int x){
        if(head==null) insertAsFirst(x);
        else insertAsLast(head, x);
    }

    private void insertAsLast(Node p, int x){
        if(p==null) return;
        if(p.next == null){
            Node n = new Node();
            n.data = x;
            n.next = null;
            p.next = n;
            return;
        }
        insertAsLast(p, x);
    }

    public void print(){
        if(head != null){
            System.out.println("Data in the list");
            print(head);
        }
        else System.out.println("The list is empty");
    }

    private void print(Node p){
        if(p == null) return;
        System.out.println(p.data);
        print(p.next);
    }

    public int size(){
        return size(head);
    }

    private int size(Node p){
        if(p==null) return 0;
        return size(p.next)+1;
    }

    public int getAt(int k){
        return getAt(head, k);
    }

    private int getAt(Node p, int k){
        if(k<1) System.exit(-1);
        if(k>1) getAt(p.next, k-1);
        return p.data;
    }

    public void printReverse(){
        printReverse(head);
    }

    private void printReverse(Node p){
        if(p == null && p.next!=null) printReverse(p.next); 
        System.out.println(p.data);
    }


    public int getLast(){
        return getLast(head);
    }

    private int getLast(Node p){
        if(p.next==null) return p.data;
        return getLast(p.next);
    }

    public boolean deleteLast(){
        if(head == null) return false;
        if(head.next == null){
            head = null;
            return true;
        }
        return deleteLast(head);
    }

    private boolean deleteLast(Node p){
        if(p.next.next==null){
            p.next = null;
            return true;
        }
        return deleteLast(p.next);
    }

    
}

