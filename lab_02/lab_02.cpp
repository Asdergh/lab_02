#include <iostream>
#include<vector>
#include<math.h>
#include<string>

void range_based_print(std::vector<std::string>, std::vector<int>);
void iterator_based_print(std::vector<std::string>, std::vector<int>);
void simple_cicle_base_print(std::vector<std::string>, std::vector<int>);
void mode_value(std::vector<std::string>, std::vector<int>);
float median_value(std::vector<int>);
float mean_value(std::vector<int>);

float mean_value(std::vector<int> marks_list)
{
	int seq_sum;
	float seq_mean;
	for (int mark_index{ 0 }; mark_index < marks_list.size(); mark_index++)
	{
		seq_sum = seq_sum + marks_list.at(mark_index);
	}
	seq_mean = static_cast<float>(seq_sum) / static_cast<float>(marks_list.size());
	return seq_mean;
}

void mode_value(std::vector<std::string> students_list, std::vector<int> marks_list)
{
	std::vector<int> unique_marks_list;
	std::vector<int> mode_value_for_each;
	int max_mode_value{ 0 };
	int max_mode_value_index;
	int max_mode_value_person_index;

	for (int mark_index{ 0 }; mark_index < marks_list.size(); mark_index++)
	{
		int curent_mark = marks_list.at(mark_index);
		if (unique_marks_list.size() != 0)
		{
			for (int unique_mark_index{ 0 }; unique_mark_index < unique_marks_list.size(); unique_mark_index++)
			{
				if (curent_mark != unique_marks_list.at(unique_mark_index))
				{
					unique_marks_list.push_back(curent_mark);
				}
				else 
				{
					; 
				}
			}
		}
		else
		{
			unique_marks_list.push_back(curent_mark);
		}
	}
	for (int mode_i{ 0 }; mode_i < unique_marks_list.size(); mode_i++)
	{
		int curent_mark{ unique_marks_list.at(mode_i) };
		int curent_mark_mode;
		for (int mode_j{ 0 }; mode_j < marks_list.size(); mode_j++)
		{
			if (marks_list.at(mode_j) == curent_mark)
			{
				curent_mark_mode++;
			}
			else
			{
				;
			}
		}
		mode_value_for_each.push_back(curent_mark_mode);
	}
	for (int mode_i{ 0 }; mode_i < mode_value_for_each.size(); mode_i++)
	{
		if (mode_value_for_each.at(mode_i) > max_mode_value)
		{
			max_mode_value = mode_value_for_each.at(mode_i);
			max_mode_value_index = mode_i;
		}
		else
		{
			;
		}
	}
	for (int mark_i{ 0 }; mark_i < marks_list.size(); mark_i++)
	{
		if (unique_marks_list.at(max_mode_value_index) == marks_list.at(mark_i)) {

			std::cout << "\nMODE VALUE\t" << max_mode_value << "\nPERSON WITH MODE VALUE\t" << students_list.at(mark_i);
		}
	}
}

float median_value(std::vector<int> marks_list)
{
	std::vector<int> copy_marks_list = marks_list;
	int index_of_median_item;
	int median_item;

	for (int index_i{ 0 }; index_i < copy_marks_list.size(); index_i) 
	{
		for (int index_j{ index_i + 1 }; index_j + 1 < copy_marks_list.size(); index_j++)
		{
			if (copy_marks_list.at(index_i) > copy_marks_list.at(index_j))
			{
				int tmp_placeholder = copy_marks_list.at(index_i);
				copy_marks_list.at(index_i) = copy_marks_list.at(index_j);
				copy_marks_list.at(index_j) = tmp_placeholder;
			}
			else
			{
				;
			}
		}
	}

	if (copy_marks_list.size() % 2 == 0)
	{
		index_of_median_item = copy_marks_list.size() / 2;
	}
	else
	{
		index_of_median_item = (copy_marks_list.size() + 1) / 2; 
	}
	median_item = copy_marks_list.at(index_of_median_item);

	return median_item;

}

/*void iterator_based_print(std::vector<std::string> names_list, std::vector<int> marks_list)
{
	auto  iter_start = names_list.begin();
	std::vector<std::string>::iterator iter_end = names_list.end();

	while (iter_start != iter_end)
	{
		std::cout << "\n=======\n" << "Person:\t" << names_list[iter_start] << "\Mark:\t" << marks_list[iter_start] << "\n=======\n";
		++iter_start;
	}
}
*/
void range_based_print(std::vector<std::string> names_list, std::vector<int> marks_list)
{
	int range_list[10];

	for (int iter{ 0 }; iter < names_list.size(); iter++) 
	{ 
		range_list[iter] = iter; 
	}

	for (int iter : range_list) 
	{
		std::cout << "\n=======\n" << "Person:\t" << names_list.at(iter) << "\Mark:\t" << marks_list.at(iter) << "\n=======\n";
	}
}
void simple_cicle_based_print(std::vector<std::string> names_list, std::vector<int> marks_list)
{
	for (int print_index{ 0 }; print_index < names_list.size(); print_index++)
	{
		std::cout << "\n=======\n" << "Person:\t" << names_list.at(print_index) << "\Mark:\t" << marks_list.at(print_index) << "\n=======\n";
	}

}

int main() {

	int option_choose;

	std::cout << "\n==================================\n" << "\nвыберете одну из опций инилциализации информационной выборки:\n" << "\n==================================\n"
		<< "\n1) создание деофлтной выборки (то есть данные будут введены по умолчанию)\n"
		<< "\n2) осздания рандомной выборки основанной на случайном распределении оценок\n"
		<< "\n3) создание выборки основыяваяь на консольном вводе\n";
	std::cin >> option_choose;
	std::vector<std::string> names_list{ "Arina", "Alexey", "Irina", "Igore", "Liontiy", "Matvey", "Nasty", "Lera", "Ignat", "Leonid" };
	std::vector<int> marks_list{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	switch (option_choose)
	{
	case 1:
	{
		///std::cout << "\n[TEST FIRST PRINT FUNCTION]!!!\n";
		///iterator_based_print(names_list, marks_list);
		std::cout << "\n[TEST SECOND PRINT FUNCTION]!!!\n";
		range_based_print(names_list, marks_list);
		std::cout << "\n[TEST THRED PRINT FUNCTOIN]!!!\n";
		simple_cicle_based_print(names_list, marks_list);
	}

	case 2:
	{

		int students_count;
		int marked_students{ 0 };
		std::vector<int> previouse_students_vector;
		std::cout << "\n\t\tENTER COUNT OF STUDETS THAT YOU WANT TO MARK:\n";
		std::cin >> students_count;

		while (marked_students != students_count)
		{
			int student_index = static_cast<int>(rand() % 10);

			if (previouse_students_vector.size() != 0)
			{
				std::cout << "\nEXECPTION WORKED!!!\n";
				for (int student{ 0 }; student < previouse_students_vector.size(); student++)
				{
					if (previouse_students_vector.at(student) == marks_list.at(student_index))
					{
						;
					}
					else
					{
						marks_list.at(student_index) = static_cast<int>(rand() % 100);
						marked_students++;
					}
				}
			}
			else
			{
				marks_list.at(student_index) = static_cast<int>(rand() % 100);
				previouse_students_vector.push_back(student_index);
				marked_students++;
			}
		}

		///std::cout << "\n[TEST FIRST PRINT FUNCTION]!!!\n";
		///iterator_based_print(names_list, marks_list);
		std::cout << "\n[TEST SECOND PRINT FUNCTION]!!!\n";
		range_based_print(names_list, marks_list);
		std::cout << "\n[TEST THRED PRINT FUNCTOIN]!!!\n";
		simple_cicle_based_print(names_list, marks_list);
	}
	case 3:
			
		std::string person_name;
		int person_mark;
		int curent_index;
		for (int person_index{ 0 }; person_index < names_list.size(); person_index++) std::cout << "\t" << names_list.at(person_index);
		for (;;)
		{
			std::cout << "\nENTER PERSON NAME\n";
			std::cin >> person_name;
			std::cout << "\nENTER PERSON MARK\n";
			std::cin >> person_mark;

			if (person_name == "stop") break;

			for (int index_i{ 0 }; index_i < names_list.size(); index_i++)
			{
				if (names_list.at(index_i) == person_name) marks_list.at(index_i) = person_mark;

			}

		}

		///std::cout << "\n[TEST FIRST PRINT FUNCTION]!!!\n";
		///iterator_based_print(names_list, marks_list);
		std::cout << "\n[TEST SECOND PRINT FUNCTION]!!!\n";
		range_based_print(names_list, marks_list);
		std::cout << "\n[TEST THRED PRINT FUNCTOIN]!!!\n";
		simple_cicle_based_print(names_list, marks_list);
	}

	


}
