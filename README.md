# Sierpinski Triangle in SFML

This program generates and displays the Sierpinski Triangle using recursive rendering with the SFML graphics library. It allows zooming and panning for better exploration of the fractal pattern. The Sierpinski Triangle is a fractal made by recursively subdividing an equilateral triangle into smaller equilateral triangles.
![Sierpinski Triangle Example](images/sierpinski_triangle.png)
## Features:
- **Recursive Triangle Generation**: The program generates the Sierpinski Triangle by recursively dividing the triangle into three smaller triangles.
- **Interactive Controls**:
  - **Zooming**: Scroll the mouse wheel to zoom in and out of the fractal.
  - **Panning**: Click and drag the mouse to move the view of the fractal.

## Controls:
- **Mouse Scroll**: Zoom in or out of the triangle by scrolling the mouse wheel.
- **Left Mouse Click and Drag**: Move the view of the triangle by clicking and dragging the mouse.

## Installation:

### Prerequisites:
- SFML library: This program uses SFML for window creation and graphics rendering. You can download SFML from [here](https://www.sfml-dev.org/download.php).

### Steps to Run:
1. Install SFML on your system.
2. Clone this repository or copy the code to your local machine.
3. Compile the program with SFML linked to your project.
4. Run the program to view the Sierpinski Triangle.

## Code Explanation:

1. **Midpoint Function**:
   The `midpoint` function calculates the midpoint of two points \( A \) and \( B \) and returns the result as a new `sf::Vector2f`.

2. **Recursive Function**:
   The `sierpinski` function recursively divides the triangle into smaller triangles by calculating the midpoints of its edges and drawing the resulting triangles. The depth of recursion is controlled by the `depth` parameter, which determines how many iterations of subdivision are performed.

3. **SFML Window**:
   The program creates a window of size 800x800 pixels. It uses a `sf::View` to handle zooming and panning, and the view can be moved based on mouse input and zoomed in/out using the mouse wheel.

4. **Event Handling**:
   - Mouse events are used for panning and zooming.
   - Left mouse button click starts a drag to move the view.
   - Mouse wheel scroll adjusts the zoom level.

## Customization:
- The depth of recursion in the `sierpinski` function is set to 6 by default, but you can change it to create more or fewer levels of recursion, depending on the complexity you want to visualize.
- The `sf::Color::White` and `sf::Color::Black` colors are used to color the triangles; you can change these to any other SFML colors for different visual effects.

## Dependencies:
- SFML (Simple and Fast Multimedia Library)

## License:
This project is open-source and available for personal use and modification. See the LICENSE file for more details.

---

Enjoy exploring the fractal nature of the Sierpinski Triangle!
