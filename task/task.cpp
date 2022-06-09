/*
			Введение в ООП. Класс CRectangle.
	Разработать класс CRectangle. Обеспечить класс конструктором, а также всеми
необходимыми методами-аксессорами. Предусмотреть в классе методы для
нормализации прямоугольника, перемещения прямоугольника, изменения размера
прямоугольника, вычисления площади прямоугольника и др.
Данные-члены (поля):
	left - левая сторона;
	right – правая сторона;
	top – верхняя сторона;
	bottom - нижняя сторона
			Функции-члены (методы):
	CRectangle( ); - конструктор по умолчанию;
	CRectangle( int l, int t, int r, int b ); - конструктор с параметрами (лево, верх,
право, низ);
	int Width( ); - ширина прямоугольника;
	int Height( ); - высота прямоугольника;
	bool IsRectNull( ); - метод возвращает истину, если все параметры = 0;
	bool PtInRect( int x, int y ); - метод возвращает истину, если точка лежит
внутри прямоугольника;
	void SetRect( int x1, int y1, int x2, int y2 ); - установка размера и координат;
	void SetRectEmpty( ); - установка всех координат прямоугольника в 0;
	void InflateRect( int l, int t, int r, int b ); - метод увеличивает размер
прямоугольника, двигая границы относительно центральной точки;
	void DeflateRect( int l, int t, int r, int b ); - метод уменьшает размер
прямоугольника, двигая границы относительно центральной точки;
	void NormalizeRect( ); - метод нормализует координаты
прямоугольника, т.е. если левая сторона имеет координату больше, чем
правая, то они меняются местами, то же самое относится к верхней и
нижней сторонам прямоугольника;
	void OffsetRect( int x, int y ); - метод смещает прямоугольник на
заданную величину;
	void Print (); - метод выводит на экран прямоугольник.

	Статус: Подходит ли такой метод контроля ошибок ? (в виде функции за классом).
	О задании: 2:54:30.

	Возможные доработки:
	* предусмотреть не выход за грани координат
	* предусмотреть предел сужения до квадрата с минимальными точками координат
*/

#include <iostream>
#include "CRectangle.h"
using std::cout;
using std::cin;
using std::endl;
using std::boolalpha;

int main()
{
	CRectangle cRect;
	int x{ 0 }, y{ 0 };
	int left_X{ 0 }, top_Y{ 0 }, right_X{ 0 }, bottom_Y{ 0 };

	char repeat{ 0 }; // Do you want to repeat?
	do
	{
		cout << "Enter the coordinates of the rectangle"
			<< "\nIn that order: "
			<< "\nleft_X -> top_Y -> right_X -> bottom_Y :\n";
		cin >> left_X
			>> top_Y
			>> right_X
			>> bottom_Y;
		cRect.SetRect(left_X, top_Y, right_X, bottom_Y);
		cRect.NormalizeRect();
		cout << "\nNow the coordinates of the rectangle are: ";
		cRect.Print();

		// Ширина прямоугольника;
		cout << endl
			<< "Width = " << cRect.Width()
			<< endl << endl

			// Высота прямоугольника;
			<< "Height = " << cRect.Height()
			<< endl << endl

			// Метод возвращает истину, если все параметры = 0;
			<< "All parameters are 0 ? - " << boolalpha << cRect.IsRectNull()
			<< endl << endl

			// Метод возвращает истину, если точка лежит внутри прямоугольника;
			<< "Enter point coordinates "
			<< "\nIn that order : "
			<< "\n\"X\" -> \"Y\" : ";
		do
		{
			cout << "\nx =  ";
			cin >> x;
			cout << "y = ";
			cin >> y;
			if (x < 0 || y < 0)
				cout << "\nError. The given point is beyond the coordinates, try again !" << endl;
		} while (x < 0 || y < 0);
		cout << "Is this point in a rectangle? - " << boolalpha << cRect.PtInRect(x, y)
			<< endl

			// Метод увеличивает размер прямоугольника, двигая границы относительно центральной точки;
			<< "\nHow much to increase the size of the rectangle?\n"
			<< "In that order: "
			<< "\nleft_X -> top_Y -> right_X -> bottom_Y :\n";
		cin >> left_X
			>> top_Y
			>> right_X
			>> bottom_Y;
		cRect.InflateRect(left_X, top_Y, right_X, bottom_Y);
		IsItCorrect(cRect);
		cout << "The new rectangle coordinates are : ";
		cRect.Print();

		// Метод уменьшает размер прямоугольника, двигая границы относительно центральной точки;
		cout << "\nHow much to decrease the size of the rectangle?\n"
			<< "In that order : "
			<< "\nleft_X -> top_Y -> right_X -> bottom_Y :\n";
		cin >> left_X
			>> top_Y
			>> right_X
			>> bottom_Y;
		cRect.DeflateRect(left_X, top_Y, right_X, bottom_Y);
		IsItCorrect(cRect);
		cout << "The new rectangle coordinates are : ";
		cRect.Print();

		// Метод смещает прямоугольник на заданную величину;
		cout << "\nEnter the amount you want to shift the rectangle :"
			<< "\nIn that order : "
			<< "\n\"X\" -> \"Y\" :\n";
		cin >> x
			>> y;
		cRect.OffsetRect(x, y);
		IsItCorrect(cRect);
		cout << "The new rectangle coordinates are : ";
		cRect.Print();
		cRect.SetRectEmpty();
		cout << "All rectangle coordinates are reset!" << endl;

		cout << endl;
		cout << "Do you want to repeat? ( y (yes) / n (no) )\n";
		cin >> repeat;
		cout << endl;

	} while (repeat == 'y');
}