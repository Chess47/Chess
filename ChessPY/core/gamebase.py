#！！！
import pygame
#！！！
import _thread
import time



#屏幕大小常量
SCREEN_RECT = pygame.Rect(0,0,850,935)
#刷新帧率
FRAME_PER_SEC = 60
#数组常量
#***** 我这里没有看见其他地方有引用,是有什么用吗? *****#
CHESSBOARD_ARRAY = [[0 for i in range(9)]for i in range(10)]
#网格长宽
LENGTH,WEIGHT = 86,86
#起始点
START_POINT_X,START_POINT_Y = 80,80

#调试的全局参数
#***** 下面三个变量也是.也没有看见其他地方有引用,是有什么用吗? *****#
CHESSNUM = 0
TURN = 0
ALLTURNNUM = 0


#棋盘一个类
#棋子很多个类
#基础类：用于装载图片
class baseclass(pygame.sprite.Sprite):
    def __init__(self,image_name):
        #摁键标志位
        self.boolpressed = -1
        super().__init__()
        self.image = pygame.image.load(image_name)
        self.rect = self.image.get_rect()