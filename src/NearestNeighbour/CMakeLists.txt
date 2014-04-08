add_executable(TestPrim TestPrim.c)
target_link_libraries(TestPrim Prim Input)

add_test(t-prim1 TestPrim ../../../tsp_files/exemple10.tsp)
