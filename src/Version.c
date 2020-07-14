#include "dmp/utility/Version.h"

DmpVersion dmpVersionCreate(uint32_t major, uint32_t minor, uint32_t patch)
{
   DmpVersion ver;

   ver.major = major;
   ver.minor = minor;
   ver.patch = patch;

   return ver;
}

int dmpVersionCmp(DmpVersion lhs, DmpVersion rhs)
{
   if (lhs.major < rhs.major)
      return -1;
   else if (lhs.major > rhs.major)
      return 1;

   if (lhs.minor < rhs.minor)
      return -1;
   else if (lhs.minor > rhs.minor)
      return 1;

   if (lhs.patch < rhs.patch)
      return -1;
   else if (lhs.patch > rhs.patch)
      return 1;

   return 0;
}

bool dmpVersionGT(DmpVersion lhs, DmpVersion rhs)
{
   return dmpVersionCmp(lhs, rhs) > 0;
}

bool dmpVersionGE(DmpVersion lhs, DmpVersion rhs)
{
   return dmpVersionCmp(lhs, rhs) >= 0;
}

bool dmpVersionEQ(DmpVersion lhs, DmpVersion rhs)
{
   return dmpVersionCmp(lhs, rhs) == 0;
}

bool dmpVersionLE(DmpVersion lhs, DmpVersion rhs)
{
   return dmpVersionCmp(lhs, rhs) <= 0;
}

bool dmpVersionLT(DmpVersion lhs, DmpVersion rhs)
{
   return dmpVersionCmp(lhs, rhs) < 0;
}