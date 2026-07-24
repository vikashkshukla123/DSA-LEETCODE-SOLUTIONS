class ATM {
public:
vector<int>bankNotes;

    ATM() {
        bankNotes.resize(5,0);
        
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i = 0; i < 5; i++){
            bankNotes[i] += banknotesCount[i];
        }
        
    }
    
    vector<int> withdraw(int amount) {
        vector<int>ans(5,0);
        vector<int>temp = bankNotes;
        int idx = 4;
        while(idx >= 0 && amount != 0){
            if(temp[idx] == 0){
                idx--;
                continue;
            }
            if(idx == 4){
                long long money_possible = 1LL * temp[idx] * 500;
                if(amount >= money_possible){
                    amount = amount - money_possible;
                    ans[idx] += temp[idx];
                    temp[idx] = 0;
                    idx--;
                }else{
                    int notes_required = amount / 500;
                    ans[idx] += notes_required;
                    temp[idx] -= notes_required;
                    amount = amount - (notes_required * 500);
                    idx--;

                }
            }else if(idx == 3){
                long long money_possible = 1LL*  temp[idx] * 200;
                if(amount >= money_possible){
                    amount = amount - money_possible;
                    ans[idx] += temp[idx];
                    temp[idx] = 0;
                    idx--;
                }else{
                    int notes_required = amount / 200;
                    ans[idx] += notes_required;
                    temp[idx] -= notes_required;
                    amount = amount - (notes_required * 200);
                    idx--;

                }

            }else if(idx == 2){
                long long money_possible = 1LL* temp[idx] * 100;
                if(amount >= money_possible){
                    amount = amount - money_possible;
                    ans[idx] += temp[idx];
                    temp[idx] = 0;
                    idx--;
                }else{
                    long long notes_required = 1LL * amount / 100;
                    ans[idx] += notes_required;
                    temp[idx] -= notes_required;
                    amount = amount - (notes_required * 100);
                    idx--;

                }
    
            }else if(idx == 1){
                long long money_possible = 1LL * temp[idx] * 50;
                if(amount >= money_possible){
                    amount = amount - money_possible;
                    ans[idx] += temp[idx];
                    temp[idx] = 0;
                    idx--;
                }else{
                    int notes_required = amount / 50;
                    ans[idx] += notes_required;
                    temp[idx] -= notes_required;
                    amount = amount - (notes_required * 50);
                    idx--;

                }

            }else if(idx == 0){
                long long money_possible = 1LL * temp[idx] * 20;
                if(amount >= money_possible){
                    amount = amount - money_possible;
                    ans[idx] += temp[idx];
                    temp[idx] = 0;
                    idx--;
                }else{
                    int notes_required = amount / 20;
                    ans[idx] += notes_required;
                    temp[idx] -= notes_required;
                    amount = amount - (notes_required * 20);
                    idx--;

                }

            }
        

        }
        if(amount != 0){
            return {-1};
           }

        bankNotes = temp;
        return ans;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */