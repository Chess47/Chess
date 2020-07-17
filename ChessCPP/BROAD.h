#pragma once

#include <graphics.h>
#include "My.h"
#include "resource.h"

#define 列	9
#define 行	10
#define 信息框宽度	200
#define 整格大小	60
#define 半格大小	30
#define 单方棋数	7
#define 总棋数	32

#define 将_帅	0
#define 士_仕	1
#define 象_相	2
#define 马_馬	3
#define 车_車	4
#define 炮_砲	5
#define 兵_卒	6

#define 黑方	1
#define 红方	2

#define 空	0
#define 黑将	1
#define 黑士	2
#define 黑象	3
#define 黑马	4
#define 黑車	5
#define 黑炮	6
#define 黑卒	7
#define 红帅	8
#define 红仕	9
#define 红相	10
#define 红马	11
#define 红車	12
#define 红炮	13
#define 红兵	14

#define 将军 9
#define 我方被将 10
#define 对方被将 11
#define 无子可走 12

struct STEP_MESSAGE
{
	int OPChess, BPChess;
	int nSLine, nSColumn, nELine, nEColumn;
	STEP_MESSAGE* pNextNode;
	void Set(int iopChess, int isLine, int isColumn, int ieLine, int ieColumn, int ibpChess = 空, STEP_MESSAGE* NextNode = NULL)
	{
		OPChess = iopChess, nSLine = isLine, nSColumn = isColumn, nELine = ieLine, nEColumn = ieColumn, BPChess = ibpChess, pNextNode = NextNode;
	}
	string GetStepMessage()
	{
		string str = "";
		switch (OPChess)
		{
		case 黑将:str.append("黑将");break;
		case 黑士:str.append("黑士");break;
		case 黑象:str.append("黑象");break;
		case 黑马:str.append("黑马");break;
		case 黑車:str.append("黑車");break;
		case 黑炮:str.append("黑炮");break;
		case 黑卒:str.append("黑卒");break;
		case 红帅:str.append("红帅");break;
		case 红仕:str.append("红仕");break;
		case 红相:str.append("红相");break;
		case 红马:str.append("红马");break;
		case 红車:str.append("红車");break;
		case 红炮:str.append("红炮");break;
		case 红兵:str.append("红兵");break;
		}
		str.append(" ");
		str += char('A' + nSLine);
		str += char('1' + nSColumn);
		str.append(" -> ");
		str += char('A' + nELine);
		str += char('1' + nEColumn);
		switch (BPChess)
		{
		case 空:break;
		case 黑将:str.append(":黑将"); break;
		case 黑士:str.append(":黑士"); break;
		case 黑象:str.append(":黑象"); break;
		case 黑马:str.append(":黑马"); break;
		case 黑車:str.append(":黑車"); break;
		case 黑炮:str.append(":黑炮"); break;
		case 黑卒:str.append(":黑卒"); break;
		case 红帅:str.append(":红帅"); break;
		case 红仕:str.append(":红仕"); break;
		case 红相:str.append(":红相"); break;
		case 红马:str.append(":红马"); break;
		case 红車:str.append(":红車"); break;
		case 红炮:str.append(":红炮"); break;
		case 红兵:str.append(":红兵"); break;
		}
		return str;
	}
};

class BROAD
{
private:
	int Broad[行][列];
	int StepChess[总棋数][2];
	// 步数
	int Step;
	// 图片集合
	IMAGE Chess[14];
	IMAGE ChessBroad;
	IMAGE SelectBG;
	IMAGE Select;
	IMAGE Remain;
	IMAGE MSGFrame;
	int Check(int, int);//判断指定方游戏状态
	// 步骤信息
	LISTING<STEP_MESSAGE>* ltStepMSG;
public:
	BROAD();
	// 棋盘初始化
	void Init();
	// 棋盘绘制
	void ShowBroad();
	// 选择棋子
	void SelectChess(int, int);
	// 上一步棋子信息残留绘制
	void PositionRemain();
	// 移动/切换/选择/吃子(由某点转移选择到另一点)
	bool MoveCheck(int, int, int, int);
	// 步数增加
	void UpStep();
	void AddStep(int);
	// 撤销一步
	bool Cancle();
	// 添加步骤信息
	void AddMsg(int, int, int, int, int, int);
	// 显示步骤信息
	void ShowMsg(RECT*, int);
	// 将军判断
	int Checkmate(int);
public:
	int* operator [] (int);
};

