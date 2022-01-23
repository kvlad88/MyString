
#include "Mystring.h"



String::String() : String("", 80) {}

String::String(const char* text) : String(text, 80) {}

String::String(unsigned int capacity) : String("", capacity) {}

String::String(const String& original) : String(original.text, original.capacity) {}

String::String(const char* text, unsigned int capacity)
{
	SetString(text, capacity);
}

String::~String()
{
	if (text != nullptr)
	{
		delete[] text;
		text = nullptr;
	}
}

// геттеры-сеттеры
const char* const String::GetString() const
{
	return text;
}

void String::SetString(const char* text, unsigned int capacity)
{
	length = strlen(text);

	if (capacity <= length)
		capacity = length + 1;
	this->capacity = capacity;

	delete[] this->text;
	this->text = new char[capacity];
	strcpy_s(this->text, capacity, text);
}

int String::GetLength() const
{
	return length;
}

int String::GetCapacity() const
{
	return capacity;
}

void String::Clear()
{
	text[0] = 0;
	length = 0;
}

void String::ShrinkToFit()
{
	if (length + 1 <= capacity)
	{
		return;
	}

	capacity = length + 1;
	char* temp = new char[capacity];
	strcpy_s(temp, capacity, text);
	delete[] text;
	text = temp;
}

char String::GetCharAt(unsigned int index)	// вернёт символ строки по указанной позиции
{
	char temp = text[index];
	return temp;
}

void String::Print()	// показ строки на экран
{
	cout << this->text;
	cout << endl;
}

void String::PrintLn()	// показ строки на экран с переводом курсора на следующую строку
{
	int k = 0;
	if (length > 80)
	{
		while (length > 80)
		{
			for (int i = 0; i < 80; i++)
			{
				cout << this->text[k + i];
			}
			k += 80;
			length -= 80;
			cout << endl;
		}
		for (int i = 0; i < length; i++)
		{
			cout << this->text[k + i];
		}
		cout << endl;
	}
	else
	{
		for (int i = 0; i < length; i++)
		{
			cout << this->text[i];
		}
		cout << endl;
	}
}

void String::GetLine() // ввод строки с клавиатуры
{
	if (this->text != 0)
	{
		delete[] this->text;
	}

	char* temp = new char[capacity];
	cout << "Enter the string:   ";
	cin >> temp;

	int othelength = strlen(temp);
	capacity = othelength + 1;
	this->text = temp;
	strcpy_s(this->text, capacity, text);
}

const char* String::GetCharArray() const  //??? возврат константного указателя на массив символов строки
{
	char* const ptext = &text[0];
	return ptext;
}

int String::CompareTo(String& other) // сравнение нашей строки с какой - то другой строкой. 		  //Добавить версию int CompareTo(char*)
{
	if (this->length != other.length)
	{
		return -1;
	}

	for (int i = 0; i < length; i++)
	{
		if (this->text[i] != other.text[i])
		{
			return -1;
		}
	}
	return 1;
}

int String::CompareTo(char* other) // сравнение нашей строки с какой - то другой строкой версию int CompareTo(char*)
{
	int othelength = strlen(other);
	if (this->length != othelength)
	{
		return -1;
	}

	for (int i = 0; i < length; i++)
	{
		if (text[i] != other[i])
		{
			return -1;
		}
	}
	return 1;
}

void String::Concat(String& other) //??? присоединить к нашей строке переданную строку
{
	char* temp = new char[capacity];
	capacity = strlen(text) + strlen(other.text) + 1;
	strcpy_s(temp, capacity, this->text);
	strcat_s(temp, capacity, other.text);
	temp[capacity] = '\0';
	delete[] this->text;
	this->text = temp;
	strcpy_s(this->text, capacity, text);
}

void String::Concat(char* str) // запись  в конец строки+++
{
	char* temp = new char[capacity];
	capacity = strlen(this->text) + strlen(str) + 1;
	strcpy_s(temp, capacity, this->text);
	strcat_s(temp, capacity, str);
	temp[capacity] = '\0';
	delete[] this->text;
	this->text = temp;
	strcpy_s(this->text, capacity, text);
}

void String::Concat(int value) // запись числа в конец строки+++
{
	int r = 0;
	char* tempchar = new char[r];
	int temp = value;


	while (temp != 0)
	{
		temp /= 10;
		r++;
	}

	int* array = new int[r];
	for (int i = r - 1; i >= 0; i--) {
		array[i] = value % 10;
		value /= 10;

		switch (array[i])
		{
		case 0: tempchar[i] = { '0' }; break;
		case 1: tempchar[i] = { '1' }; break;
		case 2: tempchar[i] = { '2' }; break;
		case 3: tempchar[i] = { '3' }; break;
		case 4: tempchar[i] = { '4' }; break;
		case 5: tempchar[i] = { '5' }; break;
		case 6: tempchar[i] = { '6' }; break;
		case 7: tempchar[i] = { '7' }; break;
		case 8: tempchar[i] = { '8' }; break;
		case 9: tempchar[i] = { '9' }; break;
		default: break;
		}
	}
	tempchar[r] = '\0';

	String::Concat(tempchar);
}

void String::Concat(double value) // запись числа в конец строки+++
{
	{
		int r = 0;
		char* tempchar = new char[r];
		int temp = value * 100; // точность, знаков после зпятой

		while (temp != 0)
		{
			temp /= 10;
			r++;
		}

		r++;
		temp = value * 100;;
		int* array = new int[r];
		for (int i = r - 1; i >= 0; i--)
		{
			if (i == r - 3)
			{
				tempchar[i] = { '.' };
			}
			else
			{
				array[i] = temp % 10;
				temp /= 10;
				switch (array[i])
				{
				case 0: tempchar[i] = { '0' }; break;
				case 1: tempchar[i] = { '1' }; break;
				case 2: tempchar[i] = { '2' }; break;
				case 3: tempchar[i] = { '3' }; break;
				case 4: tempchar[i] = { '4' }; break;
				case 5: tempchar[i] = { '5' }; break;
				case 6: tempchar[i] = { '6' }; break;
				case 7: tempchar[i] = { '7' }; break;
				case 8: tempchar[i] = { '8' }; break;
				case 9: tempchar[i] = { '9' }; break;
				default: break;
				}
			}
		}
		tempchar[r] = '\0';
		String::Concat(tempchar);
	}
}

bool String::Contains(String& other) // проверить, содержится ли в нашей строке переданная подстрока(в любой позиции)
{
	if (other.length > this->length)
	{
		throw "Input Error";
	}

	int k = 0; // контроль совпадений
	int t = 1;
	for (int i = 0; i < this->length; i++)
	{
		k = i;
		t = 1;
		for (int j = 0; j < other.length; j++)
		{
			if (this->text[k] == other.text[j])
			{
				if (t == other.length)
				{
					return 1;
				}
				k++;
				t++;
			}
		}
	}
	return 0;
}

bool String::EndsWith(String& other) // проверить, заканчивается ли наша строка текстом, 
							  //который передан в параметре
{
	if (other.length > this->length)
	{
		throw "Input Error";
	}

	int k = 0; // контроль совпадений
	int t = 1;
	for (int i = this->length - other.length; i < this->length; i++)
	{
		k = i;
		t = 1;
		for (int j = 0; j < other.length; j++)
		{
			if (this->text[k] == other.text[j])
			{
				if (t == other.length)
				{
					return 1;
				}
				k++;
				t++;
			}
		}
	}
	return 0;
}

bool String::StartsWith(String& other)
{
	if (other.length > this->length)
	{
		throw "Input Error";
	}

	// контроль совпадений
	int t = 1;

	for (int j = 0; j < other.length; j++)
	{
		if (this->text[j] == other.text[j])
		{
			if (t == other.length)
			{
				return 1;
			}
			t++;
		}
	}
	return 0;
}

bool String::Equals(String& other) // проверить, соответствует ли лексикографически наша строка другой строке(аналогично CompareTo)
{
	if (this->length != other.length)
	{
		return 0;
	}

	for (int i = 0; i < length; i++)
	{
		if (text[i] != other.text[i])
		{
			return 0;
		}
	}
	return 1;
}
int String::IndexOf(char symbol) // проверка на вхождение символа в строку, в результате работы возвращает индекс первого найденного символа(от начала строки); если ничего не найдено, возвращает - 1
{
	for (int j = 0; j < this->length; j++)
	{
		if (this->text[j] == symbol)
		{
			return j;
		}
	}
	return -1;
}

int String::LastIndexOf(char symbol) // проверка на вхождение символа в строку, в результате работы возвращает индекс последнего найденного символа(поиск с конца строки); если ничего не найдено, возвращает - 1
{
	int t = -1;
	for (int j = this->length - 1; j >= 0; j--)
	{
		if (this->text[j] == symbol)
		{
			t = j;
		}
	}
	return t;
}

int String::IndexOf(String& other) // проверка на вхождение подстроки в строку, в результате работы возвращает индекс начала вхождения; если ничего не найдено, возвращает - 1
{
	if (other.length > this->length)
	{
		throw "Input Error";
	}

	int k = 0; // контроль совпадений
	int t;
	for (int i = 0; i < this->length; i++)
	{
		k = i;
		t = 1;
		for (int j = 0; j < other.length; j++)
		{
			if (this->text[k] == other.text[j])
			{
				if (t == other.length)
				{
					return i;
				}
				k++;
				t++;
			}
		}
	}
	return -1;
}

int String::LastIndexOf(String& other) // проверка на вхождение подстроки в строку, в результате работы возвращает индекс начала вхождения(но поиск идёт с конца строки); если ничего не найдено, возвращает - 1
{
	if (other.length > this->length)
	{
		throw "Input Error";
	}

	int k = 0; // контроль совпадений
	int t;
	for (int i = this->length - 1; i >= 0; i--)
	{
		k = i;
		t = 1;
		for (int j = other.length - 1; j >= 0; j--)
		{
			if (this->text[k] == other.text[j])
			{
				if (t == other.length)
				{
					return i;
				}
				k--;
				t++;
			}
		}
	}
	return -1;
}

void String::Remove(int index) // удаление всех символов до конца строки, начиная от переданного индекса
{
	this->capacity = index;
	this->text[this->capacity] = '\0';
}

void String::Remove(int start, int count) // удаление count символов, начиная от индекса start
{
	if (start + count + 1 > this->length)
	{
		throw "Input Error";
	}

	for (int i = start; i < this->length; i++)
	{
		this->text[i] = this->text[i + count];
	}
	this->text[this->capacity - count] = '\0';
}

void String::Replace(char R, char Z) // меняет в строке все найденные символы R на переданный символ Z
{
	for (int i = 0; i < this->length; i++)
	{
		if (this->text[i] == R)	this->text[i] = Z;

	}
}

void String::Replace(String substr, String rep) // заменяет найденную подстроку substr 
												//?на строку rep - произвольной длины
{
	char* temp = new char[capacity];
	capacity = this->length - substr.length + rep.length;
	this->capacity = capacity;

	if (substr.length > this->length)
	{
		throw "Input Error";
	}

	int k = 0;
	int t;
	for (int i = 0; i < this->length; i++)
	{
		k = i;
		t = 1;
		for (int j = 0; j < substr.length; j++)
		{
			if (this->text[k] == substr.text[j])
			{
				if (t == substr.length)
				{
					for (int x = 0; x <= substr.length; x++)
					{
						temp[x] = this->text[x];
					}

					int y = 0;
					for (int x = i; x < i + rep.length; x++)
					{
						temp[x] = rep.text[y];
						y++;
					}

					y = 0;
					for (int x = i + substr.length; x < capacity; x++)
					{
						temp[i + rep.length + y] = this->text[x];
						y++;
					}
					temp[capacity] = '\0';
					delete[] this->text;
					this->text = temp;
				}
				k++;
				t++;
			}
		}
	}
}

String* String::Split(char separator, int& pieces) //--------?????
// делит нашу строку на кусочки, разделённые символом separator.
//Указатель на массив кусочков вернётся из функции.
//В pieces запишется количество получившихся кусочков
{
	String* sep = new String[capacity];
	char* temp = new char[capacity];
	int k = this->length / pieces;	
	int y = 0;
	int f = 1;

	for (int x = 0; x <= pieces + 1; x++)
	{
		for (int i = 0; i < k; i++)
		{
			temp[i] = this->text[i + k * y];			
		}
		temp[k * f] = '\0';		
		sep[x] = temp;
		temp[0] = separator;
		temp[1] = '\0';
		sep[x + f] = temp;

		y++;
		f++;
	}
	
return sep;
}

String String::ToLower() // привод к нижнему регистру(в том числе и для русского текста)
{
	for (int i = 0; i < length; i++)
	{
		this->text[i] = tolower(this->text[i]);
	}

	return this->text;
}
String String::ToUpper() // привод к верхнему регистру(в том числе и для русского текста)
{
	for (int i = 0; i < length; i++)
	{
		this->text[i] = towupper(this->text[i]);
	}
	return this->text;
}

void String::Trim() // убирает лишние пробелы в начале и в конце строки
{
	char* temp = new char[capacity];
	int t = 0;
	int k = this->length - 1;
	while (this->text[k] == ' ')
	{
		k--;
	}

	while (this->text[t] == ' ')
	{
		t++;
	}

	for (int i = 0; i < this->length; i++)
	{
		temp[i] = this->text[i + t];
	}

	temp[this->length - k + 1] = '\0';
	delete[] this->text;
	this->text = temp;
}

void String::TrimEnd()
{
	int k = this->length - 1;
	while (this->text[k] == ' ')
	{
		k--;
	}
	this->text[++k] = '\0';
	cout << k;
}

void String::TrimStart()
{
	char* temp = new char[capacity];

	int k = 0;
	while (this->text[k] == ' ')
	{
		k++;
	}

	for (int i = 0; i < this->length; i++)
	{
		temp[i] = this->text[i + k];
	}

	temp[this->length - k] = '\0';
	delete[] this->text;
	this->text = temp;
}

void String::Reverse() // переворачивание строки
{
	char* temp = new char[capacity];

	for (int i = 0; i < this->length; i++)
	{
		temp[i] = this->text[this->length - i - 1];
	}

	temp[this->length] = '\0';
	delete[] this->text;
	this->text = temp;
}

void String::SortAZ() // сортировка всех символов строки в алфавитном порядке от А до Я
{
	sort(this->text, this->text + length);
}

void String::SortZA() // сортировка всех символов строки в алфавитном порядке от Я до А
{
	sort(this->text, this->text + length);

	char* temp = new char[capacity];

	for (int i = 0; i < this->length; i++)
	{
		temp[i] = this->text[this->length - i - 1];
	}

	temp[this->length] = '\0';
	delete[] this->text;
	this->text = temp;
}

void String::Shuffle() // случайное перемешивание символов строки
{
	int index = 0;

	char* temp = new char[capacity];

	for (int i = 0; i < this->length; i++)
	{
		index = rand() % this->length;

		temp[i] = this->text[index];
	}

	temp[this->length] = '\0';
	delete[] this->text;
	this->text = temp;
}

void String::RandomFill() // заполнение строки случайными символами(на весь capacity)
{

	int index = 0;

	char* temp = new char[capacity];

	for (int i = 0; i < capacity; i++)
	{
		index = rand() % 255;

		temp[i] = char(index);
	}

	temp[this->length] = '\0';
	delete[] this->text;
	this->text = temp;
}

void String::ShowInfo() const
{
	cout << "Text: " << GetString() << endl;
	cout << "Length: " << GetLength() << endl;
	cout << "Capacity: " << GetCapacity() << endl;
}