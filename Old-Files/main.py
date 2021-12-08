from engi1020.arduino import *
import time
# import random
from classes import *


my_window = Screen()
my_dino = Dino()


# maybe an input validator class

def game(dino, screen, score, lives):
	# TODO: Implement buzzer at start and end
	while dino.checkCollision(screen) != True:
		button = digital_read(2)
		if button == True:
			dino.y = dino.move()
			print("Something HAPPENED " + str(dino.y))
		screen.displayToLCD(dino, score, lives)
		screen.updateState()
		time.sleep(0.1)
		print(dino.x, dino.y)
		score += 0.5
	screen.displayToLCD(dino, score, lives)
	return score



print("Welcome to our game! This is a clone of Chrome's Dinosaur game.")
# no_of_lives = int(input("Enter Number of Lives: "))
no_of_lives = 3
# TODO: Implement limits for no. of lives

# difficulty_level = input("Enter difficulty level, easy, normal, hard, impossible: ")
# TODO: Implement limits for difficulty level

total_score = 0
while no_of_lives > 0:
	score = game(my_dino, my_window, total_score, no_of_lives)
	print("collision")
	total_score += score
	no_of_lives -= 1
	print(no_of_lives)
	# TODO: Ask player if he wants to continue

print(total_score)
# Ask player for another game
