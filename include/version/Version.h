#pragma once

#include <stdbool.h>
#include <stdint.h>

typedef struct
{
   uint32_t major;
   uint32_t minor;
   uint32_t patch;
} DmpVersion;

DmpVersion dmpVersionCreate(uint32_t major, uint32_t minor, uint32_t patch);

// strcmp semantics:
// l > r  =>  1
// l == r =>  0
// l < r  => -1
int dmpVersionCmp(DmpVersion lhs, DmpVersion rhs);

bool dmpVersionGT(DmpVersion lhs, DmpVersion rhs);
bool dmpVersionGE(DmpVersion lhs, DmpVersion rhs);
bool dmpVersionEQ(DmpVersion lhs, DmpVersion rhs);
bool dmpVersionLT(DmpVersion lhs, DmpVersion rhs);
bool dmpVersionLE(DmpVersion lhs, DmpVersion rhs);
