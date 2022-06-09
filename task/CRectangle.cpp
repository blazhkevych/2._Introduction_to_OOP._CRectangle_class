#include <iostream>
#include "CRectangle.h"
using std::cout;
using std::cin;
using std::endl;

// ������� - �����(������) :
// ����������� �� ���������;
CRectangle::CRectangle()
{
	m_leftX = 1;
	m_rightX = 3;
	m_topY = 1;
	m_bottomY = 3;
}


// ����������� � �����������(����, ����, �����, ���);
CRectangle::CRectangle(int l, int t, int r, int b)
{
	m_leftX = l;
	m_rightX = r;
	m_topY = t;
	m_bottomY = b;
}

// ������ ��������������;
int CRectangle::Width()
{
	return m_rightX - m_leftX;
}

// ������ ��������������;
int CRectangle::Height()
{
	return m_bottomY - m_topY;
}

// ����� ���������� ������, ���� ��� ��������� = 0;
bool CRectangle::IsRectNull()
{
	return	m_leftX == 0 && m_topY == 0 && m_rightX == 0 && m_bottomY == 0 ? true : false;
}

// ����� ���������� ������, ���� ����� ����� ������ ��������������;
bool CRectangle::PtInRect(int x, int y)
{
	return x >= m_leftX && x <= m_rightX &&
		y >= m_topY && y <= m_bottomY ? true : false;
}

// ��������� ������� � ���������;
void CRectangle::SetRect(int x1, int y1, int x2, int y2)
{
	m_leftX = x1;
	m_rightX = x2;
	m_topY = y1;
	m_bottomY = y2;
}

// ��������� ���� ��������� �������������� � 0;
void CRectangle::SetRectEmpty()
{
	m_leftX = 0;
	m_rightX = 0;
	m_topY = 0;
	m_bottomY = 0;
}

// ����� ����������� ������ ��������������, ������ ������� ������������ ����������� �����;
void CRectangle::InflateRect(int l, int t, int r, int b)
{
	m_leftX -= l;
	m_rightX += r;
	m_topY -= t;
	m_bottomY += b;
}

// ����� ��������� ������ ��������������, ������ ������� ������������ ����������� �����;
void CRectangle::DeflateRect(int l, int t, int r, int b)
{
	m_leftX += l;
	m_rightX -= r;
	m_topY += t;
	m_bottomY -= b;
}

// ����� ����������� ���������� ��������������, �.�.���� ����� ������� ����� ���������� ������, 
// ��� ������, �� ��� �������� �������, �� �� ����� ��������� � ������� � ������ �������� ��������������;
void CRectangle::NormalizeRect()
{
	if (m_leftX > m_rightX)
	{
		int temp = m_leftX;
		m_leftX = m_rightX;
		m_rightX = temp;
	}
	if (m_topY > m_bottomY)
	{
		int temp = m_topY;
		m_topY = m_bottomY;
		m_bottomY = temp;
	}
}

// ����� ������� ������������� �� �������� ��������;
void CRectangle::OffsetRect(int x, int y)
{
	m_leftX += x;
	m_rightX += x;
	m_topY += y;
	m_bottomY += y;
}

// ����� ������� �� ����� �������������.
void CRectangle::Print()
{
	cout << endl << "m_leftX = " << m_leftX << ", " << "m_topY = " << m_topY << '\n'
		<< "m_rightX = " << m_rightX << ", " << "m_bottomY = " << m_bottomY << endl;
	/*cout << endl;
	for (int i = 0; i < length; i++)
	{

	}*/
}

//// ����� ������� ������ �� ���� ��������� ��������� ��������������
//void EnterCoordinates(CRectangle& cRect)
//{
//	int lexf_X{ 0 }, top_Y{ 0 }, right_X{ 0 }, bottom_Y{ 0 };
//	cout << "Enter the coordinates of the upper left point of the rectangle (\"X\" then \"Y\"):\n"
//		<< "lexf_X = ";
//	cin >> lexf_X;
//	cRect.setLeftX(lexf_X);
//	cout << "top_Y = ";
//	cin >> top_Y;
//	cRect.setTopY(top_Y);
//	cout << "Enter the coordinates of the lower right point of the rectangle (\"X\" then \"Y\"):\n"
//		<< "right_X = ";
//	cin >> right_X;
//	cRect.setRightX(right_X);
//	cout << "bottom_Y = ";
//	cin >> bottom_Y;
//	cRect.setBottomY(bottom_Y);
//}