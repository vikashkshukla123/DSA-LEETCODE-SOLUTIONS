class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
    vector<int>ans;
    int n = code.size();
    if(k > 0){
        int i = 0;
        while(i < n){
            int j = i+1;
            int sum = 0;
            int cnt = k;
            while(cnt --){
                sum += code[j % n];
                j++;
            }
            ans.push_back(sum);
            i++;

        }


    }else if(k < 0){
        int i = 0;
        while(i < n){
            int j = i - 1;
            if(j < 0){
                j = n - abs(j);
                j = j % n;
            }

            int sum = 0;
            int cnt = abs(k);
            while(cnt --){
                sum += code[j];
                j--;

                if(j < 0){
                    j = n - abs(j);
                    j = j % n;
                }
            }

            ans.push_back(sum);
            i++;
            

        }


    }else{
        int i = 0;
        while(i < n){
            ans.push_back(0);
            i++;

        }
        
    }
    return ans;
        
    }
};