//Made by Marcin Kosoń

#include "mainwindow.h"
#include "ui_mainwindow.h"

 /*!
 * \brief Main window of program constructor
 * \param parent
 *
 * Main constructor
 * Setting buttons behavior
 * Setting validator for QLineEdit
 * Setting initial values for pictures
 * Setting UI
 *
 */
 MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Setting buttons behavior
    connect(ui->load1,SIGNAL(released()), this, SLOT(onClickLoad1()));
    connect(ui->load2,SIGNAL(released()), this, SLOT(onClickLoad2()));
    connect(ui->loadHaraff1,SIGNAL(released()), this, SLOT(onClickLoadHaraffSift1()));
    connect(ui->loadHaraff2,SIGNAL(released()), this, SLOT(onClickLoadHaraffSift2()));
    connect(ui->start,SIGNAL(released()), this, SLOT(onClickStart()));
    connect(ui->saveImage,SIGNAL(released()), this, SLOT(saveImage()));
    //Setting validator for QLineEdit
    ui->cohesion->setValidator(new QIntValidator(1, 9999, this));
    ui->error->setValidator(new QIntValidator(1, 9999, this));
    ui->iterations->setValidator(new QIntValidator(1, 9999, this));
    ui->size->setValidator(new QIntValidator(1, 9999, this));
    //Setting initial values for pictures
    picture1.pictureIsLoaded = false;
    picture2.pictureIsLoaded = false;
    picture1.haraffSiftIsLoaded = false;
    picture2.haraffSiftIsLoaded = false;
    picture1.pictureHaraffSiftLabel = ui->pictureHaraffInfo1;
    picture2.pictureHaraffSiftLabel = ui->pictureHaraffInfo2;
    picture1.pictureLabel = ui->pictureInfo1;
    picture2.pictureLabel = ui->pictureInfo2;
    //Setting UI
    ui->image1->setAlignment(Qt::AlignTop);
    ui->image1->setAlignment(Qt::AlignLeft);
    ui->affine->setChecked(true);
    ui->start->setDisabled(true);
    ui->start->setToolTip("No pictures loaded");
    //Hints for parameters
    ui->size_label->setToolTip("Size of neighborhood of pair");
    ui->cohesion_label->setToolTip("Specifies how many pairs must be in neighborhood of each punct of pair to accept pair as consistent. Must be smaller than size of neighborhood");
    ui->iterations_label->setToolTip("Number of repetitions of model calculation in RANSAC");
    ui->error_label->setToolTip("Maximum error of the pair to be determined as matching the model");
    ui->affine->setToolTip("For 2D object");
    ui->perspetcive->setToolTip("For 3D object");
}

 /*!
 * \brief MainWindow::loadPicture Loading picture
 * \param picture object to save data
 *
 * Function opens file dialog for the user to select the file.
 * If picture has been selected, information about it will be saved to the passed object.
 * Function then tries to load .haraff.stif file
 */
 void MainWindow::loadPicture(PictureInfo &picture)
 {
    picture.fileName = QFileDialog::getOpenFileName(nullptr,"Open Image", "", "Image Files (*.png)");
    if(picture.fileName != nullptr){
        picture.picture.load(picture.fileName);
        picture.pictureIsLoaded = true;
        picture.pictureLabel->setText("loaded");
        loadHaraffSift(picture,true);
    }
}

 /*!
 * \brief MainWindow::loadHaraffSift Loading .haraff.sift file
 * \param picture object to save data
 * \param autoFind find .haraff.stift using file name
 *
 * If autoFind is true, function tries to find file by adding to name of picture file ".haraff.sift"
 * If autoFind is false, function opens file dialog for the user to select the file
 *
 */
 void MainWindow::loadHaraffSift(PictureInfo &picture,bool autoFind)
 {
     if(autoFind){
        if( QFile::exists(picture.fileName+".haraff.sift")){
            picture.fileNameHaraffSift = picture.fileName+".haraff.sift";
            picture.pictureHaraffSiftLabel->setText("loaded");
            picture.haraffSiftIsLoaded =true;
        }
        else{
            picture.pictureHaraffSiftLabel->setText("not found");
            picture.haraffSiftIsLoaded = false;
        }
    }
    else{
        picture.fileNameHaraffSift = QFileDialog::getOpenFileName(nullptr,"Open Haraff Sift file", "");
        if(picture.fileNameHaraffSift != nullptr)
        {
        picture.haraffSiftIsLoaded  = true;
        picture.pictureHaraffSiftLabel->setText("loaded");
        }
    }
}

 /*!
  * \brief MainWindow::onClickLoad1 Function called after load1 button is pressed
  *
  * Function called after load1 button is pressed.
  * Function opens file dialog for the user to select the file.
  * If file is loaded it tries to load ".haraff.sift" file
  * After that function checks if all files are loaded.
  * If they are, it unlocks start button and remove tooltip from it.
  * If both pictures are loaded, it merge them into one QPixmap and shows it
  */
 void MainWindow::onClickLoad1()
 {
    loadPicture(picture1);
    checkIfAllFilesLoaded();
    mergePictures();
}

 /*!
  * \brief MainWindow::onClickLoad2 Function called after load2 button is pressed
  *
  * Function called after load2 button is pressed.
  * Function opens file dialog for the user to select the file.
  * If file is loaded it tries to load ".haraff.sift" file
  * After that function checks if all files are loaded.
  * If they are, it unlocks start button.
  * If both pictures are loaded, it merge them into one QPixmap and shows it
  */
 void MainWindow::onClickLoad2()
 {
   loadPicture(picture2);
   checkIfAllFilesLoaded();
   mergePictures();

}

 /*!
  * \brief MainWindow::onClickLoadHaraffSift1 Function called after loadHaraff1 button is pressed
  *
  * Function called after loadHaraff1 button is pressed.
  * Function opens file dialog for the user to select the file.
  * After that function checks if all files are loaded.
  * If they are, it unlocks start button and remove tooltip from it.
  *
  */
 void MainWindow::onClickLoadHaraffSift1()
 {
     loadHaraffSift(picture1,false);
     checkIfAllFilesLoaded();
 }

 /*!
  * \brief MainWindow::onClickLoadHaraffSift2 Function called after loadHaraff1 button is pressed
  *
  * Function called after loadHaraff2 button is pressed.
  * Function opens file dialog for the user to select the file.
  * After that function checks if all files are loaded.
  * If they are, it unlocks start button.
  *
  */
 void MainWindow::onClickLoadHaraffSift2()
 {
     loadHaraffSift(picture2,false);
     checkIfAllFilesLoaded();
 }

 /*!
  * \brief MainWindow::mergePictures Function mergre to pictures into one
  *
  * Function check if both pictures are loaded.
  * If they are it merge it into one QPixmap and shows it
  *
  */
 void MainWindow::mergePictures()
 {
     if(picture1.pictureIsLoaded & picture2.pictureIsLoaded){
         mergedPictures = QPixmap(picture1.picture.width()+picture2.picture.width(), fmax(picture1.picture.height(),picture2.picture.height()));
         QPainter painter(&mergedPictures);
         painter.drawImage(0,0,picture1.picture.toImage());
         painter.drawImage(picture1.picture.width(),0,picture2.picture.toImage());
         ui->image1->setPixmap(mergedPictures.scaled(ui->image1->width(),ui->image1->height(),Qt::KeepAspectRatio));
     }
 }

 /*!
  * \brief MainWindow::checkIfAllFilesLoaded checks if all files are loaded
  *
  * Function checks if all files are loaded.
  * If they are, it unlocks start button and remove tooltip from it.
  *
  */
 void MainWindow::checkIfAllFilesLoaded()
 {
        if(picture1.pictureIsLoaded & picture2.pictureIsLoaded & picture1.haraffSiftIsLoaded & picture2.haraffSiftIsLoaded)
        {
            ui->start->setDisabled(false);
            ui->start->setToolTip("");
        }
 }

 /*!
  * \brief MainWindow::onClickStart
  *
  * Funcion calls RANSAC and show information about results.
  * Then draws a lines connecting points on pictures
  *
  */
 void MainWindow::onClickStart()
 {
    //block UI
    ui->start->setDisabled(true);
    ui->start->repaint();
    ui->returnCode->setText("Computing is in progress");
    ui->returnCode->repaint();
    //create new merge picture
    mergePictures();
    QString result;
    ransacDLL::RANSAC ransac;  
    //call a ransac   
    result = ransac.Start(picture1.fileNameHaraffSift,
                 picture2.fileNameHaraffSift,
                 ui->size->text().toInt(),
                 ui->cohesion->text().toInt(),
                 ui->iterations->text().toInt(),
                 ui->error->text().toInt(),
                 ui->affine->isChecked()?3:4);
    //split return string
    QRegularExpression separator("[(|;|/|)]");
    QList<QString> splited = result.split(separator);
    QString returnCode = splited[0];
    //check return code
    QRegularExpression separator2("[-]");
    QList<QString> info = splited[0].split(separator2);
    splited.removeAt(0);
    //handlig errors
    if(info[0] != "100")
    {
    errorHandling(info,result);
    }
    //If success
    else{
        //result message
        QString resultMessage = "Success \n "
                                "Key Point Pairs="+info[1]+
                                "\n Consistent Pairs="+info[2]+
                                "\n RANSAC Pairs="+info[3];;
        ui->returnCode->setText(resultMessage);
        //load pairs
        pairs = new std::vector<Pair>();
        for(int i=0 ; i<splited.size()/4; i++){
            pairs->push_back(*(new Pair(splited[i*4+0].replace(",",".").toFloat(),
                                        splited[i*4+1].replace(",",".").toFloat(),
                                        splited[i*4+2].replace(",",".").toFloat(),
                                        splited[i*4+3].replace(",",".").toFloat())));
        }
        //draw lines on merged pictures
        Qt::GlobalColor color [8] = {Qt::cyan,Qt::white,Qt::blue,Qt::red,Qt::green,Qt::yellow,Qt::magenta,Qt::gray};
        QPainter painter(&mergedPictures);
        for(int i=0; i<static_cast<int>(pairs->size()); i++){
            painter.setPen(color[i%8]);
           painter.drawLine((int)pairs->at(i).x1,(int)pairs->at(i).y1,(int)pairs->at(i).x2+picture1.picture.width(),(int)pairs->at(i).y2);
        }
        //show image
        ui->image1->setPixmap(mergedPictures.scaled(ui->image1->width(),ui->image1->height(),Qt::KeepAspectRatio,Qt::SmoothTransformation));
    }
    ui->start->setDisabled(false);
 }

 /*!
  * \brief MainWindow::errorHandling
  * \param ex
  * \param result
  *
  *  Function display info about error
  */
 void MainWindow::errorHandling(QList<QString> ex,QString result)
 {
     if(result == nullptr){
         ui->returnCode->setText("ransacDLL.dll error");
     }
     if(ex[0] == "200"){
         ui->returnCode->setText("Incorrect first .haraff.sift file");
     }
     if(ex[0] == "201"){
         ui->returnCode->setText("Incorrect second .haraff.sift file");
     }
     if(ex[0] == "202"){
         ui->returnCode->setText("Error during pairing");
     }
     if(ex[0] == "203"){
         QString errorMessage = "Error with cohesion calculation \n Key Point Pairs="+ex[1];
         ui->returnCode->setText(errorMessage);
     }
     if(ex[0] == "204"){
         QString errorMessage = "Error with RANSAC \n "
                                 "Key Point Pairs="+ex[1]+
                                 "\n Consistent Pairs="+ex[2];
         ui->returnCode->setText(errorMessage);
     }
 }

 /*!
  * \brief MainWindow::saveImage Saving QPixmap
  *
  * Save QPixmap to file
  */
 void MainWindow::saveImage()
 {
     QFile file("result.png");
     file.open(QIODevice::WriteOnly);
     mergedPictures.save(&file, "PNG");
 }

 /*!
  * \brief MainWindow::resizeEvent called when window is resized
  *
  * UI call this function, when window was resized.
  */
 void MainWindow::resizeEvent(QResizeEvent *)
 {
     //mayby without scaling??
     ui->image1->setPixmap(mergedPictures.scaled(ui->image1->width(),ui->image1->height(),Qt::KeepAspectRatio,Qt::SmoothTransformation));
     //update();
 }

 /*!
  * \brief MainWindow::~MainWindow destructor
  *
  * Release memory used by UI
  *
  */
 MainWindow::~MainWindow()
{
    delete ui;
}

