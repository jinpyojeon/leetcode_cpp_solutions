// 657

class Solution {
public:
    bool judgeCircle(string moves) {
        std::map<char, int> moveMap = {{'U', 0}, {'D', 0}, {'L', 0}, {'R', 0}};
        for (char & c : moves) {
                
            if (moveMap.find(c) != moveMap.end()) {
 
                moveMap[c]++;
            }
        }
        return moveMap['U'] == moveMap['D'] && moveMap['L'] == moveMap['R'];
    }
};

// 728

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        auto selfDividing = [](int n){
            int orig = n; 
            std::vector<int> digits;
            while (n) { digits.push_back(n % 10); n /= 10;}
            return std::all_of(digits.begin(), digits.end(), 
                               [orig](int d){ return d != 0 && orig % d == 0; });
        };
        std::vector<int> result;
        for (int i = left; i <= right; i++) {
            if (selfDividing(i)) result.push_back(i); 
        }
        return result;
    }
};

// 557 

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        vector<string> reversedWords;
        string result{""};
        words.push_back("");
        for (char&c : s) {
            if (c == ' ') {
                words.push_back(" ");
                words.push_back("");
            } else words.back() += c;
        }
        for (auto w : words) reversedWords.push_back(string(w.rbegin(), w.rend()));
        for_each(reversedWords.begin(), reversedWords.end(), [&result](string w) { result.append(w); });
        return result;
    
};
