class Solution {
public:
vector<int>previousSmallerElement(vector<int>&height){
    int n = height.size();
    vector<int>pse(n,0);
    stack<int>st;
    st.push(-1);

    for(int i = 0; i<n;i++){
        while(st.top() != -1 && height[st.top()] >= height[i]){
            st.pop();
        }
        pse[i] = st.top();
        st.push(i);
    }
    return pse;
}

vector<int>nextSmallerElement(vector<int>&height){
    int n = height.size();
    stack<int>st;
    vector<int>nge(n,0);
    st.push(-1);
    for(int i = n-1; i >=0; i--){
        while(st.top() != -1  && height[st.top()] >= height[i]){
            st.pop();
        }
        nge[i] = st.top();
        st.push(i);
    }

    return nge;
}


int solve(vector<int>&height){
    int n = height.size();
    vector<int>pse(n,0);
    pse = previousSmallerElement(height);

    vector<int>nse(n,0);
    nse = nextSmallerElement(height);


    int area = -1e9;
    for(int i = 0; i<n; i++){
        int h = height[i];
        int w1 = pse[i];
        int w2 = nse[i];
        if(w2 == -1){
            w2 = n;
        }
        
        int width = w2 - w1 - 1;
        area = max(area,h*width);

    }

    return area;
    
}
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = -1e9;
        vector<int>height(m,0);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(matrix[i][j] == '0'){
                    height[j] = 0;
                }else{
                    height[j] += 1;
                }
            }

            int largestArea = solve(height);
            ans = max(ans,largestArea);
        }
        return ans;
        
    }
};