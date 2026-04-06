class Solution {
    List<Integer> Tree1 = new ArrayList<>();
    List<Integer> Tree2 = new ArrayList<>();

    public void solve1(TreeNode root){
        if(root == null) return;

        if(root.left == null && root.right == null){
            Tree1.add(root.val);
            return;
        }

        solve1(root.left);
        solve1(root.right);
    }

    public void solve2(TreeNode root){
        if(root == null) return;

        if(root.left == null && root.right == null){
            Tree2.add(root.val);
            return;
        }

        solve2(root.left);
        solve2(root.right);
    }

    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        solve1(root1);
        solve2(root2);

        if(Tree1.size() != Tree2.size()) return false;

        for(int i = 0; i < Tree1.size(); i++){
            if(!Tree1.get(i).equals(Tree2.get(i))){
                return false;
            }
        }

        return true;
    }
}