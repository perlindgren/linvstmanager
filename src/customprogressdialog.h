// This file is part of LinVstManager.

#ifndef CUSTOMPROGRESSDIALOG_H
#define CUSTOMPROGRESSDIALOG_H

#include <QDialog>
class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QLabel;
class QProgressBar;
class QPushButton;

class CustomProgressDialog : public QDialog
{
    Q_OBJECT
public:
    CustomProgressDialog();
    int exec() override;
    void closeEvent(QCloseEvent *e) override;
    void init(quint16 pScanAmount);

private:
    QVBoxLayout *mLayoutVMain;
    QGridLayout *mLayoutGridCounter;
    QHBoxLayout *mLayoutHBottom;
    QProgressBar *mProgressBar;
    QLabel *mLabelMain;
    QLabel *mLabelCounterVst2;
    QLabel *mLabelCounterVst3;
    QLabel *mLabelCounterDll;
    QPushButton *mButtonCancel;
    quint16 mCntVst2;
    quint16 mCntVst3;
    quint16 mCntDll;
    quint16 mScanAmount;
    quint16 mFoundSoFar;
    void updateProgress();

signals:
    void signalCancelPressed();

public slots:
    void slotButtonCancel();
    void slotFoundVst3();
    void slotFoundVst2();
    void slotFoundDll();
};

#endif // CUSTOMPROGRESSDIALOG_H
