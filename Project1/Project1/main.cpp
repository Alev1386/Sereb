#include <iostream>
#include <string>
#include <cctype>


using namespace std;


//////////функция для замены переменных/////////////////////////////////
string replaceDigitsWithWords(const string& input) {
	string result;
	for (char ch : input) {
		if (isdigit(ch)) {  /////замена цифр на числительные 
			switch (ch) {
			case'0': result += "zero"; break;
			case'1': result += "one"; break;
			case'2': result += "two"; break;
			case'3': result += "three"; break;
			case'4': result += "four"; break;
			case'5': result += "five"; break;
			case'6': result += "six"; break;
			case'7': result += "seven"; break;
			case'8': result += "eight"; break;
			case'9': result += "nine"; break;
			} //switch
		}//if
		else {
			result += ch; ///добавляем символю, если это не цифра
		}//else
	}//for
	return result;
}
//////////////////////////////////////////////////////////////////////////////////

int main() {

	cout << "Enter sentence:\n ";

	string sentence;
	int maxDigitCount = 0;
	string maxSentence;

	//считываем предложения
	while (getline(cin, sentence)) {
		if (sentence.empty()) {
			break;
		}//if

		int count = 0;

		for (char ch : sentence) {
			if (isdigit(ch)) {
				count++;   //подсчитываем количетсво цифр в предложении
			}//if
		}//for

		//Находим предложение с максимальным кол-во цифр 
		if (count > maxDigitCount) {
			maxDigitCount = count;
			maxSentence = sentence;
		}//if
	}//while

	//Вывод результата
	if (maxDigitCount > 0) {
		cout << "most numbers in a sentence:\n" << replaceDigitsWithWords(maxSentence) << endl;
	}//if
	else {
		cout << "numbers don't appear" << endl;
	}//else

	return 0;
}//main