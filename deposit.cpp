#include "./game.h"
#include "./structures.h"
#include <vector>
using namespace structures;

// int getdepositid(int xqry, int yqry)
// {
//   for(int checkd; checkd < deposits.size(); checkd++)
//   {
//     if(deposits.at(checkd).x == xqry & deposits.at(checkd).y == yqry)
//     {
//       return checkd;
//     }
//   }
//   return -1;
// }
//
// int getdepositx(int depositid)
// {return deposits.at(depositid).x;}
// int getdeposity(int depositid)
// {return deposits.at(depositid).y;}
//
// char getdepositresource(int depositid)
// {
//   return deposits.at(depositid).resourcetype;
// }
//
// void clearresources(int depositid, int minerate)
// {
//   deposits.at(depositid).amount -= minerate;
// }
//
// void irongenerator()
// {
//   int depositcount{randbell(8, 2)};
//
//   for(int i{0}; i < depositcount; i++)
//   {
//     int x{randuni(0, 9)};
//     int y{randuni(0, 9)};
//
//     if(getdepositid(x, y) == -1)
//     {
//       deposits.push_back({x, y, 0b0000'0001, randbell(750, 250)});
//     }
//   }
// }
//
// void dodeposits()
// {
//   for(int i{0}; i < deposits.size(); i++)
//   {
//     addobject(deposits.at(i).x, deposits.at(i).y, '@');
//   }
// }
//
// void dodepositdata(int x, int y)
// {
//   int depositid{getdepositid(x, y)};
//
//   if(depositid != -1)
//   {
//     deposits.at(depositid).displaydepositdata();
//   }
// }
//
// void generatedeposits()
// {
//   irongenerator();
// }
