Templates works to save codes that a lof of classes use the "same" code, same scope
so, there's a way that c++ leads this for us

template <typename T>    // declare it before the class or method you want to have a dynamic Type

example in the .cpp

When we have templates, for methos, classes, or anything, all the method and/or class, has to be declared and implemented, in the header(.h) file, because template says it's not a function or class

When you have a template to a method, class, struct, or etc, it become no more a method, class, etc, it become a recipe to make the class, method, etc. Now, we can them a template method, template class, etc. That's why we canno put them in the .cpp implementation, because it's not a class or method.