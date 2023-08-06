#include <iostream>
#include <list>

using namespace std;

// 建造者模式
// 产品类
class Product {
   public:
    void Add(string _parts) { parts->push_back(_parts); }
    void Show() {
        cout << "porduct producing: ";
        for (list<string>::iterator it = parts->begin(); it != parts->end();
             ++it) {
            cout << (*it) << " ";
        }
        cout << endl;
    }

   private:
    list<string>* parts = new list<string>;
};
// 抽象建造者类
class Builder {
   public:
    // 创建产品所需物品
    virtual void buildPart1() = 0;
    virtual void buildPart2() = 0;
    // 成品
    virtual Product* getResult() = 0;
};
// 具体建造者类
class ConcreteBuilder1 : public Builder {
   public:
    virtual void buildPart1() { product->Add("part A"); }
    virtual void buildPart2() { product->Add("part B"); }
    virtual Product* getResult() { return product; }

   private:
    Product* product = new Product;
};
class ConcreteBuilder2 : public Builder {
   public:
    virtual void buildPart1() { product->Add("part X"); }
    virtual void buildPart2() { product->Add("part Y"); }
    virtual Product* getResult() { return product; }

   private:
    Product* product = new Product;
};
// 指挥者
class Director {
   public:
    void Construct(Builder* _build) {
        _build->buildPart1();
        _build->buildPart2();
    }
};

void test() {
    Director* director = new Director;
    Builder* b1 = new ConcreteBuilder1;
    // Builder* b2 = new ConcreteBuilder2;

    director->Construct(b1);
    Product *p1 = b1->getResult();
    p1->Show();

    // director->Construct(b2);
    delete p1;
    delete b1;
    delete director;
}

int main() {
    test();
}