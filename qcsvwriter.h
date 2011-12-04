#ifndef QCSVWRITER_H
#define QCSVWRITER_H

#include <QDateTime>
#include <QFile>
#include <QLocale>
#include <QVector>

#include "QCSVWriter.h"

class CSVWRITERSHARED_EXPORT QCSVWriter : public QVector<QString> {
protected:
    /** Column separator. */
    QChar _cellSeparator_;

    /** Decimal separator used for floating point numbers formating. */
    QChar _decimalPoint_;

    /** Define date/time format. */
    QString _dateTimeFormat_;

    /** File to write CSV data. */
    QFile file;

    /** Set to true if first row is writen into file. */
    bool hasRows;

    /** C locale, used to convert numbers to strig etc. */
    QLocale localeC;

public:
    QCSVWriter();

    QCSVWriter(int columns);

    QChar cellSeparator() {
        return _cellSeparator_; }

    void close();

    const QString& dateTimeFormat() {
        return _dateTimeFormat_; }

    QChar decimalSeparator() {
        return _decimalPoint_; }

    QFile::FileError error() const;

    QString errorString() const;

    bool open();

    const QString& setAt(const int index, const double value);

    const QString& setAt(const int index, const int value) {
        return setAt(index, qint64(value)); }

    const QString& setAt(const int index, const unsigned int value) {
        return setAt(index, qint64(value)); }

    const QString& setAt(const int index, const long int value) {
        return setAt(index, qint64(value)); }

    const QString& setAt(const int index, const qint64 value);

    const QString& setAt(const int index, const QDateTime &value);

    const QString& setAt(const int index, const QString &value);

    void setCellSeparator(const QChar separator) {
        _cellSeparator_ = separator; }

    void setDateTimeFormat(const QString &dtFormat) {
        _dateTimeFormat_ = dtFormat; }

    void setDecimalSeparator(const QChar separator) {
        _decimalPoint_ = separator; }

    void setFileName(QString name);

    bool write();
};

#endif // QCSVWRITER_H
