#include <QtCore/QString>
#include <QtTest/QtTest>
#include <../qcsvwriter.h>
#include <math.h>

class QCSVWriterTest : public QObject
{
    Q_OBJECT
private:
    static const char filePathWrite[];
    static const char filePathRead[];

public:
    QCSVWriterTest();

private Q_SLOTS:
    void testWriteFile();
    void testCompareResult();
};

const char QCSVWriterTest::filePathWrite[] = "tst_QCSVWritertest.csv";
const char QCSVWriterTest::filePathRead[] = "../tests/tst_qcsvwritertest.csv";

QCSVWriterTest::QCSVWriterTest()
{
}

void QCSVWriterTest::testWriteFile()
{
    QCSVWriter csvFile(4);

    csvFile.setFileName(filePathWrite);
    QVERIFY2(csvFile.open(), "csvFile.open() failed");

    QVERIFY2(csvFile.write(), "csvFile.write() empty row failed");

    csvFile[0] = "A";
    csvFile[1] = "B";
    //csvFile[2] = "C";
    csvFile[3] = "D";
    QVERIFY2(csvFile.write(), "csvFile.write() failed");

    csvFile[0] = "space test";
    csvFile[1] = "comma,test";
    QVERIFY2(csvFile.write(), "csvFile.write() failed");

    csvFile[0] = "b\"e";
    csvFile[1] = "b\"\"e";
    csvFile[2] = " ";
    csvFile[3] = "b\"\"\"e";
    QVERIFY2(csvFile.write(), "csvFile.write() failed");

    csvFile[0] = M_PI * 2;
    csvFile[1] = M_E * 10.0e-25;
    csvFile[2] = 1.1;
    csvFile[3] = 1./10;
    QVERIFY2(csvFile.write(), "csvFile.write() failed");

    csvFile[0] = -5;
    csvFile[1] = 0;
    csvFile[2] = 3;
    csvFile[2] = (2LL<<32L) - 1;
    QVERIFY2(csvFile.write(), "csvFile.write() failed");

    QDateTime date;
    date.setDate(QDate(2011, 7, 31));
    date.setTime(QTime(17, 03, 15));
    csvFile[2] = date;
    QVERIFY2(csvFile.write(), "csvFile.write() failed");

    csvFile.close();
}

void QCSVWriterTest::testCompareResult()
{
    QFile expected(filePathRead), writen(filePathWrite);

    QVERIFY2(expected.open(QFile::ReadOnly), "expected.open() failed");
    QVERIFY2(writen.open(QFile::ReadOnly), "expected.open() failed");

    QCOMPARE(QString(writen.readAll()), QString(expected.readAll()));

    expected.close();
    writen.close();
}

QTEST_APPLESS_MAIN(QCSVWriterTest)

#include "tst_qcsvwritertest.moc"
