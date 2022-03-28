#ifndef PROFILEMANAGER_H
#define PROFILEMANAGER_H

#include "common.h"
#include <QDialog>
#include <QJsonObject>

namespace Ui {
class ProfileManager;
}

class QStringListModel;
class ProfileManager : public QDialog
{
    Q_OBJECT

public:
    explicit ProfileManager(QWidget *parent = nullptr);
    ~ProfileManager();

    QJsonObject profiles = {};
    QStringListModel *model;

    bool loadProfile(SaveFormat saveFormat);
    void saveProfile(SaveFormat saveFormat);

    void updateModel();

    void afterShowOneTime();

private:
    Ui::ProfileManager *ui;
    bool m_modified = false;

    void resetForm();
};

#endif // PROFILEMANAGER_H
