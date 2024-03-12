set(DOXYGEN_EXTRACT_ALL YES)
set(DOXYGEN_BUILTIN_STL_SUPPORT YES)

# set the documentation target name and files to include
doxygen_add_docs(DllLibDoc
    "${PROJECT_SOURCE_DIR}/MyDllLib" )
