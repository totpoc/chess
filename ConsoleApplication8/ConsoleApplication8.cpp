#include <iostream>

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

void drawField(char *moves)
{
    cout << endl;
    cout <<"   " << moves[0] << "   " << moves[1] << "  " << endl;
    cout <<" " << moves[2] << "       " << moves[3] << " " << endl;
    cout <<"     ?   "<< endl;
    cout <<" " << moves[4] << "       " << moves[5] << " " << endl;
    cout <<"   " << moves[6] << "   " << moves[7] << "  " << endl;
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "Rus");

    int fieldSizeX, fieldSizeY, posHorseX, posHorseY;
    int16_t numberOfTests, i, k;

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

      
        if ((posHorseX + posHorseY) % 2 == 0)
            cellColor = "Белая ";
        else
            cellColor = "Черная ";

        for (k = 0; k<8;k++)
            possibleMoves[k] = 'x';
        
        cout << endl;

        if (posHorseX + 2 <= fieldSizeX) // >
        {
            if (posHorseY + 1 <= fieldSizeY){
                cout << cellColor << posHorseX + 2 << ":" << posHorseY + 1 << endl;
                possibleMoves[3] = 'v';
            }
            if (posHorseY - 1 >= 1){
                cout << cellColor << posHorseX + 2 << ":" << posHorseY - 1 << endl;
                possibleMoves[5] = 'v';
            }
        }
        if (posHorseX - 2 >= 1) // <
        {
            if (posHorseY + 1 <= fieldSizeY){
                cout << cellColor << posHorseX - 2 << ":" << posHorseY + 1 << endl;
                possibleMoves[2] = 'v';
            }
            if (posHorseY - 1 >= 1){
                cout << cellColor << posHorseX - 2 << ":" << posHorseY - 1 << endl;
                possibleMoves[4] = 'v';
            }
        }
        if (posHorseY + 2 <= fieldSizeY) // ^
        {
            if (posHorseX + 1 <= fieldSizeX) {
                cout << cellColor << posHorseX + 1 << ":" << posHorseY + 2 << endl;
                possibleMoves[1] = 'v';
            }
            if (posHorseX - 1 >= 1) {
                cout << cellColor << posHorseX - 1 << ":" << posHorseY + 2 << endl;
                possibleMoves[0] = 'v';
            }
        }
        if (posHorseY - 2 >= 1) // v
        {
            if (posHorseX + 1 <= fieldSizeX){
                cout << cellColor << posHorseX + 1 << ":" << posHorseY - 2 << endl;
                possibleMoves[7] = 'v';
            }
            if (posHorseX - 1 >= 1){
                cout << cellColor << posHorseX - 1 << ":" << posHorseY - 2 << endl;
                possibleMoves[6] = 'v';
            }
        }
        drawField(possibleMoves);

    }

    return 0;
}


