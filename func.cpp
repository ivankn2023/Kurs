#include "func.h"

List::List()
{
	head = NULL;
}

int List:: num()
{
	int all = 0;
	marsh* current = head;
	while (current != NULL)
	{
		all++;
		current = current->next;
	}
	return all;
}

void List::sort_by_number() {
	marsh* b = head;
	marsh* e = nullptr;
	marsh* c = b;
	bool sort = false;
	while (!sort && c != e) {
		sort = true;
		while ((c = (c->next)) != e) {
			if (c->number < b->number) {
				swap(c->number, b->number);
				swap(c->finish, b->finish);
				swap(c->start, b->start);
				sort = false;
			}
		}
		b = b->next;
		c = b;
	}
}

void List::addNode(string s, string f, int n)
{
	marsh* nd = new marsh;
	nd->start = s;
	nd->finish = f;
	nd->number = n;
	nd->next = NULL;
	if (head == NULL)
		head = nd;
	else
	{
		marsh* current = head;
		while (current->next != NULL)
			current = current->next;
		current->next = nd;
	}
}

void List::del(int n)
{
	marsh* current = head;
	if (current->number == n) {
		head = current->next;
		delete current;
		return;
	}
	while (current != NULL)
	{
		if (n == current->next->number)
		{
			current->next = current->next->next;
			return;
		}
		current = current->next;
	}
}

void List::del_all()
{
	marsh* current = head;
	while (current->next)
	{
		current = current->next;
		head = current->next;
	}
	delete current;
}

void List::printList()
{
	marsh* current = head;
	while (current != NULL)
	{
		cout << current->number << endl;
		cout << current->start << endl;
		cout << current->finish << endl;
		current = current->next;
		cout << endl;
	}
}

int List::unic(int n)
{
	marsh* current = head;
	while (current != NULL)
	{
		if (current->number == n)
		{
			return 1;
		}
		current = current->next;
	}
	return 0;
}

int List::unic_answer(int n)
{
	marsh* current = head;
	while (current != NULL)
	{
		if (current->number == n)
		{
			cout << "Данный маршрут уже есть в базе" << endl;
			return 1;
		}
		current = current->next;
	}
	return 0;
}

void List::find(int& n)
{
	marsh* current = head;
	while (current != NULL)
	{
		if (current->number == n)
		{
			cout << "Маршрут найден" << endl;
			cout << "Его характеристики: " << endl;
			cout << current->number << endl;
			cout << current->start << endl;
			cout << current->finish << endl;
			return;
		}
		current = current->next;
	}
	cout << "Такой маршрут не найден" << endl;
	n = -5;
}

void List::red1(int n, int n1)
{
	marsh* current = head;
	while (current != NULL)
	{
		if (current->number == n)
		{
			current->number = n1;
			cout << "Ваш маршрут изменён, теперь он представляет собой:" << endl;
			cout << current->number << endl;
			cout << current->start << endl;
			cout << current->finish << endl;
			return;
		}
		current = current->next;
	}
}

void List::red2(int n, string s)
{
	marsh* current = head;
	while (current != NULL)
	{
		if (current->number == n)
		{
			current->start = s;
			cout << "Ваш маршрут изменён, теперь он представляет собой:" << endl;
			cout << current->number << endl;
			cout << current->start << endl;
			cout << current->finish << endl;
			return;
		}
		current = current->next;
	}
}

void List::red3(int n, string f)
{
	marsh* current = head;
	while (current != NULL)
	{
		if (current->number == n)
		{
			current->finish = f;
			cout << "Ваш маршрут изменён, теперь он представляет собой:" << endl;
			cout << current->number << endl;
			cout << current->start << endl;
			cout << current->finish << endl;
			return;
		}
		current = current->next;
	}
}

void List::stream()
{
	ofstream out("baza.txt");
	if (!out)
	{
		cout << "Ошибка открытия файла для выгрузки" << endl;
		cout << "Мы создали файл и выгрузили всё содержимое туда" << endl;
	}

	marsh* current = head;
	while (current != NULL)
	{
		out << current->number << endl;
		out << current->start << endl;
		out << current->finish;
		current = current->next;
		if (current != NULL) out << endl;
	}
	out.close();
}

void List::read()
{
	string st, fi;
	int num = 0;
	setlocale(LC_ALL, "RUS");
	ifstream in("baza.txt");
	while (!in.eof()) {
		in >> num;
		if (!(in >> st))
		{
			cout << "Ошибка при чтении, возможно что-то не записалось" << endl;
			return;
		}
		if (!(in >> fi))
		{
			cout << "Ошибка при чтении, возможно что-то не записалось" << endl;
			return;
		}
		else {
			addNode(st, fi, num);
		}
	}
	cout << "Данные из базы теперь в вашем распоряжении" << endl;
}


string start, finish;
int number;
List k;
int find_number;
int red_number;
string red;
int men7 = 0;
int deletik = 0;

void Menu0()
{
	k.del_all();
}

void Menu1()
{
	cout << "Введите -1, если хотите вернуться" << endl;
	cout << "Маршрут должен быть введён по следующему формату:" << endl;
	cout << "Номер маршрута" << endl;
	cout << "Начало маршрута" << endl;
	cout << "Конец маршрута" << endl;
	int tr = 1;

	while (tr != 0) {
		cout << "Введите номер марштрута: ";

		while (!(cin >> number) || (number != round(number)) || (number <= 0)||(number>999))
		{
			if (number == -1)
				return;
			cin.clear();
			while (cin.get() != '\n');
			cout << " Неправильный ввод, пожалуйста повторите" << endl;
			cout << "Введите номер марштрута: ";
		}

		if (k.unic(number)) {
			cout << "Маршрут с таким номером уже есть" << endl;
			continue;
		}
		else tr = 0;

		cout << "Введите -1, если хотите вернуться в основное меню" << endl;
		cout << "Введите начало маршрута: ";

		while (!(cin >> start) || (string_truble(start)))
		{
			if (start == "-1") return;
			cin.clear();
			while (cin.get() != '\n');
			cout << " Неправильный ввод, пожалуйста повторите" << endl;
			cout << "Введите начало маршрута: ";
		}

		cout << "Введите -1, если хотите вернуться в основное меню" << endl;
		cout << "Введите конец маршрута: ";

		while (!(cin >> finish) || (string_truble(finish)))
		{
			if (finish == "-1") return;
			cin.clear();
			while (cin.get() != '\n');
			cout << " Неправильный ввод, пожалуйста повторите" << endl;
			cout << "Введите конец маршрута: ";
		}

		cout << "Ваши данные успешно записаны" << endl;
	}
	k.addNode(start, finish, number);

	cout << "Желаете ли вы отсортировать ваш список данных" << endl;
	cout << "Введите -1, если хотите вернуться в основное меню" << endl;
	cout << "Введите 1, если хотите выполнить сортировку"<<endl;
	cout << "Введите ваш выбор: ";
		while (!(cin >> number) || (number!=1))
		{
			if (finish == "-1") return;
			cin.clear();
			while (cin.get() != '\n');
			cout << " Неправильный ввод, пожалуйста повторите" << endl;
			cout << "Введите ваш выбор: ";
		}

	k.sort_by_number();
	cout << "Данные отсортированы" << endl;
}

void Menu2()
{
	if (k.num())
	{
		cout << "Все маршруты, которые находятся в вашем распоряжении прямо сейчас: " << endl;
		k.printList();
	}
	else
	{
		cout << "Нет доступных маршрутов" << endl;
	}
}

void Menu3()
{
	int it3 = 0;

	if (!k.num())
	{
		cout << "Увы, но пока что нечего искать" << endl;
		return;
	}
	cout << "Введите -1, если хотите вернуться домой" << endl;
	cout << "Введите номер маршрута, который вы хотите найти: ";

	while (!(cin >> find_number) || (find_number != round(find_number)) || (find_number <= 0)||(find_number>999))
	{
		if (find_number == -1)
			return;
		cin.clear();
		while (cin.get() != '\n');
		cout << " Неправильный ввод, пожалуйста повторите" << endl;
		cout << "Введите номер марштрута: ";
	}

	k.find(find_number);

	if (find_number != -5)
	{
		cout << "Введите -1, если хотите вернуться домой" << endl;
		cout << "Введите 1, если хотите реадктировать данный маршрут" << endl;
		cout << "Введите 2, если хотите удалить данный маршрут" << endl;
		cout << "Введите ваш выбор: ";

		while (!(cin >> it3) || (it3 != round(it3)) || (it3 <= 0) || (it3 > 2))
		{
			if (it3 == -1)
				return;
			cin.clear();
			while (cin.get() != '\n');
			cout << " Неправильный ввод, пожалуйста повторите" << endl;
			cout << "Введите ваш выбор: ";
		}

		if (it3 == 1)
		{
			redact(find_number);
			return;
		}
		if (it3 == 2)
		{
			del_m(find_number);
			return;
		}
	}
}

void Menu4()
{
	if (!k.num())
	{
		cout << "Увы, но пока что нечего редактировать" << endl;
		return;
	}

	int tr4 = 1;
	while (tr4 != 0) {
		cout << "Введите -1, если хотите вернуться домой" << endl;
		cout << "Введите номер маршрута, который вы хотите найти:";
		find_number = 1;

		while (!(cin >> find_number) || (find_number != round(find_number)) || (find_number <= 0))
		{
			if (find_number == -1)
				return;
			cin.clear();
			while (cin.get() != '\n');
			cout << " Неправильный ввод, пожалуйста повторите" << endl;
			cout << "Введите номер марштрута: ";
		}

		tr4 = 0;
		k.find(find_number);
		if (find_number == -5) return;
		else {
			redact(find_number);
		}
	}
}

void Menu5()
{
	cout << "Введите -1, если хотите вернуться" << endl;
	int tr5 = 1;
	while (tr5 != 0) {
		cout << "Введите номер марштрута: ";
		while (!(cin >> number) || (number != round(number)) || (number <= 0)||(number>999))
		{
			if (number == -1)
				return;
			cin.clear();
			while (cin.get() != '\n');
			cout << " Неправильный ввод, пожалуйста повторите" << endl;
			cout << "Введите номер марштрута: ";
		}
		tr5 = 0;
	}

	deletik = number;
	k.find(number);
	if (number == -5) return;
	del_m(number);
}

void Menu6()
{
	cout << "Выполнена сортировка по номеру" << endl;
	k.sort_by_number();
}

void Menu7()
{
	if (!k.num())
	{
		cout << "Нет доступных маршрутов для выгрузки" << endl;
		return;
	}

	cout << "Ваша база будет выгружана в файл, всё, что у вас будет:" << endl;
	cout << "Вы уверены, что хотите потерять всё, что у вас тут есть?" << endl;
	cout << "Введите -1, если хотите уйти" << endl;
	cout << "Введите 1, если согласны выгрузить" << endl;
	while (!(cin >> men7) || (men7 != round(men7)) || (men7 != 1))
	{
		if (men7 == -1)
			return;
		cin.clear();
		while (cin.get() != '\n');
		cout << " Неправильный ввод, пожалуйста повторите" << endl;
		cout << "Введите ваш выбор: ";
	}

	k.stream();
	k.del_all();
	cout << "Ваши данные выгружены" << endl;
}

void Menu8() {
	cout << "Введите -1, если хотите вернуться в главное меню" << endl;
	cout << "Введите 1, если хотите загрузить всё то, что храниться в базе" << endl;
	cout << "Если вы введёте 1, то рискуете потерять базу, находящуюся сейчас в консоли" << endl;
	cout << "Ваш выбор: ";
	int ent8 = 0;

	while (!(cin >> ent8) || (ent8!= round(ent8)) || (ent8 != 1))
	{
		if (ent8 == -1)
			return;
		cin.clear();
		while (cin.get() != '\n');
		cout << " Неправильный ввод, пожалуйста повторите" << endl;
		cout << "Введите ваш выбор: ";
	}

	if(k.num()) k.del_all();
	k.read();
}


int string_truble(string s)
{
	string nos = "0123456789-+!,.?#$%^*()=~`";
	for (int i = 0; i < s.length(); i++)
	{
		for (int f = 0; f < nos.length(); f++)
		{
			if (s[i] == nos[f])
				return 1;
		}
	}
	return 0;
}

void redact(int n)
{
	int ent_red=0;
	string ent_redd;
	int x1 = 1;

	while (x1 != 0) {
		cout << "Введите 1, если хотите реадктировать номер маршрута" << endl;
		cout << "Введите 2, если хотите реадктировать начало маршрута" << endl;
		cout << "Введите 3, если хотите реадктировать конец маршрута" << endl;
		cout << "Введите -1, если хотите вернуться в меню" << endl;
		cout << "Введите ваш выбор: ";
		while (!(cin >> red_number) || (red_number != round(red_number)) || (red_number > 3) || (red_number <= -1) || (red_number == 0))
		{
			if (red_number == -1)
				return;
			cin.clear();
			while (cin.get() != '\n');
			cout << " Неправильный ввод, пожалуйста повторите" << endl;
			cout << "Введите ваш выбор: ";
		}

		if (red_number == 1)
		{
			cout << "Введите -1, если хотите вернуться в меню" << endl;
			cout << "Введите новый номер маршрута вместо нынешнего:";
			while (!(cin >> ent_red) || (ent_red != round(ent_red)) || (ent_red > 999) || (ent_red <= 0))
			{
				if (ent_red == -1) return;
				cin.clear();
				while (cin.get() != '\n');
				cout << " Неправильный ввод, пожалуйста повторите" << endl;
				cout << "Введите ваш выбор: ";
			}

			k.red1(n, ent_red);
			n = ent_red;

			cout << "Введите -1, если хотите вернуться в меню" << endl;
			cout << "Введите 1, если хотите вернуться к выбору параметров редактирования" << endl;
			cout << "Введите ваш выбор: ";
			while (!(cin >> ent_red) || (ent_red != round(ent_red)) || (ent_red > 999) || (ent_red <= 0))
			{
				if (ent_red == -1) return;
				cin.clear();
				while (cin.get() != '\n');
				cout << " Неправильный ввод, пожалуйста повторите" << endl;
				cout << "Введите ваш выбор: ";
			}
			x1 = 1;
		}

		if (red_number == 2)
		{
			cout << "Введите -1, если хотите вернуться в меню" << endl;
			cout << "Введите начало маршрута вместо нынешнего:";
			while (!(cin >> ent_redd) || (string_truble(ent_redd)))
			{
				if (ent_redd == "-1") return;
				cin.clear();
				while (cin.get() != '\n');
				cout << " Неправильный ввод, пожалуйста повторите" << endl;
				cout << "Введите ваш выбор: ";
			}

			k.red2(n, ent_redd);

			cout << "Введите -1, если хотите вернуться в меню" << endl;
			cout << "Введите 1, если хотите вернуться к выбору параметров редактирования" << endl;
			cout << "Введите ваш выбор: ";
			while (!(cin >> ent_red) || (ent_red != round(ent_red)) || (ent_red > 999) || (ent_red <= 0))
			{
				if (ent_red == -1) return;
				cin.clear();
				while (cin.get() != '\n');
				cout << " Неправильный ввод, пожалуйста повторите" << endl;
				cout << "Введите ваш выбор: ";
			}
			x1 = 1;
		}
		if (red_number == 3)
		{
			cout << "Введите -1, если хотите вернуться в меню" << endl;
			cout << "Введите конец маршрута вместо нынешнего:";
			while (!(cin >> ent_redd) || (string_truble(ent_redd)))
			{
				if (ent_redd == "-1") return;
				cin.clear();
				while (cin.get() != '\n');
				cout << " Неправильный ввод, пожалуйста повторите" << endl;
				cout << "Введите ваш выбор: ";
			}

			k.red3(n, ent_redd);

			cout << "Введите -1, если хотите вернуться в меню" << endl;
			cout << "Введите 1, если хотите вернуться к выбору параметров редактирования" << endl;
			cout << "Введите ваш выбор: ";
			while (!(cin >> ent_red) || (ent_red != round(ent_red)) || (ent_red > 999) || (ent_red <= 0))
			{
				if (ent_red == -1) return;
				cin.clear();
				while (cin.get() != '\n');
				cout << " Неправильный ввод, пожалуйста повторите" << endl;
				cout << "Введите ваш выбор: ";
			}
			x1 = 1;
		}
	}
}

void del_m(int n)
{
	int ent5 = 0;
	cout << "Вы действительно хотите его удалить?" << endl;
	cout << "Введите 1, если согласны удалить элемент" << endl;
	cout << "Введите -1, если хотите вернуться в меню" << endl;
	cout << "Введите ваш выбор: ";
	while (!(cin >> ent5) || (ent5 != round(ent5)) || (ent5 != 1))
	{
		if (ent5 == -1) return;
		cin.clear();
		while (cin.get() != '\n');
		cout << " Неправильный ввод, пожалуйста повторите" << endl;
		cout << "Введите ваш выбор: ";
	}

	k.del(n);
	cout << "Элемент удалён"<<endl;
}