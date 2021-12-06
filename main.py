from engi1020.arduino import *
import time
import random
from classes import *



my_window = Screen()
my_dino = Dino()


# maybe an input validator class

def game(dino, screen, score):
	# TODO: Implement buzzer at start and end
	# TODO: Implement button pressing
	while dino.checkCollision(screen) != True:
		screen.displayToLCD(dino, score)
		sceen.updateState()
		score += 0.5
	return score


def main():
	print("Welcome to our game! This is a clone of Chrome's Dinosaur game.")
	no_of_lives = int(input("Enter Number of Lives: "))
	# TODO: Implement limits for no. of lives

	difficulty_level = int(input("Enter difficulty level, easy, normal, hard, impossible"))
	# TODO: Implement limits for difficulty level

	total_score = 0
	while no_of_lives > 0:
		score = game(my_dino, my_window, total_score)
		total_score += total_score
		no_of_lives -= 1
		# TODO: Ask player if he wants to continue

	# TODO: Output final score
	# Ask player for another game

main()