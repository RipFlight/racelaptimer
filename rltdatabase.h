#ifndef RLTDATABASE_H
#define RLTDATABASE_H

#include <QtSql/QtSql>
#include "singleton.h"
#include <QList>
#include <QHash>

class ModelRace;

class RLTDatabase: public Singleton<RLTDatabase>
{
    friend class Singleton<RLTDatabase>;
public:

    QSqlDatabase* database();
    static RLTDatabase* getInstance();
    void    createDummyPilot();
    int     createNewRace(QString);
    int     addPilotToRace(int,int);
    int     addLapTimeToRace(int,int,int,int);
    QList<ModelRace*> getRaces();
signals:

public slots:

private:
    RLTDatabase();

    bool            initDatabase();
    QSqlDatabase    m_sqliteDatabase;
};

#endif // RLTDATABASE_H
