#ifndef FRMSERVER_H
#define FRMSERVER_H

#include "dictionary.h"
#include "connectivity.h"
#include "configurations.h"
#include <QWidget>
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
#include <qdesktopwidget.h>

namespace Ui {
class FrmServer;
}

class FrmServer : public QWidget
{
    Q_OBJECT

public:
    explicit FrmServer(QWidget *parent = nullptr);
    ~FrmServer();
    void setDict(Dictionary* dict);
    void setSelector(int* selector);
    void setConfigurations();

private slots:
    void on_btnBack_clicked();
    void on_btnStartServer_clicked();

    void on_cmbSource_currentIndexChanged(int index);

    void on_chkIntrusionDetection_stateChanged(int arg1);

private:
    Ui::FrmServer *ui;
    Dictionary* dict;
    int* selector;
    void selectRegion();
};

#endif // FRMSERVER_H
