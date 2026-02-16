class Solution {
public:
    int reverseBits(int n) {

        string a = bitset<32>(n).to_string();

        int i = 0;
        int j = a.length()-1;

        while(i <= j){
            swap(a[i],a[j]);
            i++;
            j--;
        }
        int decimal = stoi(a, 0, 2);
        return decimal;
    }
};