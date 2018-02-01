#ifndef PKGINTERFACE_H
#define PKGINTERFACE_H

#include <QStringList>

class pkgInterface
{
public:
	virtual ~pkgInterface(){}

	virtual void install(QStringList pkg) = 0;
	virtual void remove(QStringList pkg) = 0;
	virtual void search(QStringList pkg) = 0;
	virtual void info(QString pkg) = 0;
	virtual void clean() = 0;
	virtual void update() = 0;

	virtual QString getCmd();

protected:
	QString cmd;

	virtual void execute(QStringList args);
	virtual QStringList mergeArgs(QStringList args1, QStringList args2);
};

#endif // PKGINTERFACE_H
