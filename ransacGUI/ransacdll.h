/****************************************************************************
**
** Namespace ransacDLL generated by dumpcpp v6.1.2 using
** dumpcpp ransacDLL.tlb
** from the type library ransacDLL.tlb
**
****************************************************************************/

#ifndef QAX_DUMPCPP_RANSACDLL_H
#define QAX_DUMPCPP_RANSACDLL_H

// Define this symbol to __declspec(dllexport) or __declspec(dllimport)
#ifndef RANSACDLL_EXPORT
#define RANSACDLL_EXPORT
#endif

#include <qaxobject.h>
#include <qaxwidget.h>
#include <qdatetime.h>
#include <qpixmap.h>

struct IDispatch;


// Referenced namespace
namespace mscorlib {
    class _Type;
}

Q_DECLARE_OPAQUE_POINTER(mscorlib::_Type*)

namespace ransacDLL {


class RANSACDLL_EXPORT _RANSAC : public QAxObject
{
public:
    explicit _RANSAC(IDispatch *subobject = nullptr, QAxObject *parent = nullptr);
    /*
    Property ToString
    */
    inline QString ToString() const; //Returns the value of ToString

    /*
    Method Equals
    */
    inline bool Equals(const QVariant& obj);

    /*
    Method GetHashCode
    */
    inline int GetHashCode();

    /*
    Method GetType
    */
    inline mscorlib::_Type* GetType();

    /*
    Method Start
    */
    inline QString Start(const QString& file1, const QString& file2, int sizeN, int cohesionN, int iterations, int maxError, int afiOrPersp);

// meta object functions
    static const QMetaObject staticMetaObject;
    const QMetaObject *metaObject() const override { return &staticMetaObject; }
    void *qt_metacast(const char *) override;
};

// Actual coclasses
class RANSACDLL_EXPORT RANSAC : public QAxObject
{
public:
    explicit RANSAC(QObject *parent = nullptr);
    /*
    Property ToString
    */
    inline QString ToString() const; //Returns the value of ToString

    /*
    Method Equals
    */
    inline bool Equals(const QVariant& obj);

    /*
    Method GetHashCode
    */
    inline int GetHashCode();

    /*
    Method GetType
    */
    inline mscorlib::_Type* GetType();

    /*
    Method Start
    */
    inline QString Start(const QString& file1, const QString& file2, int sizeN, int cohesionN, int iterations, int maxError, int afiOrPersp);

// meta object functions
    static const QMetaObject staticMetaObject;
    const QMetaObject *metaObject() const override { return &staticMetaObject; }
    void *qt_metacast(const char *) override;
};

// member function implementation
#ifndef QAX_DUMPCPP_RANSACDLL_NOINLINES
inline QString RANSAC::ToString() const
{
    QVariant qax_result = property("ToString");
    Q_ASSERT(qax_result.isValid());
    return *(QString*)qax_result.constData();
}

inline bool RANSAC::Equals(const QVariant& obj)
{
    bool qax_result;
    void *_a[] = {(void*)&qax_result, (void*)&obj};
    qt_metacall(QMetaObject::InvokeMetaMethod, 8, _a);
    return qax_result;
}

inline int RANSAC::GetHashCode()
{
    int qax_result;
    void *_a[] = {(void*)&qax_result};
    qt_metacall(QMetaObject::InvokeMetaMethod, 9, _a);
    return qax_result;
}

inline mscorlib::_Type* RANSAC::GetType()
{
    mscorlib::_Type* qax_result = 0;
#ifdef QAX_DUMPCPP_MSCORLIB_H
    qRegisterMetaType<mscorlib::_Type*>("mscorlib::_Type*");
    qRegisterMetaType<mscorlib::_Type>("mscorlib::_Type");
#endif
    void *_a[] = {(void*)&qax_result};
    qt_metacall(QMetaObject::InvokeMetaMethod, 10, _a);
    return qax_result;
}

inline QString RANSAC::Start(const QString& file1, const QString& file2, int sizeN, int cohesionN, int iterations, int maxError, int afiOrPersp)
{
    QString qax_result;
    void *_a[] = {(void*)&qax_result, (void*)&file1, (void*)&file2, (void*)&sizeN, (void*)&cohesionN, (void*)&iterations, (void*)&maxError, (void*)&afiOrPersp};
    qt_metacall(QMetaObject::InvokeMetaMethod, 11, _a);
    return qax_result;
}


inline QString _RANSAC::ToString() const
{
    QVariant qax_result = property("ToString");
    Q_ASSERT(qax_result.isValid());
    return *(QString*)qax_result.constData();
}

inline bool _RANSAC::Equals(const QVariant& obj)
{
    bool qax_result;
    void *_a[] = {(void*)&qax_result, (void*)&obj};
    qt_metacall(QMetaObject::InvokeMetaMethod, 8, _a);
    return qax_result;
}

inline int _RANSAC::GetHashCode()
{
    int qax_result;
    void *_a[] = {(void*)&qax_result};
    qt_metacall(QMetaObject::InvokeMetaMethod, 9, _a);
    return qax_result;
}

inline mscorlib::_Type* _RANSAC::GetType()
{
    mscorlib::_Type* qax_result = 0;
#ifdef QAX_DUMPCPP_MSCORLIB_H
    qRegisterMetaType<mscorlib::_Type*>("mscorlib::_Type*");
    qRegisterMetaType<mscorlib::_Type>("mscorlib::_Type");
#endif
    void *_a[] = {(void*)&qax_result};
    qt_metacall(QMetaObject::InvokeMetaMethod, 10, _a);
    return qax_result;
}

inline QString _RANSAC::Start(const QString& file1, const QString& file2, int sizeN, int cohesionN, int iterations, int maxError, int afiOrPersp)
{
    QString qax_result;
    void *_a[] = {(void*)&qax_result, (void*)&file1, (void*)&file2, (void*)&sizeN, (void*)&cohesionN, (void*)&iterations, (void*)&maxError, (void*)&afiOrPersp};
    qt_metacall(QMetaObject::InvokeMetaMethod, 11, _a);
    return qax_result;
}



#endif

}

#endif

