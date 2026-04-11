

class Solution {
    public int[] recoverOrder(int[] order, int[] friends) {
        int n = friends.length;

        Set<Integer> set = new HashSet<>();
        for (int i = 0; i < n; i++) {
            set.add(friends[i]);
        }

        List<Integer> ans = new ArrayList<>();

        for (int i = 0; i < order.length; i++) {
            if (set.contains(order[i])) {
                ans.add(order[i]);
            }
        }

        int[] result = new int[ans.size()];
        for (int i = 0; i < ans.size(); i++) {
            result[i] = ans.get(i);
        }

        return result;
    }
}