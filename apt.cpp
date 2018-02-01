#include "apt.h"

apt::apt()
{
	cmd = "apt";
}

void apt::install(QStringList pkg)
{
	execute(mergeArgs(QStringList("install"), pkg));
}

void apt::remove(QStringList pkg)
{
	execute(mergeArgs(QStringList("remove"), pkg));
}

void apt::search(QStringList pkg)
{
	execute(mergeArgs(QStringList("search"), pkg));
}

void apt::info(QString pkg)
{
	execute(QStringList() << "show" << pkg);
}

void apt::clean()
{
	execute(QStringList() << "autoremove");
	execute(QStringList() << "autoclean");
}

void apt::update()
{
	execute(QStringList() << "update");
	execute(QStringList() << "upgrade");
}
