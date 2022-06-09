#include <iostream>
#include "CRectangle.h"
using std::cout;
using std::cin;
using std::endl;

// Функции - члены(методы) :
// Конструктор по умолчанию;
CRectangle::CRectangle()
{
	m_leftX = 1;
	m_rightX = 3;
	m_topY = 1;
	m_bottomY = 3;
}


// Конструктор с параметрами(лево, верх, право, низ);
CRectangle::CRectangle(int l, int t, int r, int b)
{
	m_leftX = l;
	m_rightX = r;
	m_topY = t;
	m_bottomY = b;
}

// Ширина прямоугольника;
int CRectangle::Width()
{
	return m_rightX - m_leftX;
}

// Высота прямоугольника;
int CRectangle::Height()
{
	return m_bottomY - m_topY;
}

// Метод возвращает истину, если все параметры = 0;
bool CRectangle::IsRectNull()
{
	return	m_leftX == 0 && m_topY == 0 && m_rightX == 0 && m_bottomY == 0 ? true : false;
}

// Метод возвращает истину, если точка лежит внутри прямоугольника;
bool CRectangle::PtInRect(int x, int y)
{
	return x >= m_leftX && x <= m_rightX &&
		y >= m_topY && y <= m_bottomY ? true : false;
}

// Установка размера и координат;
void CRectangle::SetRect(int x1, int y1, int x2, int y2)
{
	m_leftX = x1;
	m_rightX = x2;
	m_topY = y1;
	m_bottomY = y2;
}

// Установка всех координат прямоугольника в 0;
void CRectangle::SetRectEmpty()
{
	m_leftX = 0;
	m_rightX = 0;
	m_topY = 0;
	m_bottomY = 0;
}

// Метод увеличивает размер прямоугольника, двигая границы относительно центральной точки;
void CRectangle::InflateRect(int l, int t, int r, int b)
{
	m_leftX -= l;
	m_rightX += r;
	m_topY -= t;
	m_bottomY += b;
}

// Метод уменьшает размер прямоугольника, двигая границы относительно центральной точки;
void CRectangle::DeflateRect(int l, int t, int r, int b)
{
	m_leftX += l;
	m_rightX -= r;
	m_topY += t;
	m_bottomY -= b;
}

// Метод нормализует координаты прямоугольника, т.е.если левая сторона имеет координату больше, 
// чем правая, то они меняются местами, то же самое относится к верхней и нижней сторонам прямоугольника;
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

// Метод смещает прямоугольник на заданную величину;
void CRectangle::OffsetRect(int x, int y)
{
	m_leftX += x;
	m_rightX += x;
	m_topY += y;
	m_bottomY += y;
}

// Метод выводит на экран прямоугольник.
void CRectangle::Print()
{
	cout << endl << "m_leftX = " << m_leftX << ", " << "m_topY = " << m_topY << '\n'
		<< "m_rightX = " << m_rightX << ", " << "m_bottomY = " << m_bottomY << endl;
}

// Функция выводит ошибки, в случае, выхода прямоугольника за координаты и обнуляет его координаты.
void IsItCorrect(CRectangle& cRect)
{
	// Ошибка. Прямоугольник, находится за пределами оси координат !
	if (cRect.getLeftX() < 0 || cRect.getTopY() < 0)
	{
		cRect.SetRectEmpty();
		cout << "\nError. The rectangle is outside the coordinate axis, coordinates reset !" << endl;
		return;
	}
	// Ошибка. Уменьшенный прямоугольник не может быть меньше 1 х 1 х 1 х 1 !
	if (cRect.getRightX() - cRect.getLeftX() < 1 || cRect.getBottomY() - cRect.getTopY() < 1)
	{
		cRect.SetRectEmpty();
		cout << "\n// Error. The reduced rectangle cannot be smaller than 1 x 1 x 1 x 1, coordinates reset !" << endl;
	}
}