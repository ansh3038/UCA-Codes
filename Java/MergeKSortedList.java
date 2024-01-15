/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<ListNode> temp = new PriorityQueue<>((a,b)-> a.val-b.val);
        for(ListNode L : lists){
            ListNode temp1 = L;
            while(temp1!=null){
                temp.add(temp1);
                temp1 = temp1.next;
            }
        }
        ListNode ans = temp.poll();
        ListNode t = ans;
        while(!temp.isEmpty()){
            t.next = temp.poll();
            t = t.next;
        }
        if(t!=null && t.next!=null){
            t.next = null;
        }
        return ans;
        
    }
}