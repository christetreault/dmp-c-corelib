#pragma once

#ifdef _MSC_VER
#define DMP_RESTRICT __restrict
#else
// TODO: restrict probably isn't always available otherwise
#define DMP_RESTRICT restrict
#endif