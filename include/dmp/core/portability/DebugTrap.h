#pragma once

#ifdef debugTrap
#error "debugTrap already defined!"
#endif

#ifdef _MSC_VER
#define debugTrap() __debugbreak()
#elif
#error "TODO: what is debugTrap called on not-msvc?"
#endif