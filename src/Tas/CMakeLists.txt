add_executable(TestTas TestTas.c)
target_link_libraries(TestTas Tas)

add_test(t-tas-ajout-destruction-modifKey TestTas)
set_tests_properties (t-tas-ajout-destruction-modifKey
  PROPERTIES PASS_REGULAR_EXPRESSION "CONTENU DU TAS MIN
Depart: 2	Arrive: 5	Cle: 10.0
	CONTENU DU TAS MIN
Depart: 2	Arrive: 7	Cle: 2.0
Depart: 2	Arrive: 5	Cle: 10.0
	CONTENU DU TAS MIN
Depart: 2	Arrive: 7	Cle: 2.0
Depart: 2	Arrive: 4	Cle: 4.0
Depart: 2	Arrive: 5	Cle: 10.0
	CONTENU DU TAS MIN
Depart: 2	Arrive: 7	Cle: 2.0
Depart: 2	Arrive: 4	Cle: 4.0
Depart: 2	Arrive: 5	Cle: 10.0
Depart: 2	Arrive: 1	Cle: 89.0
	CONTENU DU TAS MIN
Depart: 2	Arrive: 7	Cle: 2.0
Depart: 2	Arrive: 4	Cle: 4.0
Depart: 2	Arrive: 9	Cle: 7.0
Depart: 2	Arrive: 1	Cle: 89.0
Depart: 2	Arrive: 5	Cle: 10.0

------ TEST EXTRACTION ------

Arete extraite :	Depart: 2	Arrive: 7	Cle: 2.0
	CONTENU DU TAS MIN
Depart: 2	Arrive: 4	Cle: 4.0
Depart: 2	Arrive: 5	Cle: 10.0
Depart: 2	Arrive: 9	Cle: 7.0
Depart: 2	Arrive: 4	Cle: 42.0
Depart: 2	Arrive: 1	Cle: 42.0
Depart: 2	Arrive: 5	Cle: 42.0
Depart: 2	Arrive: 1	Cle: 89.0
Depart: 2	Arrive: 3	Cle: 42.0
Depart: 2	Arrive: 2	Cle: 42.0
Arete extraite :	Depart: 2	Arrive: 4	Cle: 4.0
	CONTENU DU TAS MIN
Depart: 2	Arrive: 9	Cle: 7.0
Depart: 2	Arrive: 5	Cle: 10.0
Depart: 2	Arrive: 2	Cle: 42.0
Depart: 2	Arrive: 4	Cle: 42.0
Depart: 2	Arrive: 1	Cle: 42.0
Depart: 2	Arrive: 5	Cle: 42.0
Depart: 2	Arrive: 1	Cle: 89.0
Depart: 2	Arrive: 3	Cle: 42.0

------ TEST MODIFKEYS ------

	CONTENU DU TAS MIN
Depart: 2	Arrive: 5	Cle: 1.0
Depart: 2	Arrive: 9	Cle: 7.0
Depart: 2	Arrive: 2	Cle: 42.0
Depart: 2	Arrive: 4	Cle: 42.0
Depart: 2	Arrive: 1	Cle: 42.0
Depart: 2	Arrive: 5	Cle: 42.0
Depart: 2	Arrive: 1	Cle: 89.0
Depart: 2	Arrive: 3	Cle: 42.0
	CONTENU DU TAS MIN
Depart: 2	Arrive: 5	Cle: 1.0
Depart: 2	Arrive: 2	Cle: 2.0
Depart: 2	Arrive: 9	Cle: 7.0
Depart: 2	Arrive: 4	Cle: 42.0
Depart: 2	Arrive: 1	Cle: 42.0
Depart: 2	Arrive: 5	Cle: 42.0
Depart: 2	Arrive: 1	Cle: 89.0
Depart: 2	Arrive: 3	Cle: 42.0")
