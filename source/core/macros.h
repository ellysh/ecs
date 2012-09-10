#ifndef MACROS_H
#define MACROS_H

/* A macro to disallow the copy constructor and operator= functions.
 * This should be used in the private: declarations for a class.
 * For more info see http://google-styleguide.googlecode.com/svn/trunk/cppguide.xml */
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
private: \
    TypeName(const TypeName&);               \
    TypeName& operator=(const TypeName&);

#endif
