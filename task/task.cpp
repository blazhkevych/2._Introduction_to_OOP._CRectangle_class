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


	СТАТУС : Готово.

	ВОЗМОЖНЫЕ ДОРАБОТКИ:
	* добавить проверку на вводимые символы
	* вывод на печать системы координат и прорисовка на ней прямоугольника по заданным координатам.

	ИЗВЕСТНЫЕ ОШИБКИ:
	* при увеличении прямоугольника, с него можно сделать что угодно.
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
	int pointCoordX{ 0 }, pointCoordY{ 0 };
	int left_X{ 0 }, top_Y{ 0 }, right_X{ 0 }, bottom_Y{ 0 };
	bool check{ false }, checkInside{ false };
	char repeat{ 0 }; // Повторить задание ?
	do
	{
		do
		{
			cout << "Enter the coordinates of the rectangle"
				<< "\nIn that order: "
				<< "\nleft_X -> top_Y -> right_X -> bottom_Y :\n";
			cin >> left_X;
			cin >> top_Y;
			cin >> right_X;
			cin >> bottom_Y;
			cRect.SetRect(left_X, top_Y, right_X, bottom_Y);
			check = (Error_RectangleCoordOutsideAxis(cRect) || Error_RectangleIsTooSmall(cRect));
		} while (check);
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
			<< endl << endl;

		// Метод возвращает истину, если точка лежит внутри прямоугольника;
		do
		{
			cout << "Enter point coordinates "
				<< "\nIn that order : "
				<< "\n\"X\" -> \"Y\" : ";
			cout << "\nx =  ";
			cin >> pointCoordX;
			cout << "y = ";
			cin >> pointCoordY;
			check = Error_PointCoordOutsideAxis(pointCoordX, pointCoordY);
		} while (check);
		cout << "Is this point in a rectangle? - " << boolalpha << cRect.PtInRect(pointCoordX, pointCoordY)
			<< endl;

		// Метод увеличивает размер прямоугольника, двигая границы относительно центральной точки;
		do
		{
			cout << "\nHow much to increase the size of the rectangle "
				<< '(' << cRect.getLeftX() << ", " << cRect.getTopY() << " ; "
				<< cRect.getRightX() << ", " << cRect.getBottomY() << ") ?"
				<< "\nIn that order: "
				<< "\nleft_X -> top_Y -> right_X -> bottom_Y :\n";
			cin >> left_X;
			cin >> top_Y;
			cin >> right_X;
			cin >> bottom_Y;
			cRect.InflateRect(left_X, top_Y, right_X, bottom_Y);
			check = (Error_RectangleCoordOutsideAxis(cRect) || Error_RectangleIsTooSmall(cRect));
			if (check)
			{
				do
				{
					cout << "Enter the coordinates of the rectangle"
						<< "\nIn that order: "
						<< "\nleft_X -> top_Y -> right_X -> bottom_Y :\n";
					cin >> left_X;
					cin >> top_Y;
					cin >> right_X;
					cin >> bottom_Y;
					cRect.SetRect(left_X, top_Y, right_X, bottom_Y);
					checkInside = (Error_RectangleCoordOutsideAxis(cRect) || Error_RectangleIsTooSmall(cRect));
				} while (checkInside);
			}
		} while (check);
		cout << "The new rectangle coordinates are : ";
		cRect.Print();

		// Метод уменьшает размер прямоугольника, двигая границы относительно центральной точки;
		do
		{
			cout << "\nHow much to decrease the size of the rectangle "
				<< '(' << cRect.getLeftX() << ", " << cRect.getTopY() << " ; "
				<< cRect.getRightX() << ", " << cRect.getBottomY() << ") ?"
				<< "\nIn that order: "
				<< "\nleft_X -> top_Y -> right_X -> bottom_Y :\n";
			cin >> left_X;
			cin >> top_Y;
			cin >> right_X;
			cin >> bottom_Y;
			cRect.DeflateRect(left_X, top_Y, right_X, bottom_Y);
			check = (Error_RectangleCoordOutsideAxis(cRect) || Error_RectangleIsTooSmall(cRect));
			if (check)
			{
				do
				{
					cout << "Enter the coordinates of the rectangle"
						<< "\nIn that order: "
						<< "\nleft_X -> top_Y -> right_X -> bottom_Y :\n";
					cin >> left_X;
					cin >> top_Y;
					cin >> right_X;
					cin >> bottom_Y;
					cRect.SetRect(left_X, top_Y, right_X, bottom_Y);
					checkInside = (Error_RectangleCoordOutsideAxis(cRect) || Error_RectangleIsTooSmall(cRect));
				} while (checkInside);
			}
		} while (check);
		cout << "The new rectangle coordinates are : ";
		cRect.Print();

		// Метод смещает прямоугольник на заданную величину;
		do
		{
			cout << "\nEnter the amount you want to shift the rectangle "
				<< '(' << cRect.getLeftX() << ", " << cRect.getTopY() << " ; "
				<< cRect.getRightX() << ", " << cRect.getBottomY() << ") :"
				<< "\nIn that order : "
				<< "\n\"X\" -> \"Y\" :\n";
			cin >> pointCoordX;
			cin >> pointCoordY;
			cRect.OffsetRect(pointCoordX, pointCoordY);
			check = (Error_RectangleCoordOutsideAxis(cRect) || Error_RectangleIsTooSmall(cRect));
			if (check)
			{
				do
				{
					cout << "Enter the coordinates of the rectangle"
						<< "\nIn that order: "
						<< "\nleft_X -> top_Y -> right_X -> bottom_Y :\n";
					cin >> left_X;
					cin >> top_Y;
					cin >> right_X;
					cin >> bottom_Y;
					cRect.SetRect(left_X, top_Y, right_X, bottom_Y);
					checkInside = Error_RectangleCoordOutsideAxis(cRect);
				} while (checkInside);
			}
		} while (check);
		cout << "The new rectangle coordinates are : ";
		cRect.Print();

		// Сброс положения координат прямоугольника перед возможным повтором.
		cRect.SetRectEmpty();
		cout << "\nThe end !"
			<< "\nAll rectangle coordinates are reset!" << endl;

		cout << endl;
		cout << "Do you want to repeat? ( y (yes) / n (no) )\n";
		cin >> repeat;
		cout << endl;

	} while (repeat == 'y');
}