#include "CRectangle.h"

// Функции - члены(методы) :
// Конструктор по умолчанию;
/*
CRectangle::CRectangle()
{
	m_leftX = 1;
	m_rightX = 3;
	m_topY = 1;
	m_bottomY = 3;
}
*/

// Конструктор с параметрами(лево, верх, право, низ);
CRectangle::CRectangle(int l = 1, int t = 1, int r = 3, int b = 3)
{
	// продолжить отсюда 
}

// Ширина прямоугольника;
int CRectangle::Width()
{

}

// Высота прямоугольника;
int CRectangle::Height()
{

}

// Метод возвращает истину, если все параметры = 0;
bool CRectangle::IsRectNull()
{

}

// Метод возвращает истину, если точка лежит внутри прямоугольника;
bool CRectangle::PtInRect(int x, int y)
{

}

// Установка размера и координат;
void CRectangle::SetRect(int x1, int y1, int x2, int y2)
{

}

// Установка всех координат прямоугольника в 0;
void CRectangle::SetRectEmpty()
{

}

// Метод увеличивает размер прямоугольника, двигая границы относительно центральной точки;
void CRectangle::InflateRect(int l, int t, int r, int b)
{

}

// Метод уменьшает размер прямоугольника, двигая границы относительно центральной точки;
void CRectangle::DeflateRect(int l, int t, int r, int b)
{

}

// Метод нормализует координаты прямоугольника, т.е.если левая сторона имеет координату больше, 
// чем правая, то они меняются местами, то же самое относится к верхней и нижней сторонам прямоугольника;
void CRectangle::NormalizeRect()
{

}

// Метод смещает прямоугольник на заданную величину;
void CRectangle::OffsetRect(int x, int y)
{

}

// Метод выводит на экран прямоугольник.
void CRectangle::Print()
{

}