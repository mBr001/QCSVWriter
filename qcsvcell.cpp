#include "qcsvcell.h"

QCSVCell::QCSVCell() :
    QString(),
    _dateTimeFormat_(),
    _decimalPoint_('.'),
    localeC(QLocale::c())
{
}

QCSVCell::operator QString&()
{
    return *this;
}

QCSVCell::operator const QString&() const
{
    return *this;
}

const QString& QCSVCell::operator=(const double value)
{
    QString cell(localeC.toString(value));

    if (!_decimalPoint_.isNull() &&
            _decimalPoint_ != localeC.decimalPoint()) {
        cell = cell.replace(localeC.decimalPoint(), _decimalPoint_);
    }

    return QString::operator=(cell);
}

const QString& QCSVCell::operator=(const qint64 value)
{
    return QString::operator=(localeC.toString(value));
}

const QString& QCSVCell::operator=(const QDateTime &value)
{
    if (_dateTimeFormat_.isEmpty())
        return QString::operator=(value.toString(Qt::ISODate));

    return QString::operator=(value.toString(_dateTimeFormat_));
}

const QString& QCSVCell::operator=(const QString &value)
{
    return QString::operator=(value);
}
