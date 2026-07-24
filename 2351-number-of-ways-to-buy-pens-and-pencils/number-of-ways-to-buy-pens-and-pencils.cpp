class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long maxi_item = 0;
        long long max_pen = total/cost1;
        for(int pen = 0; pen <= max_pen; pen++){
            long long pen_cost = 1LL* pen * cost1;
            long long pencil_cost = total - pen_cost;
            long long pencil = pencil_cost / cost2;


            maxi_item += pencil + 1;

        }

        long long maxi_item2 = 0;
        long long maxi_pencil = total/cost2;
        for(int pencil = 0; pencil <= maxi_pencil; pencil++){
            long long pencil_cost = 1LL * pencil * cost2;
            long long pen_cost = total - pencil_cost;
            long long pen = pen_cost/cost1;

            maxi_item2 += pen + 1;
        }



return max(maxi_item,maxi_item2);
        
    }
};