//{ Driver Code Starts
//Initial Template for Java

/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;
import java.math.*;

class Node  
{ 
    int data; 
    Node left, right; 
   
    public Node(int d)  
    { 
        data = d; 
        left = right = null; 
    } 
}

class GFG
{
    static Node buildTree(String str)
    {
        // Corner Case
        if(str.length() == 0 || str.equals('N'))
            return null;
        String[] s = str.split(" ");
        
        Node root = new Node(Integer.parseInt(s[0]));
        Queue <Node> q = new LinkedList<Node>();
        q.add(root);
        
        // Starting from the second element
        int i = 1;
        while(!q.isEmpty() && i < s.length)
        {
              // Get and remove the front of the queue
              Node currNode = q.remove();
        
              // Get the curr node's value from the string
              String currVal = s[i];
        
              // If the left child is not null
              if(!currVal.equals("N")) 
              {
        
                  // Create the left child for the curr node
                  currNode.left = new Node(Integer.parseInt(currVal));
        
                  // Push it to the queue
                  q.add(currNode.left);
              }
        
              // For the right child
              i++;
              if(i >= s.length)
                  break;
              currVal = s[i];
        
              // If the right child is not null
              if(!currVal.equals("N")) 
              {
        
                  // Create the right child for the curr node
                  currNode.right = new Node(Integer.parseInt(currVal));
        
                  // Push it to the queue
                  q.add(currNode.right);
              }
              
              i++;
        }
    
        return root;
    }
    
    public static void main(String args[]) throws IOException {
    
       BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while(t>0)
        {
            String s = br.readLine();
            Node root = buildTree(s);
            
            Solution T = new Solution();
            System.out.println(T.largestBst(root));
            
            t--;
        }
    }
}


// } Driver Code Ends


//User function Template for Java

// class Node  
// { 
//     int data; 
//     Node left, right; 
   
//     public Node(int d)  
//     { 
//         data = d; 
//         left = right = null; 
//     } 
// }

class TreeInfo {
    int size;
    int minVal;
    int maxVal;
    boolean isBst;
    public TreeInfo(int sz, int mn, int mx, boolean isBst){
        this.size = sz;
        this.minVal = mn;
        this.maxVal = mx;
        this.isBst = isBst;
    }
}
class Solution{
    static TreeInfo solve(Node root){
        if(root==null) return new TreeInfo(0, Integer.MAX_VALUE, Integer.MIN_VALUE,true);
        TreeInfo left = solve(root.left);
        TreeInfo right = solve(root.right);
        if(!left.isBst || !right.isBst || left.maxVal>=root.data || right.minVal<=root.data){
            return left.size >=right.size ? new TreeInfo(left.size, Integer.MIN_VALUE, Integer.MAX_VALUE, false) :
             new TreeInfo(right.size, Integer.MIN_VALUE, Integer.MAX_VALUE, false);
            
        }
        return new TreeInfo(left.size + right.size +1, Math.min(root.data, left.minVal), Math.max(root.data, right.maxVal), true);
    }
    static int largestBst(Node root)
    {
        TreeInfo temp = solve(root);
        return temp.size;
    }
    
}