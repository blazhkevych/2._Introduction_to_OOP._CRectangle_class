#pragma once
class CRectangle
{
	// Данные - члены(поля) :
	int m_leftX;	// координата по >> X левой верхнней точки << прямоугольника);
	int m_rightX;	// координата по >> X правой нижней точки << прямоугольника);
	int m_topY;	// координата по >> Y левой верхнней точки << прямоугольника);
	int m_bottomY;	// координата по >> Y правой нижней точки << прямоугольника);
public:
	// Методы-аксессоры:
	// Инспекторы (позволяют получить значения полей)
	int getLeftX() { return m_leftX; }
	int getRightX() { return m_rightX; }
	int getTopY() { return m_topY; }
	int getBottomY() { return m_bottomY; }

	// Модификаторы (позволяют установить значения полей)
	int setLeftX(int left_X) { m_leftX = left_X; }
	int setRightX(int rightX) { m_rightX = rightX; }
	int setTopY(int topY) { m_topY = topY; }
	int setBottomY(int bottomY) { m_bottomY = bottomY; }

	// Функции - члены(методы) :
	// Конструктор по умолчанию;
	// CRectangle();

	// Конструктор с параметрами(лево, верх, право, низ);
	CRectangle(int l = 1, int t = 1, int r = 3, int b = 3);

	// Ширина прямоугольника;
	int Width();

	// Высота прямоугольника;
	int Height();

	// Метод возвращает истину, если все параметры = 0;
	bool IsRectNull();

	// Метод возвращает истину, если точка лежит внутри прямоугольника;
	bool PtInRect(int x, int y);

	// Установка размера и координат;
	void SetRect(int x1, int y1, int x2, int y2);

	// Установка всех координат прямоугольника в 0;
	void SetRectEmpty();

	// Метод увеличивает размер прямоугольника, двигая границы относительно центральной точки;
	void InflateRect(int l, int t, int r, int b);

	// Метод уменьшает размер прямоугольника, двигая границы относительно центральной точки;
	void DeflateRect(int l, int t, int r, int b);

	// Метод нормализует координаты прямоугольника, т.е.если левая сторона имеет координату больше, 
	// чем правая, то они меняются местами, то же самое относится к верхней и нижней сторонам прямоугольника;
	void NormalizeRect();

	// Метод смещает прямоугольник на заданную величину;
	void OffsetRect(int x, int y);

	// Метод выводит на экран прямоугольник.
	void Print();
};

