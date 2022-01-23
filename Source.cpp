#include <iostream>
#include "Mystring.h"

using namespace std;

int main()
{
	String d("Vladimir", 20);
	d.ShowInfo();

/*
	d.PrintLn();
	String e = d;
	e.String::ShowInfo();
	cout << e.GetCharAt(2) << endl;
	e.PrintLn();
	d.PrintLn();
	cout << String::GetText2();
	d.Print();
	cout << d.GetCharArray();
		
*/
/* +++++
	String other = { " KOCH" };
	d.Concat(other);
	d.Print();

	char ch[]{ " KOCH" };
	char* cha = &ch[0];
	d.Concat(cha);
	d.Print();

	int y = 12345;
	d.Concat(y);
	d.Print();

	double x = 12345.67;
	d.Concat(x);
	d.Print();

	d.GetLine();

	String a("Vlad");
	cout << d.CompareTo(a) << endl;

	char ch[]{ "Vladimir" };
	char* cha = &ch[0];
	cout << d.CompareTo(cha) << endl;

	String a("Vlad");
	cout << d.Contains(a) << endl;

	String a("mir");
	cout << d.EndsWith(a) << endl;

	String a("Vl");
	cout << d.StartsWith(a) << endl;

	String a("Vladimir");
	cout << d.Equals(a) << endl;
	cout << d.IndexOf('a') << endl;
	cout << d.LastIndexOf('p') << endl;
	String a("mir");
	cout << d.IndexOf(a) << endl;

	int y = 4;
	d.Remove(y);
	d.Print();

	int start = 2;
	int count = 3;
	d.Remove(start, count);
	d.Print();

	char R = 'i';
	char Z = 'o';
	d.Replace(R, Z);
	d.Print();

	String substr("dim");
	String rep("xxxxxxxxxxxxxxxxx");
	d.Replace(substr, rep);
	d.Print();

	d.String::ToLower();
	d.Print(); 

	d.String::ToUpper();
	d.Print();

	d.String::TrimStart();
	d.Print();

	d.String::TrimEnd();
	d.Print();
	
	d.String::Trim();
	d.Print();

	d.String::Reverse();
	d.Print();

	d.String::Shuffle();
	d.Print();

	d.String::RandomFill();
	d.Print();

	d.String::SortAZ();
	d.Print();

	d.String::SortZA();
	d.Print();

*/

//----;
char separator = '^';
int pieces = 3;
	
cout << d.String::Split(separator, pieces);
	


//cout << e.GetString();



/*

cout << a.GetString() << endl;
cout << b.GetString() << endl;
cout << c.GetString() << endl;
cout << "========================\n";
cout << b.GetString() << endl;
cout << b.GetLength() << endl;
cout << b.GetCapacity() << endl;
cout << "========================\n";
a.SetString("nice weather");
cout << a.GetString() << endl;
cout << a.GetLength() << endl;
cout << a.GetCapacity() << endl;
cout << "========================\n";
a.Clear();
cout << a.GetString() << endl;
cout << a.GetLength() << endl;
cout << a.GetCapacity() << endl;
cout << "========================\n";
a.ShrinkToFit();
cout << a.GetLength() << endl;
cout << a.GetCapacity() << endl;
*/
}