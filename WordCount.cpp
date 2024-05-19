#include <iostream>  
#include <fstream>  
#include <string>  
#include <cctype> // ���� isspace ����  
  
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
    bool inWord = true; // �����ж��Ƿ��ڵ�����  
  
    char ch;  
    while (file.get(ch)) {    
	    if (!isspace(ch) && ch != ',') { // ������ǿո��Ʊ�������з��򶺺�  
	        charCount++;    
	        if (!inWord) { // ���֮ǰ���ڵ����У����ڽ����˵���  
	            inWord = true;  
	            wordCount++;    
	        }    
	    } else { // ��������˷ָ������ո��Ʊ�������з��򶺺ţ�  
	        if (inWord) { // ���֮ǰ�ڴ���һ������  
	            inWord = false;  
	        }  
	    }    
	} 
  
    // �����ļ�ĩβ�����������ļ�ĩβ�ǵ��ʵ�һ���֣���Ҳ��Ҫ����  
    if (inWord) {  
        wordCount++;  
    }  
  
    file.close();  
  
    cout << "�ַ���: " << charCount << endl;  
    cout << "������: " << wordCount << endl;  
  
    return 0;  
}
