from engi1020.arduino import *
import random
import time




class Dino:
	def __init__(self, y=1):
		self.x = 1
		self.y = y

	def __repr__(self):
		# return '🦕'
		return 'd'

	def getposition(self):
		return (self.x, self.y)

	def move(self):
		if self.y == 1:
			self.y == 0
			return self.y
		else:
			self.y == 1
			return self.y

	def checkCollision(self, screen):
		if screen.window[0][self.y] == 1:
			return True
		else:
			return False




class Screen:
	def __init__(self):
		self.window =  [[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], 
						[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]]

	def get(self):
		return self.window

	def set(self, new_window):
		self.window = new_window

	def displayToLCD(self, my_dino, score, lives):
		obstacle = "#"
		for row in self.window:
			index_cell = 0
			for cell in row:
				lcd_move_cursor(self.window.index(row), index_cell + 1)
				if cell == 1:
					lcd_print(obstacle)
				else:
					lcd_print(" ")
				index_cell += 1
				
		lcd_move_cursor(my_dino.y, 1)
		lcd_print(str(my_dino))

		lcd_move_cursor(0, 12)
		lcd_print(int(score))

		lcd_move_cursor(1, 12)
		lcd_print("@" * lives)
		


	def updateState(self):
		new_window = self.window.copy()

		del new_window[0][0]
		del new_window[1][0]

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

		self.set(new_window)

class InputValidator:
	pass
		
if __name__ == "__main__":
	my_dino = Dino()
	my_window = Screen()
	my_window.displayToLCD(my_dino, 42, 3)

	print(my_window.window)

	for i in range(0, 17):
		my_window.updateState()
		my_window.displayToLCD(my_dino, 42, 3)
		print(my_window.window)
		time.sleep(0.1)
	
