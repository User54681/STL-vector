#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>

void menu(std::vector<int> vec);
void push_rand(std::vector<int> vec);
void find_index(std::vector<int> vec);
void del_dupl(std::vector<int> vec);

int main()
{
	setlocale(LC_ALL, "Rus");
	std::ifstream file("file.txt");

	if (!file.is_open()) {
		std::cout << "Файл не открылся" << "\n";
		return 0;
	}

    std::vector<int> vec((std::istream_iterator<int>(file)), std::istream_iterator<int>());
    menu(vec);
}

void menu(std::vector<int> vec) {
    unsigned choice = 0;
    while (choice != 7) {
        std::cout << "Выберите для дальнейшего действия: " << "\n";
        std::cout << "1 - Реверсировать вектор" << "\n";
        std::cout << "2 - Найти минимальный элемент" << "\n";
        std::cout << "3 - Удалить из вектора все четные элементы" << "\n";
        std::cout << "4 - Отсортировать вектор в убывающей или возрастающей последовательности" << "\n";
        std::cout << "5 - Вставить в вектор произвольный элемент" << "\n";
        std::cout << "6 - Определить индекс заданного элемента" << "\n";
        std::cout << "7 - Вывести вектор";
        std::cout << "8 - Выход из меню" << "\n";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::reverse(vec.begin(), vec.end());
            break;
        case 2:
            auto min_el = *std::min_element(vec.begin(), vec.end());
            std::cout << "Минимальный элемент: " << min_el << '\n';
            break;
        case 3:
            vec.erase(std::remove_if(vec.begin(), vec.end(), [](int x -> bool{ return x % 2 == 0; }), vec.end());
            break;
        case 4:
            std::sort(vec.begin(), vec.end());
            break;
        case 5:

            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        }
    }
}

void push_rand(std::vector<int> vec) {

}

void find_index(std::vector<int> vec) {

}

void del_dupl(std::vector<int> vec) {

}