#ifndef QCSVCELL_H
#define QCSVCELL_H

#include <QDateTime>
#include <QLocale>
#include <QString>

class QCSVCell : public QString
{
private:
    /** Define date/time format. */
    QString _dateTimeFormat_;

    /** Decimal separator for formating floating point numbers. */
    QChar _decimalPoint_;

    /** C locale, used to convert numbers to strig etc. */
    QLocale localeC;

public:
    QCSVCell();

    operator QString&();

    operator const QString&() const;

    /** Set CSV cell to specified value converted to QString. */
    const QString& operator=(const double value);

    /** Set CSV cell to specified value converted to QString. */
    const QString& operator=(const int value) {
        return (*this) = qint64(value); }

    /** Set CSV cell to specified value converted to QString. */
    const QString& operator=(const long int value);

    /** Set CSV cell to specified value converted to QString. */
    const QString& operator=(const QDateTime &value);

    /** Set CSV cell to specified value converted to QString. */
    const QString& operator=(const qint64 value);

    /** Set CSV cell to specified value converted to QString. */
    const QString& operator=(const QString &value);

    /** Set CSV cell to specified value converted to QString. */
    const QString& operator=(const unsigned int value);

    QChar decimalSeparator() {
        return _decimalPoint_; }

    const QString& dateTimeFormat() {
        return _dateTimeFormat_; }

    /** Set formating string for date/time value conversion. */
    void setDateTimeFormat(const QString &format) {
        _dateTimeFormat_ = format; }

    /** Set decimal point separator for floating point numbers. */
    void setDecimalSeparator(const QChar separator) {
        _decimalPoint_ = separator; }

    //friend QCSVWriter;
};

#endif // QCSVCELL_H
