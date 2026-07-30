class Solution {
public:
    int minimumBuckets(string hamsters) {
        int n = hamsters.length();
        if(n == 1){
            if(hamsters[0] == 'H') return -1;
            return 0;
        }
        for(int i = 1; i < n-1; i++){
            if(hamsters[i] == 'H'){
                if(hamsters[i-1] == '.' || hamsters[i+1] == '.'){
                    continue;
                }else{
                    return -1;
                }
            }
        }

        if(hamsters[0] == 'H' && hamsters[1] == 'H') return -1;
        if(hamsters[n-1] == 'H' && hamsters[n-2] == 'H') return -1;


        int ans = 0;
        string to_parse = hamsters;
        if(to_parse[0] == 'H' && to_parse[1] == '.'){
            ans++;
            to_parse[1] = 'B';
        }

        if(to_parse[n-1] == 'H' && to_parse[n-2] == '.'){
            ans++;
            to_parse[n-2] = 'B';
        }


        for(int i = 1; i < n-1; i++){
            if(to_parse[i] == '.' || to_parse[i] == 'B'){
                continue;
            }else if(to_parse[i] == 'H' && (i-1 >= 0 && to_parse[i-1] == 'B')){
                continue;
            }else if(to_parse[i] == 'H' && (i + 1 < n && to_parse[i+1] == 'B')){
                continue;
            }else if(to_parse[i] == 'H' && (i-1 >= 0 && to_parse[i-1] == '.' && i+1 < n && to_parse[i+1] != 'H')){
                ans++;
                to_parse[i+1] = 'B';
            }else if(to_parse[i] == 'H' && (i-1 >= 0 && to_parse[i-1] == '.'  && (i + 1 < n  && to_parse[i+1] == 'H'))){
                ans++;
                to_parse[i-1] = 'B';
            }else if(to_parse[i] == 'H' && (i-1 >= 0 && to_parse[i-1] == 'H' && (i + 1 < n && to_parse[i+1] == '.'))){
                ans++;
                to_parse[i+1] = 'B';
            }
        }
        return ans;
    }
};