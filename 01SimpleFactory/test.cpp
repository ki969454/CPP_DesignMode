#include <iostream>

using namespace std;

// 简单工厂模式
// 抽象类
class AbstractOperation {
   public:
    virtual int getResult() = 0;
    void Get(int num1, int num2) {
        this->numberA = num1;
        this->numberB = num2;
    }

   public:
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

// 工厂类 扩展时需要修改源代码
class OperationFactory {
   public:
    static AbstractOperation* Operated(char _str) {
        switch (_str) {
            case '+':
                return new OperationAdd;
            case '-':
                return new OperationSub;
            case '*':
                return new OperationMul;
            case '/':
                return new OperationDiv;
            default:
                return nullptr;
                break;
        }
        return nullptr;
    }
};

void test1() {
    OperationFactory* factory = new OperationFactory;
    AbstractOperation* operate = factory->Operated('+');
    operate->Get(10, 1);
    cout << operate->getResult() << endl;
    delete operate;
    delete factory;
}

int main() {
    test1();
    return 0;
}