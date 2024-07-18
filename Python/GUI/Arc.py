import tkinter as tk
import math
# Create the main window
window = tk.Tk()
window.title("Canvas Arc Fill Example")
window.geometry("400x300")

# Create a canvas widget
canvas = tk.Canvas(window, width=400, height=300, bg="white")
canvas.pack()

# Filled arc (outline only, no fill)
canvas.create_arc(50, 300, 300, 50, start=25, extent=125, outline="green", width=20, style=tk.ARC)
# Filled arc (outline only, no fill)
canvas.create_arc(50, 300, 300, 50, start=25, extent=50, outline="yellow", width=20, style=tk.ARC)
# Filled arc (outline only, no fill)
canvas.create_arc(50, 300, 300, 50, start=25, extent=26, outline="red", width=20, style=tk.ARC)

# Arc parameters
arc_center = (175, 175)
arc_radius = 120
arc_start_angle = 25
arc_extent = 125
# Line parameters
current_angle = arc_start_angle
for i in range(6):
 
 x = arc_center[0] + arc_radius * math.cos(math.radians(current_angle))
 y = arc_center[1] - arc_radius * math.sin(math.radians(current_angle))
  # Draw the line
 line_id = canvas.create_line(arc_center[0], arc_center[1], x, y, fill="black", width=1)
 current_angle += 25
# Initial line
x = arc_center[0] + arc_radius * math.cos(math.radians(current_angle))
y = arc_center[1] - arc_radius * math.sin(math.radians(current_angle))
line_id = canvas.create_line(arc_center[0], arc_center[1], x, y, fill="black", width=5)

def on_drag(event):
    dx = event.x - arc_center[0]
    dy = arc_center[1] - event.y
    angle = math.degrees(math.atan2(dy, dx))
    
    # Normalize the angle to the range 0 to 100
    normalized_angle = (angle - arc_start_angle) % 360
    value = int(((126-normalized_angle) / arc_extent) * 100)
    
    # Ensure the value is within 0 to 100
    if value < 0:
        value = 0
    elif value > 100:
        value = 100
    
    # Print the current value
   
    print(value)

    # Update the line position
    x, y = arc_center[0] + arc_radius * math.cos(math.radians(angle)), arc_center[1] - arc_radius * math.sin(math.radians(angle))
    canvas.coords(line_id, arc_center[0], arc_center[1], x, y)

# Bind the drag event to the canvas
canvas.bind("<B1-Motion>", on_drag)

canvas.create_text(55,125,text="0")
canvas.create_text(300,130,text="100")

# Start the Tkinter event loop
window.mainloop()
