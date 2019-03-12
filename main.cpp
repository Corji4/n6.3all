#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <time.h>

using namespace std;

struct students
{
	string full_name;
	int age;
	string gender;
	int course;
	double progress;
};

void print_list_txt(students* list, int number, ofstream& output);
void print_list_bin(students* list, int number, ofstream& output);
void create(students list[], int number_of_students);
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
	ofstream bad_txt("bad_students.txt");
	for (int i = 0; i < number_of_students; i++)
	{
		if (list[i].progress < 4)
		{
			print_list_txt(list, i, bad_txt);
		}
	}
	bad_txt.close();
	system("pause");
	return 0;
}

string get_name(string gender)
{
	ifstream name1("name1" + gender + ".txt");
	ifstream name2("name2" + gender + ".txt");
	ifstream name3("name3" + gender + ".txt");
	string n;
	string result = "";
	int k = rand() % 50;
	for (int j = 0; j < k; j++)
	{
		name2 >> n;
	}
	result += n;
	k = rand() % 50;
	for (int j = 0; j < k; j++)
	{
		name1 >> n;
	}
	result += " " + n;
	k = rand() % 10;
	for (int j = 0; j < k; j++)
	{
		name3 >> n;
	}
	result += " " + n;
	name1.close();
	name2.close();
	name3.close();
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
			(list + i)->full_name = get_name("b");
		}
		else
		{
			(list + i)->gender = "Девушка";
			(list + i)->age = 17 + rand() % 4;
			(list + i)->course = (list + i)->age - 16;
			(list + i)->progress = 1 + rand() % 10;
			(list + i)->full_name = get_name("g");
		}
	}
}

void print_list_txt(students* list, int number, ofstream& output)
{
	output << setw(35) << (list + number)->full_name << setw(10) << (list + number)->age << setw(10) << (list + number)->gender << setw(10) << (list + number)->course << setw(10) << (list + number)->progress << endl;
}

void print_list_bin(students* list, int number, ofstream& output)
{
	string name = (list + number)->full_name;
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