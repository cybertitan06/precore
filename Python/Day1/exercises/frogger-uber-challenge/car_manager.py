#car manager class module generates/ displays and moves all cars on the game screen

from turtle import Turtle
import random

COLORS = ["red", "orange", "yellow", "green", "blue", "purple"]
STARTING_MOVE_DISTANCE = 5
MOVE_INCREMENT = 10

class CarManager:

    def __init__(self):
        """initialize all relevant values"""

    def create_car(self):
        """randomly generates a new car, places on the board and add it to the list of cars in the car manager. """

    def move_cars(self):
        """moves all cars on the screen right to left"""

    def level_up(self):
        """increases the car speed"""