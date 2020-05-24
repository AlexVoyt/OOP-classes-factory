#pragma warning(push, 0)
#include <iostream>
#include <vector>
#include <stdint.h>
#pragma warning(pop)

typedef int8_t  s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

enum Race
{
    HUMAN = 0,
    ELF = 1,
    ORC = 2,
};

enum Specialization
{
    WARRIOR = 0,
    MAGE = 1,
    RANGER = 2,
};

void Print_Race(Race race)
{
    switch(race)
    {
        case HUMAN:
        {
            std::cout << "Human" << std::endl;
        } break;
        case ORC:
        {
            std::cout << "Orc" << std::endl;
        } break;
        case ELF:
        {
            std::cout << "Elf" << std::endl;
        } break;
        default:
        {}
    };
}

void Print_Specialization(Specialization spec)
{
    switch(spec)
    {
        case WARRIOR:
        {
            std::cout << "Warrior" << std::endl;
        } break;
        case MAGE:
        {
            std::cout << "Mage" << std::endl;
        } break;
        case RANGER:
        {
            std::cout << "Ranger" << std::endl;
        } break;
        default:
        {}
    };
}

class Creature
{
    u32 hp = 0;
    u32 damage = 0;
    Race race = HUMAN;
    Specialization spec = WARRIOR;

    public:
    Creature(u32 _hp, u32 _damage, Race _race, Specialization _spec)
    {
        hp = _hp;
        damage = _damage;
        race = _race;
        spec = _spec;
    }

    void Print()
    {
        std::cout << "HP: " << hp << std::endl;
        std::cout << "DAMAGE" << damage << std::endl;
        Print_Race(race);
        Print_Specialization(spec);
    }

    static Creature *Create_Orc_Warrior()
    {
        return new Creature(45, 10, ORC, WARRIOR);
    }

    static Creature *Create_Elf_Warrior()
    {
        return new Creature(35, 12, ELF, WARRIOR);
    }

    static Creature *Create_Human_Mage()
    {
        return new Creature(25, 16, HUMAN, MAGE);
    }

};

int main()
{
    Creature *cr1 = Creature::Create_Orc_Warrior();
    Creature *cr2 = Creature::Create_Elf_Warrior();
    Creature *cr3 = Creature::Create_Human_Mage();
    cr1->Print();
    cr2->Print();
    cr3->Print();
    return 0;
}
