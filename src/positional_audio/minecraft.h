#pragma once

#include <QtCore/QObject>
#include <QtCore/QJsonObject>
#include "tsvr_definitions.h"

class Minecraft : public QObject, public CustomEnvironmentSupportInterface
{
    Q_OBJECT
    Q_INTERFACES(CustomEnvironmentSupportInterface)
    Q_PROPERTY(QString identity
               READ getIdentity
               NOTIFY identityChanged)

public:
    explicit Minecraft(QObject *parent = 0);

    QString getIdentity() const;

    bool onIdentityRawDirty(QString rawIdentity);
    bool onInfoData(QTextStream &data);

signals:
    void identityChanged(QString);

private:
    QJsonObject m_meObj;

};
