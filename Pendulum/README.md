# Simple Pendulum Simulation using OpenGL & GLUT
This program simulates the rhythmic motion of a simple pendulum using OpenGL and GLUT. The pendulum consists of a fixed suspension point (pivot), a string, and a bob attached at the end. The bob swings continuously between two extreme positions, demonstrating the natural oscillatory motion of a pendulum.

The program uses Bresenham’s Line Drawing Algorithm to draw the string and support bar, and the Midpoint Circle Algorithm to draw the pivot and the bob. The position of the bob is calculated using trigonometric functions (sin and cos). A timer function updates the angle repeatedly, creating smooth pendulum animation between −45° and +45°.

## Overview

This program simulates the rhythmic motion of a **simple pendulum** using OpenGL and GLUT.  
The pendulum consists of:

- Fixed suspension point (pivot)
- String
- Bob (mass) attached at the end

The bob swings continuously between two extreme positions (−45° and +45°), showing natural pendulum-like oscillatory behavior.

### Drawing Techniques Used
- **Bresenham’s Line Drawing Algorithm** — used to draw the string and the top support bar
- **Midpoint Circle Algorithm** — used to draw the pivot point and the pendulum bob
- Trigonometric functions (`sin` and `cos`) — to calculate the real-time position of the bob
- GLUT timer function — to create smooth, continuous animation

## Features
- Realistic back-and-forth pendulum swinging motion
- Labeled pivot point (**A**) and extreme swing positions (**B**)
- Clean and minimalistic educational visualization
- Uses efficient integer-based algorithms (Bresenham line, Midpoint circle) wherever possible
