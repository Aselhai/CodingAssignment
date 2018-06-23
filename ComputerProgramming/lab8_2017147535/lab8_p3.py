import turtle

turtle.setup(800, 600)

x = turtle.getturtle()

x.penup()
x.setposition(-400, 300)
x.pendown()
x.setposition(400, -300)

x.penup()
x.setposition(400, 300)
x.pendown()
x.setposition(-400, -300)

