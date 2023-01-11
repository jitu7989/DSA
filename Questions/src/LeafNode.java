import java.util.*;
import java.util.stream.IntStream;

public class LeafNode {


    static class TreeNode {
        int val;
        TreeNode left;TreeNode right;
        TreeNode() {}
        TreeNode(int val) { this.val = val; }
        TreeNode(int val, TreeNode left, TreeNode right) {
              this.val = val;
              this.left = left;
              this.right = right;
          }
    }


        public boolean leafSimilar(TreeNode root1, TreeNode root2) {

            ArrayList<TreeNode> tree1LeafNodes = listLeafNode( root1 , new ArrayList<>() );
            ArrayList<TreeNode> tree2LeafNodes = listLeafNode( root1 , new ArrayList<>() );

            if(tree1LeafNodes.size()!= tree2LeafNodes.size() ) return false;

            for (int i = 0; i < tree1LeafNodes.size() ; i++) {
                if( tree2LeafNodes.get(i).val!=tree1LeafNodes.get(i).val )
                    return false;
            }
            return true;
        }

        ArrayList<TreeNode> listLeafNode( TreeNode root , ArrayList<TreeNode> nodes ){

            if( root == null ) return null;


            if( root.left == null && root.right == null  )
                nodes.add(root);

            if( root.left  != null ) listLeafNode( root.left  , nodes );
            if( root.right != null ) listLeafNode( root.right , nodes );

            return nodes;
        }



}
