#include <iostream>

using namespace std;

// 抽象工厂模式
// 抽象用户类
class AbstractUser {
   public:
    virtual void Inser() = 0;
};

// 具体用户类
class SqlServerUser : public AbstractUser {
   public:
    virtual void Inser() { cout << "Sql server add user" << endl; }
};
class AccessUser : public AbstractUser {
   public:
    virtual void Inser() { cout << "Access add user" << endl; }
};

// 抽象部门类
class AbstractDepartment {
   public:
    virtual void Inser() = 0;
};
// 具体部门类
class SqlServerDepartment : public AbstractDepartment {
   public:
    virtual void Inser() { cout << "Sql server add Department" << endl; }
};
class AccessDepartment : public AbstractDepartment {
   public:
    virtual void Inser() { cout << "Access add Department" << endl; }
};

// 抽象工厂类
class AbstractFactory {
   public:
    virtual AbstractUser* User() = 0;
    virtual AbstractDepartment* Department() = 0;
};
// 具体工厂类
class SqlServerFactory : public AbstractFactory {
   public:
    virtual AbstractUser* User() { return new SqlServerUser; }
    virtual AbstractDepartment* Department() { return new SqlServerDepartment; }
};
class AccessFactory : public AbstractFactory {
   public:
    virtual AbstractUser* User() { return new AccessUser; }
    virtual AbstractDepartment* Department() { return new AccessDepartment; }
};

void test1() {
    AbstractFactory* factory = nullptr;
    AbstractUser* user = nullptr;
    AbstractDepartment* department = nullptr;
    factory = new AccessFactory;
    user = factory->User();
    department = factory->Department();
    user->Inser();
    department->Inser();
    delete factory;
}

int main() {
    test1();
    return 0;
}