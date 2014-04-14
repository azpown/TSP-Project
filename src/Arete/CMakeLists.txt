add_executable(TestArete TestArete.c Arete.c)

add_test(t-Arete-creation-destruction-modification TestArete)
set_tests_properties (t-Arete-creation-destruction-modification
  PROPERTIES PASS_REGULAR_EXPRESSION "Depart: 0	Arrive: 10	Cle: 5.0
Depart: 0	Arrive: 3	Cle: 5.0
5.0 == 5.0 -> 0
50 == 25 -> 1
50 == 100 -> -1")