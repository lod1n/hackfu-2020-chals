#define _CRT_SECURE_NO_WARNINGS

#include "character.h"

character::character() {
	this->maxhealth = 50;
	this->maxfatigue = 80;
	this->health = this->maxhealth;
	this->fatigue = this->maxfatigue;
	this->strength = 10;
	strcpy(this->name, name);
	strcpy(this->sword_name, sword_name);
}

int character::getHealth(void) {
	return this->health;
}

void character::setHealth(int health) {
	this->health = health;
}

void character::setName(const char* new_name) {
	
	if (strlen(new_name) > 15)
	{
		new_name = "NICE TRY ;)";
		strcpy(this->name, new_name);
	}
	strcpy(this->name, new_name);
	//strncpy(this->name, new_name, sizeof(name));
}

const char* character::getName(void) {
	return this->name;
}

int character::getStrength(void) {
	return this->strength;
}

void character::setStrength(int strength) {
	this->strength = strength;
}

int character::getFatigue(void) {
	return this->fatigue;
}

void character::setFatigue(int fatigue) {
	this->fatigue = fatigue;
}

void character::takeDamage(int damage) {
	if ((this->health - damage) < 0) {
		this->health = 0;
	}
	else {
		this->health -= damage;
	}
}

void character::healDamage(int damage) {
	if ((this->health + damage) > this->maxhealth) {
		this->health = this->maxhealth;
	}
	else {
		this->health += damage;
	}
}

bool character::isDead(void) {
	return this->health <= 0;
}

void character::updateKillCount(int count)
{
	if (count == 0)
	{
		killCount = count;
	}
	else
	{
		killCount += 1;
	}
}

int character::getKillCount()
{
	return killCount;
}

void character::updateSleepCount(int count)
{
	if (count == 0)
	{
		sleepCount = count;
	}
	else
	{
		sleepCount += 1;
	}
}

int character::getSleepCount()
{
	return sleepCount;
}

void character::resetRanAway()
{
	ranAway = false;
}

bool character::ranAwayCheck()
{
	return ranAway;
}

bool character::hasSwordCheck()
{
	return hasSword;
}

const char* character::getSwordName(void)
{
	return this->sword_name;
}

void character::setSwordName(const char* sword_buf)
{
	strcpy(this->sword_name, sword_buf);
}

void character::setSword()
{
	this->hasSword = true;
}

void character::doQuickAttack(character* monster, std::queue<std::string> & messages) {
	std::ostringstream message;
	int damage = rand() % 10 + 1;

	if (this->getFatigue() < 10) {
		message << this->getName() << " is too fatigued to attack!";
	}
	else {
		this->setFatigue(this->fatigue - 10);
		monster->takeDamage(damage);
		message << this->getName() << " does a quick attack on " <<
			monster->getName() << ", dealing " << damage << " damage.";
	}

	messages.push(message.str());
}

void character::doHeavyAttack(character* monster, std::queue<std::string>& messages) {
	std::ostringstream message;
	int damage = rand() % 10 + 6;

	if (this->getFatigue() < 20) {
		message << this->getName() << " is too fatigued to attack!";
	}
	else {
		this->setFatigue(this->fatigue - 20);
		monster->takeDamage(damage);
		message << this->getName() << " does a heavy attack on " <<
			monster->getName() << ", dealing " << damage << " damage.";
	}

	messages.push(message.str());
}

void character::doRest(character* monster, std::queue<std::string>& messages) {
	std::ostringstream message;
	int health = rand() % 30 + 1;
	int fatigue = rand() % 30 + 1;

	if ( (this->health + health) > this->maxhealth) {
		health = (this->maxhealth - this->health);
	}

	if ((this->fatigue + fatigue) > this->maxfatigue) {
		fatigue = (this->maxfatigue - this->fatigue);
	}

	this->healDamage(health);
	this->setFatigue(this->fatigue + fatigue);

	message << this->getName() << " rests, restoring " << health << " health, and " <<
		fatigue << " fatigue.";
	
	messages.push(message.str());
}

void character::doSleep(character* monster, std::queue<std::string>& messages)
{
	std::ostringstream message;
	message << this->getName() << " takes a nap... zzZZzz";

	messages.push(message.str());
}

int character::doRun(character* monster, std::queue<std::string>& messages) {
	if (this->fatigue <= 0) {
		messages.push("You are too fatigued to run!");
		return 0;
	}
	else {
		messages.push("You run away.");
		ranAway = true;
	}
}

void character::setMaxHealth(int maxhealth) {
	this->maxhealth = maxhealth;
	if (this->health > this->maxhealth)
		this->health = this->maxhealth;
}

int character::getMaxHealth(void) {
	return this->maxhealth;
}

void character::setMaxFatigue(int maxfatigue) {
	this->maxfatigue = fatigue;
}

int character::getMaxFatigue(void) {
	return this->maxfatigue;
}