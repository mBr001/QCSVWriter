#include "qcsvwriter.h"

#include <QStringList>

QCSVWriter::QCSVWriter() :
    QVector<QCSVCell>(),
    _cellSeparator_(','),
    file(),
    hasRows(false)
{}

QCSVWriter::QCSVWriter(int columns) :
    QVector<QCSVCell>(columns),
    _cellSeparator_(','),
    file(),
    hasRows(false)
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

bool QCSVWriter::open(const QString &fileName)
{
    setFileName(fileName);
    return open();
}

void QCSVWriter::setDateTimeFormat(const QString &format)
{
    for(QCSVWriter::iterator cell(begin()); cell != end(); ++cell) {
        cell->setDateTimeFormat(format);
    }
}

void QCSVWriter::setDecimalSeparator(const QChar separator)
{
    for(QCSVWriter::iterator cell(begin()); cell != end(); ++cell) {
        cell->setDecimalSeparator(separator);
    }
}

void QCSVWriter::setFileName(QString name)
{
    file.setFileName(name);
}

bool QCSVWriter::write()
{
    QStringList row;

    row.reserve(size());
    for (QVector<QCSVCell>::iterator icells(begin());
         icells != end(); ++icells) {
        const QString &val(*icells);

        if (val.contains(_cellSeparator_) ||
                val.contains("\"") ||
                val.contains("\n") ||
                val.contains("\r")) {
            QString s(val);
            s.replace("\"", "\"\"");
            row.append(QString("\"%1\"").arg(s));
        }
        else
            row.append(val);
        (*icells).clear();
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
