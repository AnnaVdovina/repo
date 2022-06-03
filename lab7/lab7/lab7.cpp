#include <iostream>

using namespace std;

// Абстрактные продукты
struct PostCard {
    virtual string give() = 0; //ЧВФ
};

struct Present {
    virtual string give() = 0;//ЧВФ
};

struct Cake {
    virtual string give() = 0;//ЧВФ
};


//Конкретные продукты
struct  NYCard : public PostCard {
    virtual string give() {
        string res = "NYCard::give()";
        return res;
    }
};

struct BDCard : public PostCard {
    virtual string give() {
        string res = "BDCard::give()";
        return res;
    }
};

struct MarchCard : public PostCard {
    virtual string give() {
        string res = "MarchCard::give()";
        return res;
    }
};

struct  NYPresent : public Present {
    virtual string give() {
        string res ="NYPresent::give()";
        return res;
    }
};

struct BDPresent : public Present {
    virtual string give() {
        string res ="BDPresent::give()";
        return res;
    }
};

struct MarchPresent : public Present {
    virtual string give() {
        string res ="MarchPresent::give()";
        return res;
    }
};

struct  NYCake : public Cake {
    virtual string give() {
        string res ="NYCake::give()";
        return res;
    }
};

struct BDCake : public Cake {
    virtual string give() {
        string res ="BDCake::give()";
        return res;
    }
};
struct MarchCake : public Cake {
    virtual string give() {
        string res ="MarchCake::give()";
        return res;
    }
};



//Если хотим еще один уровень сложности, то нам нужна еще конкретная фабрика


//Абстрактная фабрика
struct AbstractFactory {
    virtual PostCard* createPostCard() = 0; // интерфейс для создания семейств объектов
    virtual Present* createPresent() = 0;
    virtual Cake* createCake() = 0;//новая ЧВФ для создания нового продукта
};

//Конкретные фабрики
struct NYFactory : public AbstractFactory {
    virtual PostCard* createPostCard() {
        return new NYCard();
    }
    virtual Present* createPresent() {
        return new NYPresent();
    }
    virtual Cake* createCake() { //реализация нового метода для создания нового продукта
        return new NYCake();
    }
};


struct BDFactory : public AbstractFactory {
    virtual PostCard* createPostCard() {
        return new BDCard();
    }
    virtual Present* createPresent() {
        return new BDPresent();
    }
    virtual Cake* createCake() { //реализация нового метода для создания нового продукта
        return new BDCake();
    }
};

struct MarchFactory : public AbstractFactory {
    virtual PostCard* createPostCard() {
        return new MarchCard();
    }
    virtual Present* createPresent() {
        return new MarchPresent();
    }
    virtual Cake* createCake() {
        return new MarchCake();
    }
};


//программа-клиент
int main() {

    AbstractFactory* F = new NYFactory(); //предполагаем сначала низкий уровень сложности -> семейство "тупых" продуктов
    PostCard* m;
    Present* b;
    Cake* d; //указатель на новый продукт

    m = F->createPostCard();
    b = F->createPresent();
    d = F->createCake();

    m->give();
    b->give();
    d->give();

    delete F;
    delete m; delete b; delete d;

    cout << "------------------------" << endl;

    F = new BDFactory();

    m = F->createPostCard();
    b = F->createPresent();
    d = F->createCake();

    m->give();
    b->give();
    d->give();

    delete F;
    delete m; delete b; delete d;

    cout << "------------------------" << endl;

    
    F = new MarchFactory();

    m = F->createPostCard();
    b = F->createPresent();
    d = F->createCake();

    m->give();
    b->give();
    d->give();

    delete F;
    delete m; delete b; delete d;
    
    cout << "------------------------" << endl;


    return 0;
}