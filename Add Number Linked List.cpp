//{ Driver Code Starts
// driver

import java.io.*;
import java.util.*;


// } Driver Code Ends

/* node for linked list

class Node {
    int data;
    Node next;

    Node(int d) {
        data = d;
        next = null;
    }
}

*/

class Solution {
    
    Node reverse(Node head)
    {
        Node prev = null,curr=head;
            while(curr!=null)
            {
                Node next = curr.next;
                curr.next = prev;
                prev = curr;
                curr = next;
            }
            
            return prev;
    }
        
    Node addTwoLists(Node num1, Node num2) {
        // code here
        num1 = reverse(num1);
        num2 = reverse(num2);
        Node flag = new Node(0);
        Node tail = flag;
        int res = 0;
        
        while(num1!=null || num2!=null || res!=0)
        {
            int sum = res;
            if(num1!=null)
            {
                sum+=num1.data;
                num1 = num1.next;
            }
            if(num2!=null)
            {
                sum+=num2.data;
                num2=num2.next;
            }
            res = sum/10;
            tail.next = new Node(sum % 10);
            tail = tail.next;
        }
        
        Node ans = reverse(flag.next);
        while(ans!=null && ans.data == 0 && ans.next!=null)
        {
            ans = ans.next;
        }
        return ans;
    }
}


//{ Driver Code Starts.

class Node {
    int data;
    Node next;

    Node(int d) {
        data = d;
        next = null;
    }
}

class GfG {

    static void printList(Node n) {
        while (n != null) {
            System.out.print(n.data + " ");
            n = n.next;
        }
        System.out.println();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(read.readLine());
        while (T-- > 0) {

            String str[] = read.readLine().trim().split(" ");
            int n = str.length;

            Node num1 = new Node(Integer.parseInt(str[0]));
            Node tail = num1;
            for (int i = 1; i < n; i++) {
                int val = Integer.parseInt(str[i]);
                tail.next = new Node(val);
                tail = tail.next;
            }

            String str2[] = read.readLine().trim().split(" ");
            int m = str2.length;

            Node num2 = new Node(Integer.parseInt(str2[0]));
            tail = num2;
            for (int i = 1; i < m; i++) {

                tail.next = new Node(Integer.parseInt(str2[i]));
                tail = tail.next;
            }

            Solution g = new Solution();
            Node res = g.addTwoLists(num1, num2);
            printList(res);

            System.out.println("~");
        }
    }
}

// } Driver Code Ends
