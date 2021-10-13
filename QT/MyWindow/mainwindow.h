#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QAction>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    void mousePressEvent(QMouseEvent * event); //按下鼠标
    void contextMenuEvent(QContextMenuEvent *event);//右键菜单
private:
   QMenu *pop_menu;
   QAction  *add_images_action;
   QAction *add_folder_action;
   QAction *remove_selected_action;
   QAction *remove_all_action;

public slots:
   void selectImages(void);
   void selectFolder(void);
   void removeSelectedImages(void);
   void removeAllImages(void);
};

#endif // MAINWINDOW_H
