class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            unordered_map<char, int> counter;
            for (int j = 0; j < board[i].size(); j++) {
                char val = board[i][j];
                if (val == '.') continue;
                counter[val]++; 
                if (counter[val] > 1) {
                    cout << counter[val] << endl;
                    return false;
                } 
            }
        }

        for (int i = 0; i < board.size(); i++) {
            unordered_map<char, int> counter;
            for (int j = 0; j < board[i].size(); j++) {
                char val = board[j][i];
                if (val == '.') continue;
                counter[val]++; 
                if (counter[val] > 1) {
                    cout << counter[val] << endl;
                    return false;
                } 
            }
        }


        for (int boxRow = 0; boxRow < 3; boxRow++) {
            for (int boxCol = 0; boxCol < 3; boxCol++) {
                unordered_map<char, int> counter;

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        char val = board[boxRow * 3 + i][boxCol * 3 + j];
                        if (val == '.') continue;
                        counter[val]++;
                        if (counter[val] > 1) {
                            return false;
                        }
                    }
                }
            }
        }   


        

        return true;
    }
};