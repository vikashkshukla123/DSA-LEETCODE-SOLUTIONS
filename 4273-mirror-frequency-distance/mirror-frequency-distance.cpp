class Solution {
public:
    int mirrorFrequency(string s) {
        int n = s.length();
        string actual = s;
        int sum = 0;
       

        int m = actual.length();
        unordered_map<char,int>mp1;
        unordered_map<int,int>mp2;
        for(int i = 0; i<m; i++){
            if(actual[i] >= 'a' && actual[i] <= 'z'){
                mp1[actual[i]]++;
            }else{
                int val = actual[i] - '0';
                mp2[val]++;
            }
        }

        unordered_set<char>jo_hogaya1;
        unordered_set<int>jo_hogaya2;

        for(int i = 0; i<m; i++){
            if(actual[i] >= 'a' && actual[i] <= 'z'){
                char ch1 = actual[i];
                char ch2 =  'z' - (ch1 - 'a');

                int f1 = mp1[ch1];
                int f2 = 0;
                if(mp1.find(ch2) != mp1.end()){
                    f2 = mp1[ch2];
                }


                if(jo_hogaya1.find(ch2) == jo_hogaya1.end() && jo_hogaya1.find(ch1) == jo_hogaya1.end()){
                    sum += abs(f1-f2);

                }

                jo_hogaya1.insert(ch1);
                jo_hogaya1.insert(ch2);

                

                
            }else{
                int val1 = actual[i] - '0';
                int val2 = 9 - val1;

                int f1 = mp2[val1];
                int f2 = 0;
                if(mp2.find(val2) != mp2.end()){
                    f2 = mp2[val2];
                }

                if(jo_hogaya2.find(val1) == jo_hogaya2.end() && jo_hogaya2.find(val2) == jo_hogaya2.end()){
                    sum += abs(f1-f2);

                }

                jo_hogaya2.insert(val1);
                jo_hogaya2.insert(val2);
            }
        }


return sum;


        
    }
};