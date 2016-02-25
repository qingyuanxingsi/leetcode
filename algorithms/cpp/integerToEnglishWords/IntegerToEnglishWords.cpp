// Source : https://leetcode.com/problems/integer-to-english-words/
// Author : qingyuanxingsi
// Date   : 2016-02-25

/*************************************************************************************** 
 *
 * Convert a non-negative integer to its english words representation. Given input is 
 * guaranteed to be less than 231 - 1.
 * 
 * For example,
 * 
 * 123 -> "One Hundred Twenty Three"
 * 12345 -> "Twelve Thousand Three Hundred Forty Five"
 * 1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
 * 
 *   Did you see a pattern in dividing the number into chunk of words? For example, 123 
 * and 123000.
 *
 *   Group the number by thousands (3 digits). You can write a helper function that 
 * takes a number less than 1000 and convert just that chunk to words.
 *
 *   There are many edge cases. What are some good test cases? Does your code work with 
 * input such as 0? Or 1000010? (middle chunk is zero and should not be printed out)
 *               
 ***************************************************************************************/

#include <string>

class Solution {
private:
    vector<string> jumps = {"Thousand","Million","Billion","Trillion"};
    vector<string> ones = {"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
    vector<string> teens = {"Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    vector<string> tys = {"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
public:
    string numberToWords(int num) {
        if(num == 0){
            return "Zero";
        }
        int divide = 1000;
        vector<string> result;
        int tag = -1;
        while(num != 0){
            int div = num / divide;
            int remainder = num % divide;
            tag++;
            if(remainder != 0){
                vector<string> tmp = say(remainder);
                result.insert(result.begin(),tmp.begin(),tmp.end());
            }
             if(div % divide !=0){
                result.insert(result.begin(),jumps[tag]);
            }
            num = div;
        }
        string final = "";
        for(int i=0;i!=result.size()-1;i++){
            final += result[i] + " ";
        }
        final += result[result.size()-1];
        return final;
    }
    
    vector<string> say(int num){
        vector<string> tmp;
        int a = num / 100;
        if(a != 0){
            tmp.push_back(ones[a]);
            tmp.push_back("Hundred");
        }
        int b = num % 100;
        int c = b / 10;
        int d = b % 10;
        if(c == 1){
            tmp.push_back(teens[d]);
        }
        else{
            if(c>=2){
                tmp.push_back(tys[c]);
            }
            if(d>=1){
                tmp.push_back(ones[d]);
            }
        }
        return tmp;
    }
};
