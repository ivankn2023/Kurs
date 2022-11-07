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
			cout << "������ ������� ��� ���� � ����" << endl;
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
			cout << "������� ������" << endl;
			cout << "��� ��������������: " << endl;
			cout << current->number << endl;
			cout << current->start << endl;
			cout << current->finish << endl;
			return;
		}
		current = current->next;
	}
	cout << "����� ������� �� ������" << endl;
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
			cout << "��� ������� ������, ������ �� ������������ �����:" << endl;
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
			cout << "��� ������� ������, ������ �� ������������ �����:" << endl;
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
			cout << "��� ������� ������, ������ �� ������������ �����:" << endl;
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
		cout << "������ �������� ����� ��� ��������" << endl;
		cout << "�� ������� ���� � ��������� �� ���������� ����" << endl;
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
			cout << "������ ��� ������, �������� ���-�� �� ����������" << endl;
			return;
		}
		if (!(in >> fi))
		{
			cout << "������ ��� ������, �������� ���-�� �� ����������" << endl;
			return;
		}
		else {
			addNode(st, fi, num);
		}
	}
	cout << "������ �� ���� ������ � ����� ������������" << endl;
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
	cout << "������� -1, ���� ������ ���������" << endl;
	cout << "������� ������ ���� ����� �� ���������� �������:" << endl;
	cout << "����� ��������" << endl;
	cout << "������ ��������" << endl;
	cout << "����� ��������" << endl;
	int tr = 1;

	while (tr != 0) {
		cout << "������� ����� ���������: ";

		while (!(cin >> number) || (number != round(number)) || (number <= 0)||(number>999))
		{
			if (number == -1)
				return;
			cin.clear();
			while (cin.get() != '\n');
			cout << " ������������ ����, ���������� ���������" << endl;
			cout << "������� ����� ���������: ";
		}

		if (k.unic(number)) {
			cout << "������� � ����� ������� ��� ����" << endl;
			continue;
		}
		else tr = 0;

		cout << "������� -1, ���� ������ ��������� � �������� ����" << endl;
		cout << "������� ������ ��������: ";

		while (!(cin >> start) || (string_truble(start)))
		{
			if (start == "-1") return;
			cin.clear();
			while (cin.get() != '\n');
			cout << " ������������ ����, ���������� ���������" << endl;
			cout << "������� ������ ��������: ";
		}

		cout << "������� -1, ���� ������ ��������� � �������� ����" << endl;
		cout << "������� ����� ��������: ";

		while (!(cin >> finish) || (string_truble(finish)))
		{
			if (finish == "-1") return;
			cin.clear();
			while (cin.get() != '\n');
			cout << " ������������ ����, ���������� ���������" << endl;
			cout << "������� ����� ��������: ";
		}

		cout << "���� ������ ������� ��������" << endl;
	}
	k.addNode(start, finish, number);

	cout << "������� �� �� ������������� ��� ������ ������" << endl;
	cout << "������� -1, ���� ������ ��������� � �������� ����" << endl;
	cout << "������� 1, ���� ������ ��������� ����������"<<endl;
	cout << "������� ��� �����: ";
		while (!(cin >> number) || (number!=1))
		{
			if (finish == "-1") return;
			cin.clear();
			while (cin.get() != '\n');
			cout << " ������������ ����, ���������� ���������" << endl;
			cout << "������� ��� �����: ";
		}

	k.sort_by_number();
	cout << "������ �������������" << endl;
}

void Menu2()
{
	if (k.num())
	{
		cout << "��� ��������, ������� ��������� � ����� ������������ ����� ������: " << endl;
		k.printList();
	}
	else
	{
		cout << "��� ��������� ���������" << endl;
	}
}

void Menu3()
{
	int it3 = 0;

	if (!k.num())
	{
		cout << "���, �� ���� ��� ������ ������" << endl;
		return;
	}
	cout << "������� -1, ���� ������ ��������� �����" << endl;
	cout << "������� ����� ��������, ������� �� ������ �����: ";

	while (!(cin >> find_number) || (find_number != round(find_number)) || (find_number <= 0)||(find_number>999))
	{
		if (find_number == -1)
			return;
		cin.clear();
		while (cin.get() != '\n');
		cout << " ������������ ����, ���������� ���������" << endl;
		cout << "������� ����� ���������: ";
	}

	k.find(find_number);

	if (find_number != -5)
	{
		cout << "������� -1, ���� ������ ��������� �����" << endl;
		cout << "������� 1, ���� ������ ������������� ������ �������" << endl;
		cout << "������� 2, ���� ������ ������� ������ �������" << endl;
		cout << "������� ��� �����: ";

		while (!(cin >> it3) || (it3 != round(it3)) || (it3 <= 0) || (it3 > 2))
		{
			if (it3 == -1)
				return;
			cin.clear();
			while (cin.get() != '\n');
			cout << " ������������ ����, ���������� ���������" << endl;
			cout << "������� ��� �����: ";
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
		cout << "���, �� ���� ��� ������ �������������" << endl;
		return;
	}

	int tr4 = 1;
	while (tr4 != 0) {
		cout << "������� -1, ���� ������ ��������� �����" << endl;
		cout << "������� ����� ��������, ������� �� ������ �����:";
		find_number = 1;

		while (!(cin >> find_number) || (find_number != round(find_number)) || (find_number <= 0))
		{
			if (find_number == -1)
				return;
			cin.clear();
			while (cin.get() != '\n');
			cout << " ������������ ����, ���������� ���������" << endl;
			cout << "������� ����� ���������: ";
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
	cout << "������� -1, ���� ������ ���������" << endl;
	int tr5 = 1;
	while (tr5 != 0) {
		cout << "������� ����� ���������: ";
		while (!(cin >> number) || (number != round(number)) || (number <= 0)||(number>999))
		{
			if (number == -1)
				return;
			cin.clear();
			while (cin.get() != '\n');
			cout << " ������������ ����, ���������� ���������" << endl;
			cout << "������� ����� ���������: ";
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
	cout << "��������� ���������� �� ������" << endl;
	k.sort_by_number();
}

void Menu7()
{
	if (!k.num())
	{
		cout << "��� ��������� ��������� ��� ��������" << endl;
		return;
	}

	cout << "���� ���� ����� ��������� � ����, ��, ��� � ��� �����:" << endl;
	cout << "�� �������, ��� ������ �������� ��, ��� � ��� ��� ����?" << endl;
	cout << "������� -1, ���� ������ ����" << endl;
	cout << "������� 1, ���� �������� ���������" << endl;
	while (!(cin >> men7) || (men7 != round(men7)) || (men7 != 1))
	{
		if (men7 == -1)
			return;
		cin.clear();
		while (cin.get() != '\n');
		cout << " ������������ ����, ���������� ���������" << endl;
		cout << "������� ��� �����: ";
	}

	k.stream();
	k.del_all();
	cout << "���� ������ ���������" << endl;
}

void Menu8() {
	cout << "������� -1, ���� ������ ��������� � ������� ����" << endl;
	cout << "������� 1, ���� ������ ��������� �� ��, ��� ��������� � ����" << endl;
	cout << "���� �� ������ 1, �� �������� �������� ����, ����������� ������ � �������" << endl;
	cout << "��� �����: ";
	int ent8 = 0;

	while (!(cin >> ent8) || (ent8!= round(ent8)) || (ent8 != 1))
	{
		if (ent8 == -1)
			return;
		cin.clear();
		while (cin.get() != '\n');
		cout << " ������������ ����, ���������� ���������" << endl;
		cout << "������� ��� �����: ";
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
		cout << "������� 1, ���� ������ ������������� ����� ��������" << endl;
		cout << "������� 2, ���� ������ ������������� ������ ��������" << endl;
		cout << "������� 3, ���� ������ ������������� ����� ��������" << endl;
		cout << "������� -1, ���� ������ ��������� � ����" << endl;
		cout << "������� ��� �����: ";
		while (!(cin >> red_number) || (red_number != round(red_number)) || (red_number > 3) || (red_number <= -1) || (red_number == 0))
		{
			if (red_number == -1)
				return;
			cin.clear();
			while (cin.get() != '\n');
			cout << " ������������ ����, ���������� ���������" << endl;
			cout << "������� ��� �����: ";
		}

		if (red_number == 1)
		{
			cout << "������� -1, ���� ������ ��������� � ����" << endl;
			cout << "������� ����� ����� �������� ������ ���������:";
			while (!(cin >> ent_red) || (ent_red != round(ent_red)) || (ent_red > 999) || (ent_red <= 0))
			{
				if (ent_red == -1) return;
				cin.clear();
				while (cin.get() != '\n');
				cout << " ������������ ����, ���������� ���������" << endl;
				cout << "������� ��� �����: ";
			}

			k.red1(n, ent_red);
			n = ent_red;

			cout << "������� -1, ���� ������ ��������� � ����" << endl;
			cout << "������� 1, ���� ������ ��������� � ������ ���������� ��������������" << endl;
			cout << "������� ��� �����: ";
			while (!(cin >> ent_red) || (ent_red != round(ent_red)) || (ent_red > 999) || (ent_red <= 0))
			{
				if (ent_red == -1) return;
				cin.clear();
				while (cin.get() != '\n');
				cout << " ������������ ����, ���������� ���������" << endl;
				cout << "������� ��� �����: ";
			}
			x1 = 1;
		}

		if (red_number == 2)
		{
			cout << "������� -1, ���� ������ ��������� � ����" << endl;
			cout << "������� ������ �������� ������ ���������:";
			while (!(cin >> ent_redd) || (string_truble(ent_redd)))
			{
				if (ent_redd == "-1") return;
				cin.clear();
				while (cin.get() != '\n');
				cout << " ������������ ����, ���������� ���������" << endl;
				cout << "������� ��� �����: ";
			}

			k.red2(n, ent_redd);

			cout << "������� -1, ���� ������ ��������� � ����" << endl;
			cout << "������� 1, ���� ������ ��������� � ������ ���������� ��������������" << endl;
			cout << "������� ��� �����: ";
			while (!(cin >> ent_red) || (ent_red != round(ent_red)) || (ent_red > 999) || (ent_red <= 0))
			{
				if (ent_red == -1) return;
				cin.clear();
				while (cin.get() != '\n');
				cout << " ������������ ����, ���������� ���������" << endl;
				cout << "������� ��� �����: ";
			}
			x1 = 1;
		}
		if (red_number == 3)
		{
			cout << "������� -1, ���� ������ ��������� � ����" << endl;
			cout << "������� ����� �������� ������ ���������:";
			while (!(cin >> ent_redd) || (string_truble(ent_redd)))
			{
				if (ent_redd == "-1") return;
				cin.clear();
				while (cin.get() != '\n');
				cout << " ������������ ����, ���������� ���������" << endl;
				cout << "������� ��� �����: ";
			}

			k.red3(n, ent_redd);

			cout << "������� -1, ���� ������ ��������� � ����" << endl;
			cout << "������� 1, ���� ������ ��������� � ������ ���������� ��������������" << endl;
			cout << "������� ��� �����: ";
			while (!(cin >> ent_red) || (ent_red != round(ent_red)) || (ent_red > 999) || (ent_red <= 0))
			{
				if (ent_red == -1) return;
				cin.clear();
				while (cin.get() != '\n');
				cout << " ������������ ����, ���������� ���������" << endl;
				cout << "������� ��� �����: ";
			}
			x1 = 1;
		}
	}
}

void del_m(int n)
{
	int ent5 = 0;
	cout << "�� ������������� ������ ��� �������?" << endl;
	cout << "������� 1, ���� �������� ������� �������" << endl;
	cout << "������� -1, ���� ������ ��������� � ����" << endl;
	cout << "������� ��� �����: ";
	while (!(cin >> ent5) || (ent5 != round(ent5)) || (ent5 != 1))
	{
		if (ent5 == -1) return;
		cin.clear();
		while (cin.get() != '\n');
		cout << " ������������ ����, ���������� ���������" << endl;
		cout << "������� ��� �����: ";
	}

	k.del(n);
	cout << "������� �����"<<endl;
}