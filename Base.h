#pragma once
class Base
{
protected:
    virtual void SetHP(int hp);
    virtual void SetAtk(int atk);
    virtual void SetDef(int def);
    virtual void SetLevel(int lvl);

public:
    const std::string name;
    Base(std::string Name);
    ~Base();
    virtual int GetHP() const;
    virtual int GetAtk() const;
    virtual int GetDef() const;
    virtual int GetLevel() const;
    virtual bool IsDead() const;
    virtual void Victory();
    void Attack(Base& other);
    void Load(int hp, int atk, int def, int lvl);
};

class Character : public Base {
    int _hp;
    int _atk;
    int _def;
    int _lvl=1;

public:
    void SetHP(int hp) override { _hp = hp; };
    void SetAtk(int atk) override { _atk = atk; };
    void SetDef(int def) override { _def = def; };
    void SetLevel(int lvl) override { _lvl = lvl; };

    int GetHP() const { return _hp; }
    int GetAtk() const { return _atk; }
    int GetDef() const { return _def; }
    int GetLevel() const { return _lvl; }

    bool IsDead() const {
        if (_hp <= 0) return true;
        else return false;
    }
   
    Character(std::string Name);
    ~Character();
};

class Player : public Character {
    int _xp;
public:
    Player(std::string Name = "Player");
    ~Player();
    void SetXP(int xp) { _xp = xp; }
    int GetXP() { return _xp; }
};

class Enemy : public Character {
    int _xpReward;
public:
    Enemy(std::string Name = "Enemy");
    ~Enemy();

    void SetXpReward(int xpReward) { _xpReward = xpReward; }
    int GetXpReward() { return _xpReward; }
    
};

