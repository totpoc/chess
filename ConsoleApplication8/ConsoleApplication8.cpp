#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");

    int fieldSizeX, fieldSizeY, numberOfTests, posHorseX, posHorseY;
    unsigned int i;
    string cellColor;

    cout << "Введите количество тестов :";
    cin >> numberOfTests;

    for (i = 0; i < numberOfTests; i++)
    {
        cout << "Введите размеры поля :";
        cin >> fieldSizeX >> fieldSizeY;

        cout << "Введите координаты коня :";
        cin >> posHorseX >> posHorseY;

        if ((posHorseX + posHorseY) % 2 == 0)
            cellColor = "Белая ";
        else
            cellColor = "Черная ";

        if (posHorseX + 2 <= fieldSizeX) // >
        {
            if (posHorseY + 1 <= fieldSizeY)
                cout << cellColor << posHorseX + 2 << ":" << posHorseY + 1 << endl;
            if (posHorseY - 1 >= 1)
                cout << cellColor << posHorseX + 2 << ":" << posHorseY - 1 << endl;
        }
        if (posHorseX - 2 >= 1) // <
        {
            if (posHorseY + 1 <= fieldSizeY)
                cout << cellColor << posHorseX - 2 << ":" << posHorseY + 1 << endl;
            if (posHorseY - 1 >= 1)
                cout << cellColor << posHorseX - 2 << ":" << posHorseY - 1 << endl;
        }
        if (posHorseY + 2 <= fieldSizeY) // ^
        {
            if (posHorseX + 1 <= fieldSizeX)
                cout << cellColor << posHorseX + 1 << ":" << posHorseY + 2 << endl;
            if (posHorseX - 1 >= 1)
                cout << cellColor << posHorseX - 1 << ":" << posHorseY + 2 << endl;
        }
        if (posHorseY - 2 >= 1) // v
        {
            if (posHorseX + 1 <= fieldSizeX)
                cout << cellColor << posHorseX + 1 << ":" << posHorseY - 2 << endl;
            if (posHorseX - 1 >= 1)
                cout << cellColor << posHorseX - 1 << ":" << posHorseY - 2 << endl;
        }

    }

    return 0;
}


