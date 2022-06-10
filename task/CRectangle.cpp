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
}

// ������� ��� ��������� ������:
// ������. ���������� ��������������, ��������� �� ��������� ��� ��������� !
bool Error_RectangleCoordOutsideAxis(CRectangle& cRect)
{
	// ������. ���������� ��������������, ��������� �� ��������� ��� ��������� !
	if (cRect.getLeftX() < 0 || cRect.getTopY() < 0 || cRect.getRightX() < 0 || cRect.getBottomY() < 0)
	{
		cRect.SetRectEmpty();
		cout << "\nError. The coordinate of the rectangle is outside the coordinate axis, coordinates reset !"
			<< "\nTry again !" << endl;

		return true;
	}
	else
		return false;
}

// ������. ����������� ������������� �� ����� ���� ������ 1 � 1 � 1 � 1 !
bool Error_RectangleIsTooSmall(CRectangle& cRect)
{
	if (cRect.getRightX() - cRect.getLeftX() < 1 || cRect.getBottomY() - cRect.getTopY() < 1)
	{
		cRect.SetRectEmpty();
		cout << "\nError. The reduced rectangle cannot be smaller than 1 x 1 x 1 x 1 !, coordinates reset !"
			<< "\nTry again !" << endl;

		return true;
	}
	else
		return false;
}

// ������. ���������� �������� ����� ��������� ��� ��� ��������� !
bool Error_PointCoordOutsideAxis(int& pointCoordX, int& pointCoordY)
{
	if (pointCoordX < 0 || pointCoordY < 0)
	{
		pointCoordX = 0;
		pointCoordY = 0;
		cout << "\nError. The coordinates of the specified point are outside the coordinate axis !, coordinates reset !"
			<< "\nTry again !" << endl;

		return true;
	}
	else
		return false;
}