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

void write_list_bin(students* list, int number, ofstream& output);
void create(students list[], int number_of_students);
void read_file_to_list(string name, students list[], int number);
string get_name(string gender);

int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	students list[100];
	students bad_list[100];
	int number_of_students = 5;//1 + rand() % 100;
	create(list, number_of_students);
	ofstream all_students_bin("all_students.bin", ios::binary);
	for (int i = 0; i < number_of_students; i++)
	{
		write_list_bin(list, i, all_students_bin);
	}
	all_students_bin.close();
	ofstream bad_students_bin("bad_students.bin",ios::binary);
	int bad_number=0;
	for (int i = 0; i < number_of_students; i++)
	{
		if (list[i].progress < 4)
		{
			write_list_bin(list, i, bad_students_bin);
			bad_number++;
		}
	}
	bad_students_bin.close();
	read_file_to_list("bad_students.bin", bad_list, bad_number);
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

void write_list_bin(students* list, int number, ofstream& output)
{
	string name1, name2, name3;
	name2= (list + number)->name2;
	name1= (list + number)->name1;
	name3= (list + number)->name3;
	int age = (list + number)->age;
	string gender = (list + number)->gender;
	int course = (list + number)->course;
	double progress = (list + number)->progress;
	output.write(reinterpret_cast <char*> (&name2), sizeof(string));
	output.write(reinterpret_cast <char*> (&name1), sizeof(string));
	output.write(reinterpret_cast <char*> (&name3), sizeof(string));
	output.write(reinterpret_cast <char*> (&age), sizeof(int));
	output.write(reinterpret_cast <char*> (&gender), sizeof(string));
	output.write(reinterpret_cast <char*> (&course), sizeof(int));
	output.write(reinterpret_cast <char*> (&progress), sizeof(double));
}

void read_file_to_list(string name, students list[], int number)
{
	ifstream input(name,ios::binary);
	input.clear();
	string name1;
	string name2;
	string name3;
	int age;
	string gender;
	int course;
	double progress;
	for (int i = 0; i < number; i++)
	{
		input.read(reinterpret_cast <char*> (&name2), sizeof(string));
		input.read(reinterpret_cast <char*> (&name1), sizeof(string));
		input.read(reinterpret_cast <char*> (&name3), sizeof(string));
		input.read(reinterpret_cast <char*> (&age), sizeof(int));
		input.read(reinterpret_cast <char*> (&gender), sizeof(string));
		input.read(reinterpret_cast <char*> (&course), sizeof(int));
		input.read(reinterpret_cast <char*> (&progress), sizeof(double));
		(list + i)->name1 = name1;
		(list + i)->name2 = name2;
		(list + i)->name3 = name3;
		(list + i)->age = age;
		(list + i)->gender = gender;
		(list + i)->course = course;
		(list + i)->progress = progress;
	}
	input.close();
}