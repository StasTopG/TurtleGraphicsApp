#include "mainwindow.h"
#include "ui_mainwindow.h" // Include the header generated from the UI file
#include <QGraphicsLineItem>
#include <QKeyEvent>
#include <QGraphicsPolygonItem>
#include <QtMath>

/**
 * @brief Constructor for the MainWindow class.
 *
 * Initializes the UI, sets up the graphics scene, and creates the turtle.
 *
 * @param parent The parent widget of the main window.
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),  // Create the UI object
    scene(new QGraphicsScene(this)),  // Create the graphics scene
    penDown(true),  // Initialize pen to down (drawing)
    position(0, 0),  // Initialize turtle's position
    angle(90) {   // Initialize turtle's angle (facing up)

    ui->setupUi(this);  // Set up the UI elements

    // Set up the graphics view
    ui->graphicsView->setScene(scene);  // Set the scene for the graphics view
    scene->setSceneRect(-250, -250, 500, 500);  // Center the scene

    // Create the turtle (a black arrow)
    QPolygonF arrowShape;
    arrowShape << QPointF(0, 0) << QPointF(-10, -20) << QPointF(10, -20);  // Define the arrow shape
    turtle = new QGraphicsPolygonItem(arrowShape);  // Create the turtle item
    turtle->setBrush(Qt::black);  // Set the turtle's color to black
    scene->addItem(turtle);  // Add the turtle to the scene
    turtle->setPos(position);  // Set the initial position of the turtle
    turtle->setRotation(-angle);  // Align the turtle with the initial angle

    // Connect the input line to the command handler
    connect(ui->lineEdit, &QLineEdit::returnPressed, this, &MainWindow::handleCommand);  // Connect the line edit's returnPressed signal to the handleCommand slot
}

/**
 * @brief Destructor for the MainWindow class.
 *
 * Cleans up the UI object.
 */
MainWindow::~MainWindow() {
    delete ui;  // Delete the UI object
}

/**
 * @brief Handles commands entered by the user in the line edit.
 *
 * Parses the command and updates the turtle's state and graphics scene accordingly.
 */
void MainWindow::handleCommand() {
    QString command = ui->lineEdit->text().trimmed();  // Get the command text and remove whitespace
    ui->lineEdit->clear();  // Clear the line edit

    if (command.startsWith("forward")) {  // Handle "forward" command
        int distance = command.section(' ', 1, 1).toInt();  // Extract the distance from the command
        qreal radian = qDegreesToRadians(angle);  // Convert angle to radians
        QPointF newPosition = position + QPointF(distance * qCos(radian), -distance * qSin(radian));  // Calculate the new position
        if (penDown) {  // Draw a line if the pen is down
            scene->addLine(QLineF(position, newPosition), QPen(Qt::black, 2));  // Add a line to the scene
        }
        position = newPosition;  // Update the turtle's position
        turtle->setPos(position);  // Update the turtle's position in the scene
    } else if (command.startsWith("turn")) {  // Handle "turn" command
        int degrees = command.section(' ', 1, 1).toInt();  // Extract the degrees from the command
        angle += degrees;  // Update the turtle's angle
        turtle->setRotation(-angle);  // Rotate the turtle in the scene
    } else if (command == "pen down") {  // Handle "pen down" command
        penDown = true;  // Set the pen to down (drawing)
    } else if (command == "pen up") {  // Handle "pen up" command
        penDown = false;  // Set the pen to up (not drawing)
    }
}
