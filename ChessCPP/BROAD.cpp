#include "BROAD.h"

// 检查棋盘状态
int BROAD::Check(int side, int istate = 0)
{
	int state = 空;
	int mmLine, mmColumn;
	mmLine = mmColumn = -1;
	//锁定我 将_帅 位置
	for (int i = 0; i < 行; i++)
	{
		for (int j = 0; j < 列; j++)
		{
			if (((side - 1) * 单方棋数 + 将_帅 + 1) == Broad[i][j])
			{
				mmLine = i, mmColumn = j;
				break;
			}
		}
		if (-1 != mmLine && -1 != mmColumn) break;
	}
	//遍历对方所有棋子
	for (int i = 0; i < 行; i++)
	{
		for (int j = 0; j < 列; j++)
		{
			if ((红方 + 黑方 - side) == (Broad[i][j] - 1) / 单方棋数 + 1)
			{
				int oChess = (Broad[i][j] - 1) % 单方棋数;
				double oDistance = Distance(mmLine, mmColumn, i, j);
				switch (oChess)
				{
				case 将_帅:
					if (mmColumn == j)
					{
						//将_帅 正对，中间没有其他棋子
						bool temp = 1;
						for (int u = min(mmLine, i) + 1; u < max(mmLine, i) && temp; u++)
						{
							temp &= (空 == Broad[u][mmColumn]);
						}
						if (temp && 将军 != istate)
						{
							return 将军;
						}
						else if (temp && 将军 == istate)
						{
							//进一步判断我方能否规避
							return 将军;
						}
					}
					break;
				case 马_馬:
					//判断 将_帅 与 马_馬 的相对位置
					if (2.0 < oDistance && 2.5 > oDistance)
					{
						//位置合理，判断能否将军
						int cLine, cColumn;
						cLine = i + int((mmLine - i) / 2.0);
						cColumn = j + int((mmColumn - j) / 2.0);
						if (空 == Broad[cLine][cColumn] && 将军 != istate)
						{
							return 将军;
						}
						else if (空 == Broad[cLine][cColumn] && 将军 == istate)
						{
							//进一步判断我方能否规避
							return 将军;
						}
					}
					break;
				case 车_車:
					//判断 将_帅 与 车_車 的相对位置
					if ((mmColumn == j && mmLine != i) || (mmColumn != j && mmLine == i))
					{
						bool temp = 1;
						if (mmColumn == j && mmLine != i)
						{
							//将_帅 与 车_車 正对，中间没有其他棋子
							for (int u = min(mmLine, i) + 1; u < max(mmLine, i) && temp; u++)
							{
								temp &= (空 == Broad[u][mmColumn]);
							}
						}
						else if (mmColumn != j && mmLine == i)
						{
							for (int u = min(mmColumn, j) + 1; u < max(mmColumn, j) && temp; u++)
							{
								temp &= (空 == Broad[mmLine][u]);
							}
						}
						if (temp && 将军 != istate)
						{
							return 将军;
						}
						else if (temp && 将军 == istate)
						{
							//进一步判断我方能否规避
							return 将军;
						}
					}
					break;
				case 炮_砲:
					//判断 将_帅 与 炮_砲 的相对位置
					if ((mmColumn == j && mmLine != i) || (mmColumn != j && mmLine == i))
					{
						int temp = 0;
						if (mmColumn == j && mmLine != i)
						{
							//将_帅 与 炮_砲 正对，中间要求只有一枚棋子
							for (int u = min(mmLine, i) + 1; u < max(mmLine, i); u++)
							{
								if (空 != Broad[u][mmColumn]) temp++;
							}
						}
						else if (mmColumn != j && mmLine == i)
						{
							for (int u = min(mmColumn, j) + 1; u < max(mmColumn, j); u++)
							{
								if (空 != Broad[u][mmColumn]) temp++;
							}
						}
						if (1 == temp && 将军 != istate)
						{
							return 将军;
						}
						else if (1 == temp && 将军 == istate)
						{
							//进一步判断我方能否规避
							return 将军;
						}
					}
					break;
				case 兵_卒:
					//判断 将_帅 与 兵_卒 的相对位置
					if (1.0 == oDistance && 将军 != istate)
					{
						return 将军;
					}
					else if (1.0 == oDistance && 将军 == istate)
					{
						//进一步判断我方能否规避
						return 将军;
					}
					break;
				}
			}
		}
	}
	return 空;
}

BROAD::BROAD()
{
	ltStepMSG = new LISTING<STEP_MESSAGE>((STEP_MESSAGE*)NULL);
	// 加载图片集合
	loadimage(&ChessBroad, TEXT("IMAGE"), MAKEINTRESOURCEA(IDB_BITMAP1));
	loadimage(&Chess[黑車 - 1], TEXT("IMAGE"), MAKEINTRESOURCEA(IDB_BITMAP2));
	loadimage(&Chess[黑将 - 1], TEXT("IMAGE"), MAKEINTRESOURCEA(IDB_BITMAP3));
	loadimage(&Chess[黑马 - 1], TEXT("IMAGE"), MAKEINTRESOURCEA(IDB_BITMAP4));
	loadimage(&Chess[黑炮 - 1], TEXT("IMAGE"), MAKEINTRESOURCEA(IDB_BITMAP5));
	loadimage(&Chess[黑士 - 1], TEXT("IMAGE"), MAKEINTRESOURCEA(IDB_BITMAP6));
	loadimage(&Chess[黑象 - 1], TEXT("IMAGE"), MAKEINTRESOURCEA(IDB_BITMAP7));
	loadimage(&Chess[黑卒 - 1], TEXT("IMAGE"), MAKEINTRESOURCEA(IDB_BITMAP8));
	loadimage(&Chess[红兵 - 1], TEXT("IMAGE"), MAKEINTRESOURCEA(IDB_BITMAP9));
	loadimage(&Chess[红車 - 1], TEXT("IMAGE"), MAKEINTRESOURCEA(IDB_BITMAP10));
	loadimage(&Chess[红马 - 1], TEXT("IMAGE"), MAKEINTRESOURCEA(IDB_BITMAP11));
	loadimage(&Chess[红炮 - 1], TEXT("IMAGE"), MAKEINTRESOURCEA(IDB_BITMAP12));
	loadimage(&Chess[红仕 - 1], TEXT("IMAGE"), MAKEINTRESOURCEA(IDB_BITMAP13));
	loadimage(&Chess[红帅 - 1], TEXT("IMAGE"), MAKEINTRESOURCEA(IDB_BITMAP14));
	loadimage(&Chess[红相 - 1], TEXT("IMAGE"), MAKEINTRESOURCEA(IDB_BITMAP15));
	loadimage(&Select, TEXT("IMAGE"), MAKEINTRESOURCEA(IDB_BITMAP16));
	loadimage(&SelectBG, TEXT("IMAGE"), MAKEINTRESOURCEA(IDB_BITMAP17));
	loadimage(&Remain, TEXT("IMAGE"), MAKEINTRESOURCEA(IDB_BITMAP18));
	loadimage(&MSGFrame, TEXT("IMAGE"), MAKEINTRESOURCEA(IDB_BITMAP19));
}

// 棋盘初始化
void BROAD::Init()
{
	for (int i = 0; i < 总棋数; i++)
	{
		StepChess[红方-1][i] = StepChess[黑方 - 1][i] = 空;
	}
	Step = 0;
	for (int i = 0; i < 行; i++)
	{
		for (int j = 0; j < 列; j++)
		{
			Broad[i][j] = 空;
		}
	}
	Broad[0][0] = Broad[0][8] = 黑車;
	Broad[0][1] = Broad[0][7] = 黑马;
	Broad[0][2] = Broad[0][6] = 黑象;
	Broad[0][3] = Broad[0][5] = 黑士;
	Broad[0][4] = 黑将;
	Broad[2][1] = Broad[2][7] = 黑炮;
	Broad[3][0] = Broad[3][2] = Broad[3][4] = Broad[3][6] = Broad[3][8] = 黑卒;
	Broad[9][0] = Broad[9][8] = 红車;
	Broad[9][1] = Broad[9][7] = 红马;
	Broad[9][2] = Broad[9][6] = 红相;
	Broad[9][3] = Broad[9][5] = 红仕;
	Broad[9][4] = 红帅;
	Broad[7][1] = Broad[7][7] = 红炮;
	Broad[6][0] = Broad[6][2] = Broad[6][4] = Broad[6][6] = Broad[6][8] = 红兵;
	initgraph(整格大小 * (列 + 1) + 信息框宽度, 整格大小 * (行 + 1));
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 20;
	strcpy_s(f.lfFaceName, _T("黑体"));
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
	setbkmode(TRANSPARENT);
}

// 棋盘绘制
void BROAD::ShowBroad()
{
	BeginBatchDraw();
	putimage(0, 0, &ChessBroad);
	setfillcolor(BLACK);
	for (int i = 0; i < 行; i++)
	{
		for (int j = 0; j < 列; j++)
		{
			if (空 != Broad[i][j])
			{
				solidcircle((j + 1) * 整格大小, (i + 1) * 整格大小, 半格大小 - 3);
			}
		}
	}
	for (int i = 0; i < 行; i++)
	{
		for (int j = 0; j < 列; j++)
		{
			if (空 != Broad[i][j])
			{
				putimage(j * 整格大小 + 半格大小, i * 整格大小 + 半格大小, &Chess[Broad[i][j] - 1], SRCPAINT);
			}
		}
	}
	EndBatchDraw();
}

// 选择棋子
void BROAD::SelectChess(int line, int column)
{
	BeginBatchDraw();
	putimage(column * 整格大小 + 半格大小, line * 整格大小 + 半格大小, &SelectBG, SRCAND);
	putimage(column * 整格大小 + 半格大小, line * 整格大小 + 半格大小, &Select, SRCPAINT);
	EndBatchDraw();
}

// 上一步棋子信息残留绘制
void BROAD::PositionRemain()
{
	if (0 == ltStepMSG->GetCount()) return;
	int line1, column1, line2, column2;
	STEP_MESSAGE* pLastMsg = ltStepMSG->GetLast();
	line1 = pLastMsg->nSLine, column1 = pLastMsg->nSColumn;
	line2 = pLastMsg->nELine, column2 = pLastMsg->nEColumn;
	BeginBatchDraw();
	putimage(column1 * 整格大小 + 半格大小, line1 * 整格大小 + 半格大小, &SelectBG, SRCAND);
	putimage(column1 * 整格大小 + 半格大小, line1 * 整格大小 + 半格大小, &Remain, SRCPAINT);
	putimage(column2 * 整格大小 + 半格大小, line2 * 整格大小 + 半格大小, &SelectBG, SRCAND);
	putimage(column2 * 整格大小 + 半格大小, line2 * 整格大小 + 半格大小, &Remain, SRCPAINT);
	EndBatchDraw();
}

// 移动/切换/选择/吃子(由某点转移选择到另一点)
bool BROAD::MoveCheck(int nFromColumn, int nFromLine, int nToColumn, int nToLine)
{
	bool is = FALSE;
	int From = Broad[nFromLine][nFromColumn];
	int To = Broad[nToLine][nToColumn];
	int FromSide = (From - 1) / 单方棋数 + 1, FromChess = (From - 1) % 单方棋数;
	int ToSide = (To - 1) / 单方棋数 + 1, ToChess = (To - 1) % 单方棋数;
	if (空 == To)
	{
		ToSide = ToChess = 空;
	}
	//棋子移动判断
	double dis = Distance(nFromColumn, nFromLine, nToColumn, nToLine);
	switch (FromChess)
	{
	case 将_帅:
		if (1.0 == dis)
		{
			if (黑方 == FromSide && (0 <= nToLine && 2 >= nToLine && 3 <= nToColumn && 5 >= nToColumn))
			{
				is = (FromSide != ToSide);
			}
			else if (红方 == FromSide && (7 <= nToLine && 9 >= nToLine && 3 <= nToColumn && 5 >= nToColumn))
			{
				is = (FromSide != ToSide);
			}
		}
		break;
	case 士_仕:
		if (1.0 < dis && 1.5 > dis)
		{
			if (黑方 == FromSide && (0 <= nToLine && 2 >= nToLine && 3 <= nToColumn && 5 >= nToColumn))
			{
				is = (FromSide != ToSide);
			}
			else if (红方 == FromSide && (7 <= nToLine && 9 >= nToLine && 3 <= nToColumn && 5 >= nToColumn))
			{
				is = (FromSide != ToSide);
			}
		}
		break;
	case 象_相:
		if (2.5 < dis && 3.0 > dis)
		{
			if (黑方 == FromSide && (0 <= nToLine && 4 >= nToLine && 0 <= nToColumn && 8 >= nToColumn))
			{
				is = (FromSide != ToSide);
			}
			else if (红方 == FromSide && (5 <= nToLine && 9 >= nToLine && 0 <= nToColumn && 8 >= nToColumn))
			{
				is = (FromSide != ToSide);
			}
		}
		break;
	case 马_馬:
		if (2.0 < dis && 2.5 > dis)
		{
			if (0 <= nToLine && 9 >= nToLine && 0 <= nToColumn && 8 >= nToColumn)
			{
				int cLine, cColumn;
				cLine = nFromLine + int((nToLine - nFromLine) / 2.0);
				cColumn = nFromColumn + int((nToColumn - nFromColumn) / 2.0);
				if (空 == Broad[cLine][cColumn] && FromSide != ToSide)
				{
					is = 1;
				}
			}
		}
		break;
	case 车_車:
		if ((nFromLine == nToLine && nFromColumn != nToColumn) || (nFromLine != nToLine && nFromColumn == nToColumn))
		{
			if (0 <= nToLine && 9 >= nToLine && 0 <= nToColumn && 8 >= nToColumn)
			{
				//要求两点之间没有其他棋子
				bool temp = 1;
				if (nFromLine == nToLine && nFromColumn != nToColumn)
				{
					for (int i = min(nFromColumn, nToColumn) + 1; i < max(nFromColumn, nToColumn) && temp; i++)
					{
						temp &= (空 == Broad[nFromLine][i]);
					}
				}
				else if (nFromLine != nToLine && nFromColumn == nToColumn)
				{
					for (int i = min(nFromLine, nToLine) + 1; i < max(nFromLine, nToLine) && temp; i++)
					{
						temp &= (空 == Broad[i][nFromColumn]);
					}
				}
				if (temp && FromSide != ToSide)
				{
					is = 1;
				}
			}
		}
		break;
	case 炮_砲:
		if (nFromLine == nToLine && nFromColumn != nToColumn)
		{
			if (0 <= nToLine && 9 >= nToLine)
			{
				//移动要求两点之间没有其他棋子，吃子要求两点之间仅有一枚棋子
				int temp = 0;
				for (int i = min(nFromColumn, nToColumn) + 1; i < max(nFromColumn, nToColumn); i++)
				{
					if (空 != Broad[nFromLine][i])
					{
						temp++;
					}
				}
				if ((空 == ToSide && 0 == temp) || (红方 + 黑方 == FromSide + ToSide && 1 == temp))
				{
					is = 1;
				}
			}
		}
		else if (nFromLine != nToLine && nFromColumn == nToColumn)
		{
			if (0 <= nToColumn && 8 >= nToColumn)
			{
				//移动要求两点之间没有其他棋子，吃子要求两点之间仅有一枚棋子
				int temp = 0;
				for (int i = min(nFromLine, nToLine) + 1; i < max(nFromLine, nToLine); i++)
				{
					if (空 != Broad[i][nFromColumn])
					{
						temp++;
					}
				}
				if ((空 == ToSide && 0 == temp) || (红方 + 黑方 == FromSide + ToSide && 1 == temp))
				{
					is = 1;
				}
			}
		}
		break;
	case 兵_卒:
		if (1.0 == dis)
		{
			if (0 <= nToLine && 9 >= nToLine && 0 <= nToColumn && 8 >= nToColumn)
			{
				if (黑方 == FromSide)
				{
					if (3 <= nFromLine && 4 >= nFromLine && nFromLine < nToLine)
					{
						//本方地盘，单向移动
						is = (FromSide != ToSide);
					}
					else if (5 <= nFromLine && 9 >= nFromLine && nFromLine <= nToLine)
					{
						//对方地盘，三向移动
						is =(FromSide != ToSide);
					}
				}
				else if (红方 == FromSide)
				{
					if (5 <= nFromLine && 6 >= nFromLine && nFromLine > nToLine)
					{
						//本方地盘，单向移动
						is = (FromSide != ToSide);
					}
					else if (0 <= nFromLine && 4 >= nFromLine && nFromLine >= nToLine)
					{
						//对方地盘，三向移动
						is = (FromSide != ToSide);
					}
				}
			}
		}
		break;
	}
	return is;
}

// 步数增加
void BROAD::UpStep()
{
	Step++;
}

// 指定棋子步数增加
void BROAD::AddStep(int chess)
{
	for (int i = 0; i < 总棋数; i++)
	{
		if (空 == StepChess[i][0])
		{
			StepChess[i][0] = chess;
			StepChess[i][1] = Step + 1;
			break;
		}
	}
	Step++;
}

// 撤销一步
bool BROAD::Cancle()
{
	if (0 == ltStepMSG->GetCount()) return FALSE;
	STEP_MESSAGE* lastStep = ltStepMSG->GetLast();
	Broad[lastStep->nSLine][lastStep->nSColumn] = lastStep->OPChess;
	if (空 != (Broad[lastStep->nELine][lastStep->nEColumn] = lastStep->BPChess))
	{
		for (int i = 0; i < 总棋数; i++)
		{
			if (空 == StepChess[i][0] && 0 < i)
			{
				StepChess[i - 1][0] = 空;
				StepChess[i - 1][1] = 空;
				break;
			}
		}
	}
	Step--;
	return ltStepMSG->Del(lastStep);
}

// 添加步骤信息
void BROAD::AddMsg(int iopChess, int isLine, int isColumn, int ieLine, int ieColumn, int ibpChess = 空)
{
	STEP_MESSAGE * pNewMsg = new STEP_MESSAGE;
	pNewMsg->Set(iopChess, isLine, isColumn, ieLine, ieColumn, ibpChess);
	ltStepMSG->Add(pNewMsg);
}

// 显示步骤信息
void BROAD::ShowMsg(RECT* rec, int side)
{
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 20;
	settextstyle(&f);
	BeginBatchDraw();
	putimage(整格大小 * (列 + 1), 0, &MSGFrame);
	int count = 0;
	if (1 <= (count = ltStepMSG->GetCount()))
	{
		STEP_MESSAGE* temp = ltStepMSG->GetHead();
		while (20 < count)
		{
			temp = temp->pNextNode;
			count--;
		}
		int i = 0;
		while (NULL != temp)
		{
			RECT rrec = { 整格大小 * (列 + 1) + 5, 5 + 20 * i, 整格大小 * (列 + 1) + 信息框宽度 - 5, 25 + 20 * i };
			if(红方== (temp->OPChess - 1) / 单方棋数 + 1) settextcolor(RED);
			else settextcolor(BLACK);
			drawtext(temp->GetStepMessage().c_str(), &rrec, DT_LEFT | DT_VCENTER | DT_SINGLELINE);
			temp = temp->pNextNode;
			i++;
		}
	}
	gettextstyle(&f);
	f.lfHeight = 30;
	settextstyle(&f);
	settextcolor(GREEN);
	drawtext("退出游戏", &rec[0], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("撤回一步", &rec[1], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	RECT ttrec[2] = { { 605, 500, 725, 530 },{ 705, 500, 765, 530 } };
	drawtext("当前：", &ttrec[0], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	if (红方 == side)
	{
		settextcolor(RED);
		drawtext("红方", &ttrec[1], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
	else if (黑方 == side)
	{
		settextcolor(BLACK);
		drawtext("黑方", &ttrec[1], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
	EndBatchDraw();
}

// 将军判断
int BROAD::Checkmate(int side)
{
	//当前方执行行动后，进行判断
	//判断当前游戏状态
	int state = 空;
	//判断我方状态
	state = Check(side);
	if (将军 == state) return 我方被将;
	else if (空 == state)
	{
		//我方未于被将状态
		//判断敌方状态
		state = Check(红方 + 黑方 - side);
	}
	if (空 == state) return state;
	else if (将军 == state)
	{
		//对方处于被将状态
		//进一步判断
		state = Check(红方 + 黑方 - side, state);
		return 对方被将;
	}
	//1.行动后，游戏正常进行
	//2.行动后，有一方处于被将状态
			//若使当前方处于被将状态，将提醒并撤回当前行动
			//若使敌方处于被将状态，将提醒，进一步判断
				//3.行动后，对方处于被将状态，且无子可走，结束游戏
	return 空;
}

int * BROAD::operator[](int n)
{
	return Broad[n];
}
