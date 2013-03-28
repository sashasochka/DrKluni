project(drkluni)

add_executable(drkluni DrKluniHelper.cpp main.cpp)

install(TARGETS drkluni RUNTIME DESTINATION bin)
