#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MedianFilterPlugin;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void onBrowseImagePushButtonClicked();
    void onFilterPushButtonClicked();

private:
    Ui::MainWindow *ui;
    MedianFilterPlugin* mMedianFilterPlugin;
};

#endif // MAINWINDOW_H
