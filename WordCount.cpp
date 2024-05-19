#include <iostream>  
#include <fstream>  
#include <string>  
#include <cctype> // 用于 isspace 函数  
  
using namespace std;
   
int main() {  
    string filename;  
    cout << "Enter the filename: ";  
    cin >> filename;  
  
    ifstream file(filename);  
    if (!file.is_open()) {  
        cerr << "Failed to open file." << endl;  
        return 1;  
    }  
  
    int charCount = 0;  
    int wordCount = 0;  
    bool inWord = true; // 用于判断是否在单词中  
  
    char ch;  
    while (file.get(ch)) {    
	    if (!isspace(ch) && ch != ',') { // 如果不是空格、制表符、换行符或逗号  
	        charCount++;    
	        if (!inWord) { // 如果之前不在单词中，现在进入了单词  
	            inWord = true;  
	            wordCount++;    
	        }    
	    } else { // 如果遇到了分隔符（空格、制表符、换行符或逗号）  
	        if (inWord) { // 如果之前在处理一个单词  
	            inWord = false;  
	        }  
	    }    
	} 
  
    // 处理文件末尾的情况，如果文件末尾是单词的一部分，则也需要计数  
    if (inWord) {  
        wordCount++;  
    }  
  
    file.close();  
  
    cout << "字符数: " << charCount << endl;  
    cout << "单词数: " << wordCount << endl;  
  
    return 0;  
}
