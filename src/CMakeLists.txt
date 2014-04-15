add_library(Arbre ArbrePlanaire/ArbrePlanaireInt.c ArbrePlanaire/ArbrePlanaireGenerique.c)
add_library(Tas Tas/TasArete.c Tas/TasGenerique.c Arete/Arete.c)
add_library(Input Input/Input.c Graphe/Graphe.c)
add_library(NN NearestNeighbour/NearestNeighbour.c Graphe/Graphe.c)

add_library(FonctionTest Test/FonctionTest.c)
target_link_libraries(FonctionTest Input)
add_library(Prim Prim-MST/Prim.c)
target_link_libraries(Prim Arbre Tas)
add_library(BFO BruteForceOpti/BruteForceOpti.c)
target_link_libraries(BFO NN)


install(TARGETS Arbre Tas Input NN Prim BFO FonctionTest DESTINATION ${TSP_SOURCE_DIR}/lib)

add_subdirectory(Arete)
add_subdirectory(Input)
add_subdirectory(ArbrePlanaire)
add_subdirectory(Tas)
add_subdirectory(Prim-MST)
add_subdirectory(NearestNeighbour)
add_subdirectory(BruteForceOpti)


#add_subdirectory(NearestNeighbour)
# Petite modif' a faire 