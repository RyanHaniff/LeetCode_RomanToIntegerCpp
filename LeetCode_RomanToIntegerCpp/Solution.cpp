#include "Solution.h"
#include <unordered_map>
#include <iostream>

Solution::Solution() {

}

int Solution::romanToInt(std::string s) {

    std::unordered_map<char, int> map = {   { 'I' , 1 },
                                            { 'V' , 5 },
                                            { 'X' , 10 },
                                            { 'L' , 50 },
                                            { 'C' , 100 },
                                            { 'D' , 500 },
                                            { 'M' , 1000 } };

    // back() gets the last char in the string
    int addFromBack = map[s.back()];
    for (int i = s.length() - 2; i>= 0; --i) {

        if (map[s[i]] < map[s[i + 1]]) {
            std::cout << map[s[i]] << " < " << map[s[i + 1]] << "/n";
            addFromBack = addFromBack - map[s[i]];
            std::cout << addFromBack << "/n";
        }
        else {
            std::cout << map[s[i]];
            addFromBack = addFromBack + map[s[i]];
            std::cout << addFromBack << "/n";
        }
    }

    return addFromBack;

}



int main() {

    Solution sln;
    std::cout << sln.romanToInt("III");

	return 0;
}
