#include <iostream>

using namespace std;

// 工厂方法模式
// 抽象运算类
class AbstractOperation {
   public:
    virtual int getResult() = 0;
    void Get(int num1, int num2) {
        this->numberA = num1;
        this->numberB = num2;
    }

   protected:
    int numberA = 0;
    int numberB = 0;
};

// 具体实现类
class OperationAdd : public AbstractOperation {
   public:
    virtual int getResult() { return numberA + numberB; }
};
class OperationSub : public AbstractOperation {
   public:
    virtual int getResult() { return numberA - numberB; }
};
class OperationMul : public AbstractOperation {
   public:
    virtual int getResult() { return numberA * numberB; }
};
class OperationDiv : public AbstractOperation {
   public:
    virtual int getResult() { return numberA / numberB; }
};

// 抽象运算工厂类-->开闭原则: 对扩展开放，对修改关闭
class AbstractOperationFactory {
   public:
    virtual AbstractOperation* CreateOperate() = 0;
};

// 具体运算工厂类
class AddFactory : public AbstractOperationFactory {
   public:
    virtual AbstractOperation* CreateOperate() { return new OperationAdd; }
};
class SubFactory : public AbstractOperationFactory {
   public:
    virtual AbstractOperation* CreateOperate() { return new OperationSub; }
};
class MulFactory : public AbstractOperationFactory {
   public:
    virtual AbstractOperation* CreateOperate() { return new OperationMul; }
};
class DivFactory : public AbstractOperationFactory {
   public:
    virtual AbstractOperation* CreateOperate() { return new OperationDiv; }
};

void test1() {
    AbstractOperationFactory* factory = new AddFactory;
    AbstractOperation* operate = factory->CreateOperate();
    operate->Get(10, 20);
    cout << operate->getResult() << endl;
    delete operate;
    delete factory;
}

int main() {
    test1();
    return 0;
}