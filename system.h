#ifndef SYSTEM_H
#define SYSTEM_H
#include <map>
#include <string>
#include <vector>
#include "models.h"

using namespace std;

bool checkUser(string id, string password);

int setUser(string name, string id, string password);

string getUserName();

vector<Community> getJoinedClub();

vector<Community> getAllClub();

vector<Action> getMyAction();

int joinClub(string clubID);

int applyAction(string actName, string time, string actDescription,
                string clubID);

vector<Action> getAllAction();

vector<Action> getCheckAction();

void acceptAction(string id);

void rejectAction(string id);

#endif
