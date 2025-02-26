//////////////////////////////////////////////////////////////////////////////
// Time.h 
// ���������� ���� � ���������� �����

#pragma once
#include <iostream>
using namespace std;

class Time
{
private:
    int first;  // ������
    int second; // �������

public:
    int GetFirst() const { return first; }
    int GetSecond() const { return second; }
    void SetFirst(int value);
    void SetSecond(int value);

    void Init(int h, int m);

    void Read();
    void Display() const;

    // ����� ������������ � �������
    int Minutes() const;
};

Time makeTime(int h, int m);
//////////////////////////////////////////////////////////////////////////////
// Time.cpp 
// ���� ��������� � ��������� ������ �����

#include "Time.h"

void Time::SetFirst(int value)
{
    first = (value >= 0) ? value : 0;
}

void Time::SetSecond(int value)
{
    second = (value >= 0 && value < 60) ? value : 0;
}

void Time::Init(int h, int m)
{
    SetFirst(h);
    SetSecond(m);
}

void Time::Read()
{
    int h, m;
    cout << "����i�� ������: ";
    cin >> h;
    cout << "����i�� �������: ";
    cin >> m;
    Init(h, m);
}

void Time::Display() const
{
    cout << "���: " << first << " ����� " << second << " ������" << endl;
}

int Time::Minutes() const
{
    return first * 60 + second;
}

Time makeTime(int h, int m)
{
    if (h < 0 || m < 0 || m >= 60)
    {
        cerr << "�������: ���������i �������� ����!" << endl;
        exit(1);
    }
    Time t;
    t.Init(h, m);
    return t;
}
//////////////////////////////////////////////////////////////////////////////
// main.cpp 
// �������� ���� ������� � ������� main
#include "Time.h"

int main()
{
    setlocale(LC_CTYPE, "ukr");
    Time t1;
    t1.Read();
    t1.Display();
    cout << "��� � ��������: " << t1.Minutes() << endl;

    return 0;
}
