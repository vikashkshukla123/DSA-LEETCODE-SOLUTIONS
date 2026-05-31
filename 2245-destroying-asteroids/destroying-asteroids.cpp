class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size();
        sort(asteroids.begin(),asteroids.end());
        long long planet = (1LL * mass);
        for(int i = 0; i < n; i++){
            long long asteroid_mass = asteroids[i];
            if(asteroid_mass > planet){
                return false;
            }
            planet = planet + asteroid_mass;
        }
        return true;
    }
};