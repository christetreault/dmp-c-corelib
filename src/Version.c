#include "version/Version.h"

DmpVersion dmpVersionCreate(uint32_t major,
                            uint32_t minor,
                            uint32_t patch)
{
  DmpVersion ver;

  ver.major = major;
  ver.minor = minor;
  ver.patch = patch;

  return ver;
}

bool dmpVersionGE(DmpVersion lhs,
                  DmpVersion rhs)
{
  bool majorGE = lhs.major >= rhs.major;
  bool minorGE = lhs.minor >= rhs.minor;
  bool patchGE = lhs.patch >= rhs.patch;

  return majorGE && minorGE && patchGE;
}

bool dmpVersionLT(DmpVersion lhs,
                  DmpVersion rhs)
{
  bool majorLT = lhs.major < rhs.major;
  bool minorLT = lhs.minor < rhs.minor;
  bool patchLT = lhs.patch < rhs.patch;

  return majorLT && minorLT && patchLT;
}

bool dmpVersionEQ(DmpVersion lhs,
                  DmpVersion rhs)
{
  bool majorEQ = lhs.major == rhs.major;
  bool minorEQ = lhs.minor == rhs.minor;
  bool patchEQ = lhs.patch == rhs.patch;

  return majorEQ && minorEQ && patchEQ;
}
