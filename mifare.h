﻿#ifndef MIFARE_H
#define MIFARE_H

#include <QObject>

class Mifare : public QObject
{
    Q_OBJECT
public:
    explicit Mifare(QObject *parent = nullptr);
    enum ProcessingState
    {
        NONE,
        DATA,
        KEY,
    };
    enum InputType
    {
        FROM_RDBL,
        FROM_RDSC,
        FROM_CHK,
        FROM_NESTED,
    };

    void setProcessingState(ProcessingState st);
    void setInputType(InputType tp);
public slots:
    void processData(const QString str);
    void processKey(const QString str);
signals:

private:
    bool isProcessingData=false;
    bool isProcessingKey=false;
    InputType inputType;
    QStringList dataList;
    QStringList keyList[2];
};

#endif // MIFARE_H
