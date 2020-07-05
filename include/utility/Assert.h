#pragma once

#include <stdio.h>

// TODO: different versions for debug vs release mode

#ifndef dmpExpect
#define dmpExpect(_msg, _e)                                                                        \
   {                                                                                               \
      if (!(_e))                                                                                   \
      {                                                                                            \
         fprintf(stderr,                                                                           \
             "Truth Assertion Failed!\n\t%s\n\tFile: %s"                                           \
             "\n\tLine: %d\n\tFunction: %s\n",                                                     \
             _msg, __FILE__, __LINE__, __func__);                                                  \
         exit(EXIT_FAILURE);                                                                       \
      }                                                                                            \
   }
#else
#error dmpExpect already defined!
#endif

#ifndef dmpVerify
#define dmpVerify(_msg, _e) expect(_msg, _e)
#else
#error dmpVerify already defined!
#endif

#ifndef dmpUnreachable
#define dmpUnreachable(_msg)                                                                       \
   {                                                                                               \
      fprintf(stderr,                                                                              \
          "Unreachable code executed! This should never happen!\n\t%s\n\tFile: %s"                 \
          "\n\tLine: %d\n\tFunction: %s\n",                                                        \
          _msg, __FILE__, __LINE__, __func__);                                                     \
      exit(EXIT_FAILURE);                                                                          \
   }
#else
#error dmpUnreachable already defined!
#endif

#ifndef dmpTodo
#define dmpTodo(_msg)                                                                              \
   {                                                                                               \
      fprintf(stderr,                                                                              \
          "Feature not implemented! This should never happen!\n\t%s\n\tFile: %s"                   \
          "\n\tLine: %d\n\tFunction: %s\n",                                                        \
          _msg, __FILE__, __LINE__, __func__);                                                     \
      exit(EXIT_FAILURE);                                                                          \
   }
#else
#error dmpTodo already defined!
#endif

#ifndef dmpImpossible
#define dmpImpossible(_msg)                                                                        \
   {                                                                                               \
      fprintf(stderr,                                                                              \
          "This should never happen!\n\t%s\n\tFile: %s"                                            \
          "\n\tLine: %d\n\tFunction: %s\n",                                                        \
          _msg, __FILE__, __LINE__, __func__);                                                     \
      exit(EXIT_FAILURE);                                                                          \
   }
#else
#error dmpImpossible already defined!
#endif
