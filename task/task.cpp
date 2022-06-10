/*
			�������� � ���. ����� CRectangle.
	����������� ����� CRectangle. ���������� ����� �������������, � ����� �����
������������ ��������-�����������. ������������� � ������ ������ ���
������������ ��������������, ����������� ��������������, ��������� �������
��������������, ���������� ������� �������������� � ��.
������-����� (����):
	left - ����� �������;
	right � ������ �������;
	top � ������� �������;
	bottom - ������ �������
			�������-����� (������):
	CRectangle( ); - ����������� �� ���������;
	CRectangle( int l, int t, int r, int b ); - ����������� � ����������� (����, ����,
�����, ���);
	int Width( ); - ������ ��������������;
	int Height( ); - ������ ��������������;
	bool IsRectNull( ); - ����� ���������� ������, ���� ��� ��������� = 0;
	bool PtInRect( int x, int y ); - ����� ���������� ������, ���� ����� �����
������ ��������������;
	void SetRect( int x1, int y1, int x2, int y2 ); - ��������� ������� � ���������;
	void SetRectEmpty( ); - ��������� ���� ��������� �������������� � 0;
	void InflateRect( int l, int t, int r, int b ); - ����� ����������� ������
��������������, ������ ������� ������������ ����������� �����;
	void DeflateRect( int l, int t, int r, int b ); - ����� ��������� ������
��������������, ������ ������� ������������ ����������� �����;
	void NormalizeRect( ); - ����� ����������� ����������
��������������, �.�. ���� ����� ������� ����� ���������� ������, ���
������, �� ��� �������� �������, �� �� ����� ��������� � ������� �
������ �������� ��������������;
	void OffsetRect( int x, int y ); - ����� ������� ������������� ��
�������� ��������;
	void Print (); - ����� ������� �� ����� �������������.


	������ : ������.

	��������� ���������:
	* �������� �������� �� �������� �������
	* ����� �� ������ ������� ��������� � ���������� �� ��� �������������� �� �������� �����������.

	��������� ������:
	* ��� ���������� ��������������, � ���� ����� ������� ��� ������.
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
	char repeat{ 0 }; // ��������� ������� ?
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

		// ������ ��������������;
		cout << endl
			<< "Width = " << cRect.Width()
			<< endl << endl

			// ������ ��������������;
			<< "Height = " << cRect.Height()
			<< endl << endl

			// ����� ���������� ������, ���� ��� ��������� = 0;
			<< "All parameters are 0 ? - " << boolalpha << cRect.IsRectNull()
			<< endl << endl;

		// ����� ���������� ������, ���� ����� ����� ������ ��������������;
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

		// ����� ����������� ������ ��������������, ������ ������� ������������ ����������� �����;
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

		// ����� ��������� ������ ��������������, ������ ������� ������������ ����������� �����;
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

		// ����� ������� ������������� �� �������� ��������;
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

		// ����� ��������� ��������� �������������� ����� ��������� ��������.
		cRect.SetRectEmpty();
		cout << "\nThe end !"
			<< "\nAll rectangle coordinates are reset!" << endl;

		cout << endl;
		cout << "Do you want to repeat? ( y (yes) / n (no) )\n";
		cin >> repeat;
		cout << endl;

	} while (repeat == 'y');
}