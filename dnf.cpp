#include "dnf.h"

dnf::dnf()
{
	cmd = "dnf";
}

void dnf::install(QStringList pkg)
{
	execute(mergeArgs(QStringList("install"), pkg));
}

void dnf::remove(QStringList pkg)
{
	execute(mergeArgs(QStringList("remove"), pkg));
}

void dnf::search(QStringList pkg)
{
	execute(mergeArgs(QStringList("search"), pkg));
}

void dnf::info(QString pkg)
{
	execute(QStringList() << "info" << pkg);
}

void dnf::clean()
{
	execute(QStringList() << "clean" << "all");
}

void dnf::update()
{
	execute(QStringList() << "update");
}
