#define _CRT_SECURE_NO_WARNINGS

#include "character.h"
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <queue>

const char* monster_names[] = { "Valefor", "Ixion", "Yojimbo", "Bahamut", "Shiva" };
std::queue<std::string> messages;
std::string encryptDecrypt(std::string toEncrypt);
//std::string getString(int n);

void flag() {

	// hide the flag by just having it be a xor'd string 
	std::string hidden_flag = "\x1b\x73\x25\x1d\x05\x60\x17\x2d\x14\x1d\x77\x0f\x77\x0b\x61\x0c\x3a\x0f\x16\x70\x64\x2f\x1c\x02\x71\x07";
	std::string flag = "/1%"; 
	//hidden_flag = encryptDecrypt(hidden_flag);

	std::string decFlag = encryptDecrypt(flag);
	std::string decFlagCont = encryptDecrypt(hidden_flag);

	std::cout << "How did you even get here? Good news though, you just found something shiny and interesting!!\n" << std::endl;
	std::cout << decFlag << "{" << decFlagCont << "}\n" << std::endl;

	while(true);
}

std::string encryptDecrypt(std::string toEncrypt) {
	char key[3] = { 'B', 'C', 'P' }; //Any chars will work
	std::string output = toEncrypt;

	for (int i = 0; i < toEncrypt.size(); i++)
		output[i] = toEncrypt[i] ^ key[i % (sizeof(key) / sizeof(char))];

	return output;
}

/*
std::string getString(int n)
{
	std::string error = "SOMETHINGWENTWRONG";
	std::string string1 = "Y0u_";
	std::string string2 = "F0UnD";
	std::string string3 = "_4_5H1Ny_";
	std::string string4 = "T34m_R3D";

	switch (n) {
	case '1':
		return string1;
		break;
	case '2':
		return string2;
		break;
	case '3':
		return string3;
		break;
	case '4':
		return string4;
		break;
	default:
		return error;
		break;
	}
}
*/

void get_name(character* player, char* name) {
	
	std::cout << "Enter a character name: ";
	// gets was removed, so use gets_s with a large size on a small buffer.
	//gets_s(name, sizeof player->name);
	fgets(name, sizeof player->name, stdin);
}

bool check_sword_name(character* player)
{
	if (!strcmp(player->getName(), "Anima\n") || player->getKillCount() == 5)
	{
		return true;
	}
	else
		return false;
}
void name_sword(character* player, char* sword_buf)
{
	std::cout << "I think i'll call you: ";
	// here's your buffer overflow, find the offset of the return, smash the stack and bobs your uncle 
	//gets_s(sword_buf, sizeof player->sword_name);
	fgets(sword_buf, sizeof player->sword_name, stdin);
}

void output_encounter_options() {

	std::cout << "+========SKILLS========+" << std::endl;
	std::cout << "| 1) Quick attack" << std::setfill(' ') << std::setw(7) << " |" << std::endl;
	std::cout << "| 2) Heavy attack" << std::setfill(' ') << std::setw(7) << " |" << std::endl;
	std::cout << "| 3) Rest" << std::setfill(' ') << std::setw(15) << " |" << std::endl;
	std::cout << "| 4) Run" << std::setfill(' ') << std::setw(16) << " |" << std::endl;
	std::cout << "+======================+" << std::endl << std::endl;

}

void output_options() {

	std::cout << "+=======ACTIONS=======+" << std::endl;
	std::cout << "| 1) Show stats" << std::setfill(' ') << std::setw(8) << " |" << std::endl;
	std::cout << "| 2) Find monster" << std::setfill(' ') << std::setw(6) << " |" << std::endl;
	std::cout << "| 3) Rest" << std::setfill(' ') << std::setw(14) << " |" << std::endl;
	std::cout << "| q) Give up" << std::setfill(' ') << std::setw(11) << " |" << std::endl;
	std::cout << "+=====================+" << std::endl << std::endl;

}

void output_stats(character* player, character* monster) {

	if (monster != nullptr) {
		std::cout << "+======YOUR STATS======+    +=====MONSTER STATS====+" << std::endl;
		std::cout << "| Name: " << std::setfill(' ') << std::setw(14) << player->getName() << " |";
		std::cout << "    ";
		std::cout << "| Name: " << std::setfill(' ') << std::setw(14) << monster->getName() << " |" << std::endl;

		std::cout << "| Health: " << std::setfill(' ') << std::setw(8) << player->getHealth() << "/" << player->getMaxHealth() << " |";
		std::cout << " vs ";
		std::cout << "| Health: " << std::setfill(' ') << std::setw(9) << monster->getHealth() << "/" << monster->getMaxHealth() << " |" << std::endl;

		std::cout << "| Fatigue: " << std::setfill(' ') << std::setw(7) << player->getFatigue() << "/" << player->getMaxFatigue() << " |";
		std::cout << "    ";
		std::cout << "| Fatigue: " << std::setfill(' ') << std::setw(7) << monster->getFatigue() << "/" << monster->getMaxFatigue() << " |" << std::endl;

		std::cout << "+======================+    +======================+" << std::endl << std::endl;
	}
	else if (player->hasSwordCheck()) 
	{
		std::cout << "+======YOUR STATS======+" << std::endl;
		std::cout << "| Name: " << std::setfill(' ') << std::setw(14) << player->getName() << " |" << std::endl;
		std::cout << "| Health: " << std::setfill(' ') << std::setw(8) << player->getHealth() << "/" << player->getMaxHealth() << " |" << std::endl;
		std::cout << "| Fatigue: " << std::setfill(' ') << std::setw(7) << player->getFatigue() << "/" << player->getMaxFatigue() << " |" << std::endl;
		std::cout << "| Weapon: " << std::setfill(' ') << std::setw(11) << player->getSwordName() << " |" << std::endl;
		std::cout << "+======================+" << std::endl;
	}
	else {
		std::cout << "+======YOUR STATS======+" << std::endl;
		std::cout << "| Name: " << std::setfill(' ') << std::setw(14) << player->getName() << " |" << std::endl;
		std::cout << "| Health: " << std::setfill(' ') << std::setw(8) << player->getHealth() << "/" << player->getMaxHealth() << " |" << std::endl;
		std::cout << "| Fatigue: " << std::setfill(' ') << std::setw(7) << player->getFatigue() << "/" << player->getMaxFatigue() << " |" << std::endl;
		std::cout << "+======================+" << std::endl;
	}


}

character* generate_random_monster() {

	character* monster = new character();

	int monster_names_count = sizeof((monster_names)) / sizeof((monster_names[0]));
	const char* name = monster_names[rand() % monster_names_count];

	monster->setName(name);
	monster->setMaxHealth(rand() % 50 + 10);

	return monster;

}

void output_messages(std::queue<std::string> & messages) {

	std::queue<std::string> tmp = messages;

	std::cout << "+" << std::setfill('=') << std::setw(80) << "+" << std::endl;

	while (!messages.empty()) {
		std::cout << "| " << std::setfill(' ');
		std::cout << std::setw(77) << std::left << messages.front();
		std::cout << std::right << " |" << std::endl;
		messages.pop();
	}

	std::cout << "+" << std::setfill('=') << std::setw(80) << "+" << std::endl;

}

void start_encounter(character* player, character* monster) {

	std::string option;
	int monster_option;

	messages.push("You have encountered " + std::string(monster->getName()) + "!");

	while (!player->isDead() && !monster->isDead() && !player->ranAwayCheck() ){

		option = "";

		// Output main UI.
		system("cls");
		output_stats(player, monster);
		output_encounter_options();
		output_messages(messages);
		
		// Get user option, get it again if no input.
		std::cout << "\n> ";
		std::getline(std::cin, option);
		if (option.empty()) continue;

		// Handle user option.
		switch (option[0]) {
		case '1':
			player->doQuickAttack(monster, messages);
			break;
		case '2':
			player->doHeavyAttack(monster, messages);
			break;
		case '3':
			player->doRest(monster, messages);
			break;
		case '4':
			player->doRun(monster, messages);
			break;
		default:
			messages.push("Invalid key!");
			continue;
		}

		// Generate pseudorandom option for monster.
		if (monster->getFatigue() <= 12 || monster->getSleepCount() == 2)
		{
			monster_option = 3;
			monster->updateSleepCount(0);
		}
		else
			monster_option = rand() % 3;

		// Handle monster option.
		switch (monster_option) {
		case 0:
			monster->doSleep(player, messages);
			monster->updateSleepCount(1);
			break;
		case 1:
			monster->doQuickAttack(player, messages);
			break;
		case 2:
			monster->doHeavyAttack(player, messages);
			break;
		case 3:
			monster->doRest(player, messages);
			break;
		}

	}

	// Manage player death.
	if (player->isDead()) {
		system("cls");
		std::cout << "You got donked on the head and fell unconscious! You should rest a while." << std::endl;
		player->updateKillCount(0);
		std::cout << "Oh and your kill counter got reset... womp womp :(" << std::endl;
		std::getline(std::cin, option);
	}
	if (player->ranAwayCheck())
	{
		system("cls");
		std::cout << player->getName() << " successfully ran away" << std::endl;
		std::getline(std::cin, option);
		player->resetRanAway();
	}
	// Manage monster death.
	else if (monster->isDead()) {
		system("cls");
		std::cout << monster->getName() << " has died!" << std::endl;
		player->updateKillCount(1);
		std::cout << "Monster kills: " << player->getKillCount() << std::endl;
		std::getline(std::cin, option);
	}
}

void game_loop(character* player, char* sword_buf) {

	std::string option;
	character* monster;


	for (int i = 0; i < 1; i++) 
	{
		if (!strcmp(player->getName(), "NICE TRY ;)"))
		{
			std::cout << "\nNICE TRY LOSER ;)\nYou'll have to try harder than that!\nLet's set your name to something more appropriate.\n\n";
		}
	}


	while (true) {

		if (!player->hasSwordCheck())
		{
			if (check_sword_name(player))
			{
				std::cout << "WELL WELL WELL WHAT DO WE HAVE HERE\n*you pick up a sword overflowing with power*\n";
				name_sword(player, sword_buf);
				player->setSwordName(sword_buf);
				player->setSword();
			}
		}

		// Clear the option and output list of available options.
		option = "";
		output_options();

		// Accept input.
		std::cout << "\n> ";
		std::getline(std::cin, option);
		system("cls");

		// Handler use input.
		switch (option[0]) {
		case '1':
			output_stats(player, nullptr);
			break;
		case '2':
			monster = generate_random_monster();
			start_encounter(player, monster);
			delete monster;
			break;
		case '3':
			player->setHealth(player->getMaxHealth());
			player->setFatigue(player->getMaxFatigue());
			std::cout << "You have recovered all of the health and fatigue." << std::endl << std::endl;
			break;
		case 'q':
			std::cout << "Goodbye cruel world!" << std::endl;
			return;
		default:
			break;

		}
	}
}

int main(int argc, char** argv) {

	//debugging
	printf("%p\n", flag);
	//flag();

	character player = character();
	char name[1024];
	char sword_buf[12];
	get_name(&player, name);
	player.setName(name);

	srand(time(NULL));
	game_loop(&player, sword_buf);

	return 0;
}