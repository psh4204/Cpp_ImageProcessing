#pragma once
class CAction
{
public:
	void AddPointName(char* functionName);
	void Undo();
	void Redo();
	void AutoSavePoint();
private:
	// ���� �ִ밪
	int MAX = 250;
	// �� �̻� �۾��ϸ� ��� Temp�� ����ȴ�
	int PointNum = 10;
};

