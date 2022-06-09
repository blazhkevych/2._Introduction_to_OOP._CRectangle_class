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

	������: �������� �� ����� ����� �������� ������ ? (� ���� ������� �� �������).
	� �������: 2:54:30.

	��������� ���������:
	* ������������� �� ����� �� ����� ���������
	* ������������� ������ ������� �� �������� � ������������ ������� ���������
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

		// ������ ��������������;
		cout << endl
			<< "Width = " << cRect.Width()
			<< endl << endl

			// ������ ��������������;
			<< "Height = " << cRect.Height()
			<< endl << endl

			// ����� ���������� ������, ���� ��� ��������� = 0;
			<< "All parameters are 0 ? - " << boolalpha << cRect.IsRectNull()
			<< endl << endl

			// ����� ���������� ������, ���� ����� ����� ������ ��������������;
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

			// ����� ����������� ������ ��������������, ������ ������� ������������ ����������� �����;
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

		// ����� ��������� ������ ��������������, ������ ������� ������������ ����������� �����;
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

		// ����� ������� ������������� �� �������� ��������;
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