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
	// �������-�������
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
	char GetCharAt(unsigned int index);	// ����� ������ ������ �� ��������� �������
	void Print();	// ����� ������ �� �����
	void PrintLn();	// ����� ������ �� ����� � ��������� ������� �� ��������� ������
	void GetLine(); // ���� ������ � ����������
	const char* GetCharArray() const;  //??? ������� ������������ ��������� �� ������ �������� ������
	int CompareTo(String &other); // ��������� ����� ������ � ����� - �� ������ �������. 
	int CompareTo(char* other);
	void Concat(String &str); // ������������ � ����� ������ ���������� ������
	void Concat(char* str);
	void Concat(int x);
	void Concat(double);	
	bool Contains(String &other); // ���������, ���������� �� � ����� ������ ���������� ���������(� ����� �������)
	bool EndsWith(String &other); // ���������, ������������� �� ���� ������ �������, ������� ������� � ���������
	bool StartsWith(String &other);
	bool Equals(String &other); // ���������, ������������� �� ����������������� ���� ������ ������ ������(���������� CompareTo)
	int IndexOf(char symbol); // �������� �� ��������� ������� � ������, � ���������� ������ ���������� ������ ������� ���������� �������(�� ������ ������); ���� ������ �� �������, ���������� - 1
	int LastIndexOf(char symbol); // �������� �� ��������� ������� � ������, � ���������� ������ ���������� ������ ���������� ���������� �������(����� � ����� ������); ���� ������ �� �������, ���������� - 1
	int IndexOf(String &other); // �������� �� ��������� ��������� � ������, � ���������� ������ ���������� ������ ������ ���������; ���� ������ �� �������, ���������� - 1
	int LastIndexOf(String &other); // �������� �� ��������� ��������� � ������, � ���������� ������ ���������� ������ ������ ���������(�� ����� ��� � ����� ������); ���� ������ �� �������, ���������� - 1
	void Remove(int index); // �������� ���� �������� �� ����� ������, ������� �� ����������� �������
	void Remove(int start, int count); // �������� count ��������, ������� �� ������� start
	void Replace(char R, char Z); // ������ � ������ ��� ��������� ������� R �� ���������� ������ Z
	void Replace(String substr, String rep); // �������� ��������� ��������� substr �� ������ rep
	String* Split(char separator, int& pieces); // ����� ���� ������ �� �������, ���������� �������� separator.��������� �� ������ �������� ������� �� �������.� pieces ��������� ���������� ������������ ��������
	String ToLower(); // ������ � ������� ��������(� ��� ����� � ��� �������� ������)
	String ToUpper(); // ������ � �������� ��������(� ��� ����� � ��� �������� ������)
	void Trim(); // ������� ������ ������� � ������ � � ����� ������
	void TrimEnd();
	void TrimStart();
	void Reverse(); // ��������������� ������
	void SortAZ(); // ���������� ���� �������� ������ � ���������� ������� �� � �� �
	void SortZA(); // ���������� ���� �������� ������ � ���������� ������� �� � �� �
	void Shuffle(); // ��������� ������������� �������� ������
	void RandomFill(); // ���������� ������ ���������� ���������(�� ���� capacity)
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
