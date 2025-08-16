class Solution {
public:
    int maximum69Number (int num) {

        vector<int>numstore;
        while(num > 0){
            int a = num % 10;
            numstore.push_back(a);
            num = num/10;
            
        }
        reverse(numstore.begin(), numstore.end());
        int n = numstore.size();
        for(int i = 0; i<n; i++){
            if(numstore[i] == 9) continue;
            numstore[i] = 9;
            break;
        }
        string resultString ="";
        for(int i = 0; i<n; i++){
            resultString += to_string(numstore[i]);
        }
        return stoi(resultString);



    }
};