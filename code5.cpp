#include <iostream>
#include <chrono> //для "хроно" штуки, которая в последствии будет в сиде
#include <random> //для функций рандома
using namespace std;
int rows_cols = 5; //N - размер матрицы
int rowssave_forprint = rows_cols;
int ITER = 0;
int timetravel = 0, shutka = 0; //штук чтобы в функции можно было границы уменьшать со
временем
void printMATRIX(int rows_cols, int** arr)
{
//выводим массив
cout << endl << ITER << ") " << endl;
cout << endl;
for (int j = 0; j < rows_cols; j++)
{
for (int i = 0; i < rows_cols; i++)
{
cout << arr[j][i] << " ";
}
cout << endl;
}
}
bool check(int *arr)
{
//проверка перед рекурсией
bool helper = true;
for (int l = 0; l < rows_cols - 1; l++)
{
if (arr[l] < arr[l + 1]) helper = false;
}
if (arr[rows_cols - 1] > arr[rows_cols - 2]) helper = false;
return helper;
}
void QuickSort(int* arr, int rows, int mainindex, int** arirMAXIMA)
{//элемент из столбца от конца на один + инлекс главного элемента
int MARSLET = *(arirMAXIMA[rows-1] + mainindex);
int saver1main = 0, saver2bigger = 0, saver3prost = 0;
for (int i = mainindex + 1; i < rows; i++) //для всех последующих элементов, которые
БОЛЬШЕ //////////////В ЭТОЙ СТРОЧКЕ ОСНОВНОЙ СМЫСЛ
{
if (ITER > pow(rows_cols,2) ) break;
if (arirMAXIMA[rows_cols - 1][i] >= arirMAXIMA[rows_cols - 1][mainindex]) //в случае
нахождение элемента больше или такого же
{
if (arirMAXIMA[rows_cols - 1][mainindex + 1] <=
arirMAXIMA[rows_cols - 1][mainindex]) //и это не БУКВАЛЬНО следующий элемент
{
for (int k = 0; k < rows_cols; k++)
{
//cout << "\nAZAZA 1\n";
//сейвы
saver1main = arirMAXIMA[k][mainindex];
saver2bigger = arirMAXIMA[k][i];
saver3prost = arirMAXIMA[k][mainindex + 1];
//cout << "\n" << MARSLET << " is = " << mainindex
<< "\n";
//переназначаем элементы
arirMAXIMA[k][mainindex + 1] = saver1main;
//главный элемент шагает 1 раз вперёд
arirMAXIMA[k][i] = saver3prost; //элемент на
который наступили, наступает на тот "большой"
arirMAXIMA[k][mainindex] = saver2bigger;
//большой переселяется за главный слева
}
mainindex++; //индекс на 1 больше, ведь
"главный" элемент всё таки шагнул, и его индекс изменился
ITER++; //одно переставление
printMATRIX(rowssave_forprint, arirMAXIMA);
}
else
{
//cout << "\nAZAZA 2\n";
for (int k = 0; k < rows_cols; k++)
{
//сейвы
saver1main = arirMAXIMA[k][mainindex];
saver2bigger = arirMAXIMA[k][i];
//cout << "\n" << MARSLET << " is = " << mainindex << "\n";
//переназначаем элементы
arirMAXIMA[k][i] = saver1main; //главный элемент шагает 1
раз вперёд
arirMAXIMA[k][mainindex] = saver2bigger; //большой
переселяется за главный слева
}
mainindex++; //индекс на 1 больше, ведь
"главный" элемент всё таки шагнул, и его индекс изменился
ITER++; //одно переставление
printMATRIX(rowssave_forprint, arirMAXIMA);
}
}
}
// cout << "\n" << MARSLET << " is = " << mainindex << "\n";
int prikol = rows - mainindex - 1 - timetravel;
// тут ещё -1 потому что ровсколс не имеет нулевого значения в отличии от майниндекса
if (prikol > 1 && check(arr) != true)
{//остатки справа
cout << "\nRECURS RIGHT IS START\n";
QuickSort(arr, rows_cols, mainindex + 1, arirMAXIMA);
timetravel += mainindex;
}
///////////////(int i = mainindex + 1; i < rows; i++) /
if (mainindex - shutka > 1 && check(arr) != true)
{//остатки слева
cout << "\nRECURS LEFT IS START\n";
QuickSort(arr, mainindex, 0, arirMAXIMA);
shutka += mainindex;
}
if (mainindex == 0 && check(arr) != true)
{
QuickSort(arr, rows_cols, mainindex + 1, arirMAXIMA);
}
}//rows/2 работает только если штука находится посредине ------------ && mainindex < rows_cols/2
//////////////////////////////////////////////////ПРОБЛЕМА КАЖЕТСЯ В ТОМ, ЧТО Я КРИВО В ПОСЛЕДУЮЩИЕ
РАЗЫ КИДАЮ 4Й И 1Й АРГУМЕНТЫ//////////////////////
int main()
{
//создаём динамический массив
int** arr = new int* [rows_cols];
for (int i = 0; i < rows_cols; i++)
{
arr[i] = new int[rows_cols];
}
//заполняем массива рандомом
unsigned seed = chrono::system_clock::now().time_since_epoch().count(); //формировка
сида, с помощью времени хроно
default_random_engine generator(seed); //обозначение генератора
uniform_int_distribution<int> distribution(1, 9); //определение границ и функции вызова
for (int j = 0; j < rows_cols; j++)
{
for (int i = 0; i < rows_cols; i++)
{
arr[j][i] = distribution(generator);
}
}
printMATRIX(rowssave_forprint, arr);
QuickSort(arr[rows_cols - 1], rows_cols, 0, arr);
cout << "\n\nF\tI\tN\tA\tL\n\n";
printMATRIX(rowssave_forprint, arr);
//delete чистим память
for (int i = 0; i < rows_cols; i++)
{
delete [] arr[i];
}
delete[] arr;
}