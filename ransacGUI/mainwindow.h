#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "pair.h"
#include "pictureinfo.h"
#include <QFileDialog>
#include <QLayout>
#include "ransacdll.h"
#include <QPainter>
#include <QRegularExpression>
#include <QIntValidator>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/*!
 * \brief The MainWindow class
 *
 * Class with program main window
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void onClickLoad1();
    void onClickLoad2();
    void onClickStart();
    void onClickLoadHaraffSift1();
    void onClickLoadHaraffSift2();
    void saveImage();

private:

    void mergePictures();
    void checkIfAllFilesLoaded();
    void loadPicture(PictureInfo &picture);
    void loadHaraffSift(PictureInfo &picture,bool autoFind);
    void errorHandling(QList<QString> ex,QString result);


    /*!
     * \brief UI
     *
     * UI of main window
     */
    Ui::MainWindow *ui;

    /*!
     * \brief picture1
     *
     * Informations about first picture
     */
    PictureInfo picture1;

    /*!
     * \brief picture2
     *
     * Informations about second picture
     */
    PictureInfo picture2;

    /*!
     * \brief mergedPictures
     *
     * Pixmap of two merged pictures
     */
    QPixmap mergedPictures;

    /*!
     * \brief pairs
     *
     * List of pairs from RANSAC
     */
    std::vector<Pair> *pairs;

protected:
    void resizeEvent(QResizeEvent *);
};
#endif // MAINWINDOW_H
