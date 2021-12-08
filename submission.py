# GitHub Link: https://github.com/harnoor-singh/ENGI1020-Final-Project/tree/submission

from engi1020.arduino import *
import random
import time


button_pin = 2 # Should be a digital pin
buzzer_pin = 4 # Should be a digital pin


class Dino:
	"""
	Returns an instance of Dino object.
	However, this class is no longer being used.
	Instead, dino is now just a variable representing its position
	"""
	def __init__(self, y=1):
		self.x = 0
		self.y = y

	def __repr__(self):
		# return '🦕'
		return 'd'

	def getposition(self):
		return (self.x, self.y)



def checkCollision(collision_wall, dino_position):
	"""
	Checks whether the dino has collided with an obstacle or not.
	"""
	if collision_wall[dino_position] == 1:
		return True
	else:
		return False



def move(dino_position):
	"""
	Moves the dino up or down
	"""
	if dino_position == 0:
		return 1
	elif dino_position == 1:
		return 0
	else:
		print("Something has gone wrong")




class Screen:
	"""
	Initializes an array, to be printed on LCD.
	Also declares required functions
	"""
	def __init__(self):
		self.window =  [[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], 
						["d", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]]

	def get(self):
		return self.window

	def set(self, new_window):
		self.window = new_window

	def reset(self):
		lcd_clear()
		new_window = [[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], 
					["d", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]]
		self.set(new_window) 

	def displayToLCD(self, score, lives):
		obstacle = "#"
		for row in self.window:
			index_cell = 0
			for cell in row:
				lcd_move_cursor(self.window.index(row), index_cell + 1)
				if cell == 1:
					lcd_print(obstacle)
				elif cell == 0:
					lcd_print(" ")
				elif cell == "d":
					lcd_print("d")
				index_cell += 1

		lcd_move_cursor(0, 12)
		lcd_print(int(score))

		lcd_move_cursor(1, 12)
		lcd_print("@" * lives)
		

	def updateState(self, dino_position):
		new_window = self.window.copy()
		collision_wall = [new_window[0][1], new_window[1][1]]
		if checkCollision(collision_wall, dino_position) == True:
			return True

		last_column = (new_window[0][-1], new_window[1][-1])

		if last_column == (0, 0):
			append_col = random.choice(((0, 1), (1, 0), (0, 0)))
		elif last_column == (0, 1):
			append_col = random.choice(((0, 1), (0, 0)))
		elif last_column == (1, 0):
			append_col = random.choice(((1, 0), (0, 0)))
		else:
			print("Something has gone wrong. Please debug the code.")


		new_window[0].append(append_col[0])
		new_window[1].append(append_col[1])

		del new_window[0][0]
		del new_window[1][0]

		if dino_position == 0:
			new_window[0][0] = "d"
		elif dino_position == 1:
			new_window[1][0] = "d"

		self.set(new_window)

		return False




class InputValidator:
	"""
	Makes sure the input entered by user is correct and expected.
	This class is required so as to not repeat the validation logic for every question
	"""
	def __init__(self, name, question, possibleAnswers):
		self.name = name
		self.question = question # Must be a string
		self.possibleAnswers = possibleAnswers # Must be a list of various strings

	def ask(self):
		answer = input(str(self.question))
		while answer not in self.possibleAnswers:
			print(f"Please check your input. Enter correct {self.name}")
			answer = input(str(self.question))
		return answer




def game(dino_position, my_window, score, lives, score_increase):
	"""
	This function implements the logic of a game session
	"""
	collision = False
	while collision == False:
		button = digital_read(button_pin)
		if button == True:
			dino_position = move(dino_position)
		my_window.displayToLCD(score, lives)
		collision = my_window.updateState(dino_position)
		score += score_increase
	return score

def main():
	"""
	Runs the main logic of the whole game
	"""
	total_score = 0
	dino_position = 1

	my_window = Screen()
	# my_dino = Dino()		# No longer being used.


	print("Welcome to our game! This is a clone of Chrome's Dinosaur game.")


	no_of_lives_Question = InputValidator(
		"number of lives (either 1, 2, 3, or 4)", 
		"Enter no. of lives you wish to have(1 to 4): ", 
		["1","2","3","4"])
	no_of_lives = no_of_lives_Question.ask()
	no_of_lives = int(no_of_lives)


	difficulty_level_Question = InputValidator(
		"difficulty level (normal or hard)", 
		"Enter the difficulty level you want (enter 'n' for normal, and 'h' for hard): ", 
		['n', 'h', 'normal', 'hard'])
	difficulty_level = difficulty_level_Question.ask()



	if difficulty_level == 'n' or difficulty_level == 'normal':
		score_increase = 1
	else:
		score_increase = 0.5

	buzzer_note(buzzer_pin, 300, 600)

	while no_of_lives > 0:
		score = game(dino_position, my_window, total_score, no_of_lives, score_increase)
		buzzer_note(buzzer_pin, 500, 500)
		total_score = score
		no_of_lives -= 1
		dino_position = 1
		lcd_clear()
		if no_of_lives == 0:
			break
		lcd_print("continue now?")
		button = digital_read(button_pin)
		while button == False:
			button = digital_read(button_pin)
		time.sleep(0.5)
		my_window.reset()
	lcd_clear()
	lcd_print("Total Score: " + str(total_score))



play_again = True
while play_again == True:
	main()
	time.sleep(3)
	lcd_move_cursor(1, 0)
	lcd_print("Play again?")
	button = digital_read(button_pin)
	while button == False:
		button = digital_read(button_pin)
	lcd_clear()
	lcd_print('Check computer')
	lcd_move_cursor(1, 0)
	lcd_print('screen')
	exit_Question = InputValidator(		
		"key to exit or to play again",
		"Press 'e' to exit, or 'p' to play again: ",
		['e', 'p', 'exit', 'play', 'play again'])
	exit = exit_Question.ask()
	if exit == 'e':
		play_again = False
	lcd_clear()
