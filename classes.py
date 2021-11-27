
class MyObject:
	def __init__(self, x, y):
		self.x = x
		self.y = y

	def __repr__():
		pass


class Dino(MyObject):
	def __init__(self, y)
		super().__init__(1, y)

	def __repr__(self):
		pass

	def getposition(self):
		pass

	def move(self)
		pass


class Obstacle(MyObject):
	def __init__(self, x, y)
		super().__init__(x, y)

	def __repr__(self):
		pass


class Screen:
	def __init__(self):
		self.window =  [[0, 0, 0, 0, 0, 0, 0, 0, 0, 0], 
						[0, 0, 0, 0, 0, 0, 0, 0, 0, 0]]

	def getter(self):
		return self.window

	def setter(self, new_window):
		self.window = new_window

	def displayToLCD(self):
		pass

	def updateState(self, delta_time):
		pass

		
