add_executable(TestPrim TestPrim.c)
target_link_libraries(TestPrim Prim Input)

add_test(t-prim1 TestPrim ../../../tsp_files/exemple10.tsp)
set_tests_properties (t-prim1
  PROPERTIES PASS_REGULAR_EXPRESSION "0 -> 2 -> 5 -> 4 -> 7 -> 9 -> 3 -> 1 -> 6 -> 8 -> 0"
  PASS_REGULAR_EXPRESSION "Taille chemin : 52.0")