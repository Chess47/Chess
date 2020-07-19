import sys 
sys.path.append("../core") 
from gamerule import chessgame


if __name__ == '__main__':
    game = chessgame()
    game.start_game()