#ifndef QCSVWRITER_H
#define QCSVWRITER_H

#include <QDateTime>
#include <QFile>
#include <QLocale>
#include <QVector>

#include "QCSVWriter.h"
#include "qcsvcell.h"

class QCSVWriterCell {

};

class CSVWRITERSHARED_EXPORT QCSVWriter : public QVector<QCSVCell> {
protected:
    /** Column separator. */
    QChar _cellSeparator_;

    /** File to write CSV data. */
    QFile file;

    /** Set to true if first row is writen into file. */
    bool hasRows;

public:
    /** Create CSV file writer. Number of columns is set to 0. */
    QCSVWriter();

    /** Create CSV file writer with N columns. */
    QCSVWriter(int columns);

    QChar cellSeparator() {
        return _cellSeparator_; }

    /** Close CSV file. */
    void close();

    QFile::FileError error() const;

    QString errorString() const;

    /** Open CSV file for writing.

      If file does not exist, new one is created,
      if file exists it is trucanted. */
    bool open();

    /** Open CSV file for writing.

      If file does not exist, new one is created,
      if file exists it is trucanted. */
    bool open(const QString &fileName);

    /** Set cells separator, defaults to ','. */
    void setCellSeparator(const QChar separator) {
       _cellSeparator_ = separator; }

    /** Set date/time format for all cells. */
    void setDateTimeFormat(const QString &dtFormat);

    /** Set decimal point separator for all cells. */
    void setDecimalSeparator(const QChar separator);

    void setFileName(QString name);

    /** Write prepared CSV row into file, all cells are reset to empty. */
    bool write();
};

#endif // QCSVWRITER_H
