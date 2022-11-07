// Kurs.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "func.h"
int MenuNumber=1;
void Menu()
{
	cout << "Выберите действия:" << endl;
	cout << " Выход из программы (0)"<< endl;
	cout << " Добавление маршрута (1)" << endl;
	cout << " Показать все маршруты (2)" << endl;
	cout << " Найти маршрут по его номеру (3)" << endl;
	cout << " Редактировать маршрут (4)" << endl;
	cout << " Удалить маршрут (5)" << endl;
	cout << " Отсортировать структуру по номеру маршрута (6)" << endl;
	cout << " Выгрузить маршруты в базу данных (7)" << endl;
	cout << " Загрузить маршруты из базы данных (8)" << endl;
	cout << " НАШЕ ДЕЙСТВИЕ ПОД НОМЕРОМ: ";
	while (!(cin >> MenuNumber) || (cin.peek() != '\n') || (MenuNumber != round(MenuNumber)) || (MenuNumber < 0) || (MenuNumber > 8 ))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Некорректный ввод" << endl;
		cout << " НАШЕ ДЕЙСТВИЕ ПОД НОМЕРОМ: ";
	}
	cout << endl;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	while (MenuNumber != 0)
	{
		Menu();
		if (MenuNumber == 1)
		{
			Menu1();
			/*system("cls");*/
		}

		if (MenuNumber == 2)
		{
			Menu2();
		}

		if (MenuNumber == 3)
		{
			Menu3();
		}

		if (MenuNumber == 4)
		{
			Menu4();
		}

		if (MenuNumber == 5)
		{
			Menu5();
		}

		if (MenuNumber == 6)
		{
			Menu6();
		}

		if (MenuNumber == 7)
		{
			Menu7();
		}

		if (MenuNumber == 8)
		{
			Menu8();
		}

		cout << endl;
	}
	Menu0();
	cout << " Спасибо что воспользовались нашим приложением";
	return 0;
}