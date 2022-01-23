#pragma once
#include <iostream>
#include <cctype>
#include <ctime>
#include <algorithm>
using namespace std;

class String
{
	char* text = nullptr;
	unsigned int length = 0;
	unsigned int capacity = 80;

public:
	String();
	String(const char* text);
	explicit String(unsigned int capacity);
	String(const String& original);
	String(const char* text, unsigned int capacity);
	~String();
	// геттеры-сеттеры
	const char* const GetString() const;
	void SetString(const char* text, unsigned int capacity = 80);
	int GetLength() const;
	int GetCapacity() const;
	//	const char* const GetText2() const
	//	{
	//		return text2;
	//	}
	void Clear();
	void ShrinkToFit();
	char GetCharAt(unsigned int index);	// вернёт символ строки по указанной позиции
	void Print();	// показ строки на экран
	void PrintLn();	// показ строки на экран с переводом курсора на следующую строку
	void GetLine(); // ввод строки с клавиатуры
	const char* GetCharArray() const;  //??? возврат константного указателя на массив символов строки
	int CompareTo(String &other); // сравнение нашей строки с какой - то другой строкой. 
	int CompareTo(char* other);
	void Concat(String &str); // присоединить к нашей строке переданную строку
	void Concat(char* str);
	void Concat(int x);
	void Concat(double);	
	bool Contains(String &other); // проверить, содержится ли в нашей строке переданная подстрока(в любой позиции)
	bool EndsWith(String &other); // проверить, заканчивается ли наша строка текстом, который передан в параметре
	bool StartsWith(String &other);
	bool Equals(String &other); // проверить, соответствует ли лексикографически наша строка другой строке(аналогично CompareTo)
	int IndexOf(char symbol); // проверка на вхождение символа в строку, в результате работы возвращает индекс первого найденного символа(от начала строки); если ничего не найдено, возвращает - 1
	int LastIndexOf(char symbol); // проверка на вхождение символа в строку, в результате работы возвращает индекс последнего найденного символа(поиск с конца строки); если ничего не найдено, возвращает - 1
	int IndexOf(String &other); // проверка на вхождение подстроки в строку, в результате работы возвращает индекс начала вхождения; если ничего не найдено, возвращает - 1
	int LastIndexOf(String &other); // проверка на вхождение подстроки в строку, в результате работы возвращает индекс начала вхождения(но поиск идёт с конца строки); если ничего не найдено, возвращает - 1
	void Remove(int index); // удаление всех символов до конца строки, начиная от переданного индекса
	void Remove(int start, int count); // удаление count символов, начиная от индекса start
	void Replace(char R, char Z); // меняет в строке все найденные символы R на переданный символ Z
	void Replace(String substr, String rep); // заменяет найденную подстроку substr на строку rep
	String* Split(char separator, int& pieces); // делит нашу строку на кусочки, разделённые символом separator.Указатель на массив кусочков вернётся из функции.В pieces запишется количество получившихся кусочков
	String ToLower(); // привод к нижнему регистру(в том числе и для русского текста)
	String ToUpper(); // привод к верхнему регистру(в том числе и для русского текста)
	void Trim(); // убирает лишние пробелы в начале и в конце строки
	void TrimEnd();
	void TrimStart();
	void Reverse(); // переворачивание строки
	void SortAZ(); // сортировка всех символов строки в алфавитном порядке от А до Я
	void SortZA(); // сортировка всех символов строки в алфавитном порядке от Я до А
	void Shuffle(); // случайное перемешивание символов строки
	void RandomFill(); // заполнение строки случайными символами(на весь capacity)
	void ShowInfo() const;

	//	private:
	//		void Initialize(const char* str, int capacity = 80) {
	//			length = strlen(str);
	//			this->capacity = (capacity > length) ? capacity : length + 20;
	//			this->text = new char[this->capacity];
	//			strcpy_s(this->text, length + 1, str);
	//		}
//
};
