#ifndef MAIN_H
#define MAIN_H

#include <QtCore/QCoreApplication>
#include <QCommandLineParser>
#include <QDebug>
#include <QFile>

#include "pkginterface.h"
#include "apt.h"
#include "pacman.h"
#include "pacaur.h"
#include "yaourt.h"
#include "zypper.h"
#include "dnf.h"
#include "yum.h"

struct stParserData{
	QString force;
	QStringList install;
	QStringList remove;
	QStringList search;
	QString info;
	bool update;
	bool clean;
};

pkgInterface *createPkg(QString &force);
stParserData parseArgs(QCoreApplication &app);

#endif // MAIN_H
