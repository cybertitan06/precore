# scoreboard class module handles displaying the score to the game screen
from turtle import Turtle

FONT = ("Courier", 24, "normal")


class Scoreboard(Turtle):

    def __init__(self):
        """initialize all relevant values to the scoreboard. Note this is a child class for the Turtle Class"""
        super().__init__()

    def update_scoreboard(self):
        """update the scoreboard with the new score"""

    def increase_level(self):
        """increase the level of the scoreboard class"""

    def game_over(self):
        """display the gameover message to the scoreboard"""