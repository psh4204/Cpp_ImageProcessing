#pragma once
class CAction
{
public:
	void AddPointName(char* functionName);
	void Undo();
	void Redo();
	void AutoSavePoint();
private:
	// 버퍼 최대값
	int MAX = 250;
	// 이 이상 작업하면 계속 Temp로 저장된다
	int PointNum = 10;
};

