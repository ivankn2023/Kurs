#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;
//хранение:
//  Номер
//  Начало маршрута
//  Конец маршрута
//          пример:
//          51
//          Питер
//          Минск

struct marsh
{
    string start;
    string finish;
    int number;
    marsh* next;
};
class List
{
private:
    marsh* head;
public:
    List();
    int num();
    void sort_by_number();
    void addNode(string s, string f, int n);
    void del(int n);
    void del_all();
    void printList();
    int unic(int n);
    int unic_answer(int n);
    void find(int& n);
    void red1(int n, int n1);
    void red2(int n, string s);
    void red3(int n, string f);
    void stream();
    void read();
};

void Menu0();
void Menu1();
void Menu2();
void Menu3();
void Menu4();
void Menu5();
void Menu6();
void Menu7();
void Menu8();

int string_truble(string s);
void redact(int );
void del_m(int);