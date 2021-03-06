#ifndef CONFIGMIGRATIONITEM_H
#define CONFIGMIGRATIONITEM_H

#include <QString>

struct ConfigMigrationItem
{
    enum class Type
    {
        SQL_HISTORY,
        DATABASES,
        FUNCTION_LIST,
        BUG_REPORTS
    };

    QString label;
    Type type;
};

#endif // CONFIGMIGRATIONITEM_H
