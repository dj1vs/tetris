#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGridLayout>
#include <QTimer>
#include <QKeyEvent>
#include <QRandomGenerator>
#include <QMessageBox>
#include <QSpacerItem>
#include <QSpinBox>
#include <QLabel>
#include <QFrame>
#include <QPushButton>

#include "tetrispiece/tetrispiece.h"


class GameWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GameWidget(QWidget *parent = nullptr);
    ~GameWidget();
protected:
    void keyPressEvent(QKeyEvent *event);
private:
    QPushButton *goBack;
    QGraphicsScene scene;
    QGraphicsView *view;
    QGridLayout *layout;

    QSpinBox *linesBox;
    QLabel *linesLabel;

    QSpinBox *levelBox;
    QLabel *levelLabel;

    QSpinBox *speedBox;
    QLabel *speedLabel;

    QLabel *nextPieceLabel;
    QLabel *nextPiecePic;

    QVBoxLayout *statsLayout;


    TetrisPiece *curPiece;

    QTimer timer;

    int board[20][10] = {};
    bool gameover=0;

    int maxHeight = 19;

    int lines = 0;
    int level = 0;
    int speed = 500;

    QChar nextPiece;

    const int startingSpeed = 500;

    const QString piecesTypes = "ITOLJSZ";
    const int piecesCoords[8] = {0, 125, 300, 450, 600, 750, 930, 1152};
    const QColor colors[5] = {Qt::black, Qt::red, Qt::blue, Qt::darkGreen, Qt::magenta};

    QImage piecesImage;

    void mainCycle();

    void drawGame();
    bool makeLogic();
    void drawPause();


    void addPiece();
    void removePiece();
    void clearLines();

    void makeNewPiece();
    void setNextPiecePic();

    bool isGoingDown();
    bool isGoingLeft();
    bool isGoingRight();
    bool isRotating(bool dir);

    QChar randomTetrisPiece() {
        return piecesTypes[QRandomGenerator::global()->generate() % 7];}
    //return 'I';}

signals:
    void gameOver();

};

#endif // GAMEWIDGET_H
