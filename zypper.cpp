#include "zypper.h"

zypper::zypper()
{
	cmd = "zypper";
}

void zypper::install(QStringList pkg)
{
	execute(mergeArgs(QStringList("install"), pkg));
}

void zypper::remove(QStringList pkg)
{
	execute(mergeArgs(QStringList("remove"), pkg));
}

void zypper::search(QStringList pkg)
{
	execute(mergeArgs(QStringList("search"), pkg));
}

void zypper::info(QString pkg)
{
	execute(QStringList() << "info" << pkg);
}

void zypper::clean()
{
	execute(QStringList() << "clean");
}

void zypper::update()
{
	execute(QStringList() << "update");
}
