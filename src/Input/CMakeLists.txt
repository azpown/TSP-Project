add_executable(TestParseur1 TestInput1.c )
target_link_libraries (TestParseur1 Input)
add_executable(TestParseur2 TestInput2.c )
target_link_libraries (TestParseur2 Input)

add_test(t-parseur1 TestParseur1 ../../../tsp_files/exemple10.tsp)
set_tests_properties (t-parseur1
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
  PASS_REGULAR_EXPRESSION "9.0	4.0	11.0	10.0	8.0	8.0	13.0	10.0	16.0"	
  PASS_REGULAR_EXPRESSION "9.0	7.0	2.0	7.0	9.0	13.0	10.0	15.0	11.0"	
  PASS_REGULAR_EXPRESSION "4.0	7.0	7.0	6.0	4.0	6.0	9.0	8.0	12.0"	
  PASS_REGULAR_EXPRESSION "11.0	2.0	7.0	5.0	7.0	11.0	8.0	13.0	9.0"	
  PASS_REGULAR_EXPRESSION "10.0	7.0	6.0	5.0	2.0	6.0	3.0	8.0	6.0"	
  PASS_REGULAR_EXPRESSION "8.0	9.0	4.0	7.0	2.0	4.0	5.0	6.0	8.0"	
  PASS_REGULAR_EXPRESSION "8.0	13.0	6.0	11.0	6.0	4.0	5.0	2.0	8.0"	
  PASS_REGULAR_EXPRESSION "13.0	10.0	9.0	8.0	3.0	5.0	5.0	5.0	3.0"	
  PASS_REGULAR_EXPRESSION "10.0	15.0	8.0	13.0	8.0	6.0	2.0	5.0	6.0"	
  PASS_REGULAR_EXPRESSION "16.0	11.0	12.0	9.0	6.0	8.0	8.0	3.0	6.0"	
  PASS_REGULAR_EXPRESSION "display_data :"
  PASS_REGULAR_EXPRESSION "1  ->	1.0	1.0"
  PASS_REGULAR_EXPRESSION "2  ->	1.0	10.0"
  PASS_REGULAR_EXPRESSION "3  ->	2.0	4.0"
  PASS_REGULAR_EXPRESSION "4 ->	3.0	10.0"
  PASS_REGULAR_EXPRESSION "5 ->	5.0	7.0"
  PASS_REGULAR_EXPRESSION "6 ->	5.0	5.0"
  PASS_REGULAR_EXPRESSION "7 ->	7.0	3.0"
  PASS_REGULAR_EXPRESSION "8 ->	8.0	7.0"
  PASS_REGULAR_EXPRESSION "9 ->	9.0	3.0"
  PASS_REGULAR_EXPRESSION "10 ->	10.0	8.0")
  
add_test(t-parseur2 TestParseur2)
set_tests_properties (t-parseur2 
  PROPERTIES PASS_REGULAR_EXPRESSION "OK")