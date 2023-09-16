#include <iostream>
using namespace std;
int length(char* buff) //Вспомогательная функция для посчета длины строк
{
	int len = 0;
	while (buff[len] != '\0')
		len++;
	return len;
}
class Foostring {
	char* buff;
public:
	Foostring(char* tbuff) {
		buff = tbuff;
	}
	~Foostring(){
		delete(buff);
	}
	void Show() {
    	cout << buff << endl;
    }
	char* GetString() {
    	return buff;
	}
	void add(Foostring str)
	{
	    char* str1 = buff;
    	char* str2 = str.GetString();
    	int len1 = length(str1);
    	int len2 = length(str2);
    	buff = NULL;
    	buff = new char[len1 + len2]; 
    	for (int i = 0; i < len1; i++) 
    		buff[i] = str1[i];
    	
    	for (int i = len1; i < len2 + len1; i++) 
			buff[i] = str2[i - len1];
      	
    	for (int i = len1 + len2; i < length(buff); i++) 
			buff[i] = '\0';
	}
};
int main()
{
	char* s;
	s = NULL;
	s = new char;
	cout << "Enter something: ";
	cin >> s;
	Foostring str(s);
	str.Show();
	s = new char;
	cout << "Enter something one more time: ";
	cin >> s;
	Foostring str1(s);
	str.add(str1);
	str.Show();
}
