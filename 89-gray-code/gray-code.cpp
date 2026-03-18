class Solution {
public:
vector<string>generate(int n){
    if(n == 1){
        return {"0","1"};
    }

    vector<string>ans;
    vector<string>temp = generate(n-1);

    for(int i = 0; i <temp.size(); i++){
        string s = temp[i];
        ans.push_back("0" + s);
    }

    for(int i = temp.size() - 1; i>=0; i--){
        string s = temp[i];
        ans.push_back("1" + s);
    }


    return ans;
}
    vector<int> grayCode(int n) {
        vector<string>gray = generate(n);
        vector<int>ans;
        for(int i = 0; i<gray.size(); i++){
            int val = stoi(gray[i],0,2);

            ans.push_back(val);

        }
        return ans;
    }
};