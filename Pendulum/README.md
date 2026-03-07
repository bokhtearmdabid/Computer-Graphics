# Simple Pendulum Simulation using OpenGL & GLUT

A basic 2D pendulum animation created with OpenGL and GLUT, demonstrating classic oscillatory motion.

## Overview

This program simulates the rhythmic motion of a **simple pendulum** using OpenGL and GLUT.  
The pendulum consists of:

- Fixed suspension point (pivot)
- String
- Bob (mass) at the end

The bob swings continuously between two extreme positions (−45° and +45°), showing natural pendulum-like oscillatory behavior.

### Drawing Techniques Used
- **Bresenham’s Line Drawing Algorithm** → for string and support bar
- **Midpoint Circle Algorithm** → for pivot point and pendulum bob
- Trigonometric functions (`sin`, `cos`) → to calculate bob position
- GLUT timer → to create smooth, continuous animation

## Features

- Realistic pendulum swinging motion
- Labeled pivot (A) and extreme positions (B)
- Clean, minimalistic visualization
- Uses only integer-based algorithms where possible (Bresenham, Midpoint Circle)

## Important Code Sections

### 1. Global Variables

```c
int centerX = 250;
int centerY = 400;
int length  = 200;

float angle     = -45.0f;
int   direction = 1;

Function,Purpose,Algorithm / Method
drawCircle(),Draws pivot and bob,Midpoint Circle Algorithm
drawLine(),Draws string and top support bar,Bresenham’s Line Algorithm
drawText(),"Shows labels ""A"" and ""B""",glutBitmapCharacter()
display(),Main rendering function,Calculates bob position with sin/cos
timer(),Animation update,"Increments angle, reverses at ±45°"
init(),"Sets up projection, colors, etc.",gluOrtho2D()
