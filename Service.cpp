#include "Service.h"
#include "User.h"
#include "SerieValidator.h"
#include "TelefonValidator.h"



/*Service::Service()
{
}
*/

/*Service::Service(RepoTemplate<Serie*> repo, RepoTemplate<User*> repoUser)
{
	this->repo = repo;
	this->repoUser = repoUser;
	User u1("Ana", "123");
	User u2("Ion", "1234");
	repoUser.addElem(u1);
	repoUser.addElem(u2);
}*/

bool Service::login(string u, string p)
{
	User* usr = new User(u, p);
	this->activeUser = (*usr);
	return((repoUser.findElem(usr) != -1) and (!this->activeUser.getUserName().empty()));
}

bool Service::logedIn() {
	return !this->activeUser.getUserName().empty();
}

/*void Service::logout(string name, string pass)
{
	/this->activeUser.getUserName("");
	/this->activeUser.setPassword("");
	User u(name, pass);
	repoUser.delElem(u);

}*/

Service::~Service()
{
}

list<Serie*>Service::getAllSeries() {
	return repo.getAll();
}

int Service::size() {
	return repo.size();
}

Serie* Service::getItemFromPos(int i) {
	return(repo.getItemFromPos(i));
}

/*void Service::loadFromFile(string f, char delim) {
	repo.loadFromFile(f, delim);
}

void Service::addElem(Serie& s) {
	validate(s);
	repo.addElem(s);
}

void Service::delElem(Serie& s) {
	if (repo.findElem(s) == -1)
		throw exception("Could not find the item you want to delete!'\n'");
	else repo.delElem(s);
}
*/