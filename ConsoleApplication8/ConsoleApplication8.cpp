#include <iostream>
#include <Windows.h>

using namespace std;

int getCorrectInput()
{
    int inputNumber;
    while (!(cin >> inputNumber) || (cin.peek() != '\n') || inputNumber < 1)
    {
        cin.clear();
        while (cin.get() != '\n');
        cout <<"Введите корректное число :";
    }
    return inputNumber;
}

void setColor(char inputMoves) {
    int bg = 0;
    int text = 0;

    if (inputMoves =='v')
        text = 2;
    if (inputMoves == 'x')
        text = 4;
    if (inputMoves == '?')
        text = 7;
    
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));

    cout << inputMoves;
}

void drawField(char* moves)
{
    cout << endl;
    cout << "   "; setColor(moves[0]);  cout << "   ";  setColor(moves[1]); cout << "  " << endl;
    cout << " "; setColor(moves[2]); cout << "       "; setColor(moves[3]); cout << " " << endl;
    cout << "     "; setColor('?'); cout << endl;
    cout << " "; setColor(moves[4]); cout << "       "; setColor(moves[5]);cout << " " << endl;
    cout << "   "; setColor(moves[6]); cout << "   "; setColor(moves[7]);cout << "  " << endl;
    cout << endl;


    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 7));
    
}


int main()
{
    setlocale(LC_ALL, "Rus");

    int fieldSizeX, fieldSizeY, posHorseX, posHorseY;
    int16_t numberOfTests, numberOfMoves, i, k;

    char possibleMoves[8];
    string cellColor;

    cout << "Введите количество тестов :";
    numberOfTests = getCorrectInput();


    for (i = 0; i < numberOfTests; i++)
    {
        cout << "Введите размеры поля по X:";
        fieldSizeX = getCorrectInput();
        cout << "Введите размеры поля по Y:";
        fieldSizeY = getCorrectInput();


        cout << "Введите координаты коня по X:";
        posHorseX = getCorrectInput();
        cout << "Введите координаты коня по Y:";
        posHorseY = getCorrectInput();

        cout << endl;

        if (posHorseX <= fieldSizeX && posHorseY <= fieldSizeY) {
            if ((posHorseX + posHorseY) % 2 == 0)
                cellColor = "Белая ";
            else
                cellColor = "Черная ";

            for (k = 0; k < 8; k++)
                possibleMoves[k] = 'x';


            numberOfMoves = 0;

            if (posHorseX + 2 <= fieldSizeX) // >
            {
                if (posHorseY + 1 <= fieldSizeY) {
                    cout << cellColor << posHorseX + 2 << ":" << posHorseY + 1 << endl;
                    possibleMoves[3] = 'v';
                    numberOfMoves++;
                }
                if (posHorseY - 1 >= 1) {
                    cout << cellColor << posHorseX + 2 << ":" << posHorseY - 1 << endl;
                    possibleMoves[5] = 'v';
                    numberOfMoves++;
                }
            }
            if (posHorseX - 2 >= 1) // <
            {
                if (posHorseY + 1 <= fieldSizeY) {
                    cout << cellColor << posHorseX - 2 << ":" << posHorseY + 1 << endl;
                    possibleMoves[2] = 'v';
                    numberOfMoves++;
                }
                if (posHorseY - 1 >= 1) {
                    cout << cellColor << posHorseX - 2 << ":" << posHorseY - 1 << endl;
                    possibleMoves[4] = 'v';
                    numberOfMoves++;
                }
            }
            if (posHorseY + 2 <= fieldSizeY) // ^
            {
                if (posHorseX + 1 <= fieldSizeX) {
                    cout << cellColor << posHorseX + 1 << ":" << posHorseY + 2 << endl;
                    possibleMoves[1] = 'v';
                    numberOfMoves++;
                }
                if (posHorseX - 1 >= 1) {
                    cout << cellColor << posHorseX - 1 << ":" << posHorseY + 2 << endl;
                    possibleMoves[0] = 'v';
                    numberOfMoves++;
                }
            }
            if (posHorseY - 2 >= 1) // v
            {
                if (posHorseX + 1 <= fieldSizeX) {
                    cout << cellColor << posHorseX + 1 << ":" << posHorseY - 2 << endl;
                    possibleMoves[7] = 'v';
                    numberOfMoves++;
                }
                if (posHorseX - 1 >= 1) {
                    cout << cellColor << posHorseX - 1 << ":" << posHorseY - 2 << endl;
                    possibleMoves[6] = 'v';
                    numberOfMoves++;
                }
            }
            cout << endl << "Количество возможных ходов:" << numberOfMoves << endl;
            drawField(possibleMoves);
        }
        else
            cout << "Конь за пределами поля" << endl;
    }

    return 0;
}


