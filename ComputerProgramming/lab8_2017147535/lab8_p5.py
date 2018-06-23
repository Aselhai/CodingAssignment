import turtle

def drawSquare(myturtle, x, y, a):
    myturtle = turtle.getturtle()
    
    myturtle.penup()
    myturtle.setposition(x, y)
    
    myturtle.pendown()
    myturtle.setposition(x-a, y)
    myturtle.setposition(x-a, y-a)
    myturtle.setposition(x, y-a)
    myturtle.setposition(x, y)
    myturtle.penup()

the_turtle = turtle.getturtle()
drawSquare(the_turtle, 0, 0, 100)
