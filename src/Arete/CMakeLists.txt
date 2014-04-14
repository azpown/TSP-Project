add_executable(TestArete TestArete.c Arete.c)

add_test(t-Arete1 TestArete)
set_tests_properties (t-Arete1
  PROPERTIES PASS_REGULAR_EXPRESSION "Depart: 0	Arrive: 10	Cle: 5.0
Depart: 0	Arrive: 3	Cle: 5.0
5.0 == 5.0 -> 0
50 == 25 -> 1
50 == 100 -> -1")