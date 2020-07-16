#pragma once

/*
 Basic templating system for C. The macro dmpTemplate is useful for
 building up names templated on some type. One intended useage is thus:

 In a header, expect some macro to be defined to a type name:

 ```
 #ifndef MyTemplateTy
 #error "define MyTemplateTy before including this header!"
 #endif
 ```

 Next, use this template type to declare some generic code:

 ```
 MyTemplateTy dmpTemplate(foo, MyTemplateTy)();
 ```

 In this example, if MyTemplateTy is defined to int, then a function with the
 prototype `int foo_int()` is declared. Next, have a section guarded by an
 'impl' define:

 ```
 #ifdef DefineFoo
 #undef DefineFoo
 ...
 ```

 In this section, put the implementation:

 ```
 MyTemplateTy dmpTemplate(foo, MyTemplateTy)() {
    modifySomeGlobal();
    return (MyTemplateTy) 0;
 }
 ```

 Of course, none of this is safe, as there are no include guards. You may want
 to have this all in some proper include-guarded header/source pair.

 You can even template on multiple types by nesting the macro calls:

 ```
 void dmpTemplate(dmpTemplate(foo, int), float)();
 ```

 This will expand to `void foo_int_float();`. It's ugly, but this is C and we
 must work with the tools we are given.
 */

#define dmpTemplateNameConcat(name, ty) name##_##ty
#define dmpTemplateNameEval(name, ty) dmpTemplateNameConcat(name, ty)
#define dmpTemplate(name, ty) dmpTemplateNameEval(name, ty)