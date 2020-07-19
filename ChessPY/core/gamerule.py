import pygame
from gameboard import chessboard
from gameman import chessman
from gamebase import baseclass, START_POINT_X, START_POINT_Y, WEIGHT, LENGTH, SCREEN_RECT
from gametip import tip

import math
import tkinter as tk
from tkinter import StringVar

#界面调试类别
class mainwindow():
    def __init__(self):
        self.screen = tk.Tk()
        self.screen.title('象棋调试')

        #象棋个数
        self.chessnum = StringVar()
        self.chessnum.set(CHESSNUM)
        self.text1 = tk.Label(self.screen,textvariable = self.chessnum).pack
        #落子方
        self.turn = StringVar()
        self.turn.set(TURN)
        self.text2 = tk.Label(self.screen,textvariable = self.turn).pack
        #当前步数
        self.gonumber = StringVar()
        self.gonumber.set(ALLTURNNUM)
        self.text3 = tk.Label(self.screen,textvariable = self.gonumber).pack

        self.screen.mainloop()

#主类
class chessgame(object):
    #初始化
    def __init__(self):
        self.screen = pygame.display.set_mode(SCREEN_RECT.size)
        self.chessman_group = pygame.sprite.Group()
        self.back_group = pygame.sprite.Group()
        #存放棋子的一维数组
        self.chess_array = []
        #存放走子  两个走子  0代表首次走子，奇数代表上次走了红子，偶数代表上次走了黑子
        self.chesskicknum = 0
        #定义两个走子提示
        self.tip_of_red_pre,self.tip_of_red_next,self.tip_of_black_pre,self.tip_of_black_next = tip(),tip(),tip(1),tip(1)
        self.chessman_group.add(self.tip_of_red_pre,self.tip_of_red_next,self.tip_of_black_pre,self.tip_of_black_next)
        #走子记录
        self.record_of_red = [[],[]]
        self.record_of_black = [[],[]]
    #创造精灵组
    def __create_sprites(self):
        global CHESS_ARRAY
        #棋盘
        background = chessboard()
        self.back_group.add(background)

        #红子
        self.redcar1 = chessman(1, 1, 10)
        self.redcar2 = chessman(1, 9, 10)
        self.redhorse1 = chessman(2, 2, 10)
        self.redhorse2 = chessman(2, 8, 10)
        self.redelegant1 = chessman(3, 3, 10)
        self.redelegant2 = chessman(3, 7, 10)
        self.redperson1 = chessman(4, 4, 10)
        self.redperson2 = chessman(4, 6, 10)
        self.redking = chessman(5, 5, 10)
        self.redbomb1 = chessman(6, 2, 8)
        self.redbomb2 = chessman(6, 8, 8)
        self.redsoldier1 = chessman(7, 1, 7)
        self.redsoldier2 = chessman(7, 3, 7)
        self.redsoldier3 = chessman(7, 5, 7)
        self.redsoldier4 = chessman(7, 7, 7)
        self.redsoldier5 = chessman(7, 9, 7)
        self.chessman_group.add(self.redcar1, self.redcar2, self.redhorse1, self.redhorse2, self.redelegant1,
                                 self.redelegant2, self.redperson1, self.redperson2, self.redking, self.redbomb1,
                                 self.redbomb2, self.redsoldier1, self.redsoldier2, self.redsoldier3, self.redsoldier4,
                                 self.redsoldier5)
        #黑子
        self.blackcar1 = chessman(11,1,1)
        self.blackcar2 = chessman(11,9,1)
        self.blackhorse1 = chessman(12,2,1)
        self.blackhorse2 = chessman(12,8,1)
        self.blackelegant1 = chessman(13,3,1)
        self.blackelegant2 = chessman(13,7,1)
        self.blackperson1 = chessman(14,4,1)
        self.blackperson2 = chessman(14,6,1)
        self.blackking = chessman(15,5,1)
        self.blackbomb1 = chessman(16,2,3)
        self.blackbomb2 = chessman(16,8,3)
        self.blacksoldier1 = chessman(17,1,4)
        self.blacksoldier2 = chessman(17,3,4)
        self.blacksoldier3 = chessman(17,5,4)
        self.blacksoldier4 = chessman(17,7,4)
        self.blacksoldier5 = chessman(17,9,4)
        self.chessman_group.add(self.blackcar1,self.blackcar2,self.blackhorse1,self.blackhorse2,self.blackelegant1,
                                self.blackelegant2,self.blackperson1,self.blackperson2,self.blackking,self.blackbomb1,
                                self.blackbomb2,self.blacksoldier1,self.blacksoldier2,self.blacksoldier3,
                                self.blacksoldier4,self.blacksoldier5)
        self.chess_array.append([self.redcar1, self.redcar2, self.redhorse1, self.redhorse2, self.redelegant1,
                                 self.redelegant2, self.redperson1, self.redperson2, self.redking, self.redbomb1,
                                 self.redbomb2, self.redsoldier1, self.redsoldier2, self.redsoldier3, self.redsoldier4,
                                 self.redsoldier5,self.blackcar1,self.blackcar2,self.blackhorse1,self.blackhorse2,self.blackelegant1,
                                self.blackelegant2,self.blackperson1,self.blackperson2,self.blackking,self.blackbomb1,
                                self.blackbomb2,self.blacksoldier1,self.blacksoldier2,self.blacksoldier3,
                                self.blacksoldier4,self.blacksoldier5])
        self.chessman_group.add(self.record_of_red,self.record_of_black)
    #求取鼠标点击点
    def calculate_point(self,x,y):
        xx, yy = x, y
        # 求取点击的点距离哪个十字路口最近
        x = math.floor((x - START_POINT_X) / LENGTH) + 1
        y = math.floor((y - START_POINT_Y) / WEIGHT) + 1
        # 左上起点，顺时针
        array = [[START_POINT_X + (x - 1) * LENGTH, START_POINT_Y + (y - 1) * WEIGHT], [START_POINT_X + (x) * LENGTH, START_POINT_Y + (y - 1) * WEIGHT],
                 [START_POINT_X + (x) * LENGTH, START_POINT_Y + (y) * WEIGHT], [START_POINT_X + (x - 1) * LENGTH, START_POINT_Y + (y) * WEIGHT]]
        array2 = []
        for i in array:
            dis = abs(i[0] - xx) + abs(i[1] - yy)
            array2.append(dis)
        z = min(array2)
        z = array2.index(z) + 1
        # 1 左上 2 右上 3 右下 4 左下
        if z == 1:
            finalx = x
            finaly = y
        elif z == 2:
            finalx = x + 1
            finaly = y
        elif z == 3:
            finalx = x + 1
            finaly = y + 1
        elif z == 4:
            finalx = x
            finaly = y + 1
        else:
            pass
        return [finalx,finaly]
    #事件监听，鼠标摁下？
    def __event_handler(self):
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                chessgame.__game_over()
            #鼠标摁下
            if event.type == pygame.MOUSEBUTTONDOWN:
                #求取出最终点击点
                x,y = pygame.mouse.get_pos()
                a = self.calculate_point(x,y)
                mousex,mousey = a[0],a[1]
                kicknum = 0
                # 棋盘初始化
                self.chessarray = [[0, 0, 0, 0, 0, 0, 0, 0, 0] for i in range(10)]
                for i in self.chess_array[0]:
                    # 将棋盘信息写入数组
                    self.chessarray[i.y-1][i.x-1] = i.chessnum
                #1、点击到棋子上
                for i in self.chess_array[0]:
                    #是否构成点子？
                    if i.x == mousex and i.y == mousey:
                        kicknum = 1
                        #偶数走子 红走子
                        if self.chesskicknum%2 == 0:
                            #点击黑子？--吃子
                            if i.chessnum > 9:
                                for j in self.chess_array[0]:
                                    if j.boolpressed == 1:
                                        #提取当前已经举起的旗子进行判断
                                        a = j.cangoto(mousex,mousey,self.chess_array[0],self.chessarray)
                                        if a:
                                            print('能吃')
                                            #删除被点击的子
                                            i.delself(1)
                                            #移动吃子的子
                                            j.x = mousex
                                            j.y = mousey
                                            #恢复未摁下的状态
                                            j.change(0)
                                            #按照规则来落子
                                            self.chesskicknum += 1
                            #点击红子？--换子下或者点子
                            if i.chessnum < 9:
                                for j in self.chess_array[0]:
                                    #同为红子且已经举起
                                    if j != i and j.chessnum < 9 and j.boolpressed == 1:
                                        j.change(0)
                                i.change(1)

                        #奇数走子 黑走子
                        else:
                            # 点击黑子？
                            if i.chessnum > 9:
                                for j in self.chess_array[0]:
                                    # 同为黑子且已经举起
                                    if j != i and j.chessnum > 9 and j.boolpressed == 1:
                                        j.change(0)
                                i.change(1)
                            # 点击红子？吃子？
                            if i.chessnum < 9:
                                for j in self.chess_array[0]:
                                    if j.boolpressed == 1:
                                        #提取当前已经举起的旗子进行判断
                                        a = j.cangoto(mousex,mousey,self.chess_array[0],self.chessarray)
                                        if a:
                                            print('能吃')
                                            #删除被点击的子
                                            i.delself(1)
                                            #移动吃子的子
                                            j.x = mousex
                                            j.y = mousey
                                            j.change(0)
                                            # 按照规则来落子
                                            self.chesskicknum += 1
                #2、点空地 判断能否走到
                if kicknum == 0:
                    #判断是否有子处于举起状态？
                    for i in self.chess_array[0]:
                        #对按起来的旗子进行规则判断
                        if i.boolpressed == 1:
                            a=i.cangoto(mousex,mousey,self.chess_array[0],self.chessarray)
                            if a:
                                #如果是红色
                                if self.chesskicknum %2 == 0:
                                    self.tip_of_red_pre.x ,self.tip_of_red_pre.y= i.x,i.y
                                    self.tip_of_red_next.x , self.tip_of_red_next.y = mousex,mousey
                                else:
                                    self.tip_of_black_pre.x ,self.tip_of_black_pre.y= i.x,i.y
                                    self.tip_of_black_next.x , self.tip_of_black_next.y = mousex,mousey
                                i.x = mousex
                                i.y = mousey
                                print('能走')
                                i.change(0)
                                self.chesskicknum += 1
                            else:
                                print(self.chessarray)
                                print('不能走')
                    #判断能否走到
    #扫描棋盘，进行计算
    def __scan_chessboard(self):
        pass
    #
    def __update_sprites(self):
        global CHESSNUM,TURN,ALLTURNNUM
        #存放棋子 self.kill()
        #黑马程序员 飞机大战 500-800
        CHESSNUM = len(self.chess_array[0])
        if self.chesskicknum == 1:
            TURN = 1
        else:
            TURN = 0
        ALLTURNNUM = self.chesskicknum

        self.back_group.draw(self.screen)

        self.chessman_group.update()
        self.chessman_group.draw(self.screen)

    #主运行程序
    def start_game(self):
        self.__create_sprites()
        while True:
            self.__event_handler()
            #等待鼠标摁下
            # while a:
            self.__update_sprites()
            self.__scan_chessboard()
            pygame.display.update()

    @staticmethod
    def __game_over():    #静态方法 就不接受self的东西
        print("游戏结束")
        pygame.QUIT()
        exit()
