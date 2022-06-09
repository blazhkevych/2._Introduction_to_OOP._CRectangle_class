#pragma once
class CRectangle
{
	// ������ - �����(����) :
	int m_leftX;	// ���������� �� >> X ����� �������� ����� << ��������������);
	int m_rightX;	// ���������� �� >> X ������ ������ ����� << ��������������);
	int m_topY;	// ���������� �� >> Y ����� �������� ����� << ��������������);
	int m_bottomY;	// ���������� �� >> Y ������ ������ ����� << ��������������);
public:
	// ������-���������:
	// ���������� (��������� �������� �������� �����)
	int getLeftX() { return m_leftX; }
	int getRightX() { return m_rightX; }
	int getTopY() { return m_topY; }
	int getBottomY() { return m_bottomY; }

	// ������������ (��������� ���������� �������� �����)
	int setLeftX(int left_X) { m_leftX = left_X; }
	int setRightX(int rightX) { m_rightX = rightX; }
	int setTopY(int topY) { m_topY = topY; }
	int setBottomY(int bottomY) { m_bottomY = bottomY; }

	// ������� - �����(������) :
	// ����������� �� ���������;
	// CRectangle();

	// ����������� � �����������(����, ����, �����, ���);
	CRectangle(int l = 1, int t = 1, int r = 3, int b = 3);

	// ������ ��������������;
	int Width();

	// ������ ��������������;
	int Height();

	// ����� ���������� ������, ���� ��� ��������� = 0;
	bool IsRectNull();

	// ����� ���������� ������, ���� ����� ����� ������ ��������������;
	bool PtInRect(int x, int y);

	// ��������� ������� � ���������;
	void SetRect(int x1, int y1, int x2, int y2);

	// ��������� ���� ��������� �������������� � 0;
	void SetRectEmpty();

	// ����� ����������� ������ ��������������, ������ ������� ������������ ����������� �����;
	void InflateRect(int l, int t, int r, int b);

	// ����� ��������� ������ ��������������, ������ ������� ������������ ����������� �����;
	void DeflateRect(int l, int t, int r, int b);

	// ����� ����������� ���������� ��������������, �.�.���� ����� ������� ����� ���������� ������, 
	// ��� ������, �� ��� �������� �������, �� �� ����� ��������� � ������� � ������ �������� ��������������;
	void NormalizeRect();

	// ����� ������� ������������� �� �������� ��������;
	void OffsetRect(int x, int y);

	// ����� ������� �� ����� �������������.
	void Print();
};

