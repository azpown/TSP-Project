add_executable(TestParseur1 TestInput1.c )
target_link_libraries (TestParseur1 Input)
add_executable(TestParseur2 TestInput2.c )
target_link_libraries (TestParseur2 Input)
add_executable(TestParseur3 TestInput3.c )
target_link_libraries (TestParseur3 Input)
add_executable(TestParseur4 TestInput4.c )
target_link_libraries (TestParseur4 Input)
add_executable(TestParseur5 TestInput5.c )
target_link_libraries (TestParseur5 Input)

add_test(t-parseur-affichage TestParseur1 ../../../tsp_files/exemple10.tsp)
set_tests_properties (t-parseur-affichage
  PROPERTIES PASS_REGULAR_EXPRESSION "-- Données d'entrées --"
  PASS_REGULAR_EXPRESSION "nom_file : ../../tsp_files/exemple10.tsp"
  PASS_REGULAR_EXPRESSION "nom : exemple10.tsp"
  PASS_REGULAR_EXPRESSION "type : TSP"
  PASS_REGULAR_EXPRESSION "commentaire : (null)"
  PASS_REGULAR_EXPRESSION "dimension : 10"
  PASS_REGULAR_EXPRESSION "edge_weight_type : EXPLICIT"
  PASS_REGULAR_EXPRESSION "edge_weight_format : FULL_MATRIX"
  PASS_REGULAR_EXPRESSION "display_data_type : TWOD_DISPLAY"
  PASS_REGULAR_EXPRESSION "edge_weight_matrix :"
  PASS_REGULAR_EXPRESSION "0.0\t9.0\t4.0\t11.0\t10.08.0\t8.0\t13.0\t10.0\t16.0"	
  PASS_REGULAR_EXPRESSION "9.0\t0.0\t7.0\t2.0\t7.0\t9.0\t13.0\t10.0\t15.0\t11.0"	
  PASS_REGULAR_EXPRESSION "4.0\t7.0\t0.0\t7.0\t6.0\t4.0\t6.0\t9.0\t8.0\t12.0"	
  PASS_REGULAR_EXPRESSION "11.0\t2.0\t7.0\t0.0\t5.0\t7.0\t11.0\t8.0\t13.0\t9.0"	
  PASS_REGULAR_EXPRESSION "10.0\t7.0\t6.0\t5.0\t0.0\t2.0\t6.0\t3.0\t8.0\t6.0"	
  PASS_REGULAR_EXPRESSION "8.0\t9.0\t4.0\t7.0\t2.0\t0.0\t4.0\t5.0\t6.0\t8.0"	
  PASS_REGULAR_EXPRESSION "8.0\t13.0\t6.0\t11.0\t6.0\t4.0\t0.0\t5.0\t2.0\t8.0"	
  PASS_REGULAR_EXPRESSION "13.0\t10.0\t9.0\t8.0\t3.0\t5.0\t5.0\t0.0\t5.0\t3.0"	
  PASS_REGULAR_EXPRESSION "10.0\t15.0\t8.0\t13.0\t8.0\t6.0\t2.0\t5.0\t0.0\t6.0"	
  PASS_REGULAR_EXPRESSION "16.0\t11.0\t12.0\t9.0\t6.0\t8.0\t8.0\t3.0\t6.0\t0.0"	
  PASS_REGULAR_EXPRESSION "display_data :"
  PASS_REGULAR_EXPRESSION "1  ->\t1.0\t1.0"
  PASS_REGULAR_EXPRESSION "2  ->\t1.0\t10.0"
  PASS_REGULAR_EXPRESSION "3  ->\t2.0\t4.0"
  PASS_REGULAR_EXPRESSION "4 ->\t3.0\t10.0"
  PASS_REGULAR_EXPRESSION "5 ->\t5.0\t7.0"
  PASS_REGULAR_EXPRESSION "6 ->\t5.0\t5.0"
  PASS_REGULAR_EXPRESSION "7 ->\t7.0\t3.0"
  PASS_REGULAR_EXPRESSION "8 ->\t8.0\t7.0"
  PASS_REGULAR_EXPRESSION "9 ->\t9.0\t3.0"
  PASS_REGULAR_EXPRESSION "10 ->\t10.0\t8.0")
  
add_test(t-parseur-expected-value TestParseur2)
set_tests_properties (t-parseur-expected-value 
  PROPERTIES PASS_REGULAR_EXPRESSION "OK")

add_test(t-parseur-error-noDimension TestParseur3)
set_tests_properties (t-parseur-error-noDimension
  PROPERTIES PASS_REGULAR_EXPRESSION "./TestParseur3: Dimension incorrecte")

add_test(t-parseur-error-notSymmetrical TestParseur4)
set_tests_properties (t-parseur-error-notSymmetrical
  PROPERTIES PASS_REGULAR_EXPRESSION "./TestParseur4: Erreur matrice: Matrice non symétrique.")