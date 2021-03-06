#ifndef USERINPUTFILTER_H
#define USERINPUTFILTER_H

#include "guiSQLiteStudio_global.h"
#include <QObject>

class QLineEdit;
class LazyTrigger;

class GUI_API_EXPORT UserInputFilter : public QObject
{
        Q_OBJECT

    public:
        UserInputFilter(QLineEdit* lineEdit, QObject* filterHandler, const char* handlerSlot);

        void setDelay(int msecs);

    private:
        LazyTrigger* trigger = nullptr;
        QLineEdit* lineEdit = nullptr;

    private slots:
        void filterModified();
        void applyFilter();

    signals:
        void applyFilter(const QString& value);
};

#endif // USERINPUTFILTER_H
