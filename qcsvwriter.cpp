#include "qcsvwriter.h"


#include <QStringList>

QCSVWriter::QCSVWriter() :
    QVector<QString>(),
    _cellSeparator_(','),
    _decimalPoint_('.'),
    _dateTimeFormat_("yyyy-MM-dd hh:mm:ss"),
    file(),
    hasRows(false),
    localeC(QLocale::c())
{}

QCSVWriter::QCSVWriter(int columns) :
    QVector<QString>(columns),
    _cellSeparator_(','),
    _decimalPoint_('.'),
    file(),
    hasRows(false),
    localeC(QLocale::c())
{}

void QCSVWriter::close()
{
    file.close();
}

QFile::FileError QCSVWriter::error() const
{
    return file.error();
}

QString QCSVWriter::errorString() const
{
    return file.errorString();
}

bool QCSVWriter::open()
{
    hasRows = false;
    return file.open(QFile::WriteOnly | QFile::Truncate);
}

const QString& QCSVWriter::setAt(const int index, const double value)
{
    QString cell(localeC.toString(value));

    if (!_decimalPoint_.isNull() &&
            _decimalPoint_ != localeC.decimalPoint()) {
        cell = cell.replace(localeC.decimalPoint(), _decimalPoint_);
    }

    return (*this)[index] = cell;
}

const QString& QCSVWriter::setAt(const int index, const qint64 value)
{
    return (*this)[index] = localeC.toString(value);
}

const QString& QCSVWriter::setAt(const int index, const QDateTime &value)
{
    return (*this)[index] = value.toString(_dateTimeFormat_);
}

const QString& QCSVWriter::setAt(const int index, const QString &value)
{
    return (*this)[index] = value;
}

void QCSVWriter::setFileName(QString name)
{
    file.setFileName(name);
}

bool QCSVWriter::write()
{
    QStringList row;

    row.reserve(size());
    for (QVector<QString>::iterator icells(begin());
         icells != end(); ++icells) {

        if (icells->contains(_cellSeparator_) ||
                icells->contains("\"") ||
                icells->contains("\n") ||
                icells->contains("\r")) {
            *icells = QString("\"%1\"").arg(icells->replace("\"", "\"\""));
        }
        row.append(*icells);
        icells->clear();
    }

    QString rowS(row.join(_cellSeparator_));
    if (hasRows) {
        rowS = QString("\r\n") + rowS;
    } else
        hasRows = true;

    const QByteArray array(rowS.toUtf8());
    qint64 wsize(file.write(array));

    return (wsize == array.size());
}
