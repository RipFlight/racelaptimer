/**
 * OpenRaceLapTimer - Copyright 2015 by airbirds.de, a project of polyvision UG (haftungsbeschränkt)
 *
 * Author: Alexander B. Bierbrauer
 *
 * This file is part of OpenRaceLapTimer.
 *
 * OpenRaceLapTimer is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 * OpenRaceLapTimer is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License along with Foobar. If not, see http://www.gnu.org/licenses/.
 **/

#ifndef CURRENTRACE_H
#define CURRENTRACE_H

#include <QObject>
#include <QList>
#include "singleton.h"

#define CR_RACE_STATE_NOT_RUNNING   0
#define CR_RACE_STATE_RUNNING   1

class RacePilot;
class QTableWidget;
class QSqlQueryModel;
class MainWindow;
class QLabel;

class CurrentRace : public QObject,public Singleton<CurrentRace>
{
    Q_OBJECT
    friend class Singleton<CurrentRace>;

public:
    explicit CurrentRace(QObject *parent = 0);
    void    incommingPilotSignal(QString);

    void    startRace(int,MainWindow*);
    void    stopRace();

    RacePilot* getFastestPilot();
    QList<RacePilot*>* getPilotsList();

signals:
    void pilotDataChanged();
    void fastedLapChanged();
    void raceFinished();

public slots:
private:
    unsigned int     m_uiRaceState;
    QSqlQueryModel *m_pModelRace;
    RacePilot*  getPilotByToken(QString);
    QList<RacePilot*> m_listPilots;
    qint64           m_iFastestLapTime;
};

#endif // CURRENTRACE_H
