class Solution {
public:
    bool isPalindrome(string s) {
        string newString = "";
        for (int i = 0; i < s.length(); i++) {
            if(isalnum(s.at(i))) {
                newString += tolower(s.at(i));
            }
        }

        for (int i = 0; i < (newString.length())/2; i++) {
            if (newString.at(i) == newString.at(newString.length()-1-i)) {
                cout << newString.at(i) << newString.at(newString.length()-1-i) << endl;
            } else {
                return false;
            }
        }
        return true;
    }
};