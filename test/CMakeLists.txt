add_executable(BasicTest BasicTest.cpp)
target_link_libraries(BasicTest tinygpsplus)
add_test(NAME BasicTest COMMAND BasicTest)
set_property(TEST BasicTest PROPERTY
  FAIL_REGULAR_EXPRESSION "INVALID")
