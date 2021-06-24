#include <map>
#include <string>
#include <vector>

#include "models.h"

using namespace std;

extern map<long long, Community> communities;
extern map<long long, Action> actions;
extern map<long long, Person> persons;

Person *now;

bool checkUser(string id, string password) {
  long long number = atoll(id.c_str());
  if (persons.count(number) == 0) {
    return false;
  }
  if (persons[number].GetPassword() == password) {
    now = &persons[number];
    return true;
  } else {
    return false;
  }
}

int setUser(string name, string id, string password) {
  long long number = atoll(id.c_str());
  if (persons.count(number) == 0) {
    Person newPerson(atoll(id.c_str()), name, password);
    persons[number] = newPerson;
    now = &persons[number];
    return 0;
  } else {
    return -1;
  }
}

string getUserName() { return now->GetName(); }

vector<Community> getJoinedClub() {
  vector<Community> res;
  for (auto it : now->joins) {
    res.push_back(it.second);
  }
  return res;
}

vector<Community> getAllClub(string id) {
  vector<Community> res;
  for (auto it : communities) {
    res.push_back(it.second);
  }
  return res;
}

vector<Action> getMyAction() {
  vector<Action> res;
  for (auto it : now->reviews) {
    res.push_back(it.second);
  }
  return res;
}

int joinClub(string clubID) {
  long long id = atoll(clubID.c_str());
  if (communities.count(id) == 0) {
    return -1;
  } else {
    communities[id].AppendMember();
    now->JoinCommunity(&communities[id]);
  }
}

int applyAction(string actName, string time, string actDescription,
                string clubID) {
  long long communityID = atoll(clubID.c_str());
  long long actID = actions.size() + 1;
  actions[actID] = Action(actID, actName, time, actDescription, 0,
                          communities[communityID], *now);
  now->ApplyApplication(&actions[actID]);
}
