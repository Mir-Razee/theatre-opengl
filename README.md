3D Movie Theatre Model using OpenGL & GLUT

CS352: Computer Graphics & Visualization Lab
 
 
Project Report
 
Course Instructor:                	
Dr. Somnath Dey 

Submitted By:
Mir Razee Mohideen – 200001045
Lohith Reddy Ramireddy – 200001066

Introduction:
           	This project involves using OpenGL library to build a virtual Theatre, to simulate the experience of being in the movie theatre. The model is built using multiple objects, including chairs, doors, stairs, movie screen and Air conditioning and can be viewed from different angles, by moving the camera around using the keyboard and mouse.
We have implemented square patterns on the floor, and stripes on walls with different colours, and coloured different surfaces with slightly different shades to improve the depth perception.
 
 
Specifications:
           	This section includes the technical specifications i.e., libraries required, how to run the project, and how to use it (details of key controls). (Maximum two pages)
The model was designed on Linux by using simple OpenGL, including library GLUT.


How to Run:
Install the required libraries(OpenGL and GLUT)
Run the following commands
cmake CMakeLists.txt
make
./theatre


How to use (controls):
W - to move forward
A - to move left 
S - to move back
D - to move right
M - to move vertically up
N - to move vertically down
Z - rotate whole theatre clockwise
X - rotate whole theatre anti-clockwise
Mouse movement - Move the camera to look around
Esc - close the model
 
 
 
 
Functionalities Implemented:
1. 3D viewing: The model is implemented as a 3D object, and the camera movements depict the 3D viewing
2. Keyboard accessibility: There are a wide range of keyboard inputs that can be given
3. Mouse accessibility: Mouse movement is associated with camera orientation.
4. Colour: We have used different shades of colours on different surfaces to depict depth in the model. The walls of the theatre are rendered with                  coloured stripes. The theatre screen is white, with a black background.
5. Camera movement: The camera can be moved using keyboard inputs or mouse inputs, which changes the view of the model
6. 3D Geometric Transformation: The objects' seats and walls are duplicated using 3D geometric transformations.
7. Text: The doors have signs with their respective texts, like entry and exit.
 
 









Output:
1. Overall View:
  
2. Screen View:

3. Top View:

4. Exit:

5. Entry:

6. Stairs:

7. AC ducts:

8. Floor Pattern:

9. Wall Pattern:

10.Projector Room:
