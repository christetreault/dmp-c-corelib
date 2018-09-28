#pragma once

#include <stdbool.h>
#include <stdint.h>

typedef struct
{
  uint32_t major;
  uint32_t minor;
  uint32_t patch;
} DmpVersion;

DmpVersion dmpVersionCreate(uint32_t major,
                            uint32_t minor,
                            uint32_t patch);

bool dmpVersionGE(DmpVersion lhs,
                  DmpVersion rhs);

bool dmpVersionLT(DmpVersion lhs,
                  DmpVersion rhs);

bool dmpVersionEQ(DmpVersion lhs,
                  DmpVersion rhs);
