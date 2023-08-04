#include <iostream>
using namespace std;

// 单例模式-懒汉式
class Singleton_lazy {
   private:
    Singleton_lazy() { cout << "lazy" << endl; }
    static Singleton_lazy* pSingleton;

   public:
    static Singleton_lazy* getInstance() {
        if (pSingleton == nullptr) {
            pSingleton = new Singleton_lazy;
        }
        return pSingleton;
    }
};

// 类外初始化
Singleton_lazy* Singleton_lazy::pSingleton = nullptr;

// 单例模式-饿汉式
class Singleton_hungry {
   private:
    Singleton_hungry() { cout << "hungry" << endl; }
    static Singleton_hungry* pSingleton;

   public:
    static Singleton_hungry* getInstance() {
        return pSingleton;
    }
};

// 在主函数前就实例化了
// Singleton_hungry* Singleton_hungry::pSingleton = new Singleton_hungry;


void test() {
    Singleton_lazy* s1 = Singleton_lazy::getInstance();
    Singleton_lazy* s2 = Singleton_lazy::getInstance();
    if (s1 == s2) {
        cout << "same" << endl;
    }
}

int main() {
    test();
    return 0;
}