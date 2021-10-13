#ifndef GOBANGWIDGET_H
#define GOBANGWIDGET_H

#include <QWidget>

namespace Ui {
class GobangWidget;
}

class GobangWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GobangWidget(QWidget *parent = 0);
    ~GobangWidget();

private:
    Ui::GobangWidget *ui;
};

#endif // GOBANGWIDGET_H
