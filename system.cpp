#include "system.h"

using namespace std;

Person *now;

map<long long, Community> communities;
map<long long, Action> actions;
map<long long, Person> persons;

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

vector<Community> getAllClub() {
  vector<Community> res;
  for (auto it : communities) {
    res.push_back(it.second);
  }
  return res;
}

vector<Action> getMyAction() {
  vector<Action> res;
  for (auto it : actions) {
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
    return 0;
  }
}

int applyAction(string actName, string time, string actDescription,
                string clubID) {
  long long communityID = atoll(clubID.c_str());
  long long actID = actions.size() + 1;
  actions[actID] = Action(actID, actName, time, actDescription, 0,
                          communities[communityID].GetName(), now->GetName());
  now->ApplyApplication(&actions[actID]);
  return 0;
}

vector<Action> getAllAction() {
  vector<Action> res;
  for (auto i : actions) {
    res.push_back(i.second);
  }
  return res;
}

vector<Action> getCheckAction() {
  vector<Action> res;
  for (auto i : actions) {
    if (i.second.status == 0) {
      res.push_back(i.second);
    }
  }
  return res;
}

void acceptAction(string id) {
  long long number = atoll(id.c_str());
  actions[number].status = 1;
}

void rejectAction(string id) {
  long long number = atoll(id.c_str());
  actions[number].status = -1;
}

void loadData() {
  ifstream actionFile;
  ifstream personFile;
  ifstream communityFile;
  actionFile.open("E:\\QTobgect\\manager\\actions.txt");
  personFile.open("E:\\QTobgect\\manager\\persons.txt");
  communityFile.open("E:\\QTobgect\\manager\\communities.txt");
  long long id;
  string holder, applier;
  string name, time, description;
  int status;
  while (actionFile >> id >> name >> time >> description >> status >> holder >>
         applier) {
    Action newAction(id, name, time, description, status, holder, applier);
    actions[id] = newAction;
  }
  int size;
  while (communityFile >> id >> name >> time >> description >> size) {
    Community newCommunity(id, name, time, description, size);
    for (auto it : actions) {
      if (it.second.holder == name) {
        newCommunity.holdings[it.second.GetID()] = it.second;
      }
    }
    communities[id] = newCommunity;
  }
  string password;
  int joinNumber;
  while (personFile >> id >> name >> password >> joinNumber) {
    Person newPerson(id, name, password);
    for (auto it : actions) {
      if (it.second.applier == name) {
        newPerson.reviews[it.second.GetID()] = it.second;
      }
    }
    for (int i = 0; i < joinNumber; i++) {
      long long cid;
      personFile >> cid;
      newPerson.joins[cid] = communities[cid];
    }
    persons[id] = newPerson;
  }
}

void writeData() {
  ofstream actionFile;
  ofstream personFile;
  ofstream communityFile;
  actionFile.open("E:\\QTobgect\\manager\\actions.txt");
  personFile.open("E:\\QTobgect\\manager\\persons.txt");
  communityFile.open("E:\\QTobgect\\manager\\communities.txt");
  for (auto it : persons) {
    auto now = it.second;
    personFile << now.GetID() << " " << now.GetName() << " "
               << now.GetPassword() << " " << now.joins.size();
    for (auto c : now.joins) {
      personFile << " " << c.second.GetID();
    }
    personFile << endl;
  }
  for (auto it : communities) {
    auto now = it.second;
    communityFile << now.GetID() << " " << now.GetName() << " " << now.GetTime()
                  << " " << now.GetDes() << " " << now.size <<  endl;
  }
  for (auto it : actions) {
    auto now = it.second;
    actionFile << now.GetID() << " " << now.GetName() << " " << now.GetTime()
               << " " << now.GetDes() << " " << now.status << " " << now.holder
               << " " << now.applier << endl;
  }
}
