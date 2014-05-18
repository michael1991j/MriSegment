/****************************************************************************
** Meta object code from reading C++ file 'welcomescreen.h'
**
** Created: Sun May 11 21:56:01 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../welcomescreen.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'welcomescreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_WelcomeScreen[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      24,   15,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      40,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_WelcomeScreen[] = {
    "WelcomeScreen\0\0newValue\0nextwindow(int)\0"
    "on_new_pushButton_clicked()\0"
};

void WelcomeScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        WelcomeScreen *_t = static_cast<WelcomeScreen *>(_o);
        switch (_id) {
        case 0: _t->nextwindow((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_new_pushButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData WelcomeScreen::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject WelcomeScreen::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_WelcomeScreen,
      qt_meta_data_WelcomeScreen, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &WelcomeScreen::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *WelcomeScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *WelcomeScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WelcomeScreen))
        return static_cast<void*>(const_cast< WelcomeScreen*>(this));
    return QDialog::qt_metacast(_clname);
}

int WelcomeScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void WelcomeScreen::nextwindow(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
