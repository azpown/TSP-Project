add_executable(TestArbrePlanaire TestArbre.c)
target_link_libraries(TestArbrePlanaire Arbre)

add_test(t-arbre-ajout-suppression-affichage TestArbrePlanaire)
set_tests_properties (t-arbre-ajout-suppression-affichage
  PROPERTIES PASS_REGULAR_EXPRESSION "ajout racine : 1"
  PASS_REGULAR_EXPRESSION "ajout : 2 -> pere(1)"
  PASS_REGULAR_EXPRESSION "ajout : 3 -> pere(2)"
  PASS_REGULAR_EXPRESSION "ajout : 4 -> pere(2)"
  PASS_REGULAR_EXPRESSION "Affichage avant suppression : 1 -> 2 -> 3 -> 4 -> "
  PASS_REGULAR_EXPRESSION "Affichage apres suppression de 4: 1 -> 2 -> 3 -> ")