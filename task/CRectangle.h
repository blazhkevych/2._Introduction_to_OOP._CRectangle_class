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
	void setLeftX(int left_X) { m_leftX = left_X; }
	void setRightX(int rightX) { m_rightX = rightX; }
	void setTopY(int topY) { m_topY = topY; }
	void setBottomY(int bottomY) { m_bottomY = bottomY; }

	// ������� - �����(������) :
	// ����������� �� ���������;
	CRectangle(); // ��������, ��� ��� ��� �������� ����������� � �����������.

   // ����������� � �����������(����, ����, �����, ���);
	CRectangle(int l, int t, int r, int b);

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

// ������� ��������� ������:
// ������. ���������� ��������������, ��������� �� ��������� ��� ��������� !
bool Error_RectangleCoordOutsideAxis(CRectangle& cRect);

// ������. ����������� ������������� �� ����� ���� ������ 1 � 1 � 1 � 1 !
bool Error_RectangleIsTooSmall(CRectangle& cRect);

// ������. ���������� �������� ����� ��������� ��� ��� ��������� !
bool Error_PointCoordOutsideAxis(int& pointCoordX, int& pointCoordY);