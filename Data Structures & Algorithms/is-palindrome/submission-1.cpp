class Solution {
public:
    bool isAlphanumeric(char& c) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c >= '0' && c <= '9') return true;
        else return false;
    }

    bool isPalindrome(string s) {
        int size = s.size();
        int front = 0, back = size - 1;
        while(front < back) {
            if (!isAlphanumeric(s[front])) {
                front++;
                continue;
            }
            if (!isAlphanumeric(s[back])) {
                back--;
                continue;
            }
            if (tolower(s[front]) == tolower(s[back])) {
                front++;
                back--;
            }    
            else return false;
        }
        return true;
    }
};
