from engi1020.arduino import *
import random
import time

total_score = 0
no_of_lives = 3
dino_position = 1

def checkCollision(collision_wall, dino_position):
		if collision_wall[dino_position] == 1:
			return True
		else:
			return False


def move(dino_position):
	if dino_position == 0:
		return 1
	elif dino_position == 1:
		return 0
	else:
		print("Something has gone wrong")


class Screen:
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
		print(self.window) # Remove Later
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
		print("Dino's position: " + str(dino_position))
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



my_window = Screen()
# my_dino = Dino()


def game(dino_position, my_window, score, lives):
	collision = False
	while collision == False:
		button = digital_read(2)
		if button == True:
			print("Button pressed")
			dino_position = move(dino_position)
		my_window.displayToLCD(total_score, lives)
		collision = my_window.updateState(dino_position)
		score += 0.5
	return score

print("Welcome to our game! This is a clone of Chrome's Dinosaur game.")

while no_of_lives > 0:
	score = game(dino_position, my_window, total_score, no_of_lives)
	print("collision!")
	total_score += score
	no_of_lives -= 1
	dummy_input = input("Continue?")
	time.sleep(0.5)
	my_window.reset()
	dino_position = 1

print(total_score)
