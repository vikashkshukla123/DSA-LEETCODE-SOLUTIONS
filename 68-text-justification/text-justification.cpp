class Solution {
public:
    int MAX_WIDTH;

    string findLine(int i, int j, int eachGaddhaSpace, int extraSpaceGaddha, vector<string>& words) {
        string line;

        for (int k = i; k < j; k++) {
            line += words[k];

            // no space after last word of line
            if (k == j - 1) continue;

            // add equal spaces
            for (int z = 1; z <= eachGaddhaSpace; z++) {
                line += " ";
            }

            // distribute extra spaces (from left to right)
            if (extraSpaceGaddha > 0) {
                line += " ";
                extraSpaceGaddha--;
            }
        }

        // pad remaining spaces to reach MAX_WIDTH
        while ((int)line.length() < MAX_WIDTH) {
            line += " ";
        }

        return line;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string> result;
        int i = 0;
        MAX_WIDTH = maxWidth;

        while (i < n) {
            int letters_count = words[i].length();
            int j = i + 1;
            int gaddhe = 0; // number of gaps between words

            // Try to fit as many words as possible
            while (j < n && words[j].length() + 1 + gaddhe + letters_count <= maxWidth) {
                letters_count += words[j].length();
                gaddhe++;
                j++;
            }

            int remainingGaddhe = maxWidth - letters_count;
            int eachGaddhaSpace = (gaddhe == 0) ? 0 : remainingGaddhe / gaddhe;
            int extraSpaceGaddha = (gaddhe == 0) ? 0 : remainingGaddhe % gaddhe;

            // Last line → left justify (1 space between words)
            if (j == n) {
                eachGaddhaSpace = 1;
                extraSpaceGaddha = 0;
            }

            result.push_back(findLine(i, j, eachGaddhaSpace, extraSpaceGaddha, words));

            i = j; // move to next line
        }

        return result;
    }
};