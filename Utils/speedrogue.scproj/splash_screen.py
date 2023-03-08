#!/usr/bin/python3

#just converted this splash screen to python for fun example project :)

import time
import string


class TerminalCell:
	color: int
	text: string

	def __init__(self, text, color):
		self.text = text
		self.color = color

def addlist (a, b):
	return [x + y for x, y in zip(a, b)]

def bounce (self):
	f = self % 1.0
	if not (int(self) & 1):
		return f
	return 1.0 - f

def rotate (self, n):
	n = int(n)
	if not n:
		return self
	n = n % (len(self)+1)
	return self[n:1000000] + self[0:n]

class Terminal:
	h = 35 # too many lines will break the clearscreen/reset function!
	w = 80
	TermClear = '\x1b[2J'
	TermReset = '\x1b[1;1H'
	Black = 30; Red = 31; Green=32; Yellow=33; Blue=34; Magenta=35; Cyan=36; White=37
	Screen = None

	def DrawText (self, text, x = 0, y = 0, Colors = 0):
		if not Terminal.Screen:
			Terminal.Screen = []
			for _ in range(Terminal.h):
				Line = [TerminalCell(' ', 0) for i in range(Terminal.w)]
				Terminal.Screen.append(Line)
			print(Terminal.TermClear)
		within = 0
		y = int(y)
		x = int(x)
		for c in text:
			if c == '\n' or c == '\r':
				y += 1
				within = 0
			else:
				xx = x+within
				if  0 <= xx < Terminal.w  and  0 <= y < Terminal.h  and  c != ' ':
					if c == '\x7f':
						c = ' '
				Terminal.Screen[y][xx] = TerminalCell(c, Colors)
			within+=1


	def DrawRect (self, rect, inside='', colors=0):
		r2 = addlist(rect, (1, 1, -2, -2))
		for sy in range(rect[1], rect[3]):
			for sx in range(rect[0], rect[2]):
				c = inside
				x = r2[0] <= sx <= r2[2]
				y = r2[1] <= sy <= r2[3]
				if (not x) and (not y):
					c = '+'
				elif (not x) and y:
					c = '|'
				elif (not y) and x:
					c = '-'
				self.DrawText(c, sx, sy, colors)


	def Flat(self):
		PrevCol = 0
		rz = []
		for line in Terminal.Screen:
			for cell in line:
				if PrevCol != cell.color:
					PrevCol = cell.color
					rz.append('\x1b[1;' + str(PrevCol) +'m')
				rz.append(cell.text)
				cell.text = ' '
			rz.append('\n')
		return "".join(rz)


	def Display(self):
		#print(Terminal.TermReset)
		print(self.Flat())
		time.sleep(1.0/60.0)


T = Terminal()
##################################################################
# put creative modifications after here
T.DrawRect((15,15, 25, 25), "!", Terminal.Red)
T.DrawRect((10,10, 20, 20), ".", Terminal.White)

HeartText = '''
  ,d88b. ,d88b.
 d888888v888888b
 888888888888888
 "Y88888888888P"
   "Y8888888P"
	 "Y888P"
	   "V"
'''


scale = Terminal.w / Terminal.h
h = 24
start = time.time()

while True:
	T.DrawRect((0, 0, Terminal.w, h))
	secs = time.time() - start
	for ii in range(5):
		i = float(ii)
		Title = rotate(" Mini Rogue ", i + secs*3)
		f = i*1.234 + secs*(0.33+i*0.05)
		x = bounce(1.5*f/scale) * (Terminal.w-(len(Title)+2))
		y = bounce(f)*(h-2)
		T.DrawText(Title, x+1, y+1, Terminal.Red+ii)

	title2 = "<Mini-Rogue>"
	x2 = (Terminal.w - len(title2)) / 2
	T.DrawText(title2, int(x2), 0, Terminal.Red)
	T.DrawText(HeartText , 32, 10, Terminal.Red)
	T.Display()





