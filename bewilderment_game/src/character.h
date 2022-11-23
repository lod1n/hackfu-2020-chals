#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <queue>
#include <string>
#include <sstream>

class character
{
public:
	character();

	void setName(const char*);
	const char* getName(void);

	void setHealth(int);
	int getHealth(void);

	void setMaxHealth(int);
	int getMaxHealth(void);

	void setFatigue(int);
	int getFatigue(void);

	void setMaxFatigue(int);
	int getMaxFatigue(void);

	void setStrength(int);
	int getStrength(void);

	void takeDamage(int);
	void healDamage(int);

	bool isDead(void);

	void updateKillCount(int count);
	int getKillCount();

	void updateSleepCount(int count);
	int getSleepCount();

	void resetRanAway();
	bool ranAwayCheck();


	const char* getSwordName(void);
	void setSwordName(const char*);
	void setSword();
	bool hasSwordCheck();

	void doQuickAttack(character*, std::queue<std::string>& messages);
	void doHeavyAttack(character*, std::queue<std::string>& messages);
	void doRest(character*, std::queue<std::string>& messages);
	void doSleep(character*, std::queue<std::string>& messages);
	int doRun(character*, std::queue<std::string>& messages);

	char name[1024];
	char sword_name[1024];
	int sleep_count = 0;

private:
	int maxhealth;
	int maxfatigue;
	int health;
	int fatigue;
	int strength;

	bool ranAway = false;
	bool hasSword = false;
	int killCount = 0;
	int sleepCount = 0;
};