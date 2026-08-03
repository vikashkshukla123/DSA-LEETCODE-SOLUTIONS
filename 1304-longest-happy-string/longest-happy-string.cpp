class Solution {
public:
typedef pair<int,char>p;
    string longestDiverseString(int a, int b, int c) {
        priority_queue<p>pq;
        if(a > 0){
            pq.push({a,'a'});
        }
        if(b > 0){
            pq.push({b,'b'});
        }
        if(c > 0){
            pq.push({c,'c'});
        }

        int consecutive_length = 0;
        string ans = "";
        while(!pq.empty()){
                auto it = pq.top();
                int val = it.first;
                char ch = it.second;
                pq.pop();

                if(consecutive_length == 2 && ans.back() == ch){

                    if(!pq.empty()){
                        consecutive_length = 1;
                        
                        auto it_ = pq.top();
                        int val1 = it_.first;
                        char ch1 = it_.second;
                        pq.pop();

                        ans += ch1;
                        if(val1 - 1 > 0){
                            pq.push({val1 - 1,ch1});
                        }

                        pq.push({val,ch});




                    }else{
                         break;
                    }
                    
                    
                }else{
                    if(ans.size() != 0 && ans.back() == ch){
                        consecutive_length++;
                        if(consecutive_length >= 3){
                            break;
                        }
                    }else{
                        consecutive_length = 1;
                    }
                    
                    ans += ch;

                    if(val - 1 > 0){
                        pq.push({val-1,ch});
                    }
                    

                }


        }



return ans;
        
    }
};