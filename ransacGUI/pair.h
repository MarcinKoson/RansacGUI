#ifndef PAIR_H
#define PAIR_H

/*!
 * \class Pair
 * \brief The Pair class
 *
 * Class for keeping information about coordinates of two points which are a pair
 *
 */
class Pair
{
public:
    /*!
     * \brief Pair
     *
     * Empty constructor
     */
    Pair();
    /*!
     * \brief Pair
     * \param x1
     * \param y1
     * \param x2
     * \param y2
     *
     * Constructor that takes coordinates of points
     */
    Pair(float x1,float y1,float x2,float y2);

    /*!
     * \brief x1
     * X coordinate for first point
     */
    float x1;
    /*!
     * \brief y1
     * Y coordinate for first point
     */
    float y1;
    /*!
     * \brief x2
     * X coordinate for second point
     */
    float x2;
    /*!
     * \brief y2
     * Y coordinate for second point
     */
    float y2;

};

#endif // PAIR_H
