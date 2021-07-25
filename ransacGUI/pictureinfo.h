#ifndef PICTUREINFO_H
#define PICTUREINFO_H

#include <QString>
#include <QPixmap>
#include <QLabel>

/*!
 * \class PictureInfo
 * \brief The PictureInfo class
 *
 * Class with information about picture
 *
 */
class PictureInfo
{
public:
    /*!
     * \brief PictureInfo
     * Constructor
     */
    PictureInfo();

    /*!
     * \brief fileName
     * Name of .png file
     */
    QString fileName;
    /*!
     * \brief pictureIsLoaded
     * Information if the .png file has been loaded
     */
    bool pictureIsLoaded;
    /*!
     * \brief picture
     * QPixmap with loaded .png image
     */
    QPixmap picture;
    /*!
     * \brief fileNameHaraffSift
     * Name of .haraff.sift file
     */
    QString fileNameHaraffSift;
    /*!
     * \brief fileNameHaraffSift
     * Information if the .haraff.sift file has been loaded
     */
    bool haraffSiftIsLoaded;
    /*!
     * \brief pictureLabel
     * Pointer to QLabel for info about .png file
     */
    QLabel *pictureLabel;
    /*!
     * \brief pictureLabel
     * Pointer to QLabel for info about .haraff.sift file
     */
    QLabel *pictureHaraffSiftLabel;
};

#endif // PICTUREINFO_H
