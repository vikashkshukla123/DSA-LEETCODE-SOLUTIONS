class Solution {
public:

vector<double>callOperation(double&a, double&b){
  vector<double>result;
  result.push_back(a+b);
  result.push_back(a-b);
  result.push_back(b-a);
  result.push_back(a*b);
  result.push_back(a/b);
  result.push_back(b/a);

  return result;
}
bool helper(vector<double>&copy){
  int m = copy.size();
  if(m == 1){
    return abs(copy[0] - 24.0) < 0.000001;
  }
  for(int i = 0; i<m; i++){
    for(int j = i+1; j<m; j++){
      double a = copy[i];
      double b = copy[j];

      vector<double>operation = callOperation(a,b);
      vector<double>nextRound;
      for(int k = 0; k<m; k++){
        if(k != i && k != j){
          nextRound.push_back(copy[k]);
        }
      }
      for(double o : operation){
        nextRound.push_back(o);
        if(helper(nextRound)){
          return true;
        }
        nextRound.pop_back();

      }

    }
  }
  return false;
}



    bool judgePoint24(vector<int>& cards) {
        int n = cards.size();
        vector<double>copy;
        for(int i = 0; i<n; i++){
          copy.push_back(double(cards[i]));
        }
        return helper(copy);
    }
};