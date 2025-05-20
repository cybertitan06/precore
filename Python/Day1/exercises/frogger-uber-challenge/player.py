#player class module handles and changes position of the player piece on the game screen
from turtle import Turtle

STARTING_POSITION = (0, -280)
MOVE_DISTANCE = 10
FINISH_LINE_Y = 280

class Player(Turtle):

    def __init__(self):
        """initialize all relevant values to the player piece. Note this is a child class of the class Turtle"""
        super().__init__()

    def go_up(self):
        """move the player piece by the move distance"""

    def go_to_start(self):
        """move player piece back to the starting location"""

    def is_at_finish_line(self):
        """check to see if the player is at the finish line"""