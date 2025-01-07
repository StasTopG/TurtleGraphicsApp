# Turtle Graphics Application

## Description
This is a simple turtle graphics application built using Qt and C++. The user can control the turtle by entering commands to move it forward, turn it, and control the pen (up/down).

## Features
- **Move forward** by a specified distance.
- **Turn** the turtle by a specified number of degrees.
- **Pen control** to start and stop drawing lines.

## Commands
- `forward <distance>`: Move the turtle forward by the specified distance.
- `turn <degrees>`: Turn the turtle by the specified degrees.
- `pen down`: Start drawing.
- `pen up`: Stop drawing.

## How to Build and Run
1. Clone the repository to your local machine:
   ```bash
   git clone https://github.com/StasTopG/TurtleGraphicsApp.git
   
2. Navigate to the project folder:
   cd TurtleGraphicsApp

3. Build the project using Qt Creator or via the command line with CMake:

   - Using Qt Creator:
     Open Qt Creator and choose Open Project.
     Navigate to your project folder and open the CMakeLists.txt file.
     Qt Creator will automatically configure and build the project for you.

   - Using the Command Line:
     If you don’t have Qt Creator, you can use the command line to build the project with CMake:
     mkdir build
     cd build
     cmake ..
     make

4. Run the application:

   - On Linux/Mac:
     After building the project, you can run the application with:
     ./TurtleGraphicsApp

   - On Windows:
     After building the project, navigate to the build directory and double-click TurtleGraphicsApp.exe to run the application. Alternatively, you can run it from the command prompt:
     TurtleGraphicsApp.exe

   - On other systems:
     Refer to your platform’s specific instructions on how to run compiled C++ applications.
