#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Space ship - Written by Nguyen Chiem Minh Vu");
    setCentralWidget(ui->graphicsView);

    //a few utility function using for initialize the game
    setUpScene();
    setUpPlayer();
    setUpSourceOfEnemy();
    addPlayerToScene();
    setUpView();
    setUpTimer();
    setUpGame();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    //Press Ecs to quit the game
    switch (event->key()) {
    case Qt::Key_Escape:
        this->close();
        break;

    //Press P or Space bar to pause the game
    case Qt::Key_P:
    case Qt::Key_Space:
        if(gamePause)   {

            gamePause = false;
            emit resume();
        }
        else    {

            gamePause = true;
            emit pause();
        }
        break;

    default:
        break;
    }
}

void MainWindow::continueSpawnEnemy()
{
    //spawn an enemy every 0.8 second
    timer->start(800);
}

void MainWindow::stopSpawnEnemy()
{
    //stop spawn enemy
    timer->stop();
}

void MainWindow::createWarning()
{
    warning = new Warning("Space Young-Buffalo appear!");
    scene->addItem(warning);
    QTimer::singleShot(5000,this,SLOT(clearWarning()));
}

void MainWindow::clearWarning()
{
    delete warning;
}

void MainWindow::createUpgradeWeapon()
{
    UpgradeWeapon* upgrade = new UpgradeWeapon();

    connect(this,SIGNAL(pause()),upgrade,SLOT(stop()));
    connect(this,SIGNAL(resume()),upgrade,SLOT(keepMoving()));
    connect(upgrade,SIGNAL(upgrade()),player,SLOT(levelUp()));
    scene->addItem(upgrade);
}

void MainWindow::playerGotKilled()
{
    emit pause();
}

void MainWindow::setUpScene()
{
    //create the scene
    scene = new GraphicsScene(this);
    scene->setBackgroundBrush(QBrush(Qt::black));
    scene->setSceneRect(0,0,500,600);
}

void MainWindow::setUpPlayer()
{
    //create the item to the scene
    player = new Player();
    //player->setRect(0,0,50,50);

    //make rect focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    connect(scene,SIGNAL(lastPosition(QPointF)),player,SLOT(moveToPosition(QPointF)));
    connect(scene,SIGNAL(shoot()),player,SLOT(shoot()));
    connect(player,SIGNAL(die()),this,SLOT(playerGotKilled()));
}

void MainWindow::addPlayerToScene()
{
    //add the item to the scene
    scene->addItem(player);
    player->addScoreToScene();
    player->addCounterEMP();
}

void MainWindow::setUpView()
{
    //add the view into the scene
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //fix size for the view and the scene
    ui->graphicsView->setFixedSize(500,600);

    //set position where player will begin
    player->setPos(ui->graphicsView->width()/2 - player->rect().width()/2,ui->graphicsView->height() - player->rect().height() - Player::oneMove);

    ui->graphicsView->setCursor(QCursor(Qt::BlankCursor));
}

void MainWindow::setUpTimer()
{
    //start timer
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),player,SLOT(spawnEnemy()));
    connect(timer,SIGNAL(timeout()),source_of_enemy,SLOT(decreaseNumOfEnemy()));
    timer->start(800);
}

void MainWindow::setUpGame()
{
    gamePause = false;
    connect(this,SIGNAL(pause()),this,SLOT(stopSpawnEnemy()));
    connect(this,SIGNAL(resume()),this,SLOT(continueSpawnEnemy()));

    connect(this,SIGNAL(pause()),player,SLOT(onPause()));
    connect(this,SIGNAL(resume()),player,SLOT(onResume()));
}

void MainWindow::setUpSourceOfEnemy()
{
    source_of_enemy = new SourceEnemy(10,this);
    connect(source_of_enemy,SIGNAL(outOfEnemy()),this,SLOT(stopSpawnEnemy()));
    connect(source_of_enemy,SIGNAL(outOfEnemy()),player,SLOT(enemyLevelUp()));
    connect(source_of_enemy,SIGNAL(outOfEnemy()),this,SLOT(createWarning()));
    connect(source_of_enemy,SIGNAL(outOfEnemy()),source_of_enemy,SLOT(deleteLater()));
}
