#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>

void menu(std::vector<int> vec);

int main()
{
	setlocale(LC_ALL, "Rus");
    std::srand(std::time(nullptr));

    std::ofstream fiile("file.txt");
    if (!fiile.is_open()) {
        std::cout << "Файл не открылся" << "\n";
        return 0;
    }
    for (int i = 0; i < 25; ++i) {
        int random_number = std::rand() % 100;
        fiile << random_number << "\n";
    }
    fiile.close();

	std::ifstream file("file.txt");
	if (!file.is_open()) {
		std::cout << "Файл не открылся" << "\n";
		return 0;
	}
    std::vector<int> vec((std::istream_iterator<int>(file)), std::istream_iterator<int>());
    menu(vec);
    file.close();
}

void menu(std::vector<int> vec) {
    unsigned choice = 0;
    while (choice != 9) {
        std::cout << "Выберите для дальнейшего действия: " << "\n";
        std::cout << "1 - Реверсировать вектор" << "\n";
        std::cout << "2 - Найти минимальный элемент" << "\n";
        std::cout << "3 - Удалить из вектора все четные элементы" << "\n";
        std::cout << "4 - Отсортировать вектор в убывающей или возрастающей последовательности" << "\n";
        std::cout << "5 - Вставить в вектор произвольный элемент" << "\n";
        std::cout << "6 - Определить индекс заданного элемента" << "\n";
        std::cout << "7 - Удалить из вектора дублированные элементы." << "\n";
        std::cout << "8 - Вывести вектор" << "\n";
        std::cout << "9 - Выход из меню" << "\n";
        std::cin >> choice;

        int elementToInsert;
        int elementToFind;
        auto it = std::lower_bound(vec.begin(), vec.end(), elementToInsert);
        auto min_el = *std::min_element(vec.begin(), vec.end());
        auto index = std::find(vec.begin(), vec.end(), elementToFind) - vec.begin();
        switch (choice)
        {
        case 1:
            std::reverse(vec.begin(), vec.end());
            break;
        case 2:
            //auto min_el = *std::min_element(vec.begin(), vec.end());
            std::cout << "Минимальный элемент: " << min_el << '\n';
            break;
        case 3:
            //vec.erase(std::remove_if(vec.begin(), vec.end(), [](int x -> bool{ return x % 2 == 0; }), vec.end());
            vec.erase(std::remove_if(vec.begin(), vec.end(), [](int x){ return x % 2 == 0; }), vec.end());
            break;
        case 4:
            std::sort(vec.begin(), vec.end());
            break;
        case 5:
            std::cout << "Введите число, которое хотите добавить: " << "\n";
            std::cin >> elementToInsert;
            //int elementToInsert;
            //auto it = std::lower_bound(vec.begin(), vec.end(), elementToInsert);
            vec.insert(it, elementToInsert);
            break;
        case 6:
            //int elementToFind;
            std::cout << "Введите число, которое хотите найти: " << "\n";
            std::cin >> elementToInsert;
            // index = std::find(vec.begin(), vec.end(), elementToFind) - vec.begin();
            if (index >= vec.size()) {
                std::cout << "Элемент не найден.\n";
            }
            else {
                std::cout << "Индекс элемента: " << index << '\n';
            }
            break;
        case 7:
            std::sort(vec.begin(), vec.end());
            vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
            break;
        case 8:
            for (int n : vec) {
                std::cout << n << ' ';
            }
            std::cout << '\n';
            break;
        case 9:
            break;
        }
    }
}