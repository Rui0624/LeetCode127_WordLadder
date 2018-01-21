//
//  main.cpp
//  LeetCode127_WordLadder
//
//  Created by Rui on 1/20/18.
//  Copyright © 2018 Rui. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict (wordList.begin(), wordList.end());
        unordered_map<string, int> m;
        m[beginWord] = 1;
        queue<string> q;
        q.push(beginWord);
        
        while(!q.empty())
        {
            string word = q.front();
            q.pop();
            for(int i = 0; i < word.size(); i++)
            {
                string newWord = word;
                for(char ch = 'a'; ch <= 'z'; ch++)
                {
                    newWord[i] = ch;
                    if(dict.count(newWord) && newWord == endWord)
                        return m[word] + 1;
                    if(dict.count(newWord) && !m.count(newWord)){
                        m[newWord] = m[word] + 1;
                        q.push(newWord);
                    }
                }
            }
        }
        
        return 0;
    }
};
