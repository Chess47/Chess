#include "BROAD.h"
#include <graphics.h>

int main()
{
	BROAD the_Broad;
	the_Broad.Init();
	the_Broad.ShowBroad();

	RECT rec[2]=
	{
	{ 605, 420, 795, 450 },
	{ 605, 460, 795, 490 }
	};
	int nLastColumn, nLastLine;
	int tempColumn[2] = { -1 }, tempLine[2] = { -1 };
	int nSide = 红方;
	nLastColumn = nLastLine = -1;
	the_Broad.ShowMsg(rec, nSide);

	while (1)
	{
		// 鼠标响应
		if (MouseHit())
		{
			MOUSEMSG mmsg = GetMouseMsg();
			Sleep(3);
			FlushMouseMsgBuffer();
			int mx = mmsg.x, my = mmsg.y;
			int x = (mx - 半格大小) / 整格大小, y = (my - 半格大小) / 整格大小;
			// 鼠标点击
			if (1 == mmsg.mkLButton && 0 == mmsg.mkRButton)
			{
				if (0 <= x && 列 > x && 0 <= y && 行 > y)
				{
					if (空 != the_Broad[y][x])
					{
						//点击棋子
						if (-1 == nLastColumn && -1 == nLastLine)
						{
							//上一步未选择棋子
							//棋子选择
							// 若为当前方棋子，则能够成功选中
							if (nSide == (the_Broad[y][x] - 1) / 单方棋数 + 1)
							{
								the_Broad.SelectChess(y, x);
								//成功选择，标记为 - 当前已选择棋子
								nLastColumn = x, nLastLine = y;
							}
						}
						else
						{
							//上一步已选择棋子
							//棋子判断
							//获取上一步选中的棋子
							int LastChess = the_Broad[nLastLine][nLastColumn];
							//同方棋子，切换选择
							if (((LastChess - 1) / 单方棋数) == ((the_Broad[y][x] - 1) / 单方棋数))
							{
								//重绘棋盘
								the_Broad.ShowBroad();
								//位置遗留
								the_Broad.PositionRemain();
								//棋子选择
								the_Broad.SelectChess(y, x);
								//成功选择，标记为 - 当前已选择棋子
								nLastColumn = x, nLastLine = y;
							}
							else
							{
								//异方棋子，吃子判断
								if (the_Broad.MoveCheck(nLastColumn, nLastLine, x, y))
								{
									//该行动成功
									the_Broad.AddStep(the_Broad[y][x]);
									the_Broad.AddMsg(the_Broad[nLastLine][nLastColumn], nLastLine, nLastColumn, y, x, the_Broad[y][x]);
									the_Broad[y][x] = the_Broad[nLastLine][nLastColumn];
									the_Broad[nLastLine][nLastColumn] = 空;
									//判断状态
									int state = the_Broad.Checkmate(nSide);
									if (空 != state)
									{
										//撤回当前一步
										if (我方被将 == state)
										{
											if (the_Broad.Cancle()) Beep(1000, 100);
										}
									}
									//重绘棋盘
									the_Broad.ShowBroad();
									//位置遗留
									the_Broad.PositionRemain();
									//行动成功，标记为 - 当前未选择棋子
									nLastColumn = nLastLine = -1;
									//切换行动方
									if (我方被将 != state) nSide = 红方 + 黑方 - nSide;
									//显示信息
									the_Broad.ShowMsg(rec, nSide);
								}
							}
						}
					}
					else
					{
						//点击空处
						if (-1 != nLastColumn && -1 != nLastLine)
						{
							//上一步已选择棋子
							//移动判断
							if (the_Broad.MoveCheck(nLastColumn, nLastLine, x, y))
							{
								//该位置能够移动
								the_Broad.UpStep();
								the_Broad.AddMsg(the_Broad[nLastLine][nLastColumn], nLastLine, nLastColumn, y, x, the_Broad[y][x]);
								the_Broad[y][x] = the_Broad[nLastLine][nLastColumn];
								the_Broad[nLastLine][nLastColumn] = 空;
								//判断状态
								int state = the_Broad.Checkmate(nSide);
								if (空 != state)
								{
									//撤回当前一步
									if (我方被将 == state)
									{
										if(the_Broad.Cancle()) Beep(1000, 100);
									}
								}
								//重绘棋盘
								the_Broad.ShowBroad();
								//位置遗留
								the_Broad.PositionRemain();
								//行动成功，标记为 - 当前未选择棋子
								nLastColumn = nLastLine = -1;
								//切换行动方
								if (我方被将 != state) nSide = 红方 + 黑方 - nSide;
								//显示信息
								the_Broad.ShowMsg(rec, nSide);
							}
						}
					}
				}
				else if (rec[0].left < mx && rec[0].right > mx && rec[0].top < my && rec[0].bottom > my)
				{
					//按下退出游戏
					exit(0);
				}
				else if (rec[1].left < mx && rec[1].right > mx && rec[1].top < my && rec[1].bottom > my)
				{
					//按下撤回一步
					if (FALSE == the_Broad.Cancle())
					{
						MessageBox(GetHWnd(), "当前无法撤回！", "警告", MB_OK);
					}
					else
					{
						//重绘棋盘
						the_Broad.ShowBroad();
						//位置遗留
						the_Broad.PositionRemain();
						//行动成功，标记为 - 当前未选择棋子
						nLastColumn = nLastLine = -1;
						//切换行动方
						nSide = 红方 + 黑方 - nSide;
						//显示信息
						the_Broad.ShowMsg(rec, nSide);
					}
				}
			}
			else if (0 == mmsg.mkLButton && 1 == mmsg.mkRButton)
			{
				//重绘棋盘
				the_Broad.ShowBroad();
				//位置遗留
				the_Broad.PositionRemain();
				//取消当前标记，标记为 - 当前未选择棋子
				nLastColumn = nLastLine = -1;
			}
		}
	}
	PAUSE;
	return 1;
}