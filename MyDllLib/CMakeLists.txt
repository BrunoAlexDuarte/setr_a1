# Set the source files that make up the library
set(MYDLL_SRCS
   my_dll.h my_dll.c
)

# Set the library type (can be static or dynamic )
SET (LIB_TYPE STATIC)

# Create the library
add_library (MyDllLib ${LIB_TYPE} ${MYDLL_SRCS})
