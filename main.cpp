#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <time.h>

using namespace std;

struct students
{
	string name1;
	string name2;
	string name3;
	int age;
	string gender;
	int course;
	double progress;
};

void print_list_txt(students* list, int number, ofstream& output);
void print_list_bin(students* list, int number, ofstream& output);
void create(students list[], int number_of_students);
void print_to_console(string name);
string get_name(string gender);

int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	students list[100];
	int number_of_students = 1 + rand() % 100;
	create(list, number_of_students);
	ofstream all_students_bin("all_students.bin", ios::binary);
	for (int i = 0; i < number_of_students; i++)
	{
		print_list_bin(list, i, all_students_bin);
	}
	all_students_bin.close();
	ofstream bad_students_txt("bad_students.txt");
	for (int i = 0; i < number_of_students; i++)
	{
		if (list[i].progress < 4)
		{
			print_list_txt(list, i, bad_students_txt);
		}
	}
	bad_students_txt.close();
	print_to_console("bad_students.txt");
	system("pause");
	return 0;
}

string get_name(string gender)
{
	ifstream name("name" + gender + ".txt");
	string result = "";
	int k = 1 + rand() % 40;
	for (int j = 0; j < k; j++)
	{
		name >> result;
	}
	return result;
}

void create(students list[], int number_of_students)
{
	for (int i = 0; i < number_of_students; i++)
	{
		if ((2 + rand()) % 2 == 0)
		{

			(list + i)->gender = "Парень";
			(list + i)->age = 17 + rand() % 4;
			(list + i)->course = (list + i)->age - 16;
			(list + i)->progress = 1 + rand() % 10;
			(list + i)->name1 = get_name("1b");
			(list + i)->name2 = get_name("2b");
			(list + i)->name3 = get_name("3b");
		}
		else
		{
			(list + i)->gender = "Девушка";
			(list + i)->age = 17 + rand() % 4;
			(list + i)->course = (list + i)->age - 16;
			(list + i)->progress = 1 + rand() % 10;
			(list + i)->name1 = get_name("1g");
			(list + i)->name2 = get_name("2g");
			(list + i)->name3 = get_name("3g");
		}
	}
}

void print_list_txt(students* list, int number, ofstream& output)
{
	output << setw(15) << (list + number)->name2;
	output << setw(15) << (list + number)->name1;
	output << setw(20) << (list + number)->name3;
	output << setw(5) << (list + number)->age;
	output << setw(10) << (list + number)->gender;
	output << setw(5) << (list + number)->course;
	output << setw(5) << (list + number)->progress;
	output << endl;
}

void print_list_bin(students* list, int number, ofstream& output)
{
	string name = (list + number)->name2;
	output.write(reinterpret_cast <char*> (&name), sizeof(string));
	name = (list + number)->name1;
	output.write(reinterpret_cast <char*> (&name), sizeof(string));
	name = (list + number)->name3;
	output.write(reinterpret_cast <char*> (&name), sizeof(string));
	int age = (list + number)->age;
	output.write(reinterpret_cast <char*> (&age), sizeof(int));
	string gender = (list + number)->gender;
	output.write(reinterpret_cast <char*> (&gender), sizeof(string));
	int course = (list + number)->course;
	output.write(reinterpret_cast <char*> (&course), sizeof(int));
	double progress = (list + number)->progress;
	output.write(reinterpret_cast <char*> (&progress), sizeof(double));
}

void print_to_console(string file_name)
{
	ifstream input(file_name);
	string name1, name2, name3;
	input >> name2;
	input >> name1;
	input >> name3;
	int age;
	input >> age;
	string gender;
	input>>gender;
	int course;
	input >> course;
	double progress;
	input >> progress;
	while (!input.eof())
	{
		cout << setw(15) << name2;
		cout << setw(15) << name1;
		cout << setw(20) << name3;
		cout << setw(5) << age;
		cout << setw(10) << gender;
		cout << setw(5) << course;
		cout << setw(5) << progress;
		cout << endl;
		input >> name2;
		input >> name1;
		input >> name3;
		input >> age;
		input >> gender;
		input >> course;
		input >> progress;
	}
	input.close();
}