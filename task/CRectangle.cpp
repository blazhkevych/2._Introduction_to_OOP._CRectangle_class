#include "CRectangle.h"

// ������� - �����(������) :
// ����������� �� ���������;
/*
CRectangle::CRectangle()
{
	m_leftX = 1;
	m_rightX = 3;
	m_topY = 1;
	m_bottomY = 3;
}
*/

// ����������� � �����������(����, ����, �����, ���);
CRectangle::CRectangle(int l = 1, int t = 1, int r = 3, int b = 3)
{
	// ���������� ������ 
}

// ������ ��������������;
int CRectangle::Width()
{

}

// ������ ��������������;
int CRectangle::Height()
{

}

// ����� ���������� ������, ���� ��� ��������� = 0;
bool CRectangle::IsRectNull()
{

}

// ����� ���������� ������, ���� ����� ����� ������ ��������������;
bool CRectangle::PtInRect(int x, int y)
{

}

// ��������� ������� � ���������;
void CRectangle::SetRect(int x1, int y1, int x2, int y2)
{

}

// ��������� ���� ��������� �������������� � 0;
void CRectangle::SetRectEmpty()
{

}

// ����� ����������� ������ ��������������, ������ ������� ������������ ����������� �����;
void CRectangle::InflateRect(int l, int t, int r, int b)
{

}

// ����� ��������� ������ ��������������, ������ ������� ������������ ����������� �����;
void CRectangle::DeflateRect(int l, int t, int r, int b)
{

}

// ����� ����������� ���������� ��������������, �.�.���� ����� ������� ����� ���������� ������, 
// ��� ������, �� ��� �������� �������, �� �� ����� ��������� � ������� � ������ �������� ��������������;
void CRectangle::NormalizeRect()
{

}

// ����� ������� ������������� �� �������� ��������;
void CRectangle::OffsetRect(int x, int y)
{

}

// ����� ������� �� ����� �������������.
void CRectangle::Print()
{

}