from gamebase import baseclass, START_POINT_X, START_POINT_Y, LENGTH, WEIGHT
import pygame

#下子提示类
class tip(baseclass):
    def __init__(self,num = 0):
        super().__init__('../image/象棋棋框_位框.bmp')
        if num == 0:
            self.image = pygame.image.load('../image/象棋棋框_位框.bmp')
        else:
            self.image = pygame.image.load('../image/象棋棋框_底框.bmp')
        self.rect.centery = -50
        self.rect.centerx = -50
        self.x = 0
        self.y = 0

    def update(self):
        #将理论位置等于实际位置
        self.rect.centerx = START_POINT_X + (self.x - 1) * LENGTH
        self.rect.centery = START_POINT_Y + (self.y - 1) * WEIGHT