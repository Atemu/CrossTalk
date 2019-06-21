#pragma once

#include <QtWidgets/QGroupBox>
#include <QtCore/QMap>
#include "definitions_positionalaudio.h"

class QListWidget;
class QDoubleSpinBox;
class QPushButton;

class GroupBoxPositionalAudioServers : public QGroupBox
{
    Q_OBJECT
    
public:
    explicit GroupBoxPositionalAudioServers(QWidget *parent = 0);

public slots:
    // to UI
    void UpdateUIServerAdd(QString serverUniqueId, QString serverName);
    void UpdateUIServerRemove(QString serverUniqueId, QString serverName);
    void UpdateUIServerEnabled(QString serverUniqueId, bool val);
    void UpdateUIServerBlocked(QString serverUniqueId, bool val);
    void UpdateUIServerSendInterval(QString serverUniqueId, float val);
    void UpdateUIServerSendIntervalSilentInc(QString serverUniqueId, float val);

    void UpdateUIServerSelect(QString serverUniqueId);

signals:
    void enabledSet(QString, bool);
    void sendIntervalChange(QString, float);
    void sendIntervalSilentIncChange(QString, float);
    void blockedSet(QString serverUniqueId, bool);
    void addButtonClicked();
    void removeButtonClicked(QString serverUniqueId);

private slots:
    void changePage(QString val);

//    void onAddButtonClicked();
    void onRemoveButtonClicked();
    void onSendIntervalSpinBoxValueChanged(double val);
    void onSendIntervalSilentIncSpinBoxValueChanged(double val);
    void onEnabledCheckToggled(bool val);
    void onUnblockButtonClicked();

private:
    QListWidget* m_servers;
    QGroupBox* m_settings;

    QDoubleSpinBox* m_send_interval;
    QDoubleSpinBox* m_send_interval_silent_inc;
    QPushButton* m_unblock;
    QPushButton* m_remove;

    QMap<QString, PositionalAudio_ServerSettings> m_ServerSettingsMap;
    QMap<QString, QString> m_Name2sUId;
};
