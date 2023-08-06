#include <iostream>

using namespace std;

// 适配器模式
// Target
class Player {
   public:
    Player(string _name) : name(_name) {}
    virtual void Attack() = 0;
    virtual void Defense() = 0;

   protected:
    string name;
};

class Forwards : public Player {
   public:
    Forwards(string _name) : Player(_name) {}
    virtual void Attack() { cout << "forwards " << name << " attack" << endl; }
    virtual void Defense() {
        cout << "forwards " << name << " defense" << endl;
    }
};

class Guards : public Player {
   public:
    Guards(string _name) : Player(_name) {}
    virtual void Attack() { cout << "guards " << name << " attack" << endl; }
    virtual void Defense() { cout << "guards " << name << " defense" << endl; }
};
// Adptee
class ForeignCenter {
   public:
    void setName(string _name) { name = _name; }
    string getName() { return name; }
    void ForeignAttack() { cout << "foreign " << name << " attack" << endl; }
    void ForeignDefense() { cout << "foreign " << name << " defense" << endl; }

   private:
    string name;
};
// 适配器类--Adpter
class Translator : public Player {
   public:
    Translator(string _name) : Player(_name) {
        wjzf = new ForeignCenter;
        wjzf->setName(_name);
    }
    void Attack() { wjzf->ForeignAttack(); }
    void Defense() { wjzf->ForeignDefense(); }
    ~Translator() {
        if (wjzf != nullptr) {
            delete wjzf;
        }
        wjzf = nullptr;
    }

   private:
    ForeignCenter* wjzf;
};

void test() {
    Player* p1 = new Forwards("p1");
    Player* p2 = new Guards("p2");
    Player* p3 = new Translator("foreign");
    p1->Attack();
    p1->Defense();
    p2->Attack();
    p2->Defense();
    p3->Attack();
    p3->Defense();
}

int main() {
    test();
}