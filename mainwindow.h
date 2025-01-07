#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPolygonItem>
#include <QLineEdit>

/**
 * @brief Namespace for Qt UI classes.
 *
 * This namespace is used to organize UI-related code and prevent naming
 * conflicts with other libraries.
 */
QT_BEGIN_NAMESPACE
namespace Ui {

class MainWindow;
}
QT_END_NAMESPACE

/**
 * @brief The main window of the application.
 *
 * This class inherits from QMainWindow and provides the main user interface
 * for the turtle graphics application.
 */
class MainWindow : public QMainWindow {
    /**
     * @brief Macro that enables Qt's meta-object system.
     *
     * This macro is required for using signals and slots, which are
     * essential for communication between objects in Qt applications.
     */
    Q_OBJECT

public:
    /**
     * @brief Constructor for the MainWindow class.
     * @param parent The parent widget of the main window.
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Destructor for the MainWindow class.
     */
    ~MainWindow();

private slots:
    /**
     * @brief Handles commands entered by the user in the line edit.
     */
    void handleCommand();

private:
    Ui::MainWindow *ui;  ///< Pointer to the UI elements defined in Qt Designer.
    QGraphicsScene *scene;  ///< The graphics scene where the turtle graphics are drawn.
    QGraphicsPolygonItem *turtle;  ///< The graphical item representing the turtle.
    bool penDown;  ///< Indicates whether the turtle's pen is down (drawing) or up.
    QPointF position;  ///< The current position of the turtle in the graphics scene.
    qreal angle;  ///< The current angle (direction) of the turtle.
};

#endif // MAINWINDOW_H
