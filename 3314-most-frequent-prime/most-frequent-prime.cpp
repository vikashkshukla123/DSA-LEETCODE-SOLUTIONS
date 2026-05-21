class Solution {
public:
unordered_map<int,int>prime;
bool isPrime(int num){
    int divisible = 0;
    if(num <= 1) return false;
    for(int i = 2; i * i   <=  num; i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}

void solve1(int row, int col,int val,vector<vector<int>>&mat){
    int n = mat.size();
    int m = mat[0].size();

    if(row < 0){
        return;
        
    }

    int newVal = val * 10 + mat[row][col];
    if(isPrime(newVal) && newVal > 10){
        prime[newVal]++;
    }

    solve1(row - 1, col, newVal, mat);

   
}
void solve2(int row, int col,int val, vector<vector<int>>&mat){
    int n = mat.size();
    int m = mat[0].size();

    if(row >= n){
        return;
        
    }

    int newVal = val * 10 + mat[row][col];
    if(isPrime(newVal) && newVal > 10){
        prime[newVal]++;
    }

    solve2(row + 1, col, newVal, mat);

}
void solve3(int row, int col,int val, vector<vector<int>>&mat){
    int n = mat.size();
    int m = mat[0].size();

    if(col >= m){
        return;
        
    }

    int newVal = val * 10 + mat[row][col];
    if(isPrime(newVal) && newVal > 10){
        prime[newVal]++;
    }

    solve3(row , col + 1, newVal, mat);
}

void solve4(int row, int col, int val, vector<vector<int>>&mat){
    int n = mat.size();
    int m = mat[0].size();

    if(col < 0){
        return;
    }
    int newVal = val * 10 + mat[row][col];
    if(isPrime(newVal) && newVal > 10){
        prime[newVal]++;
    }

    solve4(row ,col-1,newVal, mat);


}

void solve5(int row, int col, int val,vector<vector<int>>&mat){
    int n = mat.size();
    int m = mat[0].size();

    if(row < 0 || col >= m){
        return;
    }
    int newVal = val * 10 + mat[row][col];
    if(isPrime(newVal) && newVal > 10){
        prime[newVal]++;
    }

    solve5(row-1 ,col+1,newVal, mat);



}

void solve6(int row, int col,int val, vector<vector<int>>&mat){
    int n = mat.size();
    int m = mat[0].size();

    if(row >= n || col >= m){
        return;
    }
    int newVal = val * 10 + mat[row][col];
    if(isPrime(newVal) && newVal > 10){
        prime[newVal]++;
    }



   solve6(row + 1, col + 1,newVal, mat);
}

void solve7(int row, int col, int val,vector<vector<int>>&mat){
    int n = mat.size();
    int m = mat[0].size();

    if(row >= n || col < 0){
        return;
    }

    int newVal = val * 10 + mat[row][col];
    if(isPrime(newVal) && newVal > 10){
        prime[newVal]++;
    }




    solve7(row+1,col-1,newVal,mat);
}

void solve8(int row, int col,int val, vector<vector<int>>&mat){
    int n = mat.size();
    int m = mat[0].size();
   
   if(row < 0 || col < 0){
    return;
   }

    int newVal = val * 10 + mat[row][col];
    if(isPrime(newVal) && newVal > 10){
        prime[newVal]++;
    }

   
   solve8(row-1,col-1,newVal,mat);

}
    int mostFrequentPrime(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();


        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int val = mat[i][j];
                if(isPrime(val) && val > 10){
                    prime[val]++;
                }

                solve1(i-1,j,val,mat);
                solve2(i+1,j,val,mat);
                solve3(i,j+1,val,mat);
                solve4(i,j-1,val,mat);
                solve5(i-1,j+1,val,mat);
                solve6(i+1,j+1,val,mat);
                solve7(i+1,j-1,val,mat);
                solve8(i-1,j-1,val,mat);

            }
        }

        int result = 0;
        int prime_frequency = 0;
        for(auto it = prime.begin(); it != prime.end(); it++){
            int primeNumber = it->first;
            int freq = it->second;

            if(freq > prime_frequency){
                prime_frequency = freq;
                result = primeNumber;
            }else if(freq == prime_frequency){
                result = max(result, primeNumber);
            }
        }
        if(result == 0){
            return -1;
        }

        return result;
    }
};