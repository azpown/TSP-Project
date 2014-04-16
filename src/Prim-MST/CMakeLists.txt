add_executable(TestPrim1 TestPrim1.c)
target_link_libraries(TestPrim1 Prim Input FonctionTest)
add_executable(TestPrim2 TestPrim2.c)
target_link_libraries(TestPrim2 Prim Input FonctionTest)

add_test(t-prim-cycle-distance-valide TestPrim1 ../../../tsp_files/exemple10.tsp 0)
set_tests_properties (t-prim-cycle-distance-valide
  PROPERTIES PASS_REGULAR_EXPRESSION "Chemin : 0 -> 2 -> 5 -> 4 -> 7 -> 9 -> 3 -> 1 -> 6 -> 8 -> 0"
  PASS_REGULAR_EXPRESSION "Taille chemin : 52.0"
  PASS_REGULAR_EXPRESSION "OK")

add_test(t-prim-2approx-valide-ex10 TestPrim2 ../../../tsp_files/exemple10.tsp 42)
set_tests_properties (t-prim-cycle-distance-valide
  PROPERTIES PASS_REGULAR_EXPRESSION "OK")

# On prend l'entier directement supérieur au poid du chemin min
add_test(t-prim-2approx-valide-bays29 TestPrim2 ../../../tsp_files/bays29.tsp 2000)
set_tests_properties (t-prim-cycle-distance-valide
  PROPERTIES PASS_REGULAR_EXPRESSION "OK")

