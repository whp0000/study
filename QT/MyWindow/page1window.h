#ifndef PAGE1WINDOW_H
#define PAGE1WINDOW_H

#include <QMainWindow>
namespace Ui {
class Page1Window;
}

class Page1Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Page1Window(QWidget *parent = 0);
    ~Page1Window();

private:
    Ui::Page1Window *ui;
};

#endif // PAGE1WINDOW_H

