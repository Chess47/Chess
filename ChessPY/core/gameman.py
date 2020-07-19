from gamebase import baseclass, START_POINT_X, START_POINT_Y, WEIGHT, LENGTH
import pygame
#棋子类
class chessman(baseclass):
    #有两种状态
    def __init__(self,num=1,x=0,y=0):
        #num：旗子种类
        #红色：1 车；2 马；3 象；4 仕；5 帅；6 炮；7 兵
        #黑色：11 车；12 马；13 象；14 仕；15 帅；16 炮；17 兵

        #xy坐标轴：以左上角黑车为（0,0），x轴向右为正方向，y轴向下为正方向

        #棋子判断
        self.chessnum = num
        if num == 1:
            super().__init__('../image/象棋棋子_红車.png')
            self.rect = self.image.get_rect()
        elif num == 2:
            super().__init__('../image/象棋棋子_红马.png')
            self.rect = self.image.get_rect()
        elif num == 3:
            super().__init__('../image/象棋棋子_红相.png')
            self.rect = self.image.get_rect()
        elif num == 4:
            super().__init__('../image/象棋棋子_红仕.png')
            self.rect = self.image.get_rect()
        elif num == 5:
            super().__init__('../image/象棋棋子_红帅.png')
            self.rect = self.image.get_rect()
        elif num == 6:
            super().__init__('../image/象棋棋子_红炮.png')
            self.rect = self.image.get_rect()
        elif num == 7:
            super().__init__('../image/象棋棋子_红兵.png')
            self.rect = self.image.get_rect()
        elif num == 11:
            super().__init__('../image/象棋棋子_黑車.png')
            self.rect = self.image.get_rect()
        elif num == 12:
            super().__init__('../image/象棋棋子_黑马.png')
            self.rect = self.image.get_rect()
        elif num == 13:
            super().__init__('../image/象棋棋子_黑象.png')
            self.rect = self.image.get_rect()
        elif num == 14:
            super().__init__('../image/象棋棋子_黑士.png')
            self.rect = self.image.get_rect()
        elif num == 15:
            super().__init__('../image/象棋棋子_黑将.png')
            self.rect = self.image.get_rect()
        elif num == 16:
            super().__init__('../image/象棋棋子_黑炮.png')
            self.rect = self.image.get_rect()
        elif num == 17:
            super().__init__('../image/象棋棋子_黑卒.png')
            self.rect = self.image.get_rect()
        self.rect = pygame.Rect(0,0,60,60)
        #像素位置
        self.rect.centerx = START_POINT_X + (x - 1) * LENGTH
        self.rect.centery = START_POINT_Y + (y - 1) * WEIGHT
        #数组位置
        self.x = x
        self.y = y

    def change(self,num = 0):
        #触发按键
        self.boolpressed = num
        return [self.x,self.y]

    def update(self):
        #将理论位置等于实际位置
        self.rect.centerx = START_POINT_X + (self.x - 1) * LENGTH
        self.rect.centery = START_POINT_Y + (self.y - 1) * WEIGHT

    def delself(self,num = 0):
        if num == 1:
            self.kill()
        else:
            pass

    def __del__(self):
        pass

    def cangoto(self,x,y,array,chessarray):
        #车走竖横线，且中间不能有障碍物
        if self.chessnum == 1 or self.chessnum == 11:
            #能行标志位
            cangonum = 1
            #在同一线上
            if x == self.x or y == self.y:
                #判断中间是否有障碍物？
                if x == self.x:
                    for i in array:
                        if i.x == self.x:
                            if self.y < i.y < y or y < i.y < self.y:
                                print([self.x,self.y],[i.x,i.y],[x,y])
                                cangonum = 0
                else:
                    for i in array:
                        if i.y == self.y:
                            if self.x < i.x < x or x < i.x < self.x:
                                print([self.x,self.y],[i.x,i.y],[x,y])
                                cangonum = 0
            else:
                cangonum = 0
            print(x,y)
            print(chessarray)
            return cangonum

        #马走日且不能被别马脚
        elif self.chessnum == 2 or self.chessnum == 12:
            #走日的规则
            #[3]:
            horsecango_array = [[1,2,2],[2,1,1],[2,-1,1],[1,-2,4],[-1,-2,4],[-2,-1,3],[-2,1,3],[-1,2,2]]
            cangonum = 0
            xx = x - self.x
            yy = y - self.y
            for i in horsecango_array:
                #鼠标点击是否符合走子规则
                if xx == i[0] and yy == i[1]:
                    #考虑蹩马脚的情况
                    if i[2] == 1:
                        if chessarray[self.y - 1][self.x] == 0:
                            cangonum = 1
                    elif i[2] == 2:
                        if chessarray[self.y ][self.x - 1] == 0:
                            cangonum = 1
                    elif i[2] == 3:
                        if chessarray[self.y - 1][self.x - 2] == 0:
                            cangonum = 1
                    elif i[2] == 4:
                        if chessarray[self.y - 2][self.x - 1] == 0:
                            cangonum = 1
            return cangonum

        #象走田且不能被压相脚
        elif self.chessnum == 3 or self.chessnum == 13:
            sign = 0
            cangonum = 0
            if self.chessnum == 3:
                #红相不能过河
                if x < 5:
                    sign = 1
            else:
                if x > 5:
                    sign = 1

            if sign == 0:
                elegantcango_array = [[2,-2,1],[2,2,2],[-2,2,3],[-2,-2,4]]
                for i in elegantcango_array:
                    xx = x - self.x
                    yy = y - self.y
                    # 鼠标点击是否符合走子规则
                    if xx == i[0] and yy == i[1]:
                        if i[2] == 1:
                            #右上角
                            if chessarray[self.y - 2][self.x ] == 0:
                                cangonum = 1
                        elif i[2] == 2:
                            #右下角
                            if chessarray[self.y][self.x] == 0:
                                cangonum = 1
                            #左下角
                        elif i[2] == 3:
                            if chessarray[self.y ][self.x - 2] == 0:
                                cangonum = 1
                        elif i[2] == 4:
                            #左上角
                            if chessarray[self.y - 2][self.x - 2] == 0:
                                cangonum = 1

                return cangonum

        #仕只能在九宫格里边斜着走，五个位置
        elif self.chessnum == 4 or self.chessnum == 14:
            #符合按键规则才做判断
            cangonum = 0
            if (self.chessnum == 4 and 4<=x<=6 and 8<=y<=10) or (self.chessnum == 14 and 4<=x<=6 and 0<=y<=2):
                print('进入计算')
                personcango_array = [[1,1],[1,-1],[-1,-1],[-1,1]]
                xx = x - self.x
                yy = y - self.y
                print(xx,yy)
                for i in personcango_array:
                    #符合走子规则
                    if xx == i[0] and yy == i[1]:
                        cangonum = 1
            return cangonum

        #将帅只能在九宫格内行走
        elif self.chessnum == 5 or self.chessnum == 15:
            cangonum = 0
            if (self.chessnum == 5 and 4<=x<=6 and 8<=y<=10) or (self.chessnum == 15 and 4<=x<=6 and 0<=y<=2):
                kingcango_array = [[1,0],[0,1],[0,-1],[-1,0]]
                xx = x - self.x
                yy = y - self.y
                for i in kingcango_array:
                    if xx == i[0] and yy == i[1]:
                        cangonum = 1
            return cangonum

        #炮 直线走子以及隔子打子
        elif self.chessnum == 6 or self.chessnum == 16:
            cangonum = 1
            betweennum = 0
            #走子
            if chessarray[y - 1][x - 1] == 0:
                if x == self.x or y == self.y:
                    # 判断中间是否有障碍物？
                    if x == self.x:
                        for i in array:
                            if i.x == self.x:
                                if self.y < i.y < y or y < i.y < self.y:
                                    betweennum += 1
                    else:
                        for i in array:
                            if i.y == self.y:
                                if self.x < i.x < x or x < i.x < self.x:
                                    betweennum += 1
                else:
                    cangonum = 0
            #隔2子以上
            if betweennum > 1:
                cangonum = 0
            #隔1子
            elif betweennum == 1:
                if self.chessnum < 10:
                    if chessarray[y-1][x-1] < 10:
                        cangonum = 0
                else:
                    if chessarray[y-1][x-1] > 10:
                        cangonum = 0
            return cangonum

        #兵 过河能走左中右 未过河只能走直
        elif self.chessnum == 7 or self.chessnum == 17:
            cangonum = 0
            if self.chessnum == 7:
                #未过河
                if self.y > 5:
                    if y-self.y == -1 and x == self.x:
                        cangonum = 1
                else:
                    soldiercangoarray = [[1,0],[-1,0],[0,-1]]
                    for i in soldiercangoarray:
                        if x-self.x == i[0] and y-self.y == i[1]:
                            cangonum = 1

            elif self.chessnum == 17:
                #未过河
                if self.y < 6:
                    if y-self.y == 1 and x == self.x:
                        cangonum = 1
                else:
                    soldiercangoarray = [[1,0],[-1,0],[0,1]]
                    for i in soldiercangoarray:
                        if x-self.x == i[0] and y-self.y == i[1]:
                            cangonum = 1
            return cangonum
