import turtle
import math
import random
dorian= turtle.Turtle()
linedrawer=turtle.Turtle()
k=turtle.Turtle()
l=turtle.Turtle()
m=turtle.Turtle()
n=turtle.Turtle()
o=turtle.Turtle()
p=turtle.Turtle()
q=turtle.Turtle()
r=turtle.Turtle()
s=turtle.Turtle()
t=turtle.Turtle()
u=turtle.Turtle()
j=turtle.Turtle()
i=turtle.Turtle()
h=turtle.Turtle()
g=turtle.Turtle()

f=turtle.Turtle
e=turtle.Turtle()
d=turtle.Turtle()
c=turtle.Turtle()
b=turtle.Turtle()
a=turtle.Turtle()
t.speed(0)
dorian.hideturtle(), linedrawer.hideturtle()
pi=math.pi
rand=82
linedrawer.speed(0)
linedrawer.penup(), linedrawer.goto(-200,-50), linedrawer.pendown(), linedrawer.forward(400) 
k.penup(), k.goto(0,-50), k.left(90), k.pendown()
l.penup(), l.goto(20,-50), l.left(90), l.pendown()
m.penup(), m.goto(40,-50), m.left(90), m.pendown()
n.penup(), n.goto(60,-50), n.left(90), n.pendown()
o.penup(), o.goto(80,-50), o.left(90), o.pendown()
p.penup(), p.goto(100,-50), p.left(90), p.pendown()
q.penup(), q.goto(120,-50), q.left(90), q.pendown()
r.penup(), r.goto(140,-50), r.left(90), r.pendown()
s.penup(), s.goto(160,-50), s.left(90), s.pendown()
t.penup(), t.goto(180,-50),t.left(90), t.pendown()
u.penup(), u.goto(200,-50), u.left(90), u.pendown()
j.penup(), j.goto(-20,-50), j.left(90), j.pendown()
i.penup(), i.goto(-40,-50), i.left(90), i.pendown()
h.penup(), h.goto(-60,-50), h.left(90), h.pendown()
g.penup(), g.goto(-80,-50), g.left(90), g.pendown()
f.penup(), f.goto(-100,-50), f.left(90), f.pendown()
e.penup(), e.goto(-120,-50), e.left(90), e.pendown()
d.penup(), d.goto(-140,-50), d.left(90), d.pendown()
c.penup(), c.goto(-160,-50), c.left(90), c.pendown()
b.penup(), b.goto(-180,-50), b.left(90), b.pendown()
a.penup(), a.goto(-200,-50), a.left(90), a.pendown()

for i_ in range(0, 200):
  x=0
  y=150 
  for j_ in range(0, 20):
   dorian.penup()
   dorian.goto(x,y)
   coin=random.randint(0,100)
   if coin>rand:
    x+=10
    y-=10
    dorian.pendown(), dorian.speed(0), dorian.color("red"), dorian.goto(x,y)
    #t.clear()
   else:
    x-=10
    y-=10
    dorian.pendown(), dorian.speed(0), dorian.color("blue"), dorian.goto(x,y)   
  dorian.clear()
  if x==0:
    k.forward(5)
  elif x==20:
    l.forward(5)
  elif x==40:
    m.forward(5)
  elif x==60:
    n.forward(5)  
  elif x==80:
    o.forward(5)  
  elif x==100:
    p.forward(5)  
  elif x==120:
    q.forward(5)  
  elif x==140:
    r.forward(5)  
  elif x==160:
    s.forward(5)  
  elif x==180:
    t.forward(5)  
  elif x==200:
    u.forward(5)  
  elif x==-20:
    j.forward(5)  
  elif x==-40:
    i.forward(5)  
  elif x==-60:
    h.forward(5)  
  elif x==-80:
    g.forward(5)  
  elif x==-100:
    f.forward(5)  
  elif x==-120:
    e.forward(5)  
  elif x==-140:
    d.forward(5)     
  elif x==-160:
    c.forward(5)
  elif x==-180:
    b.forward(5)
  elif x==-200:
    a.forward(5)
turtle.done()      
      
     