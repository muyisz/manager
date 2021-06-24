#ifndef MODELS_H
#define MODELS_H


#include <map>
#include <string>

using namespace std;

class Person;
class Community;
class Action;

map<long long, Community> communities;
map<long long, Action> actions;
map<long long, Person> persons;

class Action {
private:
    long long id;
    string name;
    string time;
    string description;
    int status;
    Community *holder;
    Person *applier;

public:
    Action() {}
    Action(long long id, string name, string time, string description, int status,
           Community &holder, Person &applier) {
        this->id = id;
        this->name = name;
        this->time = time;
        this->description = description;
        this->status = status;
        this->holder = &holder;
        this->applier = &applier;
    }
    ~Action() {}
    long long GetID() { return this->id; }
    string GetName() { return this->name; }
    string GetTime() { return this->time; }
};

class Community {
private:
    long long id;
    string name;
    string time;
    string description;
    int size;
    map<long long, Action> holdings;

public:
    Community() {}
    Community(long long id, string name, string time, string description, int size) {
        this->id = id;
        this->name = name;
        this->time = time;
        this->description = description;
        this->size = size;
    }
    ~Community() {}
    long long GetID() { return this->id; }
    string GetName() { return this->name; }
    string GetTime() { return this->time; }
    int AppendMember() {
        this->size += 1;
    }
    void DeleteMember(long long) { this->size -= 1; }
    int AppendAction(Action *action) {
        int id = action->GetID();
        if (this->holdings.count(id) == 0) {
            this->holdings[id] = *action;
            return 0;
        } else {
            return -1;
        }
    }
    void DeleteAction(long long) {
        this->holdings.erase(id);
        actions.erase(id);
    }
};



class Person {
private:
    long long id;
    string name;
    string password;
    map<long long, Action> reviews;
    map<long long, Community> joins;

public:
    Person() {}
    Person(long long id, string name, string password) {
        this->id = id;
        this->name = name;
        this->password = password;
    }
    ~Person() {}
    long long GetID() { return this->id; }
    string GetName() { return this->name; }
    string GetPassword() { return this->password; }
    int ApplyApplication(Action *action) {
        int id = action->GetID();
        if (actions.count(id) == 0) {
            actions[id] = *action;
            this->reviews[id] = *action;
            return 0;
        } else {
            return -1;
        }
    }
    void CancelApplication(long long id) {
        actions.erase(id);
        this->reviews.erase(id);
    }
    int JoinCommunity(Community *community) {
        int id = community->GetID();
        if (communities.count(id) == 0) {
            this->joins[id] = *community;
            return 0;
        } else {
            return -1;
        }
    }
    void ExitCommunity(long long id) { this->joins.erase(id); }
};

#endif
