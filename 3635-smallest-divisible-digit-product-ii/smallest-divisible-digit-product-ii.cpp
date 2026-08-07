class Solution {
public:
typedef long long ll;
string freeSlotsFiller(long long required, int len){
    string str;
    for(int digit = 9; digit >= 2; digit--){
        while(required % digit == 0){
            str.push_back(digit + '0');
            required = required / digit;
        }
    }



 while(str.length() < len){
    str.push_back('1');
 }

 reverse(begin(str),end(str));

 return str;


}
    string smallestNumber(string num, long long t) {
        int n = num.length();
        ll temp = t;
        for(int primeFact : {2,3,5,7}){
            while(temp % primeFact == 0){
                temp = temp / primeFact;
            }
        }

        if(temp != 1){
            return "-1";
        }
        vector<ll>remainingFactor(n+1,t);
        for(int i = 0; i < n; i++){
            int digit = num[i] - '0';
            if(digit == 0){
                break;
            }
            remainingFactor[i+1] = remainingFactor[i]/gcd(remainingFactor[i],(ll)digit);
        }


        if(remainingFactor[n] == 1){
            return num;
        }

        int zeroPos = num.find('0');
        int zeroIdx = n-1;
        if(zeroPos != -1){
            zeroIdx = zeroPos;
        }
        for(int i = zeroIdx; i >= 0; i--){
            ll required = remainingFactor[i];
            int freeSlots = n - i - 1;
            for(int digit = (num[i] - '0') + 1; digit <= 9; digit++){
                long long FurtherRequired = required/gcd(required,(ll) digit);
                string requiredNumber = freeSlotsFiller(FurtherRequired,freeSlots);

                if(requiredNumber.length() == freeSlots){
                    return num.substr(0,i) + char(digit + '0') + requiredNumber;
                } 

            }
        }
        return freeSlotsFiller(t,n+1);
    }
};