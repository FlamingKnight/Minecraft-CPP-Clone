add_subdirectory(app)
add_subdirectory(thirdparty)
add_subdirectory(unit)

target_include_directories(rh PRIVATE .)

# target_link_options(rh PRIVATE -lpthread)
