#include <iostream>
#include <vector>
#include "circle.h"     // Assuming these headers exist in the shapes repo
#include "rectangle.h"  // Add the necessary includes for other shapes
#include "triangle.h"

int main() {
    // Vector to hold pointers to Shape objects
    std::vector<Shape*> shapes;

    // Create some shapes
    Shape* circle1 = new Circle(5.0);        // A circle with radius 5.0
    Shape* rectangle1 = new Rectangle(4.0, 6.0); // A rectangle with width 4.0 and height 6.0
    Shape* triangle1 = new Triangle(3.0, 4.0, 5.0); // A triangle with sides 3.0, 4.0, and 5.0
    Shape* circle2 = new Circle(7.0);        // Another circle with radius 7.0
    Shape* rectangle2 = new Rectangle(8.0, 10.0); // Another rectangle with width 8.0 and height 10.0

    // Add the shapes to the vector
    shapes.push_back(circle1);       // Add at the end
    shapes.push_back(rectangle1);    // Add at the end
    shapes.push_back(triangle1);     // Add at the end
    shapes.push_back(circle2);       // Add at the end
    shapes.push_back(rectangle2);    // Add at the end

    // Display the shapes (assuming they have a display method)
    std::cout << "Initial shapes in the vector:" << std::endl;
    for (Shape* shape : shapes) {
        shape->display();  // Assuming the display method shows information about the shape
    }

    // Remove the second shape (rectangle1) from the vector
    std::cout << "\nRemoving the second shape (rectangle1)..." << std::endl;
    shapes.erase(shapes.begin() + 1);

    // Display the shapes after removal
    std::cout << "Shapes in the vector after removal:" << std::endl;
    for (Shape* shape : shapes) {
        shape->display();
    }

    // Insert a new shape (triangle1) at the beginning of the vector
    std::cout << "\nInserting a new triangle at the beginning..." << std::endl;
    shapes.insert(shapes.begin(), new Triangle(6.0, 8.0, 10.0));  // New triangle with sides 6, 8, 10

    // Insert a new shape (circle) in the middle of the vector
    std::cout << "Inserting a new circle in the middle..." << std::endl;
    shapes.insert(shapes.begin() + shapes.size() / 2, new Circle(9.0));  // Circle with radius 9.0

    // Insert a new shape (rectangle) at the end
    std::cout << "Inserting a new rectangle at the end..." << std::endl;
    shapes.push_back(new Rectangle(12.0, 14.0));  // Rectangle with width 12.0 and height 14.0

    // Display the shapes after insertions
    std::cout << "\nShapes in the vector after insertions:" << std::endl;
    for (Shape* shape : shapes) {
        shape->display();
    }

    // Clean up memory
    for (Shape* shape : shapes) {
        delete shape;  // Free the dynamically allocated memory
    }
    shapes.clear();  // Clear the vector

    return 0;
}
