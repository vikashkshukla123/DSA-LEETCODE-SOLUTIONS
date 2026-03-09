class Solution {
public:
int mod = 1e9 + 7;
int t[201][201][2];
int solve(int zeroleft, int oneleft, bool lastwasone, int limit){
    if(zeroleft == 0 && oneleft == 0){
        return 1;
    }

    if(t[zeroleft][oneleft][lastwasone] != -1){
        return t[zeroleft][oneleft][lastwasone];
    }

    int result = 0;

    if(lastwasone){
        for(int length = 1; length <= min(zeroleft, limit); length++){
            result = (result + solve(zeroleft - length, oneleft, false,limit))%mod;;


        }
    }else{
        for(int length = 1; length <= min(oneleft,limit); length++){
            result = (result + solve(zeroleft,oneleft - length, true, limit)) % mod;
        }
    }


    return t[zeroleft][oneleft][lastwasone] = result;
}
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(t,-1,sizeof(t));
        
        int starting_with_zero = solve(zero,one,true,limit);
        int starting_with_one =  solve(zero,one,false,limit);


        return (starting_with_zero + starting_with_one) % mod;
    }
};