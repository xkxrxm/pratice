#pragma once
#include <string>
#include <iostream>
using std::string;
class TableTennisPlayer
{
private:
    string firstname;
    string lastname;
    bool hasTable;

public:
    TableTennisPlayer(const string &fn = "none",
                      const string &ln = "none", bool ht = false) : firstname(fn), lastname(ln), hasTable(ht) {};
    void Name() const
    {
        std::cout << lastname << "," << firstname << std::endl;
    };
    bool HasTable() const
    {
        return hasTable;
    };
    void ResetTable(bool v)
    {
        hasTable = v;
    };
};

// simple derived class
class RatedPlayer : public TableTennisPlayer
{
private:
    unsigned int rating;

public:
    RatedPlayer(unsigned intr = 0, const string &fn = "none",
                const string &ln = "none", bool ht = false) : TableTennisPlayer(fn, ln, ht), rating(intr) {};
    RatedPlayer(unsigned int r, const TableTennisPlayer &tp) : TableTennisPlayer(tp), rating(r) {};
    unsigned int Rating() const
    {
        return rating;
    }
    void ResetRating(unsigned int r)
    {
        rating = r;
    }
};