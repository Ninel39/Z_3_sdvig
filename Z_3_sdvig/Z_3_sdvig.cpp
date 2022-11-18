// Z_3_sdvig.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<Windows.h>
#include<time.h>
#include<stdlib.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    /*Создайте двухмерный массив. Заполните его случайными числами и покажите на экран.
Пользователь выбирает количество сдвигов и положение (влево, вправо, вверх, вниз).
Выполнить сдвиг массива и показать на экран полученный результат. Сдвиг циклический.
Например, если мы имеем следующий массив
1 2 0 4 5 3
4 5 3 9 0 1
и пользователь выбрал сдвиг на 2 разряда вправо, то мы получим
5 3 1 2 0 4
0 1 4 5 3 9
    */
    srand(time(NULL));

    const int row = 4, col = 4;
    int mas[row][col], mas2[row][col];
    int course, shift;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            mas[i][j] = rand() % 20;
            cout << mas[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\n\tНаправление сдвига\n"
        << "\t1. Вправо\n"
        << "\t2. Влево\n"
        << "\t3. Вверх\n"
        << "\t4. Вниз\n\n"
        << "Выберите действие: ";
    cin >> course;

    if (course == 1) {
        cout << "Выберите количество сдвигов: ";
        cin >> shift;
        if (shift > col) {
            shift %= col;
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (col - shift + j > col - 1) {
                    mas2[i][j] = mas[i][j - shift];
                    cout << mas2[i][j] << "\t";
                }
                else {
                    mas2[i][j] = mas[i][col - shift + j];
                    cout << mas2[i][j] << "\t";
                }
            }
            cout << endl;
        }
    }
    else if (course == 2) {
        cout << "Выберите количество сдвигов: ";
        cin >> shift;
        if (shift > col) {
            shift %= col;
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (shift + j - col < 0) {
                    mas2[i][j] = mas[i][j + shift];
                    cout << mas2[i][j] << "\t";
                }
                else {
                    mas2[i][j] = mas[i][shift + j - col];
                    cout << mas2[i][j] << "\t";
                }
            }
            cout << endl;
        }
    }
    else if (course == 3) {
        cout << "Выберите количество сдвигов: ";
        cin >> shift;
        if (shift > row) {
            shift %= row;
        }
        for (int j = 0; j < col; j++)
        {
            for (int i = 0; i < row; i++)
            {
                if (shift + i - row < 0) {
                    mas2[i][j] = mas[i + shift][j];
                }
                else {
                    mas2[i][j] = mas[shift + i - row][j];
                }
            }
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << mas2[i][j] << "\t";
            }
            cout << endl;
        }
    }
    else if (course == 4) {
        cout << "Выберите количество сдвигов: ";
        cin >> shift;
        if (shift > row) {
            shift %= row;
        }
        for (int j = 0; j < col; j++)
        {
            for (int i = 0; i < row; i++)
            {
                if (row - shift + i > row - 1) {
                    mas2[i][j] = mas[i - shift][j];
                }
                else {
                    mas2[i][j] = mas[row - shift + i][j];
                }
            }
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << mas2[i][j] << "\t";
            }
            cout << endl;
        }
    }

    
}


    


