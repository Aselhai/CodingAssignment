
#
# Please save this program to the hard-drive of your computer and run
# it by double-clicking on the file's icon. Running the program from
# the IDLE shell might give different behavior in terms of the event-
# processing loop.
#

import turtle
import time

def square(t, length):
  for s in range(4):
    t.forward(length)
    t.left(90)

def writeText():
  x = t.xcor()
  y = t.ycor()
  t.penup()
  u.setpos(0, 0)
  u.clear()
  u.write((int(x), int(y)), font = ('Times New Roman', 8, 'bold'))
  
def closeDown():
  turtle.bye()

def drawShape(x, y):
  t.penup()
  t.setpos(x, y)
  t.pendown()
  t.begin_fill()
  if x <= 100: #Left third:
    t.color("green")
    square(t, 10)
  elif 100 < x <= 200: #Middle third:
    t.color("red")
    t.circle(10)
  else:
    t.color("blue")
    square(t, 10)
  t.end_fill()

#
# main:
#

# Set window to be 300 x 200 with the point (0, 0) as the lower-left
# corner and (300, 200) as the upper right corner:
turtle.setup(300, 200)
turtle.screensize(300, 200)
turtle.setworldcoordinates(0, 0, 300, 200)

# Initialize global turtle t variable which will be used inside
# of the handler functions:
t = turtle.getturtle()
u= turtle.Turtle()

# Draw two vertical lines to divide the window into thirds:
t.penup()
t.setpos(100, 0) #First line
t.pendown()
t.setpos(100, 200)
t.penup()
t.setpos(200, 0) #Second line
t.pendown()
t.setpos(200, 200)

t.speed(0) # fastest screen update speed
# Register callback for key-press events:
turtle.onkey(writeText, 'Up')
turtle.onkey(closeDown, 'q')
# Register callback for mouse on-click events:
turtle.onscreenclick(drawShape)
turtle.listen()
turtle.mainloop()
