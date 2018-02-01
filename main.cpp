#include "main.h"

const char supportedPackageManagers[] = "apt, pacaur, yaourt, pacman, zypper, dnf, yum";

int main(int argc, char *argv[])
{
	if (argc == 1){
		qDebug() << "Use option -h (--help), to learn how to use the program";
		return 1;
	}

	QCoreApplication app(argc, argv);
	QCoreApplication::setApplicationName("pkg");
	QCoreApplication::setApplicationVersion("0.1");

	stParserData data = parseArgs(app);

	pkgInterface *pkg = createPkg(data.force);

	if (!data.install.isEmpty())
		if (!data.install.first().isEmpty())
			pkg->install(data.install);
	if (!data.remove.isEmpty())
		if (!data.remove.first().isEmpty())
			pkg->remove(data.remove);
	if (!data.search.isEmpty())
		if (!data.search.first().isEmpty())
			pkg->search(data.search);
	if (!data.info.isEmpty()) pkg->info(data.info);
	if (data.update) pkg->update();
	if (data.clean) pkg->clean();

	delete pkg;
	return 0;
}

pkgInterface *createPkg(QString &force)
{
	pkgInterface *pkg = nullptr;

	if (!force.isEmpty()){
		if (force == "apt")
			pkg = new apt();
		else if (force == "pacaur")
			pkg = new pacaur();
		else if (force == "yaourt")
			pkg = new yaourt();
		else if (force == "pacman")
			pkg = new pacman();
		else if (force == "zypper")
			pkg = new zypper();
		else if (force == "dnf")
			pkg = new dnf();
		else if (force == "yum")
			pkg = new yum();
	}

	if (pkg == nullptr){
		if (QFile::exists("/usr/bin/apt"))
			pkg = new apt();
		else if (QFile::exists("/usr/bin/pacaur"))
			pkg = new pacaur();
		else if (QFile::exists("/usr/bin/yaourt"))
			pkg = new yaourt();
		else if (QFile::exists("/usr/bin/pacman"))
			pkg = new pacman();
		else if (QFile::exists("/usr/bin/zypper"))
			pkg = new zypper();
		else if (QFile::exists("/usr/bin/dnf"))
			pkg = new dnf();
		else if (QFile::exists("/usr/bin/yum"))
			pkg = new yum();
		else {
			qDebug() << "Sorry, but your package manager is not supported.";
			throw;
		}

		if (!force.isEmpty())
			qDebug() << ("Select \"" + pkg->getCmd().toStdString() + "\", because").c_str() << force << "is not supported";
	}

	return pkg;
}

stParserData parseArgs(QCoreApplication &app)
{
	QCommandLineParser parser;
	parser.setApplicationDescription("Lite wrapper for system package manager\n" +
									 QString("Support: ") + supportedPackageManagers);
	parser.addHelpOption();
	parser.addVersionOption();
	parser.helpText();

	QCommandLineOption forceOption(QStringList() << "f" << "force", "force use package manager", "package manager");
	parser.addOption(forceOption);

	QCommandLineOption installOption(QStringList() << "i" << "install", "install package[s]", "package[s]");
	parser.addOption(installOption);

	QCommandLineOption removeOption(QStringList() << "r" << "remove", "remove package[s]", "package[s]");
	parser.addOption(removeOption);

	QCommandLineOption searchOption(QStringList() << "s" << "search", "search package[s]", "package[s]");
	parser.addOption(searchOption);

	QCommandLineOption infoOption(QStringList() << "a" << "about", "info about package", "package");
	parser.addOption(infoOption);

	QCommandLineOption updateOption(QStringList() << "u" << "update", "update packages");
	parser.addOption(updateOption);

	QCommandLineOption cleanOption(QStringList() << "c" << "clean", "clean crap");
	parser.addOption(cleanOption);

	parser.process(app);

	stParserData data;
	data.force = parser.value(forceOption);
	data.install = parser.value(installOption).split(",");
	data.remove = parser.value(removeOption).split(",");
	data.search = parser.value(searchOption).split(",");
	data.info = parser.value(infoOption);
	data.update = parser.isSet(updateOption);
	data.clean = parser.isSet(cleanOption);
	return data;
}
