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
	double progres;
};

void print_list(students* list, int number, ofstream& output);
void create(students list[], int number_of_students);
string get_name(string gender);

int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	students list[100];
	int number_of_students = 1 + rand() % 100;
	create(list, number_of_students);
	ofstream output("output.txt");
	for (int i = 0; i < number_of_students; i++)
	{
		print_list(list, i, output);
	}
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
			(list + i)->age = 17 + rand() % 7;
			(list + i)->course = 1 + rand() % 4;
			(list + i)->progres = 1 + rand() % 10;
			(list + i)->full_name = get_name("b");
		}
		else
		{
			(list + i)->gender = "Девушка";
			(list + i)->age = 17 + rand() % 7;
			(list + i)->course = 1 + rand() % 4;
			(list + i)->progres = 1 + rand() % 10;
			(list + i)->full_name = get_name("g");
		}
	}
}

void print_list(students* list, int number, ofstream& output)
{
	output << setw(35) << (list + number)->full_name << setw(10) << (list + number)->age << setw(10) << (list + number)->gender << setw(10) << (list + number)->course << setw(10) << (list + number)->progres << endl;
}